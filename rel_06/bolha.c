#include "geracao.h"
#include "bolha.h"
#include <stdio.h>
//=============================================================================
void bolha(int *array, int n){
    int i, j;
    int trocas=0, comp=0;
    for (i = (n - 1); i > 0; i--) {
      for (j = 0; j < i; j++) {
        comp++;
         if (array[j] > array[j + 1]) {
           trocas++;
            swap(&array[j], &array[j + 1]);
         }
      }
   }
   printf("Comp: %i - Trocas: %i", comp, trocas);
}
//=============================================================================
