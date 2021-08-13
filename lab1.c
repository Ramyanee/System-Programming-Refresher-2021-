#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void f(int p1,int p2){
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",p1,p2,getpid());
}


int main(){
    int p1,p2,p3;
    p1 = fork();

    if(p1==0){
        p3 = fork();

        if(p3==0){
        f(0,0);
        printf("Third child\n");}
        else{
        waitpid(p3,NULL,0);
        printf("First child\n");
        f(0,p3);}
    }
    else{
    p2 = fork();
     if(p2==0){

         printf("Second child\n");
        
        f(p1,0);
    }
    else{
    waitpid(p1,NULL,0);
    waitpid(p2,NULL,0);
    printf("Parent Process\n");
    
    f(p1,p2);}
    return 0;
}
}