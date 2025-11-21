#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cont;
    int mayor = 0;
    int num;
    char c;
    
    do
    {
        int ok;
        
        do
        {
            ok = 1;
            
            printf("Ingrese un número positivo: ");
            if (scanf("%d%c", &num, &c) != 2 || c != '\n')
            {
                ok = 0;
                while (getchar() != '\n'); // Limpiar el búfer de entrada
            }
            
            if (!ok)
            {
                printf("Dato erróneo\n");
            }
            else if (num < 0)
            {
                printf("Debe introducir un número positivo\n");
                ok = 0;
            }
            
        } while (!ok);
        
        if (num > mayor)
        {
            mayor = num;
        }
        
        printf("¿Desea ingresar otro número? (s/n): ");
        fflush(stdin);
        scanf(" %c", &cont);
        
    } while (cont == 's' || cont == 'S');
    
    printf("El mayor número ingresado es: %d\n", mayor);
    
    return 0;
}