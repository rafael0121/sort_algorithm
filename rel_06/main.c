#include "bolha.h"
#include "insercao.h"
#include "selecao.h"
#include "geracao.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
//=============================================================================

//Declaração de funções
void getMemory();
void call_bolha();
void call_insercao();
void call_selecao();
void exec_todos();

int main(int argc, char *argv[]){

    int ch=-1, ch_gen=-1;
    
    //loop-While para tornar o programa continuo
    while(ch != 0){
        printf("\n\t>Laboratorio-06<\n Ordenacao Algoritmos Quadraticos\n\n");
        
        //Imprime o menu
        printf("-> MENU <-\n");
        printf("1.Bolha\n");
        printf("2.Insercao\n");
        printf("3.Selecao\n");
        printf("4.Todos\n");
        printf("0.Sair");
        printf("\n-> ");
        scanf("%i",&ch);

        //IF para tratar excessões do swtich-case
        if(ch==4){
            exec_todos();
            break;
        }
        if(ch==0||ch>3||ch<0){
            break;
        }
        
        printf("\n\n\n\n\n\n\n\n\n");

        //Imprime o sub-menu
        printf("\n\t>Laboratorio-06<\n Ordenacao Algoritmos Quadraticos\n\n");
        printf("-> SUBMENU <-\n");
        printf("1.Crescente\n");
        printf("2.Decrescente\n");
        printf("3.Aleatorio\n");
        printf("0.Voltar");
        printf("\n-> ");
        scanf("%i",&ch_gen);

        //IF para tratar excessões para a variavel ch_gen
        if(ch_gen>3||ch_gen<0){
            break;
        }
        if(ch_gen==0){
            continue;
        }

        printf("\n\n\n\n\n\n\n\n\n");

        switch (ch){
            case 1:
                call_bolha(ch_gen);
                break;
            case 2:
                call_insercao(ch_gen);
                break;
            case 3:
                call_selecao(ch_gen);
                break;
        }
        
    }

    return 0;
}

//Pega memoria
void getMemory(float* currRealMem) {

    // stores each word in status file
    char buffer[1024] = "";

    // linux file contains this-process info
    FILE* file = fopen("/proc/self/status", "r");  

    if(file==NULL){
        printf("\n=> Error ao abrir arquivo de memoria<=\n");
        return;
    }
    // read the entire file
    while (fscanf(file, " %1023s", buffer) == 1) {
        if (strcmp(buffer, "VmRSS:") == 0) {
            fscanf(file, " %f", currRealMem);
        }
    }
    fclose(file);
}
 
 //Algoritmo bolha
void call_bolha(int ch_gen){

    printf("\nBolha - Algoritimo\n");
    
    float memory;
    clock_t start_time, end_time;
    double cpu_time_used;
    size_t peakSize;
    int *V;

    for(int n = 2000; n <= 1280000; n *= 2){
        FILE* arquivo = fopen("bolha.txt", "a");

        V = malloc(n * sizeof(int));

        switch (ch_gen){
            case 1:
                crescente(V, n);
                break;
            case 2:
                decrescente(V, n);
                break;
            case 3:
                aleatorio(V, n);
                break;
        } 

        //Algoritmo bolha
        start_time = clock();
        bolha(V, n);
        end_time = clock();

        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        getMemory(&memory);

        printf("N = %ld\t Time = %.2f memory %.2f\n", n, cpu_time_used, memory/1000);
        fprintf(arquivo, "\nN = %ld\t Time = %.2f memory %.2f\n", n, cpu_time_used, memory/1000);

        free(V);
        fclose(arquivo);
    }
}

//Algoritmo inserção
void call_insercao(int ch_gen){

    printf("\nInsercao - Algoritimo\n");

    float memory;
    clock_t start_time, end_time;
    double cpu_time_used;
    size_t peakSize;
    int *V;

    for(int n = 2000; n <= 1280000; n *= 2){
        
        FILE* arquivo = fopen("insercao.txt", "a");
        
        V = malloc(n * sizeof(int));

        switch (ch_gen){
            case 1:
                crescente(V, n);
                break;
            case 2:
                decrescente(V, n);
                break;
            case 3:
                aleatorio(V, n);
                break;
        } 
        
        start_time = clock();
        insercao(V, n);
        end_time = clock();

        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        getMemory(&memory);

        printf("N = %ld\t Time = %.2f\t memory = %.2lf\n", n, cpu_time_used, memory/1000);
        fprintf(arquivo, "\nN = %ld\t Time = %.2f memory %.2f\n", n, cpu_time_used, memory/1000);

        free(V);   
        fclose(arquivo);
    }    
}

//Algoritimo selecao
void call_selecao(int ch_gen){

    printf("\nSelecao - Algoritimo\n");

    float memory;
    clock_t start_time, end_time;
    double cpu_time_used;
    size_t peakSize;
    int *V;

    for(int n = 2000; n <= 1280000; n *= 2){
        
        FILE* arquivo = fopen("selecao.txt", "a");
        
        V = malloc(n * sizeof(int));

        switch (ch_gen){_
            case 1:
                crescente(V, n);
                break;
            case 2:
                decrescente(V, n);
                break;
            case 3:
                aleatorio(V, n);
                break;
        } 
        
        start_time = clock();
        selecao(V, n);
        end_time = clock();

        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        getMemory(&memory);

        printf("\tN = %ld\t Time = %.2f\t memory = %.2lf\n", n, cpu_time_used, memory/1000);
        fprintf(arquivo, "\nN = %ld\t Time = %.2f memory %.2f\n", n, cpu_time_used, memory/1000);

        free(V);   
        fclose(arquivo);
    }
}

void exec_todos(){ 
    for(int i=1; i<=3;i++){
        FILE* arquivo = fopen("bolha.txt", "a");
        switch (i){
            case 1:
                fprintf(arquivo, "=>Crescente<=");
                break;
            case 2:
                fprintf(arquivo, "=>Decrescente<=");
                break;
            case 3:
                fprintf(arquivo, "=>Aleatório<=");
                break;
        } 
        fclose(arquivo); 
        call_bolha(i); 
    }
    for(int i=1; i<=3;i++){
        FILE* arquivo = fopen("insercao.txt", "a");
        switch (i){
            case 1:
                fprintf(arquivo, "=>Crescente<=");
                break;
            case 2:
                fprintf(arquivo, "=>Decrescente<=");
                break;
            case 3:
                fprintf(arquivo, "=>Aleatório<=");
                break;
        }
        fclose(arquivo);
        call_insercao(i);
    }
    for(int i=1; i<=3;i++){
        FILE* arquivo = fopen("selecao.txt", "a");
        switch (i){
            case 1:
                fprintf(arquivo, "=>Crescente<=");
                break;
            case 2:
                fprintf(arquivo, "=>Decrescente<=");
                break;
            case 3:
                fprintf(arquivo, "=>Aleatório<=");
                break;
        }
        fclose(arquivo);
        call_selecao(i);
    }
    
}