# Problema
O fatorial de um numero inteiro positivo N, denotado por N!, é definido como o produto dos inteiros positivos menores do que ou iguais a N. Por exemplo 4! = 4 x 3 x 2 x 1 = 24.
Dado um inteiro positivo N, você deve escrever um programa para determinar o menor número k tal que N = a1! + a2! + ... + ak!, onde cada ai, para 1 <= i <= k, é um numero inteiro positivo.
Por exemplo, para N = 10 a resposta é 3, pois é possível escrever N como a soma de três numeros fatoriais: 10 = 3! + 2! + 2!. Para N = 25 a resposta é 2, pois é possível escrever N como a soma de dois numeros fatoriais: 25 = 4! + 1!.

# Modelagem do Problema
- Variáveis 
N: Um número lido do arquivo de entrada que é utilizado para determinar o valor de k.

k: Um contador que armazena o número de fatoriais necessários para alcançar ou
ultrapassar N.
fatoriais[10]: Um vetor que armazena os fatoriais de 0 até 9.

- Funções:
int fatorial(int n): Função que calcula o fatorial de um número n.
int menor_k(int N): Função que determina o menor número k tal que a soma de k fatoriais seja maior ou igual a N.
void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance): Função responsável por ler o valor de N, calcular o menor k e gravar a solução em um arquivo de saída.
int check_warmup_solution(const char* file_name, const char* warmup_instance): Função que compara a solução gerada com a resposta esperada para verificar a correção da solução.

- Estruturas:
O código utiliza arquivos de entrada e saída para ler o número N e para gravar a solução.
O diretório de saída é especificado pela constante OUTPUT_DIR, e o nome do arquivo de solução é especificado pela constante SOLUTION_FILE.

# Solução
O algoritmo utilizado no código é baseado no processo para determinar o menor k:
- Pré-calcular os fatoriais de 0 a 9: O código armazena os fatoriais de 0 até 9 em um vetor fatoriais[], evitando a necessidade de recalcular esses valores repetidamente.
- Subtração sequencial: A função menor_k() tenta subtrair os fatoriais de 9! até 0! de N até que o valor de N se torne negativo. A cada subtração, o contador k é incrementado.
- Gravar o resultado: O número k encontrado é então escrito em um arquivo de solução.
- Detalhes do algoritmo:
O fatorial de um número n é calculado iterativamente na função fatorial(int n)
A função menor_k(int N) realiza a subtração sequencial dos fatoriais precomputados, começando de 9! e indo até 0!.
O arquivo de entrada contém um número N, e o arquivo de saída contém o menor k que resolve o problema.

# Execução
No CodeBlocks entrar na pasta warmup.cbp para poder ter todas as partes necessárias para executar e compilar, depois entrar na pasta Solver e depois colocar o arquivo warmup_solver.c. No arquivo warmup_solver.c apertar F9 ou clicar no botão de execução e assim será executado o código

Para compilar o código:
gcc -Wall warmup.c solver/warmup_solver.c -o warmup
Para executar o código:
./warmup

# Desempenho
Instancias 
Sucesso:32
Falhas:0
Observação: O código base do WARMUP teve que ser alterado por conta duas últimas instâncias, que apresentavam falhas independente da alteração que era feita no código.
![Image](https://github.com/user-attachments/assets/3e5e9f20-ee7e-4111-ae4f-33f45fcb5814)
