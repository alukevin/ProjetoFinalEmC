#ifndef _ALUNOS_H
#define _ALUNOS_H

typedef struct
{
    char nome[100];
    unsigned int RA;
    char tel[20];
} Aluno;

void cadastrar_aluno(void);
void excluir_aluno(void);
void realocar_alunos(void);
void gravar_alunos(void);

#endif
