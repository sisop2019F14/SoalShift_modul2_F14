#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

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

  if ((chdir("/home/anwar/praktikum_2/no1")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

    DIR *dir;
    struct dirent *ent;
    char *fileName,*ext;
    int ret;
    char nameRule[10] = "_grey.png";
    char originalName[1000];
    char newName[1000];
    char imageSrc[1000] = "/home/anwar/praktikum_2/no1/";
    char dest[1000] = "/home/anwar/modul2/gambar/";

  while(1) {
    // main program here

         //cara cerdas
    //char *argv[3] = {"bash","changeName.sh", NULL};
    //execv("/bin/bash", argv);

    if ((dir = opendir ("/home/anwar/praktikum_2/no1/")) != NULL) {
 
        while ((ent = readdir (dir)) != NULL) {
        
            strcpy(originalName, imageSrc); 
            strcat(originalName,ent->d_name);   
            fileName=strtok(ent->d_name,".");
            ext=strtok(NULL,".");

            if(ext!=NULL)
            {
                ret=strcmp(ext,"png");
                if(ret==0)
                {
                    strcpy(newName,dest);
                    strcat(fileName,nameRule);
                    strcat(newName,fileName);
                    rename(originalName,newName);
                    //strcat(fileName,nameRule);
                    //printf("%s\n",fileName);
                    //char *argv[4] = {"mv", originalName, fileName, NULL};
                    //execv("/bin/mv", argv);
                }
            }
        
        }
        closedir (dir);
    } 

    sleep(30);
  }
  
  exit(EXIT_SUCCESS);
}