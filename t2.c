#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* myturn(void * arg){
    int *x = (int *)arg;
    static int d = 6;
    int i;
    for(i = 0;i<5;i++){
        sleep(1);
        printf("thread 1  %d %d d %d \n ",i,*x,d++);
        
    }
}


void* yourturn(void * arg){
    int *x = (int *)arg;
    static int d;
    int i;
    for(i = 0;i<5;i++){
        sleep(1);
        printf("thread 2  %d %d d %d \n ",i,*x,d++);
        
    }
}



int main(){
    
    pthread_t nt,nt2;
    int v = 100;
    pthread_create(&nt,NULL,myturn,&v);
    pthread_create(&nt2,NULL,yourturn,&v);
    pthread_join(nt,NULL);
    pthread_join(nt2,NULL);
    //for(int i =0;i<8;i++)printf("*%d*",y[i]);
    return 0;
}