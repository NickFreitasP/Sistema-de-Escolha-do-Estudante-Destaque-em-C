#include <stdio.h>
#include <stdlib.h>



typedef struct Estudante
{

 char nome[50];
 float notaTCC;
 float mediaDisciplinas;
 float indice;
 int aptoDestaque;
 int faixaIndice;

}

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


/**
* Inicializa a matriz de resumo dos índices.
* A coluna 0 deve armazenar os códigos das faixas.
* A coluna 1 deve iniciar com zero, representando a quantidade
* de estudantes em cada faixa.
*
* @param resumoIndices Matriz 4x2 de resumo por faixa de índice.
*/
void inicializarResumoIndices(int resumoIndices[4][2])
{
    int i;

    for(i = 0; i < 4; i++)
    {
        resumoIndices[i][0] = i + 1;
        resumoIndices[i][1] = 0;
    }
}

/**
* Realiza o cadastro dos estudantes.
* Para cada estudante, deve ler nome, nota de TCC e média das disciplinas.
* Também deve calcular o índice, verificar se o estudante está apto,
* classificar o índice e atualizar a matriz de resumo.
*
* @param estudantes Vetor de estudantes que será preenchido.
* @param quantidade Quantidade de estudantes a cadastrar.
* @param resumoIndices Matriz de resumo por faixa de índice.
*/
void cadastrarEstudantes(Estudante estudantes[], int quantidade, int resumoIndices[4][2]){

    for(int i = 0 ; i < quantidade ; i++ ){

          printf("Cadastro de Estudantes \n");

          // ARMAZENA O NOME DO ESTUDANTE
          printf("Nome:");
          scanf("%s",estudantes[i].nome);

          // ARMAZENA A NOTA DO TCC
          printf("\nNota do TCC :");
          estudantes[i].notaTCC = lerNotaValida();


          // ARMAZENA A MEDIA DAS DISCIPLINAS
          printf("\nMédias das Disciplinas :");
          estudantes[i].mediaDisciplinas = lerNotaValida();

         // CALCULO DO INDICE ARMAZENAMENTO DO INDICE DENTRO DO STRUCT
         estudantes[i].indice = calcularIndice(estudantes[i].notaTCC,estudantes[i].mediaDisciplinas);

         // VERIFICA SE O ESTUDANTE ESTÁ APTO / ARMAZENA A CONDIÇÃO DE APTO DENTRO DO STRUCT
         estudantes[i].aptoDestaque = verificarAptoDestaque(estudantes[i].notaTCC,estudantes[i].mediaDisciplinas);


         // CLASSIFICAÇÃO DO INDICE E ARMAZENAMENTO DENTRO DO STRUCT
         estudantes[i].faixaIndice =  classificarIndice(estudantes[i].indice);

         // ATUALIZAR A MATRIZ DE RESUMO
         for(int j = 0 ; j < 4 ; j++){

            if(estudantes[i].faixaIndice == resumoIndices[j][0]){

                resumoIndices[j][1]++;
            }
         }

    }

}

/**
* Encontra a posição do estudante destaque no vetor.
* A função deve considerar apenas estudantes aptos.
* Deve retornar a posição do estudante apto com maior índice.
* Se nenhum estudante estiver apto, deve retornar -1.
*
* @param estudantes Vetor de estudantes cadastrados.
* @param quantidade Quantidade de estudantes cadastrados.
* @return Índice do vetor onde está o estudante destaque ou -1.
*/
int encontrarIndiceDestaque(Estudante estudantes[], int quantidade){

  int indiceVetor = -1;

  for(int i = 0 ; i < quantidade ; i++ ){

     if(i == 0 && estudantes[i].aptoDestaque == 1){

         indiceVetor = i ;
     }
     else( estudantes[i].aptoDestaque == 1 && estudantes[i].indice > estudantes[i-1].indice ){
        indiceVetor = i ;
     }

     return indiceVetor;
  }




}

int main()
{
    // DECLARAÇÃO DA CONSTANTE NÚMERO MÁXIMO DE ESTUDANTES CADASTRADOS
    const int MAX_ESTUDANTES = 30;


    return 0;
}
