#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "reserva.h"

Empresta *empresta;

unsigned int indice_3 = 0;

int MenuReserva(void)
{
	int opcao = 0;

	do
	{
		printf("\n*** Menu de Reserva ***\n");
		printf("Escolha uma opcao:\n");
		printf("1.Reservar\n");
		printf("2.Devolver\n");
		printf("3.Listar Reservas\n");
		printf("4.Sair\n");
		printf("\nDigite uma opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			cadastrar_Reserva();
			break;
		case 2:
			devolver_Reserva();
			break;
		case 3:
			ListaReserva();
			break;
		default:
			if (opcao == 4)
			{
				menu();
				break;
			}
			printf("Opcao invalida! Tente novamente. \n\n");
			break;
		}
	} while (opcao != 4);

	return opcao;
}

void cadastrar_Reserva(void)
{
	int RA = 0;
	char dia[10];
	int codLivro = 0;
	int obraDisponivel = 0;
	int alunoCadastrado = 0;
	int i;

	printf("\n*** Emprestimo de Obras ***\n");
	printf("Informe o codigo da obra: ");
	scanf("%d", &codLivro);

	for (i = 0; i < indice_3; i++)
	{
		if (codLivro == empresta[i].codlivro)
		{
			printf("\nObra ja emprestada!\n");
			menu();
			exit(0);
		}
	}

	for (i = 0; i < indice_2; i++)
	{
		if (codLivro == obra[i].codigo)
		{
			obraDisponivel = 1;
		}
	}

	if (obraDisponivel == 1)
	{

		empresta[indice_3].codlivro = codLivro;

		printf("\nDigite o RA do aluno: ");
		scanf("%d", &empresta[indice_3].RA);
		getchar();

		for (i = 0; i < indice; i++)
		{
			if (empresta[indice_3].RA == aluno[i].RA)
			{
				alunoCadastrado = 1;
				break;
			}
		}
		if (alunoCadastrado == 0)
		{
			printf("Aluno nao cadastrado!\n");
			empresta[indice_3].RA = 0;
			menuCadastro();
		}

		printf("\nDigite a data de Emprestimo: ");
		fgets(empresta[indice_3].dataEmprestimo, 30, stdin);

		empresta[indice_3].dataEmprestimo[strlen(empresta[indice_3].dataEmprestimo) - 1] = '\0';
		printf("\nEmprestimo realizado com sucesso!\n\n");
		indice_3++;
		gravar_reservas();
	}
	else
	{
		printf("Obra nao existe ou indisponivel para reserva!\n");
		menu();
	}

	/* Realocar de 10 em 10 os emprestimos */
	if (indice_3 % 10 == 0)
	{

		realocar_emprestimo();
	}
}

void devolver_Reserva(void)
{
	int RA = 0;
	char dia[10];
	int codLivro = 0;

	int i;

	printf("\n*** Devolucao de Obras ***\n");
	printf("Informe o Codigo da Obra: ");
	scanf("%d", &codLivro);

	for (i = 0; i < indice_3; i++)
	{
		if (codLivro == empresta[i].codlivro)
		{
			empresta[i].codlivro = 0;
			printf("Obra devolvida com sucesso!\n");
			gravar_reservas();
			menu();
			exit(0);
		}
	}

	printf("\nA obra ainda nao foi emprestada!\n\n");
}

void realocar_emprestimo(void)
{
	empresta = calloc(indice_3, sizeof(Empresta *));
	indice_3 += 10;
}

void ListaReserva(void)
{
	int i;
	for (i = 0; i < indice_3; i++)
	{
		if (empresta[i].codlivro != 0)
		{
			printf("[%d]: ", i);
			printf("Codigo da obra: %d, ", empresta[i].codlivro);
			printf("RA do aluno: %d\n", empresta[i].RA);
			break;
		}
	}
}

void gravar_reservas()
{
	FILE *arquivo;
	int i;
	arquivo = fopen("database/reservas.txt", "w");

	if (arquivo == NULL)
	{
		printf("Erro ao salvar as reservas no arquivo!");
		exit(1);
	}

	for (i = 0; i < indice_3; i++)
	{
		if (empresta[i].codlivro != 0)
		{

			fprintf(arquivo, "RA: %d, ", empresta[i].RA);
			fprintf(arquivo, "Codigo da obra: %d, ", empresta[i].codlivro);
			fprintf(arquivo, "Data do emprestimo: %s ", empresta[i].dataEmprestimo);

			fprintf(arquivo, "\n");
		}
	}

	fclose(arquivo);
}
