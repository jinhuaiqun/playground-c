/*
 *  compile with -O2 option, will in dead loop.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int run = 1;

void* foo(void* data) {
    while (run) ;
}

void* bar(void* data) {
    sleep(1);
    run = 0;
}

void test1() {
    printf("test1 ready\n");

    pthread_t pt[2];
    pthread_create(&pt[0], NULL, foo, NULL);
    pthread_create(&pt[1], NULL, bar, NULL);

    pthread_join(pt[0], NULL);
    pthread_join(pt[1], NULL);

    printf("test1 done\n");
}

int main() {

    test1();
}
