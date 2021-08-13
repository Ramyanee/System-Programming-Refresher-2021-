#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/wait.h>


int main(){
    if(fork()==0){
        
        execl("/bin/ps","/bin/ps","-e","-d",NULL);
    }
    wait(NULL);
    return 0;

}