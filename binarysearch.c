#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ARRAY_SIZE 16
#define maxt 4
int n = ARRAY_SIZE;
int m = maxt;

int array[] = {1,2,3,6,8,9,12,14,16,26,36,3,48,68,78,89};
int matched = 0;
int t_no = 0;

pthread_mutex_t t_no_Lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  t_no_cond = PTHREAD_COND_INITIALIZER;


pthread_mutex_t matched_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  matched_cond = PTHREAD_COND_INITIALIZER;
void* _bsearch(void* args){

    pthread_mutex_lock(&t_no_Lock);
    int t = t_no++;
    pthread_cond_signal(&t_no_cond);
    pthread_mutex_unlock(&t_no_Lock);
    int start = t*(n/m);
    int end = (t+1)*(n/m);
    int mid;
    int *k = (int*)args; 
    while(end>start && matched == 0){
        mid = (end-start)/2;
        mid+=start;
        if(array[mid]==*k){
            pthread_mutex_lock(&matched_lock);
            matched = 1;
            pthread_cond_signal(&matched_cond);
            pthread_mutex_unlock(&matched_lock);
            printf("found at position %d by thread_no: %d",mid,t);
            break;
        }
        else{
            if(array[mid]>*k){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

    }

}

int main(){
    pthread_t T[maxt];
    int count = maxt;
    int k;
    scanf("%d",&k);
    for (size_t i = 0; i < count; i++)
    {
        pthread_create(&T[i], NULL, _bsearch, &k);
    }
    for (size_t i = 0; i < count; i++)
    {
        pthread_join(T[i],NULL);
    }
    if(matched==0) printf("%d not found in the array by any of the threads",k);
    return 0;

}