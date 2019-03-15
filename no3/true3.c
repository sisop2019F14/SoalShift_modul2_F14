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

#define share 1
#define get 0

int main() {
   
    if((chdir("/home/anwar/praktikum_2/no3/"))<0) {
        exit(EXIT_FAILURE);
    }

    pid_t pid1,pid2,pid3;
    int delayPriorityOne;
    int fd1[2];
    int fd2[2];
    char fileTxt[10000];

    pid1 = fork();

    if(pid1>0){

        while(wait(&delayPriorityOne)>0);

        pipe(fd1);
        pipe(fd2);
        pid2 = fork();

        if(pid2 == 0){
           // printf("Two\n");

            dup2(fd1[share],STDOUT_FILENO);

            close(fd1[share]);
            close(fd1[get]);
            close(fd2[get]);
            close(fd2[share]);

            execlp("ls","ls","campur2",NULL);

        }else{
            int delayPriorityTwo;
            while(wait(&delayPriorityTwo)>0);
            //wait(NULL);
            
            pid3=fork();
            if(pid3 == 0){
               // printf("Three\n");
                dup2(fd1[get],STDIN_FILENO);
                dup2(fd2[share],STDOUT_FILENO);
                close(fd1[get]);
                close(fd1[share]);
                close(fd2[get]);
                close(fd2[share]);

                execlp("grep","grep",".txt$",NULL);

            }else{
                
                //int delayPriorityThree;
                //while(wait(&delayPriorityThree)>0);
                //printf("Four\n");
                close(fd1[get]);
                close(fd1[share]);
                close(fd2[share]);
                int store = read(fd2[get],fileTxt,sizeof(fileTxt));
                FILE *out;
                out = fopen("data.txt","w+");
                fputs(fileTxt,out);
                fclose(out);
                close(fd2[get]);

            }

        }
        
        

    }else{
        //printf("One\n");
        //char *argv[3] = {"unzip", "campur2.zip", NULL};
        //execv("/usr/bin/unzip", argv);
        struct stat st = {0};
        if(stat("campur2",&st)!=0){
            execlp("unzip","unzip","campur2.zip", NULL);
        }
        exit(1);


    }


}