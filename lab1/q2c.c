#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/wait.h>


int main(){
    if(fork()==0){
        char *a[] = {"-a","-e",NULL};
        execv("/bin/ps",a);
    }
    wait(NULL);
    return 0;

}