/*Programa para calcular a Conjectura de Christian Goldbach: "Todo inteiro par maior que 2 pode ser escrito como a soma de 2 números primos".*/
//Autor: Gabriel Queiroz

#include <stdio.h>

//Função para verificar se o numero digitado é valido ou não
int verificarParImpar (int numero){
   if(numero % 2 == 0 && numero > 2){
      return (1);
   }
   else {
      return (0);
   }
}


//Função para calcular quantos primos tem entre 2 e o numero digitado
int quantosPrimos (int numerodigitado){

    int quantidade = 0; /*Quantidade de numeros com divisores*/
    int quantidadefinal = 0; /*Quantidade de numeros primos*/

    for(int numerador = 2; numerador < numerodigitado; numerador++){
        for(int denominador = 1; denominador <= numerador; denominador++){
            if(numerador % denominador == 0){
                quantidade++; 
            }
            if(quantidade == 2 && denominador == numerador){
                quantidadefinal++;  
            }
        }
        quantidade = 0; //resetando a variável
    }
    return (quantidadefinal);
}


//Função para calcular a Conjectura
void verificarConjectura (int numdigitado, int quantprimo){

    int vet[quantprimo]; /*vetor que vai armazenar os numeros primos, a quantidade de posições foi calculada na função que calculou a quantidade de numeros primos de 2 ate o numero digitado */
    int quantidade = 0; /*vai registrar a quantidade de vezes que um numero é divisível. Se um numero tem somente dois divisores (1 e ele mesmo), então é primo*/
    int i = 0; //posicao de um vetor
    int posicao2 = 0; //posicao de um vetor
    int posicaoreserva = 0; //variavel para ajudar a redefinir a variavel 'posicao2' que fica acumulando nos loops posteriores

    for (int numerador = 2; numerador < numdigitado; numerador++){
        for(int denominador = 1; denominador <= numerador; denominador++){

            if(numerador % denominador == 0){
                quantidade++;
            }

            if(quantidade == 2 && denominador == numerador){ 
                vet[i] = numerador; //armazena o numero primo no vetor
                i++;
            }
        }
        quantidade = 0; //reseta a variável para poder mensurar o próximo número
    }

    printf("-> Resultado <-\n\n");
    printf("Numero(n)\tdecomposicao\n");
    printf("%d", numdigitado);

    /*Estrutura para verificar se dois números primos são iguais ao numero par digitado*/
    for(int posicao = 0; posicao < quantprimo; posicao++){
        for(posicao2; posicao2 < quantprimo; posicao2++){

            if(vet[posicao] + vet[posicao2] == numdigitado){
     
                printf("\t\t %d+%d\n", vet[posicao], vet[posicao2]);
            }
        }
        posicaoreserva++;
        posicao2 = posicaoreserva;
    }
}


int main (){

   int num, numVerificado, resultadoDeQuantosPrimos, resultadoFinal;
   /*numVerificado: variável que irá armazenar o resultado de se o número digitado é impa ou par */

   printf("A conjectura de GoldBach\n");
   printf("Digite um numero: ");
   scanf("%d", &num);
   printf("\n");

   numVerificado = verificarParImpar(num);

   if(numVerificado == 1){

      resultadoDeQuantosPrimos = quantosPrimos(num); 
      verificarConjectura(num, resultadoDeQuantosPrimos);
   }
   else{
     printf("O número digitado é impar ou menor que 2\n");
   }

   return 0;

}
