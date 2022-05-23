#include "BST.h"

Celula bstCriaCelula(int chave)
{
	Celula novaCelula = (Celula)malloc(sizeof(Node));

	novaCelula->chave = chave;

	novaCelula->altura = 1;

	//novaCelula->pai = NULL;

	novaCelula->fEsq = NULL;
	novaCelula->fDir = NULL;

	novaCelula->fatorBalanceamento = bstCalculaFatorBalanceamanto(novaCelula);

	return novaCelula;
}

void bstDestoy(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	bstDestoy(raiz->fEsq);
	bstDestoy(raiz->fDir);
	free(raiz);
	raiz = NULL
}

int bstAltura(int altura)
{
	return pow(2, altura) -1;
}

int bstMaximoFolhas(int altura)
{
	return pow(2, altura -1);
}

Celula bstBusca(Celula raiz, int alvo)
{
	if (raiz == NULL || raiz->chave == alvo)
	{
		return raiz;
	} 
	else if (alvo > raiz->chave)
	{
		return bstBusca(raiz->fDir, alvo);
	}
	else 
	{
		return bstBusca(raiz->fEsq, alvo);
	}
}

Celula bstMinimo(Celula raiz)
{
	if (raiz == NULL || raiz->fEsq == NULL)
	{
		return raiz;
	} 
	else
	{
		return bstMinimo(raiz->fEsq);
	}
}

Celula bstMaximo(Celula raiz)
{
	if (raiz == NULL || raiz->fDir == NULL)
	{
		return raiz;
	}
	else
	{
		return bstMaximo(raiz->fDir);
	}
}

Celula bstInsert(Celula raiz, int chave)
{
	if (raiz == NULL)
	{
		return bstCriaCelula(chave);
	}

	if (chave > raiz->chave)
	{
		raiz->fDir = bstInsert(raiz->fDir, chave);
	}
	else
	{
		raiz->fEsq = bstInsert(raiz->fEsq, chave);
	}

	raiz->altura = bstCalculaAltura(raiz);
	return  raiz;
}

void inOrder(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	inOrder(raiz->fEsq);
	printf("%d ", raiz->chave);
	inOrder(raiz->fDir);
}

void preOrder(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	printf("%d ", raiz->chave);
	preOrder(raiz->fEsq);
	preOrder(raiz->fDir);
}

void postOrder(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	postOrder(raiz->fEsq);
	postOrder(raiz->fDir);
	printf("%d ", raiz->chave);
}

void bstPrint(Celula raiz)
{
	int opc = 0;

	printf("\nDigite o algoritmo desejado: 1- inOrder | 2- preOrder | 3- postOrder\n");
	scanf("%d", &opc);
	getchar();

	switch(opc)
	{
		//InOrder (Esquerda, Raiz, Direita)
		case 1:
			inOrder(raiz);
			break;
		//PreOrder (Raiz, Esquerda, Direita)
		case 2:
			preOrder(raiz);
			break;
		//PostOrder (Esquerda, Direita, Raiz)
		case 3:
			postOrder(raiz);
			break;
		default:
			break;
	}
}

void bstPrintIdentado(Celula raiz, int nivelAltura)
{
	if (raiz == NULL)
	{
		return raiz;
	}

	bstPrintIdentado(raiz->fDir, nivelAltura + 1);

	for (int i = 0; i < nivelAltura; ++i)
	{
		printf("\t");
	}

	printf("%d \n", raiz->chave);

	bstPrintIdentado(raiz->fEsq, nivelAltura + 1);
}

int bstCalculaNos(Celula raiz)
{

}

int bstCalculaAltura(Celula raiz)
{
	if (raiz == NULL)
	{
		return 0;
	}
	else
	{
		int esq = bstCalculaAltura(raiz->fEsq);
		int dir = bstCalculaAltura(raiz->fDir);

		if (esq > dir)
		{
			return esq + 1;
		}
		else
		{
			return dir + 1;
		}
	}
}

