#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int cod[10][10], i, j, cont = 0, codU[10]; 
    srand(time(NULL));
    for (i = 0; i < 10; i++){                                      
        for (j = 0; j < 10; j++){                              
            cod[i][j] = rand() %2;                               
        } 
    }  
    for (i = 0; i < 10; i++){                                      
        for (j = 0; j < 10; j++){                              
            printf ("%d ", cod[i][j]);
        }
        printf ("\n");
    }
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if (cod[j][i] == 1){
                cont++;
            }      
        }
        if (cont >= 5){
            codU[i] = 1;
        }else{
            codU[i] = 0;
        }
        cont = 0;  
    }
    printf ("\nCODIGO UNICO: ");
    for (i = 0; i < 10; i++){
        printf ("%d ", codU[i]);
    }
}
