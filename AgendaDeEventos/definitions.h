#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int hora, minuto;
} Horario;

typedef struct {
    Data data;
    Horario inicio;
    Horario fim;
    char descricao[50];
    char local[50];
} Evento;

void limparTela();
void pcenter(char texto[]);
void esperarEnter();
int lerInteiro();
void exibirMenu();
void cadastrarEvento(Evento **lista, int *quantidade);
void mostrarTodosEventos(Evento *lista, int quantidade);
void mostrarEventosPorData(Evento *lista, int quantidade);
void mostrarEventosPorDescricao(Evento *lista, int quantidade);
void removerEvento(Evento **lista, int *quantidade);
void ordenarEventos(Evento *lista, int quantidade);
int conflitoEvento(Evento *lista, int quantidade, Evento novo);
void salvarEventos(Evento *lista, int quantidade);
void carregarEventos(Evento **lista, int *quantidade);

#endif