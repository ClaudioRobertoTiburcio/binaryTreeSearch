#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int ra;
    struct Node *esq, *dir;
} Node;

Node* novoNo(int ra) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->ra = ra;
    n->esq = n->dir = NULL;
    return n;
}

Node* insereNo(Node* raiz, int ra) {
    if (raiz == NULL) return novoNo(ra);

    if (ra < raiz->ra)
        raiz->esq = insereNo(raiz->esq, ra);
    else if (ra > raiz->ra)
        raiz->dir = insereNo(raiz->dir, ra);

    return raiz;
}

int buscaPrefixo(Node* raiz, int prefixo, int tamanho) {
    if (raiz == NULL) return 0;

    int divisor = 1;
    for (int i = 0; i < 9 - tamanho; i++) divisor *= 10;

    int prefixoNo = raiz->ra / divisor;

    if (prefixo == prefixoNo) {
        printf(" -> prefixo %d encontrado no node com RA %d\n", prefixo, raiz->ra);
        return 1;
    }
    else if (prefixo < prefixoNo)
        return buscaPrefixo(raiz->esq, prefixo, tamanho);
    else
        return buscaPrefixo(raiz->dir, prefixo, tamanho);
}

int verificaRACompleto(Node* raiz, int ra) {
    if (raiz == NULL) return 0;
    if (ra == raiz->ra) return 1;
    if (ra < raiz->ra) return verificaRACompleto(raiz->esq, ra);
    else return verificaRACompleto(raiz->dir, ra);
}

void populaBase(Node **raiz) {
    *raiz = insereNo(*raiz, 202300018);
    *raiz = insereNo(*raiz, 202200045);
    *raiz = insereNo(*raiz, 233194555); // Meu RA 233194555, Aluno: Cláudio Roberto de Carvalho Tiburcio
    *raiz = insereNo(*raiz, 202301234);
    *raiz = insereNo(*raiz, 123456789);
}

bool verificaTamanhoRA(int consulta, int *copia, int *value) {
    *copia = consulta;
    int qtd = 0;
    while (*copia > 0) {
        *copia /= 10;
        qtd++;
    }
    if (qtd != 9) {
        printf("ERRO: O RA deve ter 9 digitos!\n");
        *value = 0;
        return true;
    }
    return false;
}

int main() {
    Node* raiz = NULL;

    populaBase(&raiz);

    int consulta;
    printf("Digite o RA (9 digitos): ");
    scanf("%d", &consulta);

    int copia;
    int value;
    if (verificaTamanhoRA(consulta, &copia, &value)) return value;

    int digitos[9];
    copia = consulta;
    for (int i = 8; i >= 0; i--) {
        digitos[i] = copia % 10;
        copia /= 10;
    }

    for (int i = 1; i <= 9; i++) {
        int prefixo = 0;
        for (int j = 0; j < i; j++) {
            prefixo = prefixo * 10 + digitos[j];
        }

        printf("Verificando prefixo: %d", prefixo);
        if (!buscaPrefixo(raiz, prefixo, i))
            printf(" -> nao encontrado\n");
    }

    if (verificaRACompleto(raiz, consulta))
        printf("\nRA %d localizado com sucesso na arvore!\n", consulta);
    else
        printf("\nRA %d nao encontrado na arvore.\n", consulta);

    return 0;
}
