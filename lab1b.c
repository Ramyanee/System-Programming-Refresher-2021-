// 

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
    printf("parent process\n");
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",p1,p2,getpid());
    //parent
}
else if(p1==0 && p2>0){
    //sleep(1);
    waitpid(p2,NULL,0);
    //wait(NULL);
    //first child
    printf("first child process\n");
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",0,p2,getpid());
    return 0;

}

else if(p1>0 && p2==0){
    
    //second process
    printf("second child process\n");
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",p1,0,getpid());
    return 0;

}
else{
    // waitpid(p1,NULL,0);
    // waitpid(p2,NULL,0);
    //sleep(2);
    //third process
    wait(NULL);
    wait(NULL);
    printf("third child process\n");
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",0,0,getpid());
    return 0;

}





    return 0;
}