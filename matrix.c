#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ARRAY_SIZE 4
#define maxt 4
int n = ARRAY_SIZE;
int m = maxt;

int a[4][4] = {{3,7,3,6},{9,2,0,3},{0,2,1,7},{2,2,7,9}};
int b[4][4] = {{6,5,5,2},{1,7,9,6},{6,6,8,9},{0,3,5,2}};
int c[4][4];
int matched = 0;
int t_no = 0;

pthread_mutex_t t_no_Lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  t_no_cond = PTHREAD_COND_INITIALIZER;

void* _bsearch(void* args){

    pthread_mutex_lock(&t_no_Lock);
    int t = t_no++;
    pthread_cond_signal(&t_no_cond);
    pthread_mutex_unlock(&t_no_Lock);
    
    int start = t*ARRAY_SIZE/4;
    int lim = (t+1)*ARRAY_SIZE/4;

    for (size_t i = start; i < lim; i++)
    {
        for (size_t j = 0; j < ARRAY_SIZE; j++)
        {
            for (size_t k = 0; k < ARRAY_SIZE; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

int main(){
    pthread_t T[maxt];
    int count = maxt;
    for (size_t i = 0; i < count; i++)
    {
        pthread_create(&T[i], NULL, _bsearch, NULL);
    }
    for (size_t i = 0; i < count; i++)
    {
        pthread_join(T[i],NULL);
    }
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        for (size_t j = 0; j < ARRAY_SIZE; j++)
        {
            printf("%d  ",c[i][j]);
        }
        printf("\n");
    }
    
    return 0;

}