//1a) Implemente a estrutura de dados para a árvore binária de busca

A estrutura sugerida na imagem é:

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

//1b) Implemente as funções de criação, remoção, busca e inserção


#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Criação de um novo nó
No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

// Inserção na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    else if (valor > raiz->dado)
        raiz->direito = inserir(raiz->direito, valor);
    return raiz;
}

// Busca na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) return raiz;
    if (valor < raiz->dado)
        return buscar(raiz->esquerdo, valor);
    else
        return buscar(raiz->direito, valor);
}

// Função auxiliar para encontrar o menor nó da subárvore
No* menorNo(No* raiz) {
    while (raiz && raiz->esquerdo != NULL)
        raiz = raiz->esquerdo;
    return raiz;
}

// Remoção de um nó
No* remover(No* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->dado)
        raiz->esquerdo = remover(raiz->esquerdo, valor);
    else if (valor > raiz->dado)
        raiz->direito = remover(raiz->direito, valor);
    else {
        // Nó com 0 ou 1 filho
        if (raiz->esquerdo == NULL) {
            No* temp = raiz->direito;
            free(raiz);
            return temp;
        } else if (raiz->direito == NULL) {
            No* temp = raiz->esquerdo;
            free(raiz);
            return temp;
        }

        // Nó com 2 filhos
        No* temp = menorNo(raiz->direito);
        raiz->dado = temp->dado;
        raiz->direito = remover(raiz->direito, temp->dado);
    }

    return raiz;
}


// 1c) Teste as funções com diferentes casos de teste

int main() {
    No* raiz = NULL;

    // Inserções
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Busca
    No* encontrado = buscar(raiz, 40);
    if (encontrado)
        printf("Valor 40 encontrado!\n");
    else
        printf("Valor 40 não encontrado!\n");

    // Remoção
    raiz = remover(raiz, 30);
    printf("Valor 30 removido!\n");

    return 0;
}




// 1d 1e 1f: Percursos

//1d) In-ordem (esquerda → raiz → direita)

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direito);
    }
}

//1e) Pré-ordem (raiz → esquerda → direita)

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

//1f) Pós-ordem (esquerda → direita → raiz)

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}



// 1g) Calcular altura da árvore

Altura = maior caminho da raiz até uma folha

int altura(No* raiz) {
    if (raiz == NULL) return -1; // Altura de árvore vazia é -1
    int altEsq = altura(raiz->esquerdo);
    int altDir = altura(raiz->direito);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}



//1h) Calcular profundidade de um nó

int profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivel;

    if (valor < raiz->dado)
        return profundidade(raiz->esquerdo, valor, nivel + 1);
    else
        return profundidade(raiz->direito, valor, nivel + 1);
}

//Chamada no main:

printf("Profundidade do valor 60: %d\n", profundidade(raiz, 60, 0));




//1i) Calcular a soma dos valores da árvore

int somaValores(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + somaValores(raiz->esquerdo) + somaValores(raiz->direito);
}



//1j) Calcular o nível de um nó

//Igual à profundidade, mas pode ter outro nome. Nível = profundidade.


//1k) Calcular o número de nós

int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerdo) + contarNos(raiz->direito);
}

//1l) Calcular o número de folhas
int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL) return 1;
    return contarFolhas(raiz->esquerdo) + contarFolhas(raiz->direito);
}