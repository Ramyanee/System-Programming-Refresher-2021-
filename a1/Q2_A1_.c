#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define maxT 4

//global variables which will only be read and not modified
int n1=9;
int n2=16;
int a[9]={7,19,1,3,5,9,13,66,8};
int b[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

//global variable which will be modified
int t_no = 0;


// mutexes

pthread_mutex_t t_no_Lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  t_no_cond = PTHREAD_COND_INITIALIZER;
int X = 0;

/////////////

void* searchPartitionInThread(void * arg){
    //using mutexes to update t_no 
    //because it is a global variable
    pthread_mutex_lock(&t_no_Lock);
    t_no++;
    pthread_cond_signal(&t_no_cond);
    pthread_mutex_unlock(&t_no_Lock);
    int t1,t2;
    //selecting partition of each array depending
    //on the thread number
    if(t_no==0){
        t1=0;
        t2=0;
    }
    else if(t_no==1){
        t1=1;
        t2=0;
    }
    else if(t_no==2){
        t1=0;
        t2=1;
    }
    else if(t_no==3){
        t1=1;
        t2=1;
    }

    //setting start and end indexes for both the arrays
    int start1 = t1*(n1/2);
    int end1 = (t1+1)*(n1/2);
    if((n1%2)==1 && t1==1)end1++;

    int start2 = t2*(n2/2);
    int end2 = (t2+1)*(n2/2);
    if((n2%2)==1 && t2==1)end2++;

    for(int i = start1; i< end1; i++){

        for(int j = start2; j< end2; j++)
        if(a[i]==b[j]) {
            
            printf("%d\n",a[i]);}

    }
    pthread_cond_signal(&t_no_cond);
    pthread_mutex_unlock(&t_no_Lock);
    
}


int main(){
    pthread_t T[maxT+1];
        //creating the four threads
        for(int i = 0; i < 4; i++)
            pthread_create(&T[i], NULL, searchPartitionInThread, NULL);
        //joining the four threads after they are done
        for(int j = 0; j < 4; j++)
            pthread_join(T[j],NULL);
    return 0;
}