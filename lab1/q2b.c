#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/wait.h>


int main(){
    if(fork()==0){

        char * e[] = {"X=xc",NULL};
        putenv("X=xc");
        
        execle("/bin/ps","/bin/ps","-e","-d",NULL,e);
    }
    wait(NULL);
    return 0;

}