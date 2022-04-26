#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
	//struct node* pai;
	int chave;
	int altura;
	struct node* fEsq;
	struct node* fDir;
} Node;

typedef Node* Celula;

Celula bstCriaCelula(int chave);

int bstAlturaMaxima(int altura);

int bstMaximoFolhas(int altura);

Celula bstBusca(Celula raiz, int alvo);

Celula bstMinimo(Celula raiz);

Celula bstMaximo(Celula raiz);

Celula bstInsert(Celula raiz, int chave);

void bstPrint(Celula raiz);

void bstPrintIdentado(Celula raiz, int nivelAltura);

int bstCalculaAltura(Celula raiz);

int bstCalculaFatorBalanceamanto(Celula raiz);

//retorna o pai da arvore que possui a soma
Celula bstTemSoma(Celula raiz);

Celula bstCopia(Celula raiz);

Celula avlInsert(Celula raiz, int chave);