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
        printf("Digite a quantidade de estudantes a serem cadastrados: ");
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


int main()
{
    // DECLARAÇÃO DA CONSTANTE NÚMERO MÁXIMO DE ESTUDANTES CADASTRADOS
    const int MAX_ESTUDANTES = 30;

    // DEFINIÇÃO DA VÁRIAVEL QUE ARMAZENA A QUANTIDADE DE ESTUDANTES
    int quantidadeEstudantes;

    // CHAMADA DA FUNÇÃO QUANTIDADE DE ESTUDANTES E ARMAZENAMENTO DENTRO DA VÁRIAVEL
    quantidadeEstudantes = lerQuantidadeEstudantes(MAX_ESTUDANTES);


    printf("Quantidade: %d\n", quantidadeEstudantes);

    return 0;
}
