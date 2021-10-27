#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* arvore_dir;
    struct no* arvore_esq;
}Tno;

void insert(Tno **raiz, int valor){
    if(*raiz == NULL){
        Tno* folha = malloc(sizeof(Tno));
        folha -> valor = valor;
        folha -> arvore_dir = NULL;
        folha -> arvore_esq = NULL;
        *raiz = folha;
    }
    if(valor > (*raiz)->valor){
        insert(&(*raiz)->arvore_dir,valor);
    }
    if(valor < (*raiz)->valor){
        insert(&(*raiz)->arvore_esq,valor);
    }
}

void pre_ordem(Tno* raiz){
    if (raiz == NULL){
        return ;
    }
    
    printf("\n %d",raiz->valor);
    pre_ordem(raiz->arvore_esq);
    pre_ordem(raiz->arvore_dir);
}

void em_ordem(Tno* raiz){
    if (raiz == NULL){
        return ;
    }
    pre_ordem(raiz->arvore_esq);
    printf("\n %d",raiz->valor);
    pre_ordem(raiz->arvore_dir);
}

int main(){
    Tno* raiz = NULL;
    int valor;

    for(valor = 0; valor <=10;valor ++){
        insert(&raiz,valor);
    }
    printf("Pre ordem*****************");
    pre_ordem(raiz);
    printf("*************************");
    em_ordem(raiz);
}