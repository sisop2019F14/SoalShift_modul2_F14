#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

int main(){
    char pidModified[10]={0};
    //get pid file
    FILE *getCmd = popen("pidof /home/anwar/log/no5a", "r");

    //grab output in string
    fgets(pidModified, 10, getCmd);
    //printf("%s\n",out);

    //convert it to unsigned int
    pid_t pid = strtoul(pidModified, NULL, 10);
    
    //close pipe
    pclose(getCmd);
    //printf("PID: %d\n", pid);
    if(!kill(pid, SIGKILL)){
        printf("PID : %d has been killed\n", pid);
    }

    return(0);
}