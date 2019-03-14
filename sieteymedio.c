#include <stdio.h>
#include <stdlib.h>

float baraja[40];  //arrelgo de 40 floats, aqui iran los digitos.
char barajac[40];   //arreglo de 40 char, son los Copas,Bastos,Espadas,Oros
int indice1,indice2;
int tipo_maquina;
float puntmaq=0;
float puntmaq1=0;
float puntmaq2=0;
float puntjug=0;
int contganemaq1=0;
int contganemaq2=0;

int main()
{
    //void presentacion();
    Menu();
    elegirOpcion();

}

void Menu()
{
    printf("Bienvenido al Menu del Juego de Cartas 7 y Medio \n \n");
    printf("1.- Jugar contra la maquina Jugador vs CPU \n");
    printf("2.- Realizar una simulacion entre CPU vs CPU \n");
    printf("3.- Salir de la aplicacion \n \n");
    printf("Elije una de las opciones anteriores \n \n");
}

//modulo que permite elejir una opcion dada por teclado
//con la condicion de que sea un numero entre 1 y 3
void elegirOpcion(int op)
{
    do
    {
        scanf("%d", &op);
        if(op==1)
        {
            printf("Escojiste 1 \n \n");
            juego();
        }else if(op==2){
            printf("Escojiste 2 \n");
            Simulacion();
        }else if(op==3){
            printf("Escojiste 3\n");
        }else
        {
            printf("Escoje un numero valido \n");
        }
    }while(op<1 || op>3);
}
//modulo que inicializa el juego
void juego()
{
    int opcion;
    Inicializar_Baraja();
    barajear();
    Turno_Jugador(baraja,barajac);
    tipo_maquina = 0;
    Turno_Maquina(baraja,barajac,indice1+1,tipo_maquina);
    quiengana();
}


void quiengana()
{
    if((puntjug>puntmaq && puntjug<=7.5) || (puntjug<7.5 && puntmaq>7.5)){
        printf("La puntuacion del jugador es: %.2f \n",puntjug);
        printf("La puntuacion de la maquina es: %.2f \n",puntmaq);
        printf("Felicidades! Jugador haz ganado la partida\n");
    }
    if((puntmaq>puntjug && puntmaq<=7.5) || (puntmaq<7.5 && puntjug>7.5)){
        printf("La puntuacion del jugador es: %.2f \n",puntjug);
        printf("La puntuacion de la maquina es: %.2f \n",puntmaq);
        printf("Lo siento La Maquina ha ganado la partida\n");
    }
    if(puntjug>7.5 && puntmaq>7.5){
        printf("Los dos tanto jugador y maquina han perdido \n");
    }
    if(puntjug==puntmaq){
        printf("La puntuacion del jugador es: %.2f \n",puntjug);
        printf("La puntuacion de la maquina es: %.2f \n",puntmaq);
        printf("Han tenido los mismo puntos\n");
    }
}

