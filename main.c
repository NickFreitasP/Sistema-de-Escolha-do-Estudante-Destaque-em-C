#include <stdio.h>
#include <stdlib.h>

/**
* Solicita e valida a quantidade de estudantes a serem cadastrados.
* A função deve aceitar apenas valores entre 1 e MAX_ESTUDANTES.
* Caso o valor informado seja inválido, deve solicitar novamente.
*
* @return Quantidade válida de estudantes.
*/

int lerQuantidadeEstudantes(int max_estudantes)
{
    // VÁRIAVEL A SER RETORNADA NA FUNÇÃO
    int quantidadeEstudantes;

    // VÁRIAVEL PARA VALIDAÇÃO DO LAÇO WHILE
    int valido = 0;

    while(valido == 0)
    {

        scanf("%d", &quantidadeEstudantes);

        if(quantidadeEstudantes >= 1 && quantidadeEstudantes <= max_estudantes)
        {
            valido = 1;
        }
        else
        {
            printf("Valor invalido!\n");
        }
    }

    return quantidadeEstudantes;
}


/**
* Solicita e valida uma nota acadêmica.
* A nota deve estar no intervalo de 0 a 10.
* Caso o usuário informe valor inválido, deve solicitar novamente.
*
* @return Nota válida informada pelo usuário.
*/
float lerNotaValida()
{
    float nota;

    int valido = 0;

    while(valido == 0)
    {
        scanf("%f", &nota);

        if(nota >= 0 && nota <= 10)
        {
            valido = 1;
        }
        else
        {
            printf("Nota invalida! Digite um valor entre 0 e 10: ");
        }
    }

    return nota;
}

/**
* Calcula o índice do estudante usando média ponderada.
* A nota de TCC tem peso 40% e a média das disciplinas tem peso 60%.
*
* @param notaTCC Nota do Trabalho de Conclusão de Curso.
* @param mediaDisciplinas Média das demais disciplinas.
* @return Índice calculado do estudante.
*/
float calcularIndice(float notaTCC, float mediaDisciplinas){

   return ( notaTCC * 0.4 ) + ( mediaDisciplinas * 0.6) ;

}

/**
* Verifica se o estudante está apto a concorrer ao destaque.
* Um estudante é apto quando sua nota de TCC é maior ou igual à média
* das demais disciplinas.
*
* @param notaTCC Nota do Trabalho de Conclusão de Curso.
* @param mediaDisciplinas Média das demais disciplinas.
* @return 1 se o estudante estiver apto; 0 caso contrário.
*/
int verificarAptoDestaque(float notaTCC, float mediaDisciplinas){

  if( notaTCC  >= mediaDisciplinas ){

     return 1;
  }
  else{

    return 0;

  }

}

/**
* Classifica o índice calculado em uma faixa numérica.
* Código 1: índice baixo, de 0,00 a 5,99.
* Código 2: índice médio, de 6,00 a 7,49.
* Código 3: índice alto, de 7,50 a 8,99.
* Código 4: índice excelente, de 9,00 a 10,00.
*
* @param indice Índice calculado do estudante.
* @return Código da faixa de índice.
*/
int classificarIndice(float indice)
{
    if(indice < 6.0)
    {
        return 1;
    }
    else if(indice < 7.5)
    {
        return 2;
    }
    else if(indice < 9.0)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}



int main()
{
    // DECLARAÇÃO DA CONSTANTE NÚMERO MÁXIMO DE ESTUDANTES CADASTRADOS
    const int MAX_ESTUDANTES = 30;


    return 0;
}
