//Código realizado por Luis Alfredo Pérez Mendoza

#include<stdio.h> 
#include<pthread.h>
#include<time.h>

#define N 20

pthread_mutex_t cp[N-1];
pthread_mutex_t cc[N-1];
int x[N];
int aux;

void tarea_ninicial(void* ptr){
   
 int i=10;
 int id=(int)ptr; 

  while(i>=1){
    
    pthread_mutex_lock(&cc[0]);
    x[0]=x[0]+1;                           //secion critica
    pthread_mutex_unlock(&cp[0]);
      }

     pthread_exit((void*)id);

}

void tarea_nintermedio(void* ptr){

 int i=10;
 int id=(int)ptr; 

  while(i>=1){
   
    pthread_mutex_lock(&cp[id-1]);
    aux=x[id-1];                           //seccion critica
    pthread_mutex_unlock(&cc[id-1]);

    pthread_mutex_lock(&cc[id-1]);
    x[id]=aux+1;                           //seccion critica
    pthread_mutex_unlock(&cp[id]);
      }

     pthread_exit((void*)id);

}

void tarea_nfinal(void* ptr){

 int i=10;
 int id=(int)ptr; 

  while(i>=1){
   
   pthread_mutex_lock(&cp[id-1]);
   aux=x[id-1];                           //seccion critica
   pthread_mutex_unlock(&cp[id-1]);
   aux++;                                //seccion critica

   printf("El numero editado es: %d\n",x[N]);
     }

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
     resultado=pthread_create(&hilos[i],NULL,(void*)&tarea_nintermedio,(void*)i);  //aqui se crean los N 
       }                                                                           //hilos del programa
   resultado=pthread_create(&hilos[N-1],NULL,(void*)&tarea_nfinal,(void*)N-1); 

   for(i=0; i<N; i++){
     pthread_join(hilos[i],(void*)&salida[i]);
       }
                         
  
   return 0;

}
