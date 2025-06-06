//Altura
int altura(No* T) {
    return (!T) ? -1 : 1 + fmax(altura(T->esquerdo), altura(T->direito));
}


//Contagem de Nós
int contarNos(No* T) {
    return (!T) ? 0 : 1 + contarNos(T->esquerdo) + contarNos(T->direito);
}


//Contagem de Folhas
int contarFolhas(No* T) {
    if (!T) return 0;
    return (!T->esquerdo && !T->direito) ? 1 : contarFolhas(T->esquerdo) + contarFolhas(T->direito);
}