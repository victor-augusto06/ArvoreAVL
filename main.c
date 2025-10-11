#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	int noValor;
	int altura;
	struct no *esquerda;
	struct no *direita;
} No;



void preOrdem(No *raiz){
	if(raiz==NULL){
		return;
	}
	printf("%d |",raiz->noValor);
	preOrdem(raiz->esquerda);
	preOrdem(raiz->direita);
}

void posOrdem(No *raiz){
	if(raiz==NULL){
		return;
	}
	posOrdem(raiz->esquerda);
	posOrdem(raiz->direita);
	printf("%d |",raiz->noValor);
}

void simetrico(No *raiz){
	if(raiz==NULL){
		return;
	}
	simetrico(raiz->esquerda);
	printf("%d |",raiz->noValor);
	simetrico(raiz->direita);	
}

No* cria_novo_no(int valor){
	No *novo = (No *)malloc(sizeof(No));
	novo->noValor=valor;
	novo->esquerda=NULL;
	novo->direita=NULL;
	novo->altura=1;
	
	return novo;
}

No* inserir(No* no_atual, int valor){
	if(no_atual==NULL){
		return cria_novo_no(valor);
	}
	else{
		if(no_atual->noValor>valor){
			no_atual->esquerda=inserir(no_atual->esquerda, valor);
		}
		else if(no_atual->noValor<valor){
			no_atual->direita=inserir(no_atual->direita, valor);
		}
	}
	return no_atual;
}

int main(){
	int condicao=1;
	No *raiz=NULL;

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
		printf("Digite '0' para sair do programa\n");
		scanf("%d", &condicao);
		
		switch(condicao){
			
			case 0:{
				return 0;
				break;
			}

			case 1: {
				int valor_novo;
				printf("Digite o valor que deseja inserir: \n");
				scanf("%d", &valor_novo);
				raiz = inserir(raiz, valor_novo);
				printf("%d foi inserido com sucesso!\n\n", valor_novo);
				break;
			}

			case 2:{
				
				break;
			}
			
			case 3:{
				printf("Iniciando a exibicao em modo Pre-Ordem!\n");
				preOrdem(raiz);
				break;
			}
			
			case 4:{
				printf("Iniciando a exibicao em modo Pos-Ordem!\n");
				posOrdem(raiz);	
				break;
			}
			
			case 5:{
				printf("Iniciando a exibicao em modo Simetrico!\n");
				simetrico(raiz);
				break;
			}			
			
			case 6:{
				break;
			}
				
			case 7:{
				break;
			}
			
			case 8:{
				break;
			}
		}
		
	}while(condicao!=0);

}
