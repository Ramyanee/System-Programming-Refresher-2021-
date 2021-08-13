#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main(){


    int x[100];
    printf("Please enter some some numbers. max 100. enter an 101 to stop entering\n");
    
    int count =0;
    while(1){
        
        scanf("%d",&x[count++]);
        if(x[count-1]==101)break;
        
    }
    
    count--;

    int pId1 = fork();

    if(pId1==-1){
        printf("fork failed");
        return 1;
    }
    else if(pId1==0){

        //even numbers
        int sum =0;
        for(int i =0;i<count;i++){
            if(x[i]%2==0) sum+=x[i];
        }
        printf("sum of even numbers: %d\n",sum);
        return 0;

    }

    int pId2 = fork();

    if(pId2==-1){
        printf("fork 2 failed");
        return 1;
    }
    else if(pId2==0){
        sleep(2);
        //odd numbers
        int sum =0;
        for(int i =0;i<count;i++){
            if(x[i]%2==1) sum+=x[i];
        }
        printf("sum of odd numbers: %d\n",sum);
        return 0;

    }
    waitpid(pId1,NULL,0);
    printf("count: %d\n",count);
    waitpid(pId2,NULL,0);


    return 0;
}