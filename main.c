#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	int noValor;
	int altura;
	struct no *esquerda;
	struct no *direita;
} No;

main(){
	int condicao=1;
	
	do{
		printf("Inicio do programa\n");
		printf("Digite '1' para inserir elemento na arvore\n");
		printf("Digite '2' para excluir elemento x da arvore\n");
		printf("Digite '3' para exibir a arvore em Pre-ordem\n");
		printf("Digite '4' para exibir a arvore em Pos-ordem\n");
		printf("Digite '5' para exibir a arvore em Ordem Simetrica\n");
		printf("Digite '6' para exibir em formato de Grafos\n");
		printf("Digite '7' para buscar um elemento x na arvore\n");
		printf("Digite '8' para editar um elemento x da arvore\n");
		printf("Digite '9' para balancear a arvore\n");
		printf("Digite '0' para sair do programa\n");
		scanf("%d", &condicao);
		
		switch(condicao){
			
			case 0:
				return 0;	
			break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
		
		}
		
	}while(condicao!=0);

}
