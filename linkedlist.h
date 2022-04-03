#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int info;
	struct no* prox;
	struct no * prev;
} No;

typedef No* Celula;

typedef struct lista
{
	Celula inicio;
	Celula fim;
} Lista;

Celula llCriaCelula(int info);
Lista* llCriarLista();

void llInsereNoFim(Lista* lista, int info);
void llInsereNoInicio(Lista* lista, int info);
void llInsereAntesDe(Lista* lista, int info, int alvo);
void llInsereDepoisDe(Lista* lista, int info, int alvo);
void llInsereOrdenado(Lista* lista, int info);

void llRemoveFim(Lista* lista);
void llRemoveInicio(Lista* lista);

Celula llRemoveNo(Lista* lista, int info);

Celula llBusca(Lista* lista, int info);

void llImprimeLista(Lista* lista);

void llImprimePonteiros(Lista* lista);

int llTemCiclo(Lista* lista);

Celula swapCelulas(Celula a, Celula b);

Celula bubbleList(Celula inicio);