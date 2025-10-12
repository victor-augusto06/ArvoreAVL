#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int noValor;
	int altura;
	struct no *esquerda;
	struct no *direita;
} No;
int altura(No* no);
int maior(int a, int b);
No* rotacao_direita(No* no);
No* rotacao_esquerda(No* no);
No* encontrar_menor_No(No* no);
No* inserir(No* no_atual, int valor);
No* excluir(No* no_atual, int valor);
No* busca_no(No* no, int valor);
No* cria_novo_no(int valor);
void preOrdem(No *raiz);
void posOrdem(No *raiz);
void simetrico(No *raiz);

int altura(No* no){
	if(no==NULL)
		return 0;
	else
		return no->altura;
}

int maior(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

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

No* rotacao_direita(No* no) {
	No* filho_esquerda = no->esquerda;
	No* subArvore_direita = filho_esquerda->direita;

	no->esquerda = subArvore_direita;
	filho_esquerda->direita = no;
	no->altura=1 + maior(altura(no->esquerda),altura(no->direita));
	filho_esquerda->altura = 1 + maior(altura(filho_esquerda->esquerda),altura(filho_esquerda->direita));
	return filho_esquerda;
}

No* rotacao_esquerda(No* no) {
	No* filho_direita = no->direita;
	No* subArvore_esquerda = filho_direita->esquerda;

	no->direita = subArvore_esquerda;
	filho_direita->esquerda = no;
	no->altura=1 + maior(altura(no->esquerda),altura(no->direita));
	filho_direita->altura = 1 + maior(altura(filho_direita->esquerda),altura(filho_direita->direita));
	return filho_direita;
}

No* inserir(No* no_atual, int valor){
	int fator_balanceamento=0;

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
	no_atual->altura= 1 + maior(altura(no_atual->esquerda),altura(no_atual->direita));
	fator_balanceamento=altura(no_atual->esquerda) - altura(no_atual->direita);
	if(fator_balanceamento>1){
		if(no_atual->esquerda->noValor>valor){
			return rotacao_direita(no_atual);
		}else{
			no_atual->esquerda = rotacao_esquerda(no_atual->esquerda);
			return rotacao_direita(no_atual);
		}
	}else if(fator_balanceamento<-1){
		if(no_atual->direita->noValor<valor){
			return rotacao_esquerda(no_atual);
		}else{
			no_atual->direita = rotacao_direita(no_atual->direita);
			return rotacao_esquerda(no_atual);
		}
	}
	return no_atual;
}

No* busca_no(No* no, int valor){
	if(no==NULL){
		return NULL;
	}

	if(no->noValor==valor)
		return no;
	else if(no->noValor>valor)
		return busca_no(no->esquerda, valor);
	else 
		return busca_no(no->direita,valor);
}

No* encontrar_menor_No(No* no) {
    while (no && no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

No* excluir(No* no_atual, int valor){
	int fator_balanceamento=0;

	if(no_atual==NULL){
		return NULL;
	}

	if(no_atual->noValor>valor){
		no_atual->esquerda = excluir(no_atual->esquerda,valor);
	}
	else if(no_atual->noValor<valor){
		no_atual->direita = excluir(no_atual->direita,valor);
	}else{
		if(no_atual->direita!=NULL && no_atual->esquerda!=NULL){
			No* temp = encontrar_menor_No(no_atual->direita);
			no_atual->noValor = temp->noValor;
			no_atual->direita = excluir(no_atual->direita, temp->noValor);

		}else if(no_atual->direita!=NULL){
			No* temp = no_atual->direita;
			free(no_atual);
			return temp;

		}else if(no_atual->esquerda!=NULL){
			No* temp = no_atual->esquerda;
			free(no_atual);
			return temp;

		}else{
			free(no_atual);
			return NULL;
		}
	}
	no_atual->altura= 1 + maior(altura(no_atual->esquerda),altura(no_atual->direita));
	fator_balanceamento=altura(no_atual->esquerda) - altura(no_atual->direita);
	if(fator_balanceamento>1){
		if(altura(no_atual->esquerda->esquerda)-altura(no_atual->esquerda->direita)>=0){
			return rotacao_direita(no_atual);
		}else{
			no_atual->esquerda = rotacao_esquerda(no_atual->esquerda);
			return rotacao_direita(no_atual);
		}
	}else if(fator_balanceamento<-1){
		if(altura(no_atual->direita->esquerda)-altura(no_atual->direita->direita)<=0){
			return rotacao_esquerda(no_atual);
		}else{
			no_atual->direita = rotacao_direita(no_atual->direita);
			return rotacao_esquerda(no_atual);
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
				int valor_excluir;
				printf("Digite o valor que deseja excluir: ");
				scanf("%d", &valor_excluir);
				raiz = excluir(raiz, valor_excluir);
				printf("Operacao de exclusao para o valor %d finalizada.\n\n", valor_excluir);
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
				int valorBusca;
				printf("Qual no você deseja procurar na arvore?");
				scanf("%d",&valorBusca);
				No* no_encontrado = busca_no(raiz, valorBusca);

				if(no_encontrado == NULL)
					printf("Nao foi possivel encontrar o no %d\n", valorBusca);
				else
					printf("Valor %d encontrado na arvore! Altura do no: %d\n\n", no_encontrado->noValor, no_encontrado->altura);
				
				break;
			}
			
			case 8:{
				int valorAntigo, valorNovo;
				printf("Qual no você deseja alterar na arvore?");
				scanf("%d",&valorAntigo);
				if(busca_no(raiz, valorAntigo)==NULL){
					printf("Valor a ser editado não foi encontrado");
				}else{
					printf("Qual o novo valor?");
					scanf("%d",&valorNovo);
					raiz = excluir(raiz, valorAntigo);
					raiz = inserir(raiz, valorNovo);
					printf("Operação concluída!");
				}
				break;
			}
		}
		
	}while(condicao!=0);
}