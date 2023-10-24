#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27

main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

   
    key = 5678;

    
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    
    s = shm;
    *s='#';
    *(s+1)='(';
    putchar(*s);
    
    while (1){
        
        if((*s!='#' && *s!='$' && *s!='%' ) && *(s+1)==')' ){
            
           putchar(*s);
           *(s+1)='('; 
        }
        sleep(2);
    }
        

   
}