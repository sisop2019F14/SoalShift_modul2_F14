#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>
#include <stdbool.h>

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

    bool startTime = false;
    int i=1;
    double diff = 0;
    while(1) {
        //printf("tes\n");
        time_t rawtime;
        time_t nowTime;
        struct tm * timeinfo;
        //printf("tes1\n");
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char newDir[20];
        //printf("tes2\n");
        if(diff>=1800){
           
            i=1;
            startTime = false;
            //printf("lebih dari\n");
        }
        //printf("tes3\n");
        if (startTime == false){
            //printf("make dir\n");
            nowTime = rawtime;
            startTime = true;
            strftime(newDir,20,"%d:%m:%Y-%R",timeinfo);
            mkdir(newDir,S_IRWXU | S_IRWXO | S_IRWXG);
            
        }
        diff = difftime(rawtime,nowTime);
        //printf("%lf\n",diff);

        //make directory
        
        FILE *fileSyslog;
        char syslogDir[]="/var/log/syslog";
        
        if(diff < 1800){
            
            fileSyslog = fopen(syslogDir,"r");
            char newFilename[30];
            //get new file name
            snprintf(newFilename,30,"%s/log%d.log",newDir,i);

            //open that file has been created
            FILE *newFileLog = fopen(newFilename,"w");
            char charHelper;
            while ((charHelper = fgetc(fileSyslog)) != EOF){
                fputc(charHelper,newFileLog);
            }
            i++;
            fclose(newFileLog);
            fclose(fileSyslog);
            printf("buat file log\n");
            sleep(60);
        }

        

        /*for(i=1; i<=30; i++){
            
            fileSyslog = fopen(syslogDir,"r");
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
            fclose(fileSyslog);
            sleep(60);
        }*/



    }
    
    exit(EXIT_SUCCESS);
}