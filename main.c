#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char const* argv[])
{

	Lista* lista = llCriarLista();
	llInsereNoInicio(lista, 10);
	llInsereNoInicio(lista, 1);
	llInsereNoFim(lista, 5);
	llInsereOrdenado(lista, 2);
	llInsereOrdenado(lista, 17);
	llInsereAntesDe(lista, 7, 2);
	llInsereDepoisDe(lista, 12, 2);

	llImprimeLista(lista);
	llImprimePonteiros(lista);

	printf("\n");

	bubbleList(lista->inicio);
	llImprimeLista(lista);
	llImprimePonteiros(lista);

	llRemoveNo(lista, 5);

	printf("\n");
	llImprimeLista(lista);
	llImprimePonteiros(lista);

	return 0;
}