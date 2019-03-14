//Código realizado por Luis Alfredo Pérez Mendoza

#include<stdio.h> 
#include<pthread.h>
#include<time.h>

pthread_mutex_t c1; 
pthread_mutex_t c2;
int numero=0;

void tarea_productor(){
  int i=1;
  while(i>=1){
   pthread_mutex_lock(&c2);
     numero++;                  //sección critica
   pthread_mutex_unlock(&c1);
  }

}

void tarea_consumidor(){
 int j=1;
 while(j>=1){
 pthread_mutex_lock(&c1);
  printf("Numero %d\n",numero);  //sección critica
 pthread_mutex_unlock(&c2);
}

}

int main () { 


pthread_mutex_init(&c1,NULL);
pthread_mutex_init(&c2,NULL);
pthread_mutex_lock(&c1);      //esta linea de codigo sirve para "inicializar" c1 como cerrado

 pthread_t hilo_consumidor;
 pthread_t hilo_productor;  
 int resultado;
 

 
    pthread_create(&hilo_consumidor,NULL,(void*)&tarea_productor,(void*)0); 
    pthread_create(&hilo_productor,NULL,(void*)&tarea_consumidor,(void*)1);       


 
   pthread_join(hilo_consumidor,(void*)NULL);
   pthread_join(hilo_productor,(void*)NULL);
                       
       
  
   return 0;

}
