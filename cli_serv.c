//Código realizado por Luis Alfredo Pérez Mendoza

#include<stdio.h> 
#include<pthread.h>
#include<time.h>
#include<string.h>

pthread_mutex_t cs; 
pthread_mutex_t cc;
char producto[20]="luis";
int tipo_producto;

void tarea_servidor(){
  int i=1;
  while(i>=1){
   pthread_mutex_lock(&cs);
     if(tipo_producto==0){
          strcpy(producto,"Leche");
	}              
 	else if(tipo_producto==1){
          strcpy(producto,"Queso");
		}
		else
          strcpy(producto,"Crema");
   pthread_mutex_unlock(&cc);
  }
}


void tarea_cliente(){
 int j=1;
 while(j>=1){
tipo_producto= rand() % 3;
 pthread_mutex_unlock(&cs);
 pthread_mutex_lock(&cc);
  printf("Lo que pedi fue: %d y lo que recibi fue: %s\n",tipo_producto,producto);  
}

}

int main () { 


pthread_mutex_init(&cs,NULL);
pthread_mutex_init(&cc,NULL);
pthread_mutex_lock(&cs);      //esta linea de codigo sirve para "inicializar" c1 como cerrado
pthread_mutex_lock(&cc);  

 pthread_t hilo_cliente;
 pthread_t hilo_servidor;  
 int resultado;
 

 
    pthread_create(&hilo_cliente,NULL,(void*)&tarea_cliente,(void*)0); 
    pthread_create(&hilo_servidor,NULL,(void*)&tarea_servidor,(void*)1);       


 
   pthread_join(hilo_cliente,(void*)NULL);
   pthread_join(hilo_servidor,(void*)NULL);
                       
    
  
   return 0;

}
