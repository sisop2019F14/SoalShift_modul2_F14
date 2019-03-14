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
#include <pwd.h>
#include <grp.h>
#include <pwd.h>


int main()
{
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

    if ((chdir("/home/anwar/praktikum_2/no2/hatiku/")) < 0) {
      exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    char fileName[1000];
    DIR *dir;
    struct dirent *ent;

    while(1) {
      
        if ((dir = opendir ("/home/anwar/praktikum_2/no2/hatiku/")) != NULL) {
    
            while ((ent = readdir (dir)) != NULL) {
                
                strcpy(fileName, ent->d_name);    
                int dif = strcmp(fileName,"elen.ku");

                if(dif==0){
                    struct stat st={0};
                    struct passwd *owner = getpwuid(st.st_uid);
                    struct group *group = getgrgid(st.st_gid);
                    //printf("%s %s\n",owner->pw_name,group->gr_name);
                        /*if(chmod(fileName,S_IRWXU|S_IRWXG|S_IRWXO)<0){
                            perror("Change Mode Failed");
                            //exit(EXIT_SUCCESS);
                        }
                        remove(fileName);*/

                    if(strcmp(owner->pw_name,"www-data")==0 && strcmp(group->gr_name,"www-data")==0){
                        //change mode
                        //char chmod[] = "0777"
                        printf("%s %s\n",owner->pw_name,group->gr_name);
                        if(chmod(fileName,S_IRWXU|S_IRWXG|S_IRWXO)<0){
                            perror("Change Mode Failed");
                            //exit(EXIT_SUCCESS);
                        }
                        remove(fileName);
                    }
                }   
            }
                closedir (dir);
        }  

        sleep(3);
    }

    exit(EXIT_SUCCESS); 
}