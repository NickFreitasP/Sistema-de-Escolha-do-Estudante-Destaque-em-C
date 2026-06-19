# Sistema de Escolha do Estudante Destaque

Trabalho prático desenvolvido em linguagem C ANSI para a disciplina de Algoritmos e Programação.

## Objetivo

O sistema realiza o cadastro de estudantes, calcula um índice acadêmico com base na nota do TCC e na média das disciplinas, verifica a elegibilidade para concorrer ao destaque e identifica o estudante destaque da turma.

## Fórmula do Índice

O índice é calculado utilizando média ponderada:

indice = (notaTCC * 0.4) + (mediaDisciplinas * 0.6)

## Regra de Elegibilidade

Um estudante é considerado apto ao destaque quando:

notaTCC >= mediaDisciplinas

## Funcionalidades

* Cadastro de até 30 estudantes.
* Validação da quantidade de estudantes.
* Validação das notas informadas.
* Cálculo automático do índice acadêmico.
* Verificação de aptidão ao destaque.
* Classificação dos estudantes por faixa de índice.
* Geração de relatório completo.
* Identificação do estudante destaque.
* Verificação de empate entre estudantes aptos.
* Exibição dos três melhores estudantes aptos.
* Estatísticas gerais dos estudantes.

## Estruturas Utilizadas

### Struct

```c
typedef struct Estudante {
    char nome[50];
    float notaTCC;
    float mediaDisciplinas;
    float indice;
    int aptoDestaque;
    int faixaIndice;
} Estudante;
```

### Vetor

```c
Estudante estudantes[MAX_ESTUDANTES];
```

### Matriz

```c
int resumoIndices[4][2];
```

## Faixas de Índice

| Código | Faixa     | Intervalo    |
| ------ | --------- | ------------ |
| 1      | Baixo     | 0,00 a 5,99  |
| 2      | Médio     | 6,00 a 7,49  |
| 3      | Alto      | 7,50 a 8,99  |
| 4      | Excelente | 9,00 a 10,00 |

## Tecnologias

* Linguagem C ANSI
* Biblioteca stdio.h
* Biblioteca stdlib.h

## Como Executar

1. Compile o programa:

```bash
gcc main.c -o programa
```

2. Execute:

```bash
./programa
```

No Windows:

```bash
programa.exe
```

## Conceitos Aplicados

* Entrada e saída de dados
* Estruturas condicionais
* Estruturas de repetição
* Funções
* Vetores
* Matrizes
* Structs
* Modularização
* Processamento de dados acadêmicos

## Autor

Nicholas Panonko

Desenvolvido como atividade acadêmica da disciplina de Algoritmos e Programação.
