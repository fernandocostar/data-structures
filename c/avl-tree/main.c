#include "avl.h" 

int main() {
	Arvore r = NULL; /* MUITO importante! */
	char op;
	int k;
	do {
		scanf(" %c", &op);
		if (op == 'I') {
			scanf("%d", &k);
			InsereArvore(&r, k);
		}
	} while(op != 'S');
	ImprimeArvore(r, 0);
	printf("Altura = %d\n", Altura(r));
	return 0;
}