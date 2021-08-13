#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int p1 = fork();
    int p2 = fork();
    if(p1==0 && p2==1){
        int p3=fork();
        
    }
    if(p2==0 && p1==1){
            fork();
        }
    fork();
    printf("End ");

    wait(NULL);
    wait(NULL);

    return 0;
}
