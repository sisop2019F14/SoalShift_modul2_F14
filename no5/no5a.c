#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>


int main() {
    pid_t pid, sid;

    pid = fork();

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();

    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/home/anwar/log")) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1) {

        time_t rawtime;
        struct tm * timeinfo;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char time[20];
        strftime(time,20,"%d:%m:%Y-%R",timeinfo);

        int i=0;

        //make directory
        mkdir(time,S_IRWXU | S_IRWXO | S_IRWXG);
    
        FILE *fileSyslog;
        char syslogDir[]="/var/log/syslog";
        fileSyslog = fopen(syslogDir,"r");

        for(i=1; i<=30; i++){
            
            char newFilename[30];
            //get new file name
            snprintf(newFilename,30,"%s/log%d.log",time,i);

            //open that file has been created
            FILE *newFileLog = fopen(newFilename,"w");
            char charHelper;
            while ((charHelper = fgetc(fileSyslog)) != EOF){
                fputc(charHelper,newFileLog);
            }

            fclose(newFileLog);
            sleep(60);
        }

        fclose(fileSyslog);
               
    }
    
    exit(EXIT_SUCCESS);
}