#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
	struct node* pai;
	int chave;
	struct node* fEsq;
	struct node* fDir;
} Node;

typedef Node* Celula;

typedef struct raiz
{
	Celula raiz;
	int altura; 
} Raiz;

Raiz* bstCriaRaiz();

Celula bstCriaCelula();

int bstAlturaMaxima(int altura);

int bstMaximoFolhas(int altura);

Celula bstBusca(Celula raiz, int alvo);

Celula bstMinimo(Celula raiz);

Celula bstMaximo(Celula raiz);