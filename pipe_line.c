//Código realizado por Luis Alfredo Pérez Mendoza

#include<stdio.h> 
#include<pthread.h>
#include<time.h>

#define N 20
pthread_mutex_t cp[N-1];
int x;

void tarea_ninicial(void* ptr){
   
   int id=(int)ptr; 
   x=1;
   pthread_mutex_unlock(&cp[id]);

     pthread_exit((void*)id);
}

void tarea_nintermedio(void* ptr){

   int id=(int)ptr; 
   pthread_mutex_lock(&cp[id-1]);
   x=x+1;
   pthread_mutex_unlock(&cp[id]);


     pthread_exit((void*)id);
}

void tarea_nfinal(void* ptr){
 
  int id=(int)ptr; 
   pthread_mutex_lock(&cp[id-1]);
   x=x+1;
   
  printf("El numero editado es: %d\n",x);

     pthread_exit((void*)id);
}


int main () { 

pthread_t hilos[N]; 
 int resultado, i;
 int salida[N];

 
   for(i=0;i<N-1; i++){
     pthread_mutex_init(&cp[i],NULL);
     pthread_mutex_lock(&cp[i]); 
       }

   resultado=pthread_create(&hilos[0],NULL,(void*)&tarea_ninicial,(void*)0); 
   for(i=1; i<N-1; i++){
     resultado=pthread_create(&hilos[i],NULL,(void*)&tarea_nintermedio,(void*)i); 
       }
   resultado=pthread_create(&hilos[N-1],NULL,(void*)&tarea_nfinal,(void*)N-1); 

   for(i=0; i<N; i++){
     pthread_join(hilos[i],(void*)&salida[i]);
       }
                         
  
   return 0;

}
