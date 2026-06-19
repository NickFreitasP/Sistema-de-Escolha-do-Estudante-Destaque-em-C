# Sistema de Escolha do Estudante Destaque

Trabalho prático desenvolvido em C ANSI para a disciplina de Algoritmos e Programação.

## Objetivo

O sistema realiza o cadastro de estudantes, calcula um índice acadêmico com base na nota do TCC e na média das disciplinas, verifica a elegibilidade para concorrer ao destaque e identifica o estudante destaque da turma.

---

## Regras de Negócio

### Cálculo do Índice

O índice é calculado pela fórmula:

```text
indice = (notaTCC * 0.4) + (mediaDisciplinas * 0.6)
```

### Regra de Elegibilidade

Um estudante é considerado apto ao destaque quando:

```text
notaTCC >= mediaDisciplinas
```

Caso nenhum estudante esteja apto, o sistema informa que não há estudante destaque.

Caso dois ou mais estudantes aptos possuam o maior índice, o sistema informa empate.

---

## Estruturas Utilizadas

### Struct Estudante

```c
typedef struct Estudante
{
    char nome[50];
    float notaTCC;
    float mediaDisciplinas;
    float indice;
    int aptoDestaque;
    int faixaIndice;
} Estudante;
```

### Vetor de Estudantes

```c
Estudante estudantes[MAX_ESTUDANTES];
```

Responsável por armazenar todos os estudantes cadastrados.

### Matriz de Resumo

```c
int resumoIndices[4][2];
```

Utilizada para armazenar a quantidade de estudantes em cada faixa de índice.

---

## Faixas de Índice

| Código | Classificação | Intervalo      |
| ------ | ------------- | -------------- |
| 1      | Baixo         | 0.00 até 5.99  |
| 2      | Médio         | 6.00 até 7.49  |
| 3      | Alto          | 7.50 até 8.99  |
| 4      | Excelente     | 9.00 até 10.00 |

---

# Documentação das Funções

## lerQuantidadeEstudantes

```c
int lerQuantidadeEstudantes(int max_estudantes);
```

Responsável por solicitar e validar a quantidade de estudantes.

### Retorno

Quantidade válida entre 1 e 30.

---

## lerNotaValida

```c
float lerNotaValida();
```

Solicita uma nota ao usuário e garante que esteja entre 0 e 10.

### Retorno

Nota válida informada pelo usuário.

---

## calcularIndice

```c
float calcularIndice(float notaTCC, float mediaDisciplinas);
```

Calcula o índice acadêmico do estudante.

### Parâmetros

* notaTCC
* mediaDisciplinas

### Retorno

Índice calculado.

---

## verificarAptoDestaque

```c
int verificarAptoDestaque(float notaTCC, float mediaDisciplinas);
```

Verifica se o estudante está apto ao destaque.

### Retorno

* 1 → apto
* 0 → não apto

---

## classificarIndice

```c
int classificarIndice(float indice);
```

Classifica o índice em uma das quatro faixas definidas.

### Retorno

Código da faixa:

* 1 → Baixo
* 2 → Médio
* 3 → Alto
* 4 → Excelente

---

## inicializarResumoIndices

```c
void inicializarResumoIndices(int resumoIndices[4][2]);
```

Inicializa a matriz de resumo.

### Objetivo

* Preencher os códigos das faixas.
* Inicializar as quantidades com zero.

---

## cadastrarEstudantes

```c
void cadastrarEstudantes(
    Estudante estudantes[],
    int quantidade,
    int resumoIndices[4][2]
);
```

Responsável pelo cadastro completo dos estudantes.

### Atividades realizadas

* Leitura do nome.
* Leitura da nota do TCC.
* Leitura da média das disciplinas.
* Cálculo do índice.
* Verificação de aptidão.
* Classificação do índice.
* Atualização da matriz de resumo.

---

## encontrarIndiceDestaque

```c
int encontrarIndiceDestaque(
    Estudante estudantes[],
    int quantidade
);
```

Procura o estudante apto com maior índice.

### Retorno

* Posição do estudante destaque.
* -1 caso nenhum estudante esteja apto.

---

## verificarEmpateDestaque

```c
int verificarEmpateDestaque(
    Estudante estudantes[],
    int quantidade,
    float maiorIndice
);
```

Verifica se mais de um estudante apto possui o maior índice.

### Retorno

* 1 → Existe empate.
* 0 → Não existe empate.

---

## calcularMediaIndices

```c
float calcularMediaIndices(
    Estudante estudantes[],
    int quantidade
);
```

Calcula a média geral dos índices.

### Retorno

Média dos índices de todos os estudantes.

---

## encontrarMenorIndice

```c
float encontrarMenorIndice(
    Estudante estudantes[],
    int quantidade
);
```

Encontra o menor índice do conjunto de estudantes.

### Retorno

Menor índice encontrado.

---

## contarEstudantesAptos

```c
int contarEstudantesAptos(
    Estudante estudantes[],
    int quantidade
);
```

Conta quantos estudantes estão aptos ao destaque.

### Retorno

Quantidade de estudantes aptos.

---

## contarEstudantesNaoAptos

```c
int contarEstudantesNaoAptos(
    Estudante estudantes[],
    int quantidade
);
```

Conta quantos estudantes não estão aptos ao destaque.

### Retorno

Quantidade de estudantes não aptos.

---

## exibirRankingTresMelhores

```c
void exibirRankingTresMelhores(
    Estudante estudantes[],
    int quantidade
);
```

Exibe os três estudantes aptos com maiores índices.

### Saída

```text
1o Lugar: Nome - Indice
2o Lugar: Nome - Indice
3o Lugar: Nome - Indice
```

---

## exibirRelatorio

```c
void exibirRelatorio(
    Estudante estudantes[],
    int quantidade,
    int resumoIndices[4][2]
);
```

Gera o relatório final do sistema.

### Informações exibidas

* Dados de cada estudante.
* Índices calculados.
* Situação de aptidão.
* Resumo por faixa de índice.
* Resultado do estudante destaque.

---

## Conceitos Aplicados

* Variáveis e constantes
* Estruturas condicionais
* Estruturas de repetição
* Vetores
* Matrizes
* Structs
* Funções
* Modularização
* Validação de entrada de dados
* Processamento de informações acadêmicas

---

## Autor

Nicholas Panonko

Projeto acadêmico desenvolvido para a disciplina de Algoritmos e Programação.
