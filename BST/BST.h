#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* pai;
	int chave;
	struct node* fEsq;
	struct node* fDir;
} Node;

typedef Node* Celula;

typedef struct arvore
{
	Celula raiz;
} Arvore;

Celula bstCriaCelula(int chave);

Arvore* bstCriaArvore();

void bstRemover(Arvore* arvore, Celula celula);

Celula bstMinimo(Arvore* arvore);

Celula bstMaximo(Arvore* arvore);