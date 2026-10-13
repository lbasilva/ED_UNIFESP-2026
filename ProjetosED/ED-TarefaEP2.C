#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FILA {
    float valor;
    struct FILA *proximo;
} Fila;

void coloca(Fila **f, float valor ) {
    Fila *novo;
    Fila *ptr;

    novo = malloc( sizeof(Fila) );
    if(!novo) {
        printf("Erro de alocação.\n");
        exit(-1);    
    }
    novo->valor = valor;
    novo->proximo = NULL;

    if(*f==NULL) {
        *f = novo;
        return;
    }
    ptr = *f;
    while( ptr->proximo != NULL ) 
        ptr = ptr->proximo;
    ptr->proximo = novo;
}

// tipo de retorno em float, combinando com a struct
float retira(Fila **f ) {
    Fila *p;
    float val;

    if(*f == NULL) return -99999;
    p = *f;
    *f = p->proximo;

    val = p->valor;
    free(p);
    return val;
}

int vazia(Fila *f) {
    return f==NULL;
}

int tamanho(Fila *f) {
    int tam=0;
    while(f) {
        tam++;
        f = f->proximo;
    }
    return tam;
}

float primeiro(Fila *f) {
    if(f==NULL) return -99999;
    return f->valor;
}

// Funções push, pop e peek ajustadas para float 
void push(Fila **f, float valor) {
    coloca(f, valor);
}

float pop(Fila **f) {
    return retira(f);
}

float peek(Fila *f) {
    return primeiro(f);
}

int main(){
    Fila *fila; //fila vazia

    fila=NULL;
    push(&fila, 10);
    push(&fila, 20);
    push(&fila, 30);
    push(&fila, 40);

    printf("Primeiro (Peek): %.1f\n", peek(fila));
    
    printf("Removido (Pop): %.1f\n", pop(&fila));
    printf("Removido (Pop): %.1f\n", pop(&fila));
    printf("Removido (Pop): %.1f\n", pop(&fila));

    push(&fila, 50);
    push(&fila, 60);

    while(fila)
        printf("Removido (Pop): %.1f\n", pop(&fila));
}