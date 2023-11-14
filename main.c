/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 53IIMQH
 *
 * Created on 10 de Fevereiro de 2019, 09:39
 */

#include <stdio.h>
#include <stdlib.h>

struct no {
    char info;
    struct no* esq;
    struct no* dir;
};

typedef struct no TNODO;

TNODO* arvore = NULL;

void inserir(TNODO** no, int valor) {
    if (*no == NULL) {
        *no = (TNODO*) malloc(sizeof (TNODO));
        (*no)->info = (char) valor;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
        printf("\n");
    } else {
        if (valor < (*no)->info) {
            printf("esq=%d ", valor);
            inserir(&(*no)->esq, valor);
        } else {
            printf("dir=%d ", valor);
            inserir(&(*no)->dir, valor);
        }
    }
}

void exibirEmOrdem(TNODO** no) {//recebe o nó raiz, de novo aquela confusão com o nome da variável
    if (*no != NULL) {//verifica se o nó atual existe, pois ao ser chamado pRaiz->direita ou pRaiz->esquerda, sabemos que poderão ser nulos
        exibirEmOrdem(&(*no)->esq); //chamada recursiva para o próximo à esquerda, e será chamado até o último à esquerda.
        printf("%c", (*no)->info); //Ao chegar no último à esquerda, ou seja, for pRaiz->esquerda for NULL, ele começa a printar, e vai printando todos os nós por onde ele passou, "voltando"
        exibirEmOrdem(&(*no)->dir); //é chamado o nó a direita, seguindo o fluxo
    }
}

void exibirPreOrdem(TNODO** no) {//Pré-Ordem é mais simples, no nó que ele tá, ele já printa. Começa pela raiz e vai printando até o último a esquerda, depois volta pro nó onde ele terá que ir até a esquerda e volta denovo a buscar o último a esquerda e segue o fluxo.
    if (*no != NULL) {//mesmo teste anterior
        printf("%c", (*no)->info); //assim que está no nó, já faz o print
        exibirPreOrdem(&(*no)->esq); //faz a chamada recursiva pro nó a esquerda, perceba que o pRaiz->direita só é chamado quando passa por todos os nós a esquerda
        exibirPreOrdem(&(*no)->dir); //chamada recursiva para nó à direita
    }
}

void exibirPosOrdem(TNODO** no) {//Pós-ordem é o que eu acho mais complicado, mas não impossível de entender. A ideia basicamente é passar por toda a árvore, e só depois vir fazendo os prints. Ele busca o último a esquerda, depois volta pro nó que tiver que voltar e vai pra direita, sem printar nada, e busca de novo o último a esquerda, ate varrer toda a árvore, depois ele vai printando tudo.
    if (*no != NULL) {
        exibirPosOrdem(&(*no)->esq);
        exibirPosOrdem(&(*no)->dir);
        printf("%c", (*no)->info);
    }
}

void liberar(TNODO** no) {
    if ((*no) != NULL) {
        liberar(&((*no)->esq));
        liberar(&((*no)->dir));
        free(*no);
    }
}

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

