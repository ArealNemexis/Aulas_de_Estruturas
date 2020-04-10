#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha
{
    int qtd;
    struct Registro * topo;
}Pilha;

typedef struct Registro
{
    int valor;
    struct Registro * proximo;
}Registro;

Pilha * cria_pilha()
{
    Pilha * pilha_criada = (Pilha *)malloc(sizeof(Pilha));

    pilha_criada->qtd = 0;
    pilha_criada->topo = NULL;

    return pilha_criada;
}

Registro * cria_registro()
{
    Registro * registro_criado = (Registro *)malloc(sizeof(Registro));

    registro_criado->valor = 0;
    registro_criado->proximo = NULL;

    return registro_criado;
}

int is_empty(Pilha * p1)
{
    if(p1->topo == NULL)
    {
        return 1;//true ou verdadeiro
    }
    else
    {
        return 0;//false ou falso
    }
}

int push(int x, Pilha * p1)
{
    Registro * empilhar = cria_registro();
    empilhar->valor = x;

    if(is_empty(p1) != 1)
    {
        Registro * aux = p1->topo;
        p1->topo = empilhar;
        empilhar->proximo = aux;
        p1->qtd++;
        return 1;
    }
    else
    {
        p1->topo = empilhar;
        p1->qtd++;
        return 1;
    }

    return 0;
}

int stackpop(Pilha * p1)
{
    Registro * topo = p1->topo;

    if(is_empty(p1) != 1){
        return topo->valor;
    }
    else
    {
        return -1;
    }  
}

int pop(Pilha * p1)
{
    if(is_empty(p1) != 1)  // if(!is_empty())
    {
        int retorno;

        Registro * aux = p1->topo;
        p1->topo = aux->proximo;
        retorno = aux->valor;
        p1->qtd--;
        free(aux);
        return retorno;
    }
    else
    {
        return -1;
    }
}

void mostra_pilha(Pilha * p1)
{
    if(is_empty(p1) != 1){
        Registro * aux = p1->topo;
        
        while(aux != NULL)
        {
            printf("| %d |\n", aux->valor);
            aux = aux->proximo;
        }
        printf("___\n");
    }
}

void menu(Pilha *p1)
{
    int opc;
    int numero;
    do
    {
        printf("\nMenu\n");
        printf("0 - exit\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - stackpop\n");
        printf("4 - is_empty\n");
        printf("5 - display\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            printf("Tchau\n");
            break;
        case 1:
            printf("\nInforme o que deseja empilhar");
            scanf("%d", &numero);

            if(push(numero, p1))
            {
                printf("Consegui empilhar");
            }
            break;

        case 2:
            numero = pop(p1);

            if(numero != -1)
            {
                printf("desempilhei %d\n", numero);
            }
            else
            {
                printf("Pilha vazia\n");
            }
            break;
        case 3:
            numero = stackpop(p1);

            if(numero != -1)
            {
                printf("Numero do topo %d\n", numero);
            }
            else
            {
                printf("Pilha vazia\n");
            }
            break;
        
        case 4:
            if(is_empty(p1))
            {
                printf("Esta vazia");
            }
            else
            {
                printf("não esta vazia\n");
            }
            break;
        case 5:
            mostra_pilha(p1);
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
        
    } while(opc != 0);
    
}

int main()
{
    Pilha * pt = cria_pilha();

    menu(pt);

    return 0;
}