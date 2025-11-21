
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
typedef struct Chrom      
   {
    short int bit[6];
      int fit;
   }chrom; 


int x(chrom popcurrent)       
{
 int z;
   z=(popcurrent.bit[0]*1)+(popcurrent.bit[1]*2)+(popcurrent.bit[2]*4)+(popcurrent.bit[3]*8)+(popcurrent.bit[4]*16);
   if(popcurrent.bit[5]==1)
   z=z*(-1);                          
    return(z);                        
 }                 

int y(int x)                          
{
 int y;
   y=-(x*x)+5;                    
   return(y);             
}    


void crossover(chrom popnext[4])
{
    int random;
    int i;
    random = rand();
    random = ((random%5)+1);

    for(i=0;i<random;i++){
        popnext[2].bit[i] = popnext[0].bit[i];
        popnext[3].bit[i] = popnext[1].bit[i];
    }

    for(i=random;i<6;i++){
        popnext[2].bit[i] = popnext[1].bit[i];
        popnext[3].bit[i] = popnext[0].bit[i];
    }

     for (i = 0; i < 4; i++) {
        popnext[i].fit = y(x(popnext[i]));
    }

    for (i = 0; i < 4; i++) {
        printf("\nCross Over popnext[%d]=%d%d%d%d%d%d    value=%d      fitness = %d ", i,
        popnext[i].bit[5], popnext[i].bit[4], popnext[i].bit[3], popnext[i].bit[2], popnext[i].bit[1], popnext[i].bit[0], x(popnext[i]), popnext[i].fit);
    }

}

int main() {
    chrom array[4];
    for(int i = 0; i < 4; i++ )
    {
        for(int j = 0; j < 4; j++ )
            array[i].bit[j] = rand()%2;
        array[i].fit = rand()%20;
    }
    crossover(array);
   
    return 0;
}
