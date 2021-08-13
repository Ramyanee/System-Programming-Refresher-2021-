#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int n1=6;
int n2=16;
int a[]={1,3,5,19,23,20};
int b[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int t_no = 0;
#define maxT 8

//please use a maxT value such that 
//(n2/maxT)*maxT is not smaller than
//the largest index for array b, that is n2-1
//otherwise there can be coverage issues


// mutexes

pthread_mutex_t t_no_Lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  t_no_cond = PTHREAD_COND_INITIALIZER;
int X = 0;

/////////////

void* searchPartitionInThread(void * arg){
    //using mutexes to update t_no 
    //because it is a global variable
    pthread_mutex_lock(&t_no_Lock);
    int t = t_no++;
    pthread_cond_signal(&t_no_cond);
    pthread_mutex_unlock(&t_no_Lock);

    
    
    //partitioning the bigger array 
    //depending on the thread number 
    //so that each of the four threads 
    //receives one fourth of the array
    int* k = (int*)arg;
    int start = t*(n2/maxT);
    int end = (t+1)*(n2/maxT);
    //printf("start %d end %d\n",start,end);
    for(int i = start; i< end; i++){

        if(b[i]==*k) {
            
            printf("%d\n",*k);}

    }
    pthread_cond_signal(&t_no_cond);
    pthread_mutex_unlock(&t_no_Lock);
    
}


int main(){
    pthread_t T[maxT];

    //each element of the small array is
    //sent to four threads to be searched in four parts
    //of the bigger array
    for (int i = 0; i < 6; i++){
        
        t_no = 0;
        
        int k = a[i];
        for(int j = 0; j < maxT; j++){
            pthread_create(&T[j], NULL, searchPartitionInThread, &k);
            
        }
        for(int j = 0; j < maxT; j++){
            pthread_join(T[j],NULL);
        }
    }
    
    return 0;
}