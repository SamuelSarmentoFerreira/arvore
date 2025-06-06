//Estrutura Modificada
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;


//Busca por Nome
Aluno* buscarAluno(Aluno* T, char* nome) {
    if (!T) return NULL;
    if (strcmp(nome, T->nome) == 0) return T;
    Aluno* encontrado = buscarAluno(T->esquerdo, nome);
    return (encontrado) ? encontrado : buscarAluno(T->direito, nome);
}


//Cálculo de Média
float calcularMedia(Aluno* T) {
    if (!T) return 0;
    int count = contarNos(T);
    return (T->nota + calcularMedia(T->esquerdo) + calcularMedia(T->direito)) / count;
}