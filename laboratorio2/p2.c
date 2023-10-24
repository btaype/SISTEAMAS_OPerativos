#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid;
  
  
  while (1) {
  const char *fifoNombre1 = "/tmp/fifo1";
  const char *fifoNombre2 = "/tmp/fifo2";
  int pipe_fd[2];
  int pipe_fd_resp[2];
  pipe(pipe_fd);
  pipe(pipe_fd_resp);
  
  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }
  if (pid > 0) {

    int n = 0;
    int resultado;
    int fd1, fd2;

    fd1 = open(fifoNombre1, O_RDONLY);
    read(fd1, &resultado, sizeof(resultado));
    close(fd1);

    n = resultado + 7;
    printf("padre (PID %d): recibido: %d, enviado: %d\n", getpid(), resultado, n);

    close(pipe_fd[0]);
    close(pipe_fd_resp[1]);
    write(pipe_fd[1], &n, sizeof(n));

            
    wait(NULL);

            
    int respuesta_hijo;
    read(pipe_fd_resp[0], &respuesta_hijo, sizeof(respuesta_hijo));
    printf("padre (PID %d): respuesta del hijo: %d\n", getpid(), respuesta_hijo);

    close(pipe_fd[1]);
    close(pipe_fd_resp[0]);

    fd2 = open(fifoNombre2, O_WRONLY);
    write(fd2, &respuesta_hijo, sizeof(respuesta_hijo));
    close(fd2);

    printf("padre (PID %d): recibido: %d, enviado: %d\n\n", getpid(), n, respuesta_hijo);

} else if (pid == 0) {
    int n2;
    close(pipe_fd[1]);
    close(pipe_fd_resp[0]); 
    read(pipe_fd[0], &n2, sizeof(n2));
    int resultado2 = n2 * 3;
    
    write(pipe_fd_resp[1], &resultado2, sizeof(resultado2));

    close(pipe_fd[0]);
    close(pipe_fd_resp[1]); // 
    printf("hijo(recibido:%d,enviado:%d)\n", n2, resultado2);
      
    exit(0);
  }
  }
  return 0;
}