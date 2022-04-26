#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(int argc, char const *argv[])
{
	Celula raiz = NULL;

	raiz = bstInsert(raiz, 50);
	bstInsert(raiz, 30);
	bstInsert(raiz, 20);
	bstInsert(raiz, 40);
	bstInsert(raiz, 70);
	bstInsert(raiz, 60);
	bstInsert(raiz, 80);

	bstPrint(raiz);

	bstPrintIdentado(raiz, 0);

	return 0;
}