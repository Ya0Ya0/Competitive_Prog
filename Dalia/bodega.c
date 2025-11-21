#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

void actualizar(int i, int j, float value, float sales[6][5]){
    sales[i][j] += value;
    sales[6][j] += value;
    sales[i][5] += value;
}

float buscarMayorValor(float sales[6][5]){
    int i, j;
    float mayor = 0;

    for(i=1;i<6;i++)
        for(j=1;j<5;j++){
            if(sales[i][j] > mayor){
                mayor = sales[i][j];
            }
        }
    return mayor;
}

int buscarMayorVend(float sales[6][5]){
    int j,i;
    bool exit = false;
    float mayor = 0;

    for(j=1;j<5;j++)
        if(sales[6][j] > mayor)
            mayor = sales[6][j];

    for(i=1;i<5 && !exit;j++)
        if(sales[6][j] == mayor){
            exit = true;

            return j;
        }
}

float buscarMayorProd(int* fila, float sales[6][5]){

    int i;
    float mayor = 0;
    for(i=1;i<6;i++){
        if(sales[i][5] > mayor){
            mayor = sales[i][5];
            *fila=i;
        }
    }
    return mayor;

}
int validarVend(char nombre[5][25], int pos){
    int ret = 1, i = 0;;
    if(strlen(nombre[pos]) > 20){
        ret = 0;
        printf("El nombre debe tener como m\240ximo 20 caracteres\n");
    }
    for(i = 0; i < strlen(nombre[pos]) && ret; i++){
        if(!isalpha(nombre[pos][i])){
            ret = 0;
            printf("El nombre no debe tener n\243meros");
        }        
    }
    
    for( i = 0; i < pos && ret; i++){
        if(strcasecmp(nombre[pos],nombre[i]) == 0){
            ret = 0;
            printf("El nombre del vendedor ya existe\n");
        }
    }
    return ret;
}
void pedirVend( char nombre[5][25] ){
    int i,j;
    for( i = 0; i < 4; i++){
        printf("Escriba el nombre del %d vendedor\n",i);
        scanf("%21s", &nombre[i]);        
        if(validarVend(nombre,i) == 0){
            i--;
        }
    }
}

void pedirProd( char nombreProd[5][25] ){
    int i,j;
    for( i = 0; i < 5; i++){
        printf("Escriba el nombre del %d producto\n",i);
        scanf("%21s", &nombreProd[i]);        
        if(validarVend(nombreProd,i) == 0){
            i--;
        }
    }
}
int validarProd(char nombreProd[6][25], int pos){
    int ret = 1, i = 0;;
    if(strlen(nombreProd[pos]) > 20){
        ret = 0;
        printf("El producto debe tener como m\240ximo 20 caracteres\n");
    }
    for(i = 0; i < strlen(nombreProd[pos]) && ret; i++){
        if(!isalpha(nombreProd[pos][i])){
            ret = 0;
            printf("El producto no debe tener n\243meros");
        }        
    }
    
    for( i = 0; i < pos && ret; i++){
        if(strcasecmp(nombreProd[pos],nombreProd[i]) == 0){
            ret = 0;
            printf("El nombre del producto ya existe\n");
        }
    }
    return ret;
}


float pedriVale(char nombresVend[5][25],char nombresProd[6][25], int* fila, int* col){
    int i = 0, valid=0;
    char nomb[21];
    printf("Introduzca el vale\n");
    printf("Introduzca el n\243mero del vendedor\n");
    for(int i = 1; i <= 4; i++){
        printf("%d-%s",i,nombresVend[i]);
    }
    do{
        valid =0;
        scanf("%2s",nomb);
        if(strlen(nomb)>1){
            valid = 1; 
        }
        if(!isalnum(nomb[0])){
            valid = 1;
        }
        if(atoi(nomb) > 4){
            valid = 1;
        }
        if(valid != 0 ){
            printf("Intrduzca un n\143mero entre 1 y 4\n");
        }
    }while(valid != 0);
    *fila = atoi(nomb)-1;

    printf("Introduzca el n\143mero del producto\n");
    
    for( i = 1; i <= 5; i++){
        printf("%d-%s",i,nombresProd[i]);
    }
    do{
        valid =0;
        scanf("%2s",nomb);
        if(strlen(nomb)>1){
            valid = 1; 
        }
        if(!isalnum(nomb[0])){
            valid = 1;
        }
        if(atoi(nomb) > 5){
            valid = 1;
        }
        if(valid != 0 ){
            printf("Intrduzca un n\143mero entre 1 y 5\n");
        }
    }while(valid != 0);
    *col = atoi(nomb)-1;
    printf("Intrdozca el valor de ventas\n");
    do{
        valid =0;
        scanf("%2s",nomb);
        if(strlen(nomb)>5){
            valid = 1; 
        }
        for(i = 0; i < strlen(nomb); i++){
            if(!isalnum(nomb[i])){
                valid = 1;
            }
        }
        
        if(valid != 0 ){
            printf("Intrduzca un n\143mero entre 0 y 10000\n");
        }
    }while(valid != 0);
    return atof(nomb);
}
void mostrarVend(char nombresVend[5][25],int pos){
    printf("El primer vendedor que posee mayor valor de venta es %s\n",nombresVend[pos]);
}
void mostrarProd(char nombresProd[6][25],int pos,int val){
    printf("El nombre del primer producto con mayores ventas en el mes es %s y su valor correspondiente es %d\n",nombresProd[pos],val);
}
void mostrarVal(float z){
    printf("El mayor valor es %f\n",z);
}


void mostrarTabla(float total[6][7],char vend[5][25],char prod[6][25]){
    printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s \n","PRODUCTOS",vend[1],vend[2],vend[3],vend[4],vend[5],"TOTAL");
    int i;
    for(i=1;i<6;i++){
        if(i==5)
            printf("%-20s","TOTAL");
        else
            printf("%-20s",prod[i]);
        printf(" %-20.2f %-20.2f %-20.2f %-20.2f %-20.2f %-20.2f\n",total[i][1],total[i][2],total[i][3],total[i][4],total[i][5],total[i][6]);
    }

}
void imprimirTabla(float total[6][5],char vend[5][25],char prod[6][25]){
    printf("%-20s %-20s %-20s %-20s %-20s %-20s \n","Vendedores",vend[1],vend[2],vend[3],vend[4],"TOTAL");
    int i;
        for(i=0;i<6;i++){
            if(i==6)
                printf("%-20s","TOTAL");
            else
                printf("%-20s",prod[i]);
            printf(" %-20.2f %-20.2f %-20.2f %-20.2f %-20.2f \n",total[i][0],total[i][1],total[i][2],total[i][3],total[i][4]);
        }
}
int main(){
    char nombresVend[5][25];
    char nombresProd[6][25];
    float sales[6][5];
    int i,j,pos1,pos2;
    for(i=0;i<6;i++)
        for(j=0;j<5;j++)
            sales[i][j]=0;

    pedirVend(nombresVend);
    pedirProd(nombresProd);
    for(i = 0;i<30;i++){
        
        actualizar(pos1,pos2,pedriVale(nombresVend,nombresProd,&pos1,&pos2),sales);
    }
    mostrarVal(buscarMayorValor(sales));
    mostrarVend(nombresVend,buscarMayorVend(sales));
    float z = buscarMayorProd(&pos1,sales);
    mostrarProd(nombresProd,z,pos1);
    
}
