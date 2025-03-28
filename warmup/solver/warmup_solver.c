#include "../include/warmup_solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OUTPUT_DIR "output/"
#define SOLUTION_FILE "solution.txt"

// Função para calcular o fatorial de um número
int fatorial(int n) {
    if (n == 0 || n == 1) return 1;
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função para encontrar o menor k
int menor_k(int N) {
    int k = 0;
    // Lista de fatoriais precomputados até 9! (362880)
    int fatoriais[10];
    for (int i = 0; i < 10; i++) {
        fatoriais[i] = fatorial(i);
    }

    // Começamos do maior fatorial possível e subtraímos de N
    for (int i = 9; i >= 0; i--) {
        while (N >= fatoriais[i]) {
            N -= fatoriais[i];
            k++;
        }
    }

    return k;
}

void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {

    FILE *fwsolptr;
    char out_file[100];

    out_file[0] = '\0';
    strcat(out_file, warmup_instance);
    strcat(out_file, OUTPUT_DIR);
    strcat(out_file, file_name);

    // Creating solution file
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    /* *****************************************
      Replace this code by your warmup solution
      ****************************************** */
    int N;
    fscanf(ptr_in_file, "%d", &N); // Lê o valor de N do arquivo de entrada

    int resultado = menor_k(N); // Calcula o menor k
    fprintf(fwsolptr, "%d\n", resultado); // Escreve o resultado no arquivo de solução
    /* *************************************** */

    fclose(fwsolptr);
}

int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution;
    char answer_line[100], solution_line[100], answer_file[100];
    int is_correct = 1;

    answer_file[0] = '\0';
    strcat(answer_file, warmup_instance);
    strcat(answer_file, OUTPUT_DIR);
    strcat(answer_file, file_name);

    // Opening answer file
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Opening solution file
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Reading from the answer file and comparing with the solution file
    while (fgets(answer_line, 100, fanswer)) {

        fgets(solution_line, 100, fsolution);

        // Remove o caractere de nova linha (\n) das strings
        answer_line[strcspn(answer_line, "\n")] = '\0';
        solution_line[strcspn(solution_line, "\n")] = '\0';

        if (strcmp(answer_line, solution_line)) {
            is_correct = 0;
            break;
        }
    }

    fclose(fanswer);
    fclose(fsolution);

    return is_correct;
}
