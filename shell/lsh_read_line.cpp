#include <cstdlib>
#include <iostream>


// **** OLD Version
#define LSH_RL_BUFSIZE 1024

char *lsh_read_line(void) {
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    int c;


    // Cast to pointer of character
    char *buffer = (char *)malloc(sizeof(char)* bufsize);

    if(!buffer) {  
        std::cerr << "lsh: allocation error\n";
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar();

        if(c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }

        position++;
    

        /*
        Buffer is too small, we need to re allocate
        */
        if(position >= bufsize) {
            bufsize += LSH_RL_BUFSIZE;

            buffer = (char *) realloc(buffer,bufsize);

            if(!buffer){
                std::cerr << "lsh: allocation error\n";
                exit(EXIT_FAILURE);
            }

        }
    }
}

