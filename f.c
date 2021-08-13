#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


// typedef struct arguments{
//     pthread_t t;
//     int threadNo;
//     int w;
// }ar;

int a1[] = {1,2,3,4,5,6};
int a2[] = {2,3,4,5};


void* helperThreadFunction(void * arg){

    printf("inside the thread with thread id: %lu \n",pthread_self());
    int *x = (int *)arg;
    for(int i=0;i<4;i++){
        
        if(a2[i]==*x)printf("%d\n",a2[i]);
    }
    //pthread_cancel(pthread_self());
    pthread_exit(NULL);
    
    return NULL;
}



int main(){
pthread_t nt[6];
    // ar * a;

for(int i = 0;i<6;i++){
    int x = a1[i];
    
    pthread_create(&nt[i],NULL,helperThreadFunction,&x);
    
    pthread_join(nt[i],NULL);
}

for(int i = 0;i<6;i++){
    pthread_join(nt[i],NULL);
}

    return 0;
}