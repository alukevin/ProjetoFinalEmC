#ifndef _RESERVA_H
#define _RESERVA_H

int menuReserva(void);
typedef struct
{
    char dataEmprestimo[30];
    unsigned int RA;
    unsigned int codlivro;
    unsigned int consultar;
} Empresta;

int MenuReserva(void);
void realocar_emprestimo(void);
void cadastrar_Reserva(void);
void devolver_Reserva(void);
void ListaReserva(void);
void gravar_reservas(void);

#endif
