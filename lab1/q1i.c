

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
    wait(NULL);
    wait(NULL);
    printf("parent process\n");
    printf("child 1 id: %d   child 2 id: %d\nmy id: %d\n",p1,p2,getpid());
}
else if(p1==0 && p2>0){
    wait(NULL);
    printf("first child process\n");
    printf("%d   child 2 id: %d\nmy id: %d\n",0,p2,getpid());
    return 0;

}

else if(p1>0 && p2==0){
    usleep(100);
    printf("second child process\n");
    printf("child 1 id: %d   %d\nmy id: %d\n",p1,0,getpid());
    return 0;

}
else{
    printf("third child process\n");
    printf("%d   %d\nmy id: %d\n",0,0,getpid());
    return 0;

}
    return 0;
}

//OBSERVATIONS
//second and third child always tends to get intertwined 
//as they do not have any children