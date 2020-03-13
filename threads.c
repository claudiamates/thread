#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
  #include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include "a2_helper.h"

sem_t sem1,sem2;
sem_t sem3,sem6,sem7,sem8;
sem_t *sem4;
sem_t *sem5;


void *thread_func(void *arg)
{
  int a = *(int*)arg;
/*sem4 = sem_open("a2_sem4",O_EXCL);
sem5 = sem_open("a2_sem5",O_EXCL);*/
  
  if(a==4)
  { //if 4 wait if 5 begin, notify 4, wait
  sem_wait(&sem1);
  info(BEGIN,4,a);
  info(END,4,a);
  sem_post(&sem2);
  }else if(a==5){
         info(BEGIN,4,a);
         sem_post(&sem1);
         sem_post(&sem1);
         sem_wait(&sem2);
         info(END,4,a);
         } else if(a==1){
                 sem_wait(sem4);
                 info(BEGIN,4,a); 
                 //sem_post(&sem5); 
                 info(END,4,a);
                 sem_post(sem5);
                sem_post(sem5);
                /* sem_post(&sem5);
                 sem_post(&sem5);*/
                 }else{
                    info(BEGIN,4,a);
                    info(END,4,a);
                    }
return NULL;
}

void *thread_func2(void *args){

int a = *(int*)args;

if(a != 13){ 
  sem_wait(&sem6);
  sem_wait(&sem3);
  info(BEGIN,2,a);
  sem_post(&sem8);
  sem_wait(&sem7);
  info(END,2,a);
  sem_post(&sem3);
  }else{
       sem_wait(&sem3);
       info(BEGIN,2,a);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_post(&sem6);
       sem_wait(&sem8);
       sem_wait(&sem8);
       sem_wait(&sem8);
       sem_wait(&sem8);
       sem_wait(&sem8);
       info(END,2,a);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
        sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem7);
       sem_post(&sem3);
       }

return NULL;
}

void *thread_func7(void *args){
int a = *(int*)args;

/*sem4 = sem_open("a2_sem4",O_CREAT,0644,0);
sem5 = sem_open("a2_sem5",O_CREAT,0644,0);*/
if(a==4){
    info(BEGIN,7,a);
    info(END,7,a);
    sem_post(sem4);
    sem_post(sem4);
    /*sem_post(&sem4);
    sem_post(&sem4);*/
    }else if(a==5){
          sem_wait(sem5);
           info(BEGIN,7,a);
            info(END,7,a);
           }else{
              info(BEGIN,7,a);
              info(END,7,a);
             }

return NULL;
}
int main(){
   sem_unlink("a2_sem4");
   sem_unlink("a2_sem5");
    sem4 = sem_open("a2_sem4",O_CREAT,0644,0);
sem5 = sem_open("a2_sem5",O_CREAT,0644,0);
    init();
    int pid2,pid3,pid4,pid5,pid6,pid7,pid8;
    int status2=0,status3=0,status4=0,status5=0,status6=0,status7=0,status8=0;

info(BEGIN,1,0);
pid2 = fork();
if(pid2 == -1){
  perror("eroare 2");
  return -1;
  }
if(pid2 == 0){
   info(BEGIN,2,0);
    pid3 = fork();
    if(pid3 == -1){
       perror("eroare 3");
      return -1;
     }
    if(pid3 ==0){
     info(BEGIN,3,0);
     pid4=fork();
     if(pid4 == -1){
       perror("eroare 4");
       return -1;
      }
     if(pid4 == 0){
       info(BEGIN,4,0);
       pthread_t threads[5];
       int values[5];
        sem_init(&sem1,0,0);
        sem_init(&sem2,0,0);
       for(int i=0;i<5;i++)
       {
         values[i]=i+1;
         pthread_create(&threads[i],NULL,thread_func,&values[i]);
       }
       for(int i=0;i<5 ;i++)
       {
       pthread_join(threads[i], NULL);
       }
       sem_destroy(&sem1);
       sem_destroy(&sem2);
       info(END,4,0);
       exit(4);
     } else{
      pid8 = fork();
      if(pid8 == -1){
        perror("eroare 8");
        return -1;
        }
	  if (pid8 == 0) {
		  info(BEGIN, 8, 0);
		  info(END, 8, 0);
                  exit(8);
	  }
     }
     waitpid(pid4,&status4,0);
     waitpid(pid8,&status8,0);
     info(END,3,0);
     exit(3);
   }else {
     pid5=fork();
     if(pid5 == -1){
        perror("eroare 5");
        return -1;
        }
     if(pid5 == 0){
     info(BEGIN,5,0);
     pid6 = fork();
     if(pid6 == -1){
          perror("eroare 6");
          return -1;
        }
    if(pid6 == 0){
       info(BEGIN,6,0);
       info(END,6,0);
       exit(6);
    }else {
      waitpid(pid6,&status6,0);
      info(END,5,0);
      exit(5);}
   } else{
     pid7 = fork();
     if(pid7 == -1){
       perror("eroare 7");
       return -1;
     }
    if(pid7 == 0){
        info(BEGIN,7,0);
        pthread_t ths[5];
        int vals[5];
        for(int i=0;i<5;i++){
           vals[i]=i+1;
           pthread_create(&ths[i],NULL,thread_func7,&vals[i]);}
        for(int i=0; i<5; i++){
           pthread_join(ths[i],NULL);}
        info(END,7,0);
        exit(7);
      }
    }
  }
   pthread_t th[44];
   int val[44];
   sem_init(&sem3,0,6);
   sem_init(&sem6,0,0);
   sem_init(&sem7,0,0);
   sem_init(&sem8,0,0);
   for(int i=0;i<44;i++){
     val[i]=i+1;
     pthread_create(&th[i],NULL,thread_func2,&val[i]);}
   for(int i=0;i<44;i++){
     pthread_join(th[i],NULL);}
   waitpid(pid3,&status3,0);
   waitpid(pid5,&status5,0);
   waitpid(pid7,&status7,0);
   sem_destroy(&sem3);
    sem_destroy(&sem6);
    sem_destroy(&sem7);
     sem_destroy(&sem8);
	 info(END, 2, 0);
   exit(2);
  }
   waitpid(pid2,&status2,0);
   info(END,1,0);
   sem_close(sem4);
   sem_close(sem5);
   //getchar();
    return 0;
}
	
	
	

