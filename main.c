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


int main()
{
    // DECLARAÇÃO DA CONSTANTE NÚMERO MÁXIMO DE ESTUDANTES CADASTRADOS
    const int MAX_ESTUDANTES = 30;


    return 0;
}
