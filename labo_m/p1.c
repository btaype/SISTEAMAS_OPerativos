#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27

main()
{
    char c;
    int shmid, con=0;
    key_t key;
    char *shm, *s;
    char aux[30];

    for(int i=0;i<30;i++) aux[i]='\0';

    key = 5678;

    
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    
    *shm='#';
    *(shm+1)='(';
    
    while (1){
        
        if((*shm!='#' && *shm!='$' && *shm!='%' ) && *(shm+1)==')' ){
            //printf("ok\n");
            //strcpy(aux,shm);
            aux[con]=*shm;

            if(con<30)
                con++;
            else
                con=0;

           for(int i=0;i<30;i++) printf("%s",&aux[i]);
           printf("\n");
           //putchar(*shm);
           *(shm+1)='('; 
        }
        sleep(2);
    }
        

   
}