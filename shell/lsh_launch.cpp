#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>


int lsh_launch(char **args) {
    pid_t pid,wpid;
    int status;

    pid = fork();

    if(pid == 0) {
        if(execvp(args[0],args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if(pid < 0) {
        // Error Forking
         perror("lsh");
    } else {
        do {
            wpid = waitpid(pid,&status,WUNTRACED);
        } while (!WIFEXITED(status) && !WIFCONTINUED(status));
        
    }
    return 1;
}