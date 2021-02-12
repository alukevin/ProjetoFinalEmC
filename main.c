/* Bibliotecas Externas */
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/* Bibliotecas Internas */
#include "alunos.h"
#include "alunos.c"
#include "obras.h"
#include "obras.c"
#include "reserva.h"
#include "reserva.c"
#include "consulta.h"
#include "consulta.c"
#include "cadastro.h"
#include "cadastro.c"
#include "listar.c"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	aluno = (Aluno *)malloc(indice * sizeof(Aluno));
	obra = (Obra *)malloc(indice_2 * sizeof(Obra));
	empresta = (Empresta *)malloc(indice_3 * sizeof(Empresta));
	menu();

	if (!aluno)
	{
		printf("Memoria nao alocada\n");
		exit(1);
	}
	if (!obra)
	{
		printf("Memoria nao alocada.\n");
		exit(1);
	}
	if (!empresta)
	{
		printf("Memoria nao alocada.\n");
		exit(1);
	}

	free(aluno);
	free(obra);
	free(empresta);
	return 0;
}

int menu()
{
	int opcao = 0;

	do
	{
		system("color FC");
		printf("\n*** Menu Principal ***\n");
		printf("Escolha uma opcao:\n");
		printf("1.Cadastro e Opcoes\n");
		printf("2.Reserva\n");
		printf("3.Consultar Livro\n");
		printf("4.Listar Registros\n");
		printf("5.Sair\n");
		printf("\nDigite uma opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			menuCadastro();
			break;

		case 2:
			MenuReserva();
			break;

		case 3:
			consultarLivro();
			break;

		case 4:
			listar("database/alunos.txt", "Alunos");
			listar("database/obras.txt", "Obras");
			listar("database/reservas.txt", "Reservas");
			break;

		case 5:
			exit(0);

		default:
			printf("Opcao invalida! Tente novamente. \n\n ");
			break;
		}

	} while (1);

	return opcao;
}
