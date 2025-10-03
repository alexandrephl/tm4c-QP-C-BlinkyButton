#include <stdint.h>
#include "qpc.h"
#include "bsp.h"

/* Binary semaphore signaled from the SW1 IRQ */
QXSemaphore SW1_sema;

// --- Thread 1: Green LED "busy work" -------------------------------------------------------
static uint32_t stack_blinky1[40];
static QXThread blinky1;

static void main_blinky1(QXThread * const me) {
    while (1) {
        uint32_t volatile i;
        for (i = 1500U; i != 0U; --i){
            BSP_ledGreenOn();
            BSP_ledGreenOff();
        }
        QXThread_delay(1U); /* block for 1 clock tick */
    }
}

// --- Thread 2: Blue LED burst when botton is switched ---------------------
static uint32_t stack_blinky2[40];
static QXThread blinky2;

static void main_blinky2(QXThread * const me) {
    while (1) {
        uint32_t volatile i;

        /* Wait forever until SW1 IRQ signals the semaphore */
        QXSemaphore_wait(&SW1_sema, //pointer to the semaphore to wait on
                         QXTHREAD_NO_TIMEOUT);  //timeout for waiting

        for (i = 15*1500U; i != 0U; --i){
            BSP_ledBlueOn();
            BSP_ledBlueOff();
        }
    }
}

int main(void) {
    BSP_init();
    QF_init();

    /* initialize the SW1 semaphore as binary*/
    QXSemaphore_init(&SW1_sema, /* pointer to semaphore to initialize */
                     0U,  /* initial semaphore count */
                     1U); /* maximum semaphore count */

    /* initializing and start blinky1 thread */
    QXThread_ctor(&blinky1, &main_blinky1, 0);
    QXTHREAD_START(&blinky1,
                   5U, /* priority */
                   (void *)0, 0, //message queue (not used here)
                   stack_blinky1, sizeof(stack_blinky1),
                   (void *)0); //extra parameter (not used)

    /* initializing and start blinky1 thread */
    QXThread_ctor(&blinky2, &main_blinky2, 0);
    QXTHREAD_START(&blinky2,
                   2U, /* priority */
                   (void *)0, 0, //message queue (not used here)
                   stack_blinky2, sizeof(stack_blinky2),
                   (void *)0); //extra parameter (not used)

    /*transfer control to RTOS to run the threads */
    return QF_run();
}

