#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define SIZE 32

int main(int argc, char* argv[])
{
    
    pid_t pid;
    char** arguments = (char **) malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
      arguments[i] = (char * ) malloc(10 * sizeof(char));
      arguments[i] = NULL;
    }



    while(1){
        printf("Command: ");

        char* cmd = malloc(SIZE * sizeof(char));
        fgets(cmd,MAX,stdin);

        if(strcmp(cmd,"quit\n")==0){
            break;
        }else{
            
           // for(int i=0; i < argc; i++) {
           //   printf("%s ", argv[i]);
           // }

            char* token = strtok(cmd, " ");
            arguments[0] = *token;
            
            int counter = 1; 
            while(token != NULL)
            {
               // printf("%s ", token);
               token = strtok(NULL, " ");
               arguments[counter] = *token;
               counter += 1;
            }           
            pid = fork();
            if (pid < 0) {
              perror("fork failure");
              exit(1);
            } else if (pid == 0) {
              execvp(arguments[0], &arguments[0]);
              exit(1);
            }           
            free(token);
        }
        free(cmd);
    }
    return 0;
}
