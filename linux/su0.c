#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include <unistd.h>
#include <time.h>


static int permissionDenied()
{
    // the superuser activity couldn't be started
    printf("su: permission denied\n");
    return 1;
}

static int executionFailure(char *context)
{
    fprintf(stderr, "su: %s. Error:%s\n", context, strerror(errno));
    return -errno;
}

int main(int argc, char **argv)
{
    int uid = 0;
    int gid = 0;

    if(setgid(gid) || setuid(uid)) 
        return permissionDenied();

    printf("setuid success!");
    
    char *exec_args[argc + 1];
    exec_args[argc] = NULL;
    exec_args[0] = "sh";
    int i;
    for (i = 1; i < argc; i++)
    {
            exec_args[i] = argv[i];
    }
    execv("/system/bin/sh", exec_args);
    return executionFailure("sh");
}