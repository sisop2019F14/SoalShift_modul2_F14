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

int main() {
   
    if((chdir("/home/anwar/praktikum_2/no3/"))<0) {
        exit(EXIT_FAILURE);
    }

    pid_t pid1,pid2,pid3;
    int delayPriorityOne;
    int fd[4];
    char fileTxt[10000];

    pid1 = fork();

    if(pid1>0){

        while(wait(&delayPriorityOne)>0);

        pipe(fd);
        pipe(fd+2);
        pid2 = fork();

        if(pid2 == 0){
           // printf("Two\n");

            close(fd[2]);
            close(fd[3]);
            close(fd[0]);
            
            dup2(fd[1],STDOUT_FILENO);
            close(fd[1]);   
            execlp("ls","ls","campur2",NULL);

        }else{
            int delayPriorityTwo;
            while(wait(&delayPriorityTwo)>0);
            //wait(NULL);
            
            pid3=fork();
            if(pid3 == 0){
               // printf("Three\n");

                close(fd[1]);
                dup2(fd[0],STDIN_FILENO);
                close(fd[0]);

                close(fd[2]);
                dup2(fd[3],STDOUT_FILENO);
                close(fd[3]);

                execlp("grep","grep",".txt$",NULL);

            }else{
                
                //int delayPriorityThree;
                //while(wait(&delayPriorityThree)>0);
                //printf("Four\n");
                close(fd[3]);
                close(fd[0]);
                close(fd[1]);
                int store = read(fd[2],fileTxt,sizeof(fileTxt));
                FILE *out;
                out = fopen("data.txt","w+");
                fputs(fileTxt,out);
                fclose(out);
                close(fd[2]);

            }

        }
        
        

    }else{
        //printf("One\n");
        //char *argv[3] = {"unzip", "campur2.zip", NULL};
        //execv("/usr/bin/unzip", argv);
        struct stat st = {0};
        if(stat("campur2",&st)!=0)
            execlp("unzip","unzip","campur2.zip", NULL);
        exit(1);


    }


}