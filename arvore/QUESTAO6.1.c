//2a) Estrutura de dados para árvore binária de busca dos alunos

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;



//Função para inserir um aluno na árvore (ordenado por matrícula)

Aluno* criarAluno(const char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->nota = nota;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

Aluno* inserirAluno(Aluno* raiz, const char* nome, int matricula, float nota) {
    if (raiz == NULL)
        return criarAluno(nome, matricula, nota);

    if (matricula < raiz->matricula)
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    else if (matricula > raiz->matricula)
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);

    return raiz;
}




//3) Buscar um aluno pelo nome

Aluno* buscarPorNome(Aluno* raiz, const char* nome) {
    if (raiz == NULL) return NULL;

    if (strcmp(raiz->nome, nome) == 0)
        return raiz;

    Aluno* encontrado = buscarPorNome(raiz->esquerdo, nome);
    if (encontrado == NULL)
        encontrado = buscarPorNome(raiz->direito, nome);

    return encontrado;
}


⸻

//4) Calcular a média das notas dos alunos

float somaNotas(Aluno* raiz) {
    if (raiz == NULL) return 0;
    return raiz->nota + somaNotas(raiz->esquerdo) + somaNotas(raiz->direito);
}

int contarAlunos(Aluno* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarAlunos(raiz->esquerdo) + contarAlunos(raiz->direito);
}

float mediaNotas(Aluno* raiz) {
    int total = contarAlunos(raiz);
    if (total == 0) return 0;
    return somaNotas(raiz) / total;
}



//Exemplo de uso no main() (para teste simples)

int main() {
    Aluno* raiz = NULL;

    raiz = inserirAluno(raiz, "Maria", 101, 8.5);
    raiz = inserirAluno(raiz, "João", 103, 7.2);
    raiz = inserirAluno(raiz, "Ana", 102, 9.1);

    Aluno* buscado = buscarPorNome(raiz, "Ana");
    if (buscado != NULL)
        printf("Encontrado: %s, Matrícula: %d, Nota: %.2f\n", buscado->nome, buscado->matricula, buscado->nota);
    else
        printf("Aluno não encontrado\n");

    printf("Média das notas: %.2f\n", mediaNotas(raiz));

    return 0;
}
