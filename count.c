#include <stdio.h>
#include <pthread.h>

#define N_LOOPS 1000000

long long sum = 0;

void * counting_function(void *arg) {
    int offset = *(int *) arg;
    
    for (int i = 0; i < N_LOOPS; i++) {
        sum += offset;
    }
    pthread_exit(NULL);
}

int main(void) {
    pthread_t id1;
    int offset1 = 1;
    pthread_create(&id1, NULL, counting_function, &offset1);
    pthread_join(id1, NULL);
    
    pthread_t id2;
    int offset2 = 1;
    pthread_create(&id2, NULL, counting_function, &offset2);
    pthread_join(id2, NULL);
    
    printf("Sum = %llu\n", sum);

    return 0;
}
