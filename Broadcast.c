//Codigo realizado por Luis Alfredo Pérez Mendoza
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int *Crea_vector(int num_elems)
  {
  int *ap;
  ap=(int*)malloc(sizeof(int)*num_elems);
  
  if (ap==NULL)
    {
     printf("Error... Memoria insuficiente\n");
    }
  
  return ap;
  }

void Despliega_vector_a(int *vector, int num_elem, int id)
  {
    int i;
    for(i=0;i<num_elem;i++)
      {
       printf("Proceso: %d, Dato del Arreglo antes %d",id,vector[i]);
       printf("\n");
      }
  }

void Despliega_vector_d(int *vector, int num_elem, int id)
  {
    int i;
    for(i=0;i<num_elem;i++)
      {
       printf("Proceso: %d, Dato del Arreglo despues %d",id,vector[i]);
       printf("\n");
      }
  }

int main(int argc, char **argv)
  {
  int dato,id,size,i;
  int *vector;
  
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&id);
  vector=Crea_vector(4);

  if (id==0)
    {
       for(i=0;i<4;i++)
         {
         //dato=1000;
         vector[i]=1000;
         }
    }

  Despliega_vector_a(vector,4,id);
  //printf("Proceso: %d, dato antes Bcast: %d \n",id,dato);
  MPI_Bcast(vector,4,MPI_INT,0,MPI_COMM_WORLD);
  //printf("Proceso: %d, despues del Bcast: %d\n",id,dato);
  Despliega_vector_d(vector,4,id);

  MPI_Finalize();

  return 0;
  }
