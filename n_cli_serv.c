//Código realizado por Luis Alfredo Pérez Mendoza

#include<stdio.h> 
#include<pthread.h>
#include<time.h>
#include<string.h>

#define N 10

pthread_mutex_t cs; 
pthread_mutex_t cc;
pthread_mutex_t cp;

char producto[20];
int tipo_producto;

void tarea_servidor(){
  int i=1;
  while(i>=1){
   pthread_mutex_lock(&cs);            
     if(tipo_producto==0){              //aqui empieza seccion critica
          strcpy(producto,"Leche");
	}              
 	else if(tipo_producto==1){
          strcpy(producto,"Queso");
		}
		else
          strcpy(producto,"Crema");    //aqui termina seccion critica
   pthread_mutex_unlock(&cc);
  }
}


void tarea_cliente(void* ptr){
 int j=1;
 while(j>=1){
 pthread_mutex_lock(&cp);
 int id=(int)ptr; 
 tipo_producto= rand() % 3;
 pthread_mutex_unlock(&cs);
 pthread_mutex_lock(&cc);
 pthread_mutex_unlock(&cp);
  printf("\n Yo soy: %d Lo que pedi fue: %d y lo que recibi fue: %s",id,tipo_producto,producto);  
}

}

int main () { 


pthread_mutex_init(&cs,NULL);
pthread_mutex_init(&cc,NULL);
pthread_mutex_init(&cp,NULL);
pthread_mutex_lock(&cs);      
pthread_mutex_lock(&cc);  

 pthread_t hilos_cliente[N]; 
 pthread_t hilo_servidor;  
 
 int resultado, i;
 int salida[N];

    for(i=0; i<N; i++){
     resultado=pthread_create(&hilos_cliente[i],NULL,(void*)&tarea_cliente,(void*)i+1); 
              }

    pthread_create(&hilo_servidor,NULL,(void*)&tarea_servidor,(void*)0);       


 
    for(i=0; i<N; i++){
     pthread_join(hilos_cliente[i],(void*)&salida[i]);

                        }

   pthread_join(hilo_servidor,(void*)NULL);
                       
    
  
   return 0;

}
