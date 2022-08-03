// Nome: Mateus Vespasiano de Castro
// RA: 159505
// Turma: IB

// https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

#include <stdio.h>
#include <stdlib.h>

// estrutura de um nó de uma árvore binária
typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
    int fb;
    int altura;
} TArv;
typedef TArv *PArv;

PArv cria(int c)
{ // cria um nó raiz
    PArv p = (PArv)malloc(sizeof(TArv));
    p->info = c;
    p->altura = 0;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

// imprime a árvore formatada, de melhor visualização
void imprimeT(PArv p, int nivel)
{
    int i;

    if (p == NULL)
        return;

    imprimeT(p->esq, nivel + 1);

    for (i = 0; i < nivel; i++)
        printf("\t");

    printf("%3d\n", p->info);

    imprimeT(p->dir, nivel + 1);
}

// desaloca a árvore da memória
PArv libera(PArv a)
{
    if (a != NULL)
    {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
    }
    return NULL;
}

int Retorno_altura(PArv raiz)
{
    if (raiz == NULL)
    {
        return (-1);
    }
    else
    {
        return (raiz->altura);
    }
}

int altura(PArv arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    else
    {
        int alturaEsq = altura(arv->esq);
        int alturaDir = altura(arv->dir);
        if (alturaEsq > alturaDir)
        {
            return alturaEsq + 1;
        }
        else
        {
            return alturaDir + 1;
        }
    }
}

PArv RR(PArv p)
{
    int alturaD, alturaE;

    PArv aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;

    alturaD = Retorno_altura(p->dir);
    alturaE = Retorno_altura(p->esq);
    if (alturaE > alturaD)
    {
        p->altura = alturaE + 1;
    }
    else
    {
        p->altura = alturaD + 1;
    }

    alturaD = Retorno_altura(aux->dir);
    alturaE = Retorno_altura(aux->esq);
    if (alturaE > alturaD)
    {
        aux->altura = alturaE + 1;
    }
    else
    {
        aux->altura = alturaD + 1;
    }

    return aux;
}

PArv LL(PArv p)
{

    int alturaD, alturaE;

    PArv aux = p->dir;
    p->dir = aux->esq;
    aux->esq = p;

    alturaD = Retorno_altura(p->dir);
    alturaE = Retorno_altura(p->esq);
    if (alturaE > alturaD)
    {
        p->altura = alturaE + 1;
    }
    else
    {
        p->altura = alturaD + 1;
    }

    alturaD = Retorno_altura(aux->dir);
    alturaE = Retorno_altura(aux->esq);
    if (alturaE > alturaD)
    {
        aux->altura = alturaE + 1;
    }
    else
    {
        aux->altura = alturaD + 1;
    }

    return aux;
}

PArv LR(PArv p)
{
    PArv aux = p->esq;
    p->esq = LL(aux);
    return RR(p);
}

PArv RL(PArv p)
{
    PArv aux = p->dir;
    p->dir = RR(aux);
    return LL(p);
}

// Busca na árvore binária um valor desejado e retorna o nó em que ele se encontra
PArv RetornaNoDesejado(PArv arv, int num)
{
    if (arv == NULL)
    {
        return NULL;
    }
    if (arv->info == num)
    {
        return arv;
    }
    if (arv->info > num)
    {
        return RetornaNoDesejado(arv->esq, num);
    }
    return RetornaNoDesejado(arv->dir, num);
}

// insere o nó na árvore principal e realiza as rotações necessárias para balanceá-la, por fim, retorna a mesma
PArv insereABB(PArv arv, PArv no)
{
    int h1, h2;

    if (arv == NULL)
    { // arvore vazia
        return no;
    }

    if (no->info < arv->info)
    { // insere na ordem, menores à esquerda e maiores à direita
        arv->esq = insereABB(arv->esq, no);

        //   arv = CalculaFatordeBalanceamento(arv);

        h1 = Retorno_altura(arv->esq);
        h2 = Retorno_altura(arv->dir);

        if ((h1 - h2) == 2)
        {
            if (no->info < arv->esq->info)
            {
                arv = RR(arv);
            }
            else
            {
                arv = LR(arv);
            }
        }
    }
    else
    {
        if (no->info > arv->info)
        {
            arv->dir = insereABB(arv->dir, no);

            h1 = Retorno_altura(arv->dir);
            h2 = Retorno_altura(arv->esq);

            if ((h1 - h2) == 2)
            {
                if (no->info > arv->dir->info)
                {
                    arv = LL(arv);
                }
                else
                {
                    arv = RL(arv);
                }
            }
        }
    }

    h1 = Retorno_altura(arv->dir);
    h2 = Retorno_altura(arv->esq);
    if (h1 > h2)
    {
        arv->altura = h1 + 1;
    }
    else
    {
        arv->altura = h2 + 1;
    }

    return arv;
}

int BuscaAVL(PArv arv, int valor)
{
    if (arv == NULL)
    {
        return 0; /* árvore vazia */
    }
    else if (valor == arv->info)
    {
        return 1; // encontrou a informação
    }
    else if (valor < arv->info)
    {
        return BuscaAVL(arv->esq, valor);
    }
    else
    {
        return BuscaAVL(arv->dir, valor);
    }
}

PArv removeAVL(PArv root, int num)
{
    PArv aux1, aux2;
    int h1, h2, fbr, fbd, fbe;

    if (root == NULL)
    {
        return (root);
    }
    if (num < root->info)
    {
        root->esq = removeAVL(root->esq, num);
    }
    else if (num > root->info)
    {
        root->dir = removeAVL(root->dir, num);
    }
    else
    {
        if ((root->esq == NULL) || (root->dir == NULL))
        {
            aux1 = root->esq ? root->esq : root->dir;

            if (aux1 == NULL)
            {
                aux1 = root;
                root = NULL;
            }
            else
            {
                *root = *aux1;
            }
            free(aux1);
        }
        else
        {
            aux2 = root->dir;
            while (aux2->esq)
            {
                aux2 = aux2->esq;
            }
            root->info = aux2->info;
            root->dir = removeAVL(root->dir, aux2->info);
        }
    }
    if (root == NULL)
    {
        return root;
    }

    h1 = Retorno_altura(root->dir);
    h2 = Retorno_altura(root->esq);
    if (h2 > h1)
    {
        root->altura = h2 + 1;
    }
    else
    {
        root->altura = h1 + 1;
    }

    // Calculo de Fatores de balanceamento
    if (root == NULL)
    {
        fbr = 0;
    }
    else
    {
        fbr = Retorno_altura(root->esq) - Retorno_altura(root->dir);
    }
    if (root->esq == NULL)
    {
        fbe = 0;
    }
    else
    {
        fbe = Retorno_altura(root->esq->esq) - Retorno_altura(root->esq->dir);
    }
    if (root->dir == NULL)
    {
        fbd = 0;
    }
    else
    {
        fbd = Retorno_altura(root->dir->esq) - Retorno_altura(root->dir->dir);
    }

    // Analise dos Fatores de Balanceamento
    if (fbr > 1 && fbe >= 0)
        return RR(root);

    if (fbr > 1 && fbe < 0)
    {
        root->esq = LL(root->esq);
        return RR(root);
    }

    if (fbr < -1 && fbd <= 0)
        return LL(root);

    if (fbr < -1 && fbd > 0)
    {
        root->dir = RR(root->dir);
        return LL(root);
    }

    return root;
}

int main()
{
    int max, min;
    int n3;
    PArv arvore = NULL, no, no2;
    PArv n_pesquisar;

    int n = 0, n2 = 0;

    scanf("%d", &n);

    while (n >= 0)
    {
        no = cria(n);

        arvore = insereABB(arvore, no);

        scanf("%d", &n);
    }

    // imprimeT(arvore, 0);

    // Altura da árvore pelo filho à esquerda
    if (arvore->esq != NULL)
    {
        min = altura(arvore->esq);
    }
    else
    {
        min = 0;
    }

    // Altura da árvore pelo filho à direita
    if (arvore->dir != NULL)
    {
        max = altura(arvore->dir);
    }
    else
    {
        max = 0;
    }

    if (min > max)
    {
        printf("%d, %d, %d\n", min, min, max);
    }
    else
    {
        printf("%d, %d, %d\n", max, min, max);
    }

    scanf("%d", &n2);

    while (n2 >= 0)
    {

        if (BuscaAVL(arvore, n2) == 1)
        {
            // printf("O numero encontrado sera removido");
            arvore = removeAVL(arvore, n2);
        }
        else
        {
            // printf("O numero nao encontrado sera adicionado");
            no2 = cria(n2);
            arvore = insereABB(arvore, no2);
        }

        scanf("%d", &n2);
    }

    scanf("%d", &n3);
    n_pesquisar = RetornaNoDesejado(arvore, n3);

    if (n_pesquisar == NULL)
    {
        printf("Valor nao encontrado");
    }
    else
    {
        if (n_pesquisar->esq != NULL)
        {
            min = altura(n_pesquisar->esq);
        }
        else
        {
            min = 0;
        }

        if (n_pesquisar->dir != NULL)
        {
            max = altura(n_pesquisar->dir);
        }
        else
        {
            max = 0;
        }

        if (min > max)
        {
            printf("%d, %d, %d\n", min, min, max);
        }
        else
        {
            printf("%d, %d, %d\n", max, min, max);
        }
    }

    libera(arvore); // Desaloca a árvore da memória

    return 0;
}