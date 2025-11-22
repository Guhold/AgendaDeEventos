#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int hora, minuto;
} horario;

typedef struct {
    data diaEvento;
    horario horarioInicio;
    horario horarioFim;
    char descricao[50];
    char local[50];
} evento;

void menuInicial();
int lerInteiro();
void cadastraEvento();
void mostraEventos();
void mostraEventosData();
void mostraEventosDesc();
void removeEvento();
void erroDigitoInvalido();
#endif