//modulo que inicializa la baraja con el arreglo de loats y char
void Inicializar_Baraja()
{

   int j=1;
   int k=1;
   int l=1;

   //Este for es para que las cartas de la baraja del 1 al 7,
   //sean los mismos dijitos, por ejemplo la carta numero 0
   //es el numero 1, para tenerlos en orden al principio depl
   //juego, pero solo hasta el 6, ya que las otras tres cartas
   //son 0.5
   for(int i=0; i<7; i++)
   {
       baraja[i] = i+1;
   }
   baraja[7] = 0.5;
   baraja[8] = 0.5;
   baraja[9] = 0.5;

   //Aqui se hace lo mismo de arriba, los primeros 7 dijitos
   //son los numeros del 1 al 7, en cierta forma estos son los
   //numeros de la segunda fila, en el arreglo iran desde el
   //10 hasta el 19
   for(int i=10; i<17; i++)
   {
       baraja[i] = j;
       j++;
   }
   baraja[17] = 0.5;
   baraja[18] = 0.5;
   baraja[19] = 0.5;

   //Este al igual que los dos anteriores llena la baraja pero ahora
   //desde la carta 20 a la 29
   for(int i=20; i<27; i++)
   {
       baraja[i] = k;
       k++;
   }
   baraja[27] = 0.5;
   baraja[28] = 0.5;
   baraja[29] = 0.5;
   //Este al igual que los dos anteriores llena la baraja pero ahora
   //las ultimas 10 elementos de la baraja
   for(int i=30; i<37; i++)
   {
       baraja[i] = l;
       l++;
   }
   baraja[37] = 0.5;
   baraja[38] = 0.5;
   baraja[39] = 0.5;

   //en este for inicializo el arreglo de char, donde los
   //primeros 10 son de la letra O (Oros)
   for(int i=0; i<10; i++)
   {
       barajac[i] = 'O';
   }
    //en este for los valores del 10 al 19 del arreglo char
    //son de la letra C (Copas)
   for(int i=10; i<20; i++)
   {
       barajac[i] = 'C';
   }
   //en este for los valores del 20 al 29 del arreglo char
    //son de la letra E (Espadas)
   for(int i=20; i<30; i++)
   {
       barajac[i] = 'E';
   }
   //los ultimos diez elementos del arreglo char, los cuales
   //tienen desde el elemetnos 29 al 39 y son de B (Bastos)
   for(int i=30; i<40; i++)
   {
       barajac[i] = 'B';
   }

   //como ya teneemos los dos arreglos llenos yde forma ordenada
   //ahora los imprimimos para que se vean bien ordenados
   printf("El contenido inicial de la baraja es: \n");
   //imprimimos los 10 primeros char
   for(int i=0; i<10; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   //ahora imprimimos los 10 primeros digitos
   for(int i=0; i<10; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
   //del 10 al 19 elñemtnos de char
   for(int i=10; i<20; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   //del 10 al 19 elemtnos de digitos
   for(int i=10; i<20; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
   //del 20 al 29 elñemtnos de char
   for(int i=20; i<30; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   //del 20 al 29 elemtnos de digitos
   for(int i=20; i<30; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
   //del 30 al 39 elñemtnos de char
   for(int i=30; i<40; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   //del 30 al 39 elemtnos de digitos
   for(int i=30; i<40; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
}

//este modulo se encarga de barajear aleatoriamebte, los arreglos
//de floatsw y de char
void barajear()
{
    //hacemos un numeros aleatorio entre 1000, no se por que pero
    //en la hoja dice jaja
    srand(time(NULL));
    int n = 200 + rand() % (1001 - 200);
    //printf("n es %d \n",n);

    float c1,c2,aux;
    char c1n,c2n;
    //Este for intercambia dos elemtnos en la baraja, las n
    //veces que sean
    for(int i=0; i<n; i++)
    {
        //f1 yf2 son otros dos valores aleatorios pero entre
        //0 y 39, para que aleatoriamente escoja dos elemtnos de
        //la baraja
        int f1 = 0 + rand() % (40-0);
        int f2 = 0 + rand() % (40-0);
        c1 = baraja[f1];
        c2 = baraja[f2];

        //c1 yc2 ya son los dos elemtnos a intercambiar, lo hacemos mediante
        //un auxiliar

        aux = c1;
        c1 = c2;
        c2 = aux;

        //ya que se intercambiaron se ponen en la baraja
        baraja[f1] = c1;
        baraja[f2] =c2;

        //aqui hacemos lo mismo pero ahora con el arrelgo de char
        //c1n y c2n son dos elemtnos aleatorios de la baraja char
        //f1 y f2 no cambian para que se intercambien no solo
        //los floats si no tgambien los char, dado que esta ordenado
        //asi al intercambiar un elemtno, cambia el digito y el char
        c1n = barajac[f1];
        c2n = barajac[f2];

        //intercambiamos esos valores
        aux = c1n;
        c1n = c2n;
        c2n = aux;

        //ya que estan intercambiados se ponen en la baraja de char
        barajac[f1] = c1n;
        barajac[f2] =c2n;
    }

    //ya haciendo los intercambios aleatorios ahora imprimimos
    //la baraja completa de char y floats
    printf("El contenido final de la baraja es: \n");
   //impresion de las cartas de oro
   for(int i=0; i<10; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   for(int i=0; i<10; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
   //impresion de las cartas de copas
   for(int i=10; i<20; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   for(int i=10; i<20; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
   //impresion de las cartas de espadas
   for(int i=20; i<30; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   for(int i=20; i<30; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");
   //impresion de las cartas de bastos
   for(int i=30; i<40; i++)
   {
       printf("%c \t",barajac[i]);
   }
   printf("\n");
   for(int i=30; i<40; i++)
   {
       printf("%.2f \t",baraja[i]);
   }
   printf("\n");

}

void Turno_Jugador(float numeros[40],char caracteres[40]){
   int i =0,j,opcion,sacar = 0;
   float contador = 0;
   char letra;

    contador=numeros[i];
    //letra = caracteres[i];
    printf("\nTURNO DEL JUGADOR");
   do
      {
       letra = caracteres[i];
         switch(letra)
          {
          case 'O':
             printf("\nTe a salido %.2f de Oros",numeros[i]);
             break;
          case 'C':
             printf("\nTe a salido %.2f de Copas",numeros[i]);
             break;
          case 'B':
             printf("\nTe a salido %.2f de Bastos",numeros[i]);
             break;
          case 'E':
             printf("\nTe a salido %.2f de Espadas",numeros[i]);
             break;
           default:
              break;
          }


       printf("\nSus cuenta hasta el momento es: %.2f \n",contador);
       printf("Desea continuar sacando cartas?? \n");
       printf("Si-->1           No-->2 \n");

       scanf("%d", &opcion);

       if(opcion == 1)
          {
           printf("\nDecidio continuar jugando\n");
           i++;
           contador =contador + numeros[i];

           if(contador>7.5)
              {
               printf("Usted a perdido con %.2f puntos :( ",contador);
               indice1 = i;
              }
           else if(contador == 7.5)
              {
               printf("FELICIDADES USTED A GANADO!!!");
               printf("Su cuenta es: %.2f",contador);
               sacar = 1;
               indice1 =i;
              }
          }
       else if(opcion == 2)
          {
           printf("Gracias por jugar a continuacion se daran los resultados\n");
           printf("Sus puntos son %.2f\n",contador);
           sacar = 1;
           indice1 =i;
          }
       else
          {
           printf("POR FAVOR INTRODUZCA UN VALOR VALIDO!!!\n");
          }

      }
   while(contador <= 7.5 && sacar == 0);
   puntjug = contador;
}


void Turno_Maquina(float numeros[40],char caracteres[40],int indice1,int maquina){
   int i =indice1,j,opcion,sacar = 0;
   float contador = 0,parametro;
   char letra;

    contador=numeros[i];
    //letra = caracteres[i];
    if(maquina == 0)
       {
       parametro = 4.5;
       }
    else if(maquina == 1)
       {
       parametro = 6.5;
       }
    else
       {
       parametro = 6.0;
       }


    printf("\n\nTURNO DE LA MAQUINA");
   do
      {
       letra = caracteres[i];
         switch(letra)
          {
          case 'O':
             printf("\nA la maquina le a salido %.2f de Oros",numeros[i]);
             break;
          case 'C':
             printf("\nA la maquina le a salido %.2f de Copas",numeros[i]);
             break;
          case 'B':
             printf("\nA la maquina le a salido %.2f de Bastos",numeros[i]);
             break;
          case 'E':
             printf("\nA la maquina le salido %.2f de Espadas",numeros[i]);
             break;
           default:
              break;
          }


       printf("\nSu cuenta hasta el momento es: %.2f \n",contador);

       if(contador<parametro)
          {
          opcion = 1;
          }
       else
          {
          opcion = 2;
          }

       if(opcion == 1)
          {
           printf("\nLa maquina decidio continuar jugando\n");
           i++;
           contador =contador + numeros[i];
           indice1 = i;
           if(contador>7.5)
              {
               printf("La maquina ha perdido con %.2f puntos :( \n",contador);
               i++;
               indice1 = i;
              }
           else if(contador == 7.5)
              {
               printf("FELICIDADES USTED A GANADO!!!");
               printf("Su cuenta es: %.2f \n",contador);
               sacar = 1;
               i++;
               indice1 = i;
              }
          }
       else if(opcion == 2)
          {
           printf("La maquina decidio terminar su turno a continuacion se daran los resultados\n");
           printf("Los puntos de la maquina son %.2f\n",contador);
           sacar = 1;
           i++;
           indice1 = i;
          }
       else
          {
           printf("POR FAVOR INTRODUZCA UN VALOR VALIDO!!!\n");
          }

      }
   while(contador <= 7.5 && sacar == 0);
   puntmaq = contador;
   indice2=indice1;
}

void quienganamaq()
{
    if((puntmaq1>puntmaq2 && puntmaq1<=7.5) || (puntmaq1<7.5 && puntmaq2>7.5)){
        contganemaq1 = contganemaq1 + 1;
    }
    if((puntmaq2>puntmaq1 && puntmaq2<=7.5) || (puntmaq2<7.5 && puntmaq1>7.5)){
        contganemaq2 = contganemaq2 +1;
    }
    if(puntjug>7.5 && puntmaq>7.5){
    }
}

void Simulacion()
{
    int numSimu;
    int totaljuegos;
    int i=1;
    indice1 = 0;
    Inicializar_Baraja_sin();
    barajear_sin();
    printf("\n");
    printf("Cuantas Simulaciones quieres hacer? \n");
    scanf("%d",&numSimu);

    do
    {
        barajear_sin();
        tipo_maquina = 1;
        Turno_Maquina_sin_impresion(baraja,barajac,indice1,tipo_maquina);
        puntmaq1 = puntmaq;
        tipo_maquina = 2;
        Turno_Maquina_sin_impresion(baraja,barajac,indice2,tipo_maquina);
        puntmaq2 = puntmaq;
        quienganamaq();
        i++;
        totaljuegos = contganemaq1 + contganemaq2;
    }while(totaljuegos<numSimu);

    printf("\nDe %d juegos \n",totaljuegos);
    printf("La maquina 1 ha ganado: %d veces \n",contganemaq1);
    printf("La maquina 2 ha ganado: %d veces \n",contganemaq2);

}

void Turno_Maquina_sin_impresion(float numeros[40],char caracteres[40],int indice1,int maquina){
   int i =indice1,j,opcion,sacar = 0;
   float contador = 0,parametro;
   char letra;

    contador=numeros[i];
    if(maquina == 0)
       {
       parametro = 4.5;
       }
    else if(maquina == 1)
       {
       parametro = 6.5;
       }
    else
       {
       parametro = 6.0;
       }
   do
      {
          if(contador<parametro)
          {
                opcion = 1;
          }
                else
          {
          opcion = 2;
          }

       if(opcion == 1)
        {
              i++;
              contador =contador + numeros[i];
              indice1 = i;

                if(contador>7.5)
                {
                    i++;
                    indice1 = i;
                }
                else if(contador == 7.5)
                {
                    sacar = 1;
                    i++;
                    indice1 = i;
                }
        }
        else if(opcion == 2)
        {
           sacar = 1;
           i++;
           indice1 = i;
        }
       else
          {
           //printf("POR FAVOR INTRODUZCA UN VALOR VALIDO!!!\n");
          }

      }
   while(contador <= 7.5 && sacar == 0);
   puntmaq = contador;
   indice2=indice1;
}

void Inicializar_Baraja_sin()
{

   int j=1;
   int k=1;
   int l=1;

   //Este for es para que las cartas de la baraja del 1 al 7,
   //sean los mismos dijitos, por ejemplo la carta numero 0
   //es el numero 1, para tenerlos en orden al principio depl
   //juego, pero solo hasta el 6, ya que las otras tres cartas
   //son 0.5
   for(int i=0; i<7; i++)
   {
       baraja[i] = i+1;
   }
   baraja[7] = 0.5;
   baraja[8] = 0.5;
   baraja[9] = 0.5;

   //Aqui se hace lo mismo de arriba, los primeros 7 dijitos
   //son los numeros del 1 al 7, en cierta forma estos son los
   //numeros de la segunda fila, en el arreglo iran desde el
   //10 hasta el 19
   for(int i=10; i<17; i++)
   {
       baraja[i] = j;
       j++;
   }
   baraja[17] = 0.5;
   baraja[18] = 0.5;
   baraja[19] = 0.5;

   //Este al igual que los dos anteriores llena la baraja pero ahora
   //desde la carta 20 a la 29
   for(int i=20; i<27; i++)
   {
       baraja[i] = k;
       k++;
   }
   baraja[27] = 0.5;
   baraja[28] = 0.5;
   baraja[29] = 0.5;
   //Este al igual que los dos anteriores llena la baraja pero ahora
   //las ultimas 10 elementos de la baraja
   for(int i=30; i<37; i++)
   {
       baraja[i] = l;
       l++;
   }
   baraja[37] = 0.5;
   baraja[38] = 0.5;
   baraja[39] = 0.5;

   //en este for inicializo el arreglo de char, donde los
   //primeros 10 son de la letra O (Oros)
   for(int i=0; i<10; i++)
   {
       barajac[i] = 'O';
   }
    //en este for los valores del 10 al 19 del arreglo char
    //son de la letra C (Copas)
   for(int i=10; i<20; i++)
   {
       barajac[i] = 'C';
   }
   //en este for los valores del 20 al 29 del arreglo char
    //son de la letra E (Espadas)
   for(int i=20; i<30; i++)
   {
       barajac[i] = 'E';
   }
   //los ultimos diez elementos del arreglo char, los cuales
   //tienen desde el elemetnos 29 al 39 y son de B (Bastos)
   for(int i=30; i<40; i++)
   {
       barajac[i] = 'B';
   }
}

void barajear_sin()
{
    //hacemos un numeros aleatorio entre 1000, no se por que pero
    //en la hoja dice jaja
    srand(time(NULL));
    int n = 200 + rand() % (1001 - 200);
    //printf("n es %d \n",n);

    float c1,c2,aux;
    char c1n,c2n;
    //Este for intercambia dos elemtnos en la baraja, las n
    //veces que sean
    for(int i=0; i<n; i++)
    {
        //f1 yf2 son otros dos valores aleatorios pero entre
        //0 y 39, para que aleatoriamente escoja dos elemtnos de
        //la baraja
        int f1 = 0 + rand() % (40-0);
        int f2 = 0 + rand() % (40-0);
        c1 = baraja[f1];
        c2 = baraja[f2];

        //c1 yc2 ya son los dos elemtnos a intercambiar, lo hacemos mediante
        //un auxiliar

        aux = c1;
        c1 = c2;
        c2 = aux;

        //ya que se intercambiaron se ponen en la baraja
        baraja[f1] = c1;
        baraja[f2] =c2;

        //aqui hacemos lo mismo pero ahora con el arrelgo de char
        //c1n y c2n son dos elemtnos aleatorios de la baraja char
        //f1 y f2 no cambian para que se intercambien no solo
        //los floats si no tgambien los char, dado que esta ordenado
        //asi al intercambiar un elemtno, cambia el digito y el char
        c1n = barajac[f1];
        c2n = barajac[f2];

        //intercambiamos esos valores
        aux = c1n;
        c1n = c2n;
        c2n = aux;

        //ya que estan intercambiados se ponen en la baraja de char
        barajac[f1] = c1n;
        barajac[f2] =c2n;
    }

    //ya haciendo los intercambios aleatorios ahora imprimimos
    //la baraja completa de char y floats
}



