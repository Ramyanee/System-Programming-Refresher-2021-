#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main(){


    int x[100];
    printf("Please enter some numbers(not more than 100 numbers).\nEnter 'x' along with the number to stop entering\n");
    char delim;
    int count =0;
    while(1){
        
        scanf("%d%c",&x[count++],&delim);
        if(delim=='x')break;
        
    }
    
    count;

    int pId1 = fork();

    if(pId1==-1){
        printf("fork failed");
        return 1;
    }
    else if(pId1==0){
        
        //even numbers
        // Child one which will print the sum of even numbers
        int sum =0;
        for(int i =0;i<count;i++){
            if(x[i]%2==0) sum+=x[i];
        }
        printf("sum of even numbers: %d\n",sum);
        return 0;

    }
    else{
        //waiting for termination of child 1 before creating a new child
        waitpid(pId1,NULL,0);

        //prints count before creating child2
        printf("count: %d\n",count);
        //new child (child2) to calculate sum of odd numbers
        int pId2 = fork();

        if(pId2==-1){
            printf("fork 2 failed");
            return 1;
        }
        else if(pId2==0){
            
            //odd numbers
            int sum =0;
            for(int i =0;i<count;i++){
                if(x[i]%2==1) sum+=x[i];
            }
            printf("sum of odd numbers: %d\n",sum);
            return 0;

        }



    }
    //waiting for termination of child 2 before terminating itself
    wait(NULL);
    
    


    return 0;
}