#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void listar(char filename[], char tipo[])
{

	FILE *arquivo;

	arquivo = fopen(filename, "r");

	printf("\n*** Listagem de %s ***\n", tipo);
	if (arquivo == NULL)
	{
		printf("Ainda nao ha registros de %s!", tipo);
	}

	int index = 1;
	char line[1000];

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		printf("[%d]: ", index);
		printf("%s", line);
		index++;
	}
	printf("\n");
	fclose(arquivo);
}
