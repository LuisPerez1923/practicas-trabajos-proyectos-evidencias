#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int **create_matrix(int n_ind,int n_reg)
{
	int *p1 = NULL;
	int **p2 = NULL;

	p1 = (int *)malloc(sizeof(int)*(n_ind*n_reg));
	if(p1!=NULL)
	{
		p2=(int **)malloc(sizeof(int *)*n_ind);
		if(p2!=NULL)
		{
			for(int i=0; i<n_ind; i++)
			{
				p2[i] = &(p1[i*n_reg]);

			

			}
		}
		else{printf("NO MEMORY\n");}
	}
	else{printf("NO MEMORY\n");}

	return p2;

}
void display_pop(int **point2, int n_ind, int n_reg)
{
        printf("YOUR MATRIX WITH %d INDIVUDUALS AND %d REGIONS TO COLOURING IS:\n",n_ind,n_reg);
        for(int i=0; i<n_ind; i++)
        {
                 printf("ind[%d]\t",i);
                for(int j=0; j<n_reg; j++)
                {
                        printf("     %d  \t",point2[i][j]);
                }
                        printf("\n");
        }
}


void cruzamiento(int **point2, int **point2_aux, int n_ind, int n_reg)
{
     int cruz_point;
     int aux[n_reg];
     cruz_point=rand()%(n_reg-1)+1; //crea el punto de cruzamiento 
     point2_aux=create_matrix(n_ind,n_reg); //crea la matriz auxiliar en donde guardaremos los datos

        for(int i=0; i<n_ind; i++)
        {
                for(int j=0; j<cruz_point; j++)
                { 
                    
                    point2_aux[i][j]=point2[i][j+n_reg-cruz_point];
                      
                }              
        }

       for(int i=0; i<n_ind; i++)
        {
                for(int j=cruz_point; j<n_reg; j++)
                { 
                    point2_aux[i][j]=point2[i][j-cruz_point];
                      
                }              
        }

       printf("La matriz auxiliar cuenta con %d individuos y %d regiones:\n",n_ind,n_reg);
        for(int i=0; i<n_ind; i++)
        {
                 printf("ind[%d]\t",i);
                for(int j=0; j<n_reg; j++)
                {
                        printf("     %d  \t",point2_aux[i][j]);
                }
                        printf("\n");
        }
      printf("El punto de cruze es %d\n", cruz_point);
}

void generate_rand_pop(int **p2,int n_ind,int n_reg,int colour)
{
	for(int i=0; i<n_ind; i++)
	{
		for(int j=0; j<n_reg; j++)
		{
			p2[i][j] = rand()%colour;
		}
	}
	

}

int main()
{
	srand(time(NULL));
	int **pop,**pop_aux,n_reg,n_ind,n_colour;

	// **pop refers to the population;
	// population = Num of individuals and Num of regions for colouring
	// n_ind -> stores the number of individuals
	// n_reg -> stores the number of regions to colouring
	// n_col -> Number of colours

	printf("ENTER THE POULATION SIZE\n");
	scanf("%d",&n_ind);
	printf("ENTER THE COLOUR REGIONS SIZE\n");
	scanf("%d",&n_reg);
	printf("ENTER THE No. OF COLOURS\n");
	scanf("%d",&n_colour);


	pop = create_matrix(n_ind,n_reg); //--> allocate the memory for the population matrix
	generate_rand_pop(pop,n_ind,n_reg,n_colour); //creates randomly the initial population
	display_pop(pop,n_ind,n_reg); // Display matrix
        cruzamiento(pop,pop_aux,n_ind,n_reg); //algoritmo de cruzamiento

}
