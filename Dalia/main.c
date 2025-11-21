#include<stdio.h>
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
        pedriVale(nombresVend,nombresProd,pos1,pos2);
        actualizar(pos1,pos2,sales);
    }
    mostrarVal(buscarMayorValor(sales));
    mostrarVend(buscarMayorVend(sales));
    float z = buscarMayorProd(&pos1,sales);
    mostrarProd(nombresProd,z,pos1);
    
}