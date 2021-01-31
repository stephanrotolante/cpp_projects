#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include "lsh_launch.h"

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};


int lsh_num_builtins() {
    return sizeof(builtin_str)/ sizeof(char *);
}

int lsh_cd(char **args) {
    if(args[1] == NULL) {
        std::cerr << "lsh: expected argument to \"cd\"\n";
    } else {
        if(chdir(args[1]) != 0){
            perror("lsh");
        } 
        
    }
    return 1;
}

int lsh_help(char **args ) {
    int i;
    std::cout << "Stephan Rotolante's LSH\n";
    std::cout << "Type program names and arguments, and hit enter.\n";
    std::cout << "The following are built in:\n";

    for(i = 0; i < lsh_num_builtins(); i++) {
        std::cout << builtin_str[i] << "\n";
    }

    std::cout << "Use th man command for informantion on other programs.\n";
    return 1;
}

int lsh_exit(char **args) {
    return 0;
}


int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit
};



int lsh_execute(char **args) {
    int i;
    
    if(args[0] == NULL) {
        return 1;
    }

    for(i =0; i < lsh_num_builtins(); i++){
        if(strcmp(args[0],builtin_str[i])== 0){
            return (*builtin_func[i])(args);
        }
    }

    return lsh_launch(args);
}
