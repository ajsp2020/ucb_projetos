#include<stdio.h>
#include<stdlib.h>


struct noDaArvore
{
    int valor;
    struct noDaArvore* esquerda;
    struct noDaArvore* direita;
    
};

typedef struct noDaArvore no;

no* inserirNo(int valor, no* esq, no* dir);
void imprimirPreOrdem(no* n);




int main(){
    no* n = inserirNo(15, inserirNo(10, NULL, inserirNo(70, NULL, NULL)), inserirNo(50, inserirNo(20, NULL, NULL), NULL));

    imprimirPreOrdem(n);

    free(n);

}


no* inserirNo(int valor, no* esq, no* dir){

    no * n = (no*)malloc(sizeof(no));

    if(n == NULL){
        exit(1);
    }else{
        n->valor = valor;
        n->esquerda = esq;
        n->direita = dir;
    }


    return n;
}

void imprimirPreOrdem(no* n){
    if (n != NULL){
        printf("%i\n", n->valor);
        imprimirPreOrdem(n->esquerda);
        imprimirPreOrdem(n->direita);

        // tentar continuar amanha
    }
}


