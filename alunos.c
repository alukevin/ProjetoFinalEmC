#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "alunos.h"

Aluno *aluno;

unsigned int indice = 0;

void cadastrar_aluno(void)
{
	int RA = 0;
	int tamanho_string = 0;
	int i;

	printf("\n*** Cadastro de alunos ***\n");
	printf("Informe o RA do aluno: ");
	scanf("%d", &RA);

	for (i = 0; i < indice; i++)
	{
		if (RA == aluno[i].RA)
		{
			printf("\nAluno ja cadastrado!\n");
			menu();
			exit(0);
		}
	}

	aluno[indice].RA = RA;

	printf("\nDigite o telefone do aluno para contato: ");
	getchar();
	fgets(aluno[indice].tel, 20, stdin);

	printf("\nDigite o nome do aluno: ");
	fgets(aluno[indice].nome, 100, stdin);

	aluno[indice].nome[strlen(aluno[indice].nome) - 1] = '\0';
	aluno[indice].tel[strlen(aluno[indice].tel) - 1] = '\0';
	printf("\nCadastro realizado com sucesso!\n\n");
	indice++;
	gravar_alunos();

	/* Realocar de 10 em 10 os alunos */
	if (indice % 10 == 0)
	{
		realocar_alunos();
	}
}

void excluir_aluno(void)
{
	int RA = 0;
	int i;

	printf("\n*** Exclusao de Alunos ***\n");
	printf("Informe o RA do Aluno:");
	scanf("%d", &RA);

	for (i = 0; i < indice; i++)
	{
		if (RA == aluno[i].RA)
		{
			aluno[i].RA = 0;
			printf("Aluno removido com sucesso!\n");
			gravar_alunos();
			menu();
			exit(0);
		}
	}

	printf("\nAluno nao encontrado!\n\n");
}

void realocar_alunos(void)
{
	aluno = calloc(indice, sizeof(Aluno *));
	indice += 10;
}

void gravar_alunos()
{
	FILE *arquivo;
	int i;
	arquivo = fopen("database/alunos.txt", "w");

	if (arquivo == NULL)
	{
		printf("Erro ao salvar os alunos no arquivo!");
		exit(1);
	}

	for (i = 0; i < indice; i++)
	{
		if (aluno[i].RA != 0)
		{
			fprintf(arquivo, "Nome do Aluno: %s, ", aluno[i].nome);
			fprintf(arquivo, "RA: %d, ", aluno[i].RA);
			fprintf(arquivo, "Telefone: %s ", aluno[i].tel);
			fprintf(arquivo, "\n");
		}
	}

	fclose(arquivo);
}
