#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "consulta.h"

void consultarLivro(void)
{
    int opcaoConsulta = 0;
    printf("Digite o codigo do livro a ser consultado: ");
    scanf("%d", &opcaoConsulta);
    if (consultlivro(opcaoConsulta) == 1)
    {
        printf("Livro disponivel, mas emprestado!\n");
    }
    else
    {
        if (consultlivro(opcaoConsulta) == 2)
        {
            printf("Livro disponivel!\n");
        }
        else
        {
            printf("Livro indisponivel!\n");
        }
    }
}

int consultlivro(int codigo)
{
    int disponivel = 0;
    int i = 0;

    for (i = 0; i < indice_2; i++)
    {
        if (codigo == obra[i].codigo)
        {
            disponivel = 2;
        }
    }

    for (i = 0; i < indice_3; i++)
    {
        if (codigo == empresta[i].codlivro)
        {
            disponivel = disponivel - 1;
        }
    }
    return disponivel;
}
