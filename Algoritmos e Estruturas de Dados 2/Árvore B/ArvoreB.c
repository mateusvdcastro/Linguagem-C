/*
Mateus Vespasiano de Castro
RA: 159505
*/

#include <stdio.h>
#include <stdlib.h>

#define M 5

enum KeyStatus
{
    Duplicate,
    SearchFailure,
    Success,
    InsertIt,
    LessKeys
};

struct node
{
    int n;
    int keys[M - 1];
    struct node *p[M];
};

void Insertion(int key);
void Search(int x);
enum KeyStatus ins(struct node *r, int x, int *y, struct node **u);
int searchPos(int x, int *key_arr, int n);
void search_teste(int key, struct node *myNode);
void traversal(struct node *myNode);


struct node *root = NULL;


int main()
{

    int key, res; // chave a ser inserida ou pesquisada

    scanf("%d", &key);

    while (key >= 0)
    {
        Insertion(key);

        scanf("%d", &key);
    }

    // traversal(root);

    printf("%d\n", root->n);

    scanf("%d", &key);
    
    Search(key);

    return 0;
}

void Insertion(int key)
{
    struct node *newnode;
    int upKey;
    enum KeyStatus value;

    value = ins(root, key, &upKey, &newnode);
    if (value == Duplicate)
        return;
    if (value == InsertIt)
    {
        struct node *uproot = root;
        root = malloc(sizeof(struct node));
        root->n = 1;
        root->keys[0] = upKey;
        root->p[0] = uproot;
        root->p[1] = newnode;
    }
}

enum KeyStatus ins(struct node *ponteiro, int key, int *chaveAcima, struct node **novoNo)
{
    struct node *novoPtr;
    struct node *ultimoPtr;
    int pos, i, n, splitPos, novaChave, ultimaChave;
    enum KeyStatus valor;

    if (ponteiro == NULL)
    {
        *novoNo = NULL;
        *chaveAcima = key;
        return InsertIt;
    }

    n = ponteiro->n;
    pos = searchPos(key, ponteiro->keys, n);

    if (pos < n && key == ponteiro->keys[pos])
        return Duplicate;

    valor = ins(ponteiro->p[pos], key, &novaChave, &novoPtr);

    if (valor != InsertIt)
        return valor;

    if (n < M - 1)
    {
        pos = searchPos(novaChave, ponteiro->keys, n);
        for (i = n; i > pos; i--)
        {
            ponteiro->keys[i] = ponteiro->keys[i - 1];
            ponteiro->p[i + 1] = ponteiro->p[i];
        }
        ponteiro->keys[pos] = novaChave;

        ponteiro->p[pos + 1] = novoPtr;

        ++ponteiro->n;

        return Success;
    }

    if (pos == M - 1)
    {
        ultimaChave = novaChave;

        ultimoPtr = novoPtr;
    }
    else
    {
        ultimaChave = ponteiro->keys[M - 2];

        ultimoPtr = ponteiro->p[M - 1];

        for (i = M - 2; i > pos; i--)
        {
            ponteiro->keys[i] = ponteiro->keys[i - 1];

            ponteiro->p[i + 1] = ponteiro->p[i];
        }
        ponteiro->keys[pos] = novaChave;

        ponteiro->p[pos + 1] = novoPtr;

    }
    splitPos = (M - 1) / 2;

    (*chaveAcima) = ponteiro->keys[splitPos];

    (*novoNo) = malloc(sizeof(struct node));

    ponteiro->n = splitPos;

    (*novoNo)->n = M - 1 - splitPos;

    for (i = 0; i < (*novoNo)->n; i++)
    {
        (*novoNo)->p[i] = ponteiro->p[i + splitPos + 1];
        if (i < (*novoNo)->n - 1)
            (*novoNo)->keys[i] = ponteiro->keys[i + splitPos + 1];
        else
            (*novoNo)->keys[i] = ultimaChave;
    }

    (*novoNo)->p[(*novoNo)->n] = ultimoPtr;

    return InsertIt;
}

void Search(int key)
{
    int pos, n;

    struct node *ptr = root;

    while (ptr)
    {
        n = ptr->n;
        pos = searchPos(key, ptr->keys, n);
        if (pos < n && key == ptr->keys[pos])
        {
            printf("%d\n", n);
            return;
        }
        ptr = ptr->p[pos];
    }
    printf("Valor nao encontrado");
}

int searchPos(int key, int *key_arr, int n)
{
    int pos = 0;
    while (pos < n && key > key_arr[pos])
        pos++;
    return pos;
}

void search_teste(int key, struct node *myNode)
{
    int i;
    if (myNode)
    {
        for (i = 0; i < myNode->n; i++)
        {
            search_teste(key, myNode->p[i]);
            if (key == myNode->keys[i + 1])
            {
                printf("%d ", myNode->n);
            }
        }
        search_teste(key, myNode->p[i]);
    }
}

// Traverse the tree
void traversal(struct node *myNode)
{
    int i;
    if (myNode)
    {
        for (i = 0; i < myNode->n; i++)
        {
            traversal(myNode->p[i]);
            printf("%d ", myNode->keys[i + 1]);
        }
        traversal(myNode->p[i]);
    }
}
