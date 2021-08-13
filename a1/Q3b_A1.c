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
        //fork returns -1 to parent if failure occurs
        printf("fork failed");
        return 1;
    }
    else if(pId1==0){
        //fork returns 0 to child if fork sucess
        //this is our first child which will calculate the sum of
        //even numbers
        //This child will fork to give another child
        int pId2 = fork();

        if(pId2==-1){
            printf("fork 2 failed");
            return 1;
        }
        else if(pId2==0){
            //This is our second child, forked from the first child
            //this is done so that there are three processes in total and not four
            //This is a grand child to the parent process
            //This will calculate the sum of
            //odd numbers
            int sum =0;
            for(int i =0;i<count;i++){
                if(x[i]%2==1) sum+=x[i];
            }
            printf("sum of odd numbers: %d\n",sum);
            return 0;

        }
        // This is child 1, waiting for the grandchild to print the sum of odd numbers
        wait(NULL);
        int sum =0;
        for(int i =0;i<count;i++){
            if(x[i]%2==0) sum+=x[i];
        }
        printf("sum of even numbers: %d\n",sum);
        return 0;

    }
    else{
        //This is the parent process waiting for child 1 to print the sum of even numbers
        wait(NULL);
        printf("count: %d\n",count);
    }
    return 0;
}