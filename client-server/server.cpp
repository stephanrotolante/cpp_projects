#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

#define BUF_SIZE 1024
int main() {


struct sockaddr_in address;

// const int PORT = 8080;


// initalizing to zero
// memset((char *)&address, 0, sizeof(address)); 
// address.sin_family = AF_INET;
// address.sin_addr.s_addr = htonl(INADDR_ANY); 
// address.sin_port = htons(PORT);



// int server_fd { 0};
// int valread  {0};

// int c;
// int position {0};

// int new_socket { 0 };


// char buffer[BUF_SIZE] = {0};
size_t bufsize = {BUF_SIZE};

char *inputBuffer = (char *)malloc(sizeof(char *)* bufsize);

// int addrlen = sizeof(address);
    
// if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
// {
//     std::cout << "cannot create socket";


//     exit(EXIT_FAILURE); 

  
// }

// if (bind(server_fd,(struct sockaddr *)&address,sizeof(address)) < 0) 
// { 
//      std::cout << "bind failed";

//     exit(EXIT_FAILURE); 
// }

// if (listen(server_fd, 3) < 0) 
// { 

//     std::cout << "In listen";
//     exit(EXIT_FAILURE); 
// }

// if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
// {
//     std::cout << "In accept";          
//     exit(EXIT_FAILURE);        
// }





while (true) {
    // valread =  read( new_socket , buffer, 1024); 

    // if(valread > 0)
    // { 
    //      std::cout << buffer;
    // } 



    // c = getchar();

    getline(&inputBuffer,&bufsize,std::cin);


    if(c == EOF || c == '\n') {
        inputBuffer[position] = '\0';
         std::cout << " " << inputBuffer << std::flush;
        write(new_socket , inputBuffer , strlen(inputBuffer));
        memset((char *)&inputBuffer, 0, sizeof(sizeof(char) * position)); 
        position = 0;
   
    } else {
        inputBuffer[position] = c;
    }

    position++;


    /*
    Buffer is too small, we need to re allocate
    */
    if(position >= bufsize) {
        bufsize += BUF_SIZE;

        inputBuffer = (char *) realloc(inputBuffer,bufsize);

        if(!inputBuffer){
            std::cerr << "lsh: allocation error\n";
            exit(EXIT_FAILURE);
        }

    }
    

}


// if(valread < 0)
// { 
//     printf("No bytes are there to read");
// } else {
//     std::cout << buffer;
// }
// char *hello = "Hello from the server"; //IMPORTANT! WE WILL GET TO IT
// write(new_socket , hello , strlen(hello));


    return 0;
}