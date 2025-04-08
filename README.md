# Problema
<html> <p> 
O fatorial de um numero inteiro positivo N, denotado por N!, é definido como o produto dos inteiros positivos menores do que ou iguais a N. Por exemplo 4! = 4 x 3 x 2 x 1 = 24. <br>
Dado um inteiro positivo N, você deve escrever um programa para determinar o menor número k tal que N = a1! + a2! + ... + ak!, onde cada ai, para 1 <= i <= k, é um numero inteiro positivo. <br>
Por exemplo, para N = 10 a resposta é 3, pois é possível escrever N como a soma de três numeros fatoriais: 10 = 3! + 2! + 2!. Para N = 25 a resposta é 2, pois é possível escrever N como a soma de dois numeros fatoriais: 25 = 4! + 1!. <br> <br>
Entrada: A entrada consiste de uma única linha que contém um inteiro N (1 <= N = 100000). <br>
Saída: Seu programa deve retornar um inteiro representando a menor quantidade de núumeros fatoriais cuja soma é igual ao valor de N.
</p> </html>

# Modelagem do Problema
## Variáveis 
- N: Um número lido do arquivo de entrada que é utilizado para determinar o valor de k.
- k: Um contador que armazena o número de fatoriais necessários para alcançar N.
- fatoriais[10]: Um vetor que armazena os fatoriais de 0 até 9.
- n: Um inteiro para achar o fatorial do mesmo.
- resultado: retorna o valor do fatorial e também é utilizado para voltar o valor k de um numero N.

## Funções:
- int fatorial(int n): Calcula o fatorial de um número n.
- int menor_k(int N): Determina o menor número k tal que a soma de k fatoriais seja igual a N.
- fscanf(ptr_in_file, "%d", &N): Lê o valor de N do arquivo de entrada.
- fprintf(fwsolptr, "%d\n", resultado): Escreve o resultado no arquivo de solução

## Estruturas:
- O código utiliza arquivos de entrada e saída para ler o número N e para gravar a solução.
- O diretório de saída é especificado pela constante OUTPUT_DIR, e o nome do arquivo de solução é especificado pela constante SOLUTION_FILE.

# Solução
O algoritmo utilizado no código é baseado no processo para determinar o menor k:
- Pré-calcular os fatoriais de 0 a 9: O código armazena os fatoriais de 0 até 9 em um vetor fatoriais[], evitando recalcular esses valores repetidamente.
- Subtração sequencial: A função menor_k() tenta subtrair os fatoriais de 9! até 0! de N até que o valor de N se torne negativo. A cada subtração, o contador k é incrementado.
- Gravar o resultado: O número k encontrado é então escrito em um arquivo de solução.

### Detalhes do algoritmo:
- O fatorial de um número n é calculado iterativamente na função fatorial(int n)
- A função menor_k(int N) realiza a subtração sequencial dos fatoriais precomputados, começando de 9! e indo até 0!.
- O arquivo de entrada contém um número N, e o arquivo de saída contém o menor k que resolve o problema.

# Execução
- Para compilar o código: entrar na pasta WARMUP utilizando "cd warmup" e depois usar o comando: gcc -Wall warmup.c solver/warmup_solver.c -o warmup
- Para executar o código: ./warmup

# Desempenho
Instâncias 

Sucesso:32

Falhas:0

Observação: O código base do WARMUP teve que ser alterado por conta duas últimas instâncias, que apresentavam falhas independente da alteração que era feita no código.

![Image](https://github.com/user-attachments/assets/3e5e9f20-ee7e-4111-ae4f-33f45fcb5814)
