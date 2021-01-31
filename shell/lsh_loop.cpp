#include <iostream>
#include "lsh_read_line.h"
#include "lsh_split_line.h"
#include "helper.h"

void lsh_loop() {
    char *line;
    char **args;
    int status { 0 };

    do {
        std::cout << "> ";
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);

    } while (status);
    
}