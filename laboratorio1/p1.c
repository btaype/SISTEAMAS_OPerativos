
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int x = 66;
int x2=0;
int ID = 0;
union sigval val;

void funcion1(int signum) {
	printf("eeeeee");
    sigqueue(ID, SIGUSR1, val);
}
int main(int argc, char **argv) {
    
    val.sival_int = atoi(argv[2]);
    ID = atoi(argv[1]);
    printf("%d\n", val.sival_int);
    printf("%d\n", (int)ID);
    pid_t mi_id = getpid();
    printf("%d\n", (int)mi_id);
    signal(SIGINT, funcion1);
    
    
    for (;;) {
        pause();
    }

    return 0;
}

