#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

void initialize_list(List *list);
void insert(List *list, int value);
int search(List *list, int value);
void print(List *list);
void initialize_table(List table[]);
void print_table(List table[]);

int main()
{
    int option, value;
    List table[LENGTH];

    initialize_table(LENGTH);

    do
    {
        printf("\n\t1 - Inserir elemento \n\t2 - Buscar elemento \n\t3- Imprimir \n\t0 - Sair");
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            printf("Voce escolheu sair...");
            wait(2);
            return 0;
            break;

        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", value);
            insert(table, value);
            break;
        
        case 2:
            printf("\nDigite o valor a ser buscado: ");
            scanf("%d", value);
            if (search(table, value) != -1)
                printf("Valor encontrado!");
            else   
                printf("Valor nao encontrado!");
            break;

        default:
            printf("Opcao nao reconhecida");
        }
    } while (option != 0);
    
}

// Função responsável pela estrutura do nó
typedef struct
{
    int value;
    struct Node *next;
}Node;
// Função responsável pela lista
typedef struct{
    Node *begin;
    int length;
}List;
//Função responsável pela inicialização
void initialize_list(List *list)
{
    list->begin = NULL;
    list->length = 0;
}
// Função inserir
void insert(List *list, int value)
{
    // Aloca um novo espaço de memória em uma das listas
    Node *new = malloc(sizeof(Node));
    // Verifica se o nó foi inicializado corretamente
    if (new)
    {
        new->next = list->begin;
        new->value = value;
        list->begin = new;
        list->length++;
    }
    else
    {
        printf("\nError! Não foi possível alocar a memória");
    }
}
//Realiza a busca na lista
int search(List *list, int value)
{
    Node *aux = list->begin;

    if (list != NULL)
    {
        while (aux->next != NULL)
        {
            if (aux->value == value)
                return value;
            aux = aux->next; 
        }
    }
    return -1;
}
// Função para imprimir valores de uma lista
void print(List *list)
{
    Node *aux = list->begin;

    if (list != NULL)
    {
        while (aux->next != NULL)
        {
            printf("%d ", aux->value);
            aux = aux->next;
        }
    }
}
// Inicializa as listas dentro da tabela;
void initialize_table(List table[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        initialize_list(&table[i]);
    }
}

void print_table(List table[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%3d", i);
        print(&table[i]);
        printf("\n");
    }
    
}