bool isBstAvl(Celula raiz)
{
	int esq = 0, dir = 0;
	bool ok = true;
	if (raiz == NULL)
	{
		return false;
	}
	ok = isBstAvl(raiz->fEsq);
	if (ok)
	{
		ok = isBstAvl(raiz->fDir);
	}
	if (ok)
	{
		esq = bstCalculaAltura(raiz->fEsq);
		dir = bstCalculaAltura(raiz->fDir);
		if (abs(e-d) <= 1)
		{
			ok = true;
		}
		else
		{
			ok = false;
		}
	}
}

int bstCalculaFatorBalanceamanto(Celula raiz)
{
	return (bstCalculaAltura(raiz->fEsq) - bstCalculaAltura(raiz->fDir));
}

Celula bstTemSoma(Celula raiz)
{

}

Celula bstCopia(Celula raiz)
{

}

Celula rotR(Celula raiz)
{
	Celula u;
	Celula v;
	u = raiz->fEsq;
	if (u->fatorBalanceamento == -1)
	{
		raiz->fEsq = u->fDir;
		u->fDir = raiz;
		raiz->fatorBalanceamento = 0;
		raiz = u;
	}
	else
	{
		v = u->fDir;
		u->fDir = v->fEsq;
		v->fEsq = u;
		raiz->fEsq = v->fDir;
		v->fDir = raiz;
		if (v->fatorBalanceamento == -1)
		{
			raiz->fatorBalanceamento = 1;
		}
		else
		{
			raiz->fatorBalanceamento = 0;
		}
		if (v->fatorBalanceamento == 1)
		{
			u->fatorBalanceamento = -1;
		}
		else
		{
			u->fatorBalanceamento = 0;
		}
		raiz = v;
	}
	raiz->fatorBalanceamento = 0;
	return raiz;
}

Celula rotL(Celula raiz)
{
	Celula u;
	Celula v;
	u = raiz->fDir;
	if (u->fatorBalanceamento == 1)
	{
		raiz->fDir = u->fEsq;
		u->fEsq = raiz;
		raiz->fatorBalanceamento = 0;
		raiz = u;
	}
	else
	{
		v = u->fEsq;
		u->fEsq = v->fDir;
		v->fDir = u;
		raiz->fDir = v->fEsq;
		v->fEsq = raiz;
		if (v->fatorBalanceamento == -1)
		{
			raiz->fatorBalanceamento = 1;
		}
		else
		{
			raiz->fatorBalanceamento = 0;
		}
		if (v->fatorBalanceamento == 1)
		{
			u->fatorBalanceamento = -1;
		}
		else
		{
			u->fatorBalanceamento = 0;
		}
		raiz = v;
	}
	raiz->fatorBalanceamento = 0;
	return raiz;
}

Celula avlInsert(Celula raiz, int chave, bool* ajustar)
{
	if (Celula raiz = NULL)
	{
		return bstCriaCelula = bstCriaCelula(chave);
		* ajustar = true;
	}
	else
	{
		if (chave < raiz->chave)
		{
			raiz->fEsq = avlInsert(raiz->fEsq, chave, ajustar);
			if (* ajustar)
			{
				switch (raiz->fatorBalanceamento)
				{
					case 1:
						raiz->fatorBalanceamento = 0;
						* ajustar = false;
						break;
					case 0:
						raiz->fatorBalanceamento = -1;
						break;
					case -1:
						raiz = rotL(raiz);
						* ajustar = false;
						break;
				}
			}
		}
		else
		{
			raiz->fDir = avlInsert(raiz->fDir, chave, ajustar);
			if (* ajustar)
			{
				switch (raiz->fatorBalanceamento)
				{
					case -1:
						raiz->fatorBalanceamento = 0;
						* ajustar = false;
						break;
					case 0:
						raiz->fatorBalanceamento = 1;
						break;
					case 1:
						raiz = rotR(raiz);
						* ajustar = false;
						break;
				}
			}
		}
	}
	return raiz;
}