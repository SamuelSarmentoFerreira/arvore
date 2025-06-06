//Criação

No* criarNo(int c) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = c;
    novo->esquerdo = novo->direito = NULL;
    return novo;
}


//Remoção, Destruir árvore

void removerArvore(No* T) {
    if (T) {
        removerArvore(T->esquerdo);
        removerArvore(T->direito);
        free(T);
    }
}


//Busca

No* buscar(No* T, int c) {
    if (!T) return NULL;
    if (c == T->dado) return T;
    return (c < T->dado) ? buscar(T->esquerdo, c) : buscar(T->direito, c);
}


//Inserção

No* inserir(No* T, int c) {
    if (!T) return criarNo(c);
    if (c < T->dado) T->esquerdo = inserir(T->esquerdo, c);
    else if (c > T->dado) T->direito = inserir(T->direito, c);
    return T;
}

