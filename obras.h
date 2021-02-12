#ifndef _OBRAS_H
#define _OBRAS_H

typedef struct
{
    unsigned int edicao;
    unsigned int codigo;
    char lancamento[30];
    char nome[200];
    char autor[50];
    char area[50];
} Obra;

void cadastrar_obra(void);
void realocar_obras(void);
void gravar_obras(void);

#endif
