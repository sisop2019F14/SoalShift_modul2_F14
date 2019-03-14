#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>

int main(){
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

    if ((chdir("/home/anwar/praktikum_2/no4")) < 0) {
      exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int accessCount=1;
    while(1){

        time_t nowTime;
        time(&nowTime);
        struct stat makanFile = {0};
        if(stat("/home/anwar/documents/makanan/makan_enak.txt",&makanFile) < 0){
            perror("makan_sehat.txt not found!!");
            return 0;
        }
        double diff = difftime(nowTime,makanFile.st_atime);
        char saveDir[1000] = "/home/anwar/documents/makanan/makanan_sehat";
        char nameFile[10000];
        //snprintf(saveDir)
        char accessCountInString[10000];
        
        if(diff <= 30){
            FILE *reminderFile;
            snprintf(accessCountInString, 10000,"%d.txt",accessCount);

            strcpy(nameFile,saveDir);
            strcat(nameFile,accessCountInString);
            reminderFile = fopen(nameFile,"w+");
            fclose(reminderFile);
            
            accessCount++;
        }

        sleep(5);
    }
    exit(EXIT_SUCCESS);
}