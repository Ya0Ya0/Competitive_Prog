#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct 
{
   int iD;
   char direccion[101];
   int nucleos;
   float ventas[31];
}PuntoVenta;

int ini(PuntoVenta array[])
{
    int tam = 20,i,j;
    char direc[20][101]=
    {
        {"Calle 23 e/ Paseo y Malecón, Vedado"},
        {"Avenida 31 e/ 42 y 44, Playa"},
        {"Calle 5ta e/ 84 y 86, Miramar"},
        {"Avenida Boyeros e/ Tulipán y La Rosa, Diez de Octubre"},
        {"Calle 19 e/ 70 y 72, Nuevo Vedado"},
        {"Avenida 51 esq. 220, La Lisa"},
        {"Calle 100 e/ 31 y 41, Marianao"},
        {"Avenida 33 e/ 84 y 86, La Coronela"},
        {"Calle 176 e/ 5ta y 7ma, Siboney"},
        {"Avenida 41 e/ 146 y 148, Fontanar"},
        {"Calle 23 e/ 26 y 28, El Vedado"},
        {"Avenida 31 e/ 42 y 44, Reparto Kholy"},
        {"Calle 1ra e/ 12 y 14, Miramar"},
        {"Avenida Salvador Allende e/ Carlos III y Belascoaín, Cerro"},
        {"Calle 19 e/ 70 y 72, Alturas del Vedado"},
        {"Avenida 51 e/ 220 y 222, La Lisa"},
        {"Calle 100 e/ 31 y 41, La Cumbre"},
        {"Avenida 33 e/ 84 y 86, Alturas de La Coronela"},
        {"Calle 176 e/ 5ta y 7ma, Residencial Siboney"},
        {"Avenida 41 e/ 146 y 148, Jaimanitas"},
    };
    srand(time(NULL));
    for(i = 0; i < 20; i++)
    {
        array[i].iD = i;
        array[i].nucleos = rand()%10000;
        strcpy(array[i].direccion,direc[i]);
        for(j = 0; j < 31;j++)
        {
            array[i].ventas[j] = rand()%100;
        }
    }
    return tam;
}
int main()
{
    PuntoVenta asd[30];
    int i,tl = ini(asd);
    for(i  = 0; i < tl; i++)
    {
        printf("%s\n",asd[i].direccion);
    }
    return 0;
}
