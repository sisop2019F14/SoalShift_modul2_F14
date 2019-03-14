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
#include <stdio.h>
#include <time.h>

int main ()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char time[20];
    strftime(time,20,"%d:%m:%Y-%R",timeinfo);

    mkdir(time,S_IRWXU | S_IRWXO | S_IRWXG);

    // now we have time

    

    

  return 0;
}

