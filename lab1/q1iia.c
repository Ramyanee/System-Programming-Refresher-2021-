
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void f(int p1,int p2){
    
}

int main(){

int p1,p2;


p1 = fork();
p2 = fork();
int pp = getpid();

if(p1>0 && p2 >0){
    waitpid(p2,NULL,0);
    printf("\nparent process\n");
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",p1,p2,getpid());
}
else if(p1==0 && p2>0){
    //wait(NULL);
    usleep(500);
    printf("\nfirst child process\n");
    printf("%d   grandchild 2 id: %d\nmy id: %d\n",0,p2,getpid());
    wait(NULL);
    return 0;

}

else if(p1>0 && p2==0){
    printf("\nsecond child process\n");
    printf("child 1 id: %d   %d\nmy id: %d\n",p1,0,getpid());
    return 0;

}
else{
    usleep(1000);
    printf("\nthird child process\n");
    printf("%d   %d\nmy id: %d\n",0,0,getpid());
    return 0;

}
wait(NULL);

    return 0;
}


/* OBSERVATIONS
A parent can wait for a child 
but a child has no access to the 
statuses of a parent process hence 
cannot wait for a parent.*/