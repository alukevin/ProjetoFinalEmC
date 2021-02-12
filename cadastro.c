#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cadastro.h"

int menuCadastro(void)
{
	int opcao = 0;

	do
	{
		printf("\n*** Menu de Cadastro *** \n");
		printf("Escolha uma opcao:\n");
		printf("1.Cadastrar aluno\n");
		printf("2.Cadastrar obra\n");
		printf("3.Excluir aluno\n");
		printf("4.Excluir obra\n");
		printf("5.Voltar \n");
		printf("\nDigite uma opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			cadastrar_aluno();
			break;
		case 2:
			cadastrar_obra();
			break;

		case 3:
			excluir_aluno();
			break;

		case 4:
			excluir_obra();
			break;

		case 5:
			menu();
			break;
		default:
			printf("Opcao invalida! Tente novamente.\n\n");
			break;
		}
	} while (opcao != 3);

	return opcao;
}
