#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 80
#define MAX_ARGS 20
#define DELIMS " \t\r\n"

int main() {

    int i, status;
    char cmd[MAX_LENGTH];    // string containing user's input
    char *argv[MAX_ARGS];    // array of pointers to char arrays

    while(1){
        printf("Enter a command: ");
        fgets(cmd, MAX_LENGTH, stdin);    // show prompt

        if (strcmp(cmd, "quit\n") == 0)    
            exit(0);

        i = 0;        // build array of arguments
        argv[i] = strtok(cmd, DELIMS);
        while (argv[i] != NULL)
        {
            argv[++i] = strtok (NULL, DELIMS);
        }


        int pid = fork();

        if (pid == 0)       
        {
            execvp(*argv, argv);
            printf("exec failed.\n");
            exit(1);
        }
        else if (pid < 0)  
        {
            printf("Error\n");
            exit(1);
        }
        else              
        {
            wait(&status);
                    printf("Child exited\n");
        }

    }

    return 0;
}


