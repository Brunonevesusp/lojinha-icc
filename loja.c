#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// estrutura referente ao estoque da loja
typedef struct loja
{
    int id, qtd;
    float preço;
    char nome[50];
} Estoque;


void insere_produto(Estoque *vet, int indice)
{
    vet[indice].id = indice;
    scanf("%s", vet[indice].nome);
    scanf("%d", &vet[indice].qtd);
    scanf("%f", &vet[indice].preço);
}


void aumenta_estoque(Estoque *vet)
{
    int indice, aumento;
    scanf("%d", &indice);
    scanf("%d", &aumento);
    vet[indice].qtd += aumento;
}


void modifica_preco(Estoque *vet)
{
    int indice;
    scanf("%d", &indice);
    scanf("%f", &vet[indice].preço);
}


// função principal
int main(void)
{
    int produtosdia, indice = 0;
    char sigla[2];
    Estoque *vet;

    scanf("%d", &produtosdia);


    // alocação dinâmica do estoque utilizando um vetor de structs
    vet = (Estoque*)malloc(produtosdia * sizeof(Estoque));


    // laço de repetição para ler a entrada e chamar a função à que se refere o comando
    while(1)
    {
        scanf(" %s", sigla);

        if(strcmp(sigla, "FE") == 0)
        {
            break;
        }
        else if(strcmp(sigla, "IP") == 0)
        {
            insere_produto(vet, indice);
            indice++;
        }
        else if(strcmp(sigla, "AE") == 0)
        {
            aumenta_estoque(vet);
        }
        else if(strcmp(sigla, "MP") == 0)
        {
            modifica_preco(vet);
        }
        else if(strcmp(sigla, "VE") == 0)
        {
            // venda(vet);
        }
        else if(strcmp(sigla, "CE") == 0)
        {
            // consulta_estoque(vet);
        }
        else if(strcmp(sigla, "CS") == 0)
        {
            // consulta_saldo(vet);
        }
        else if(strcmp(sigla, "FE") == 0)
        {
            finaliza_dia();
        }
    }

    printf("%d\n", vet[0].id);
    printf("%s\n", vet[0].nome);
    printf("%.2f\n", vet[0].preço);
    printf("%d\n", vet[0].qtd);
}
