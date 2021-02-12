#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "obras.h"

Obra *obra;

unsigned int indice_2 = 0;

void cadastrar_obra(void)
{
	int codigo = 0;
	int i;

	printf("\n*** Cadastro de obras ***\n");
	printf("Informe o codigo da obra: ");
	scanf("%d", &codigo);

	for (i = 0; i < indice_2; i++)
	{
		if (codigo == obra[i].codigo)
		{
			printf("\nObra ja cadastrada!\n");
			menu();
			exit(0);
		}
	}

	obra[indice_2].codigo = codigo;

	printf("\nDigite o numero da edicao: ");
	scanf("%d", &obra[indice_2].edicao);
	getchar();

	printf("\nDigite a data de lancamento: ");
	fgets(obra[indice_2].lancamento, 30, stdin);

	printf("\nDigite o nome da obra: ");
	fgets(obra[indice_2].nome, 200, stdin);

	printf("\nDigite o nome do autor da obra: ");
	fgets(obra[indice_2].autor, 50, stdin);

	printf("\nDigite a area de conhecimento da obra: ");
	fgets(obra[indice_2].area, 50, stdin);

	obra[indice_2].nome[strlen(obra[indice_2].nome) - 1] = '\0';
	obra[indice_2].autor[strlen(obra[indice_2].autor) - 1] = '\0';
	obra[indice_2].area[strlen(obra[indice_2].area) - 1] = '\0';
	obra[indice_2].lancamento[strlen(obra[indice_2].lancamento) - 1] = '\0';

	printf("\n Cadastro realizado com sucesso! \n \n ");
	indice_2++;
	gravar_obras();

	/* Realocar de 10 em 10 as obras */
	if (indice_2 % 10 == 0)
	{
		realocar_obras();
	}
}

void excluir_obra(void)
{
	int codigo = 0;
	int i;

	printf("\n*** Exclusao de Obras ***\n");
	printf("Informe o codigo da obra: ");
	scanf("%d", &codigo);

	for (i = 0; i < indice_2; i++)
	{
		if (codigo == obra[i].codigo)
		{
			obra[i].codigo = 0;
			printf("Obra removida com sucesso!\n");
			gravar_obras();
			menu();
			exit(0);
		}
	}

	printf("\nObra nao encontrada!\n\n");
}

void realocar_obras(void)
{
	obra = calloc(indice_2, sizeof(Obra *));
	indice_2 += 10;
}

void gravar_obras()
{
	FILE *arquivo;
	int i;
	arquivo = fopen("database/obras.txt", "w");

	if (arquivo == NULL)
	{
		printf("Erro ao salvar as obras no arquivo!");
		exit(1);
	}

	for (i = 0; i < indice_2; i++)
	{
		if (obra[i].codigo != 0)
		{
			fprintf(arquivo, "Codigo: %d, ", obra[i].codigo);
			fprintf(arquivo, "Nome: %s, ", obra[i].nome);
			fprintf(arquivo, "Autor: %s, ", obra[i].autor);
			fprintf(arquivo, "Area: %s, ", obra[i].area);
			fprintf(arquivo, "Edicao: %d, ", obra[i].edicao);
			fprintf(arquivo, "Lancamento: %s", obra[i].lancamento);
			fprintf(arquivo, "\n");
		}
	}

	fclose(arquivo);
}
