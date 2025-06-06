//ordem(esquerda-raiz-direita)
void inOrdem(No* T) {
    if (T) {
        inOrdem(T->esquerdo);
        printf("%d ", T->dado);
        inOrdem(T->direito);
    }
}


//Pré-ordem(raiz-esquerda-direita)
void preOrdem(No* T) {
    if (T) {
        printf("%d ", T->dado);
        preOrdem(T->esquerdo);
        preOrdem(T->direito);
    }
}


//Pós-ordem(esquerda-direita-raiz)
void posOrdem(No* T) {
    if (T) {
        posOrdem(T->esquerdo);
        posOrdem(T->direito);
        printf("%d ", T->dado);
    }
}