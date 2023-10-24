#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>
int  nt=0;
bool ver=false;

void activar (int signum){
    nt=nt+1;
    }

int main() {
    srand(time(NULL));
    const char *fifoNombre1 = "/tmp/fifo1";
    const char *fifoNombre2 = "/tmp/fifo2";
    
    int resultado;
    int fd1, fd2;

    pid_t pid = getpid();
    printf("id: %d\n", pid);
    signal(SIGUSR1, activar);

    while(1){
        
        if (nt>0){
             printf("i: %d\n", nt);
            int n = (rand() % (50)) ;
            mkfifo(fifoNombre1, 0666);
            mkfifo(fifoNombre2, 0666);

            fd1 = open(fifoNombre1, O_WRONLY);
            write(fd1, &n, sizeof(n));
            close(fd1);

            fd2 = open(fifoNombre2, O_RDONLY);
            read(fd2, &resultado, sizeof(resultado));
            close(fd2);

            printf("Número enviado: %d, Número obtenido: %d\n", n, resultado);
            
          

            nt=nt-1;
            
        }
    }

    return 0;
}