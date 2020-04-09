#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{   
    struct Registro * primeiro;
    struct Registro * ultimo;
}Lista;

typedef struct Registro
{
    int valor;
    struct Registro * proximo;
    struct Registro * anterior;
}Registro;

Lista * cria_lista()
{
    Lista * retorno = (Lista *)malloc(sizeof(Lista));
    
    retorno->primeiro = NULL;
    retorno->ultimo = NULL;  

    return retorno;
}

Registro * cria_registro()
{
    Registro * retorno = (Registro *)malloc(sizeof(Registro));

    retorno->valor = 0;
    retorno->proximo = NULL;
    retorno->anterior = NULL;
}

void adiciona_lista(Lista * l1, int x)
{
    Registro * adicionado =  cria_registro();
    adicionado->valor = x;
    
    if(l1->primeiro == NULL) // adiciona caso esteja vazia
    {
        l1->primeiro = adicionado;
        l1->ultimo = adicionado;
        printf("Adicionado\n");
    }
    else
    {
        Registro * aux = l1->ultimo;
        l1->ultimo = adicionado; 
        adicionado->anterior = aux;
        aux->proximo = adicionado;
        printf("Adicionado\n");
    }
}

void remove_ultimo(Lista * l1){
    
    if(l1->primeiro == NULL) // nada na lista
    {
        printf("Não existem elementos na lista\n");
    }
    else
    {
        Registro * aux = l1->ultimo;
        l1->ultimo = aux->anterior;
        l1->ultimo->proximo = NULL;
        free(aux);
        printf("Apaguei o ultimo\n");
    }
}

void remove_especifico(Lista * l1, int x)
{
    if(l1->primeiro != NULL)
    {
        Registro * aux = l1->primeiro;
        while(aux->proximo != NULL){
            if(aux->valor == x)
            {
                // aux->anterior->proximo = aux->proximo;
                // free(aux);
                // printf("Removi\n");
                break;
            }
            aux = aux->proximo;
        }
        if(aux->valor == x){
            if(aux == l1->primeiro){
                l1->primeiro = aux->proximo;
                aux->proximo->anterior = NULL;
                free(aux);
                printf("Removi\n");
            }else{
                if(aux == l1->ultimo){
                    remove_ultimo(l1);
                }else{
                    aux->anterior->proximo = aux->proximo;
                    free(aux);
                    printf("Removi\n");
                }
            }
        }else
        {
            printf("Valor não encontrado\n");
        }
        
    }else{
        printf("Lista vazia\n");
    }
}

void mostrar(Lista * l1){
    if(l1->primeiro == NULL){
        printf("\n Lista vazia");
    }else{
        Registro * elemento_a_mostrar = l1->primeiro;
        while (elemento_a_mostrar!= NULL)
        {
            printf("%d ->", elemento_a_mostrar->valor);
            elemento_a_mostrar = elemento_a_mostrar->proximo;
        }
        printf("\n");
    }
}

void busca(Lista * l1, int x)
{
    if(l1->primeiro == NULL){
        printf("Não tem nada por aqui\n");
    }else{
        int contador = 1;
        Registro * aux = l1->primeiro;
        while(aux->proximo != NULL){
            if(aux->valor == x)
            {
                break;
            }
            aux = aux->proximo;
            contador++;
        }

        if(aux->valor == x)
        {
            printf("Achei o valor %d na posicao %d\n", aux->valor, contador);
        }
        else
        {
            printf("Não achei\n");
        }
        
    }
}

void verifica_crescente(Lista * l1)
{
    if(l1->primeiro == NULL)
    {
        printf("Lista Vazia\n");
    }
    else
    {
        Registro * aux = l1->primeiro;
        while(aux != NULL){
            if(aux->anterior == NULL){
                aux = aux->proximo;
                continue;
            }
            if(aux->anterior->valor > aux->valor){
                break;
            }
            aux = aux->proximo;
        }
        if(aux == NULL){
            printf("Esta ordenada\n");
        }
        else
        {
            printf("Não esta ordenada\n");
        }   
    }
}

void menu(Lista * l1)
{
    int opcao;
    int valor_usado;
    do{
        printf("MENU\n");
        printf("0 - SAIR\n");
        printf("1 - ADICIONA\n");
        printf("2 - REMOVE DO FIM\n");
        printf("3 - REMOVE ESPECIFICO\n");
        printf("4 - BUSCA\n");
        printf("5 - MOSTRAR\n");
        printf("6 - ESTA ORDENADO?\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("FLW\n");
            break;
        case 1:
            printf("digite um valor para adicionar na lista\n");
            scanf("%d", &valor_usado);
            adiciona_lista(l1, valor_usado);
            break;
        case 2:
            remove_ultimo(l1);
            break;
        case 3:
            printf("digite um valor para remover na lista\n");
            scanf("%d", &valor_usado);
            remove_especifico(l1, valor_usado);
            break;
        case 4:
            printf("digite um valor para busca na lista\n");
            scanf("%d", &valor_usado);   
            busca(l1, valor_usado);         
            break;
        case 5:
            mostrar(l1);
            break;
        case 6:
            verifica_crescente(l1);
            break;
        default:
            printf("essa opcao não existe\n");
            break;
        }
    }while(opcao != 0);
    
}

int main(void)
{
    Lista * lt = cria_lista();

    menu(lt);
    
    return 0;
}

