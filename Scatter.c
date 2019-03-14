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
  int *dato,id,size,i;
  int *vector;
  
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&id); //sirve para reconocer el id del proceso
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  
  dato=Crea_vector(3);
 
  if (id==0)
    { 
       vector=Crea_vector(size*3);
       for(i=0;i<size*3;i++)
         {
         //dato=1000;
         vector[i]=i;
         }
    }

  
   
  //Despliega_vector_a(vector,4,id);
  printf("Proceso: %d, dato antes: [%d] [%d] [%d] \n",id,dato[0],dato[1],dato[2]);
  //MPI_Bcast(vector,4,MPI_INT,0,MPI_COMM_WORLD);
  MPI_Scatter(vector,3,MPI_INT,dato,3,MPI_INT,0,MPI_COMM_WORLD);
  printf("Proceso: %d, dato despues: [%d] [%d] [%d] \n",id,dato[0],dato[1],dato[2]);
  //Despliega_vector_d(vector,4,id);

  MPI_Finalize();

  return 0;
  }
