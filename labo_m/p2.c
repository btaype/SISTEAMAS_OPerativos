
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27

main()
{
    int shmid;
    key_t key;
    char *shm, *s;

  
    key = 5678;

    
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

   
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s=shm;
    printf("dedo");
    char f='1';
    while(1){
        if (*s=='#'){
            
            *s=f;
            *(s+1)=')';
            sleep(2);
            f=f+2;
            *s='$';
        }

    }
}