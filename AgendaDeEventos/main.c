#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Evento *listaEventos = NULL;
    int quantidade = 0;
    carregarEventos(&listaEventos, &quantidade);
    int opcao;
    do {
        exibirMenu();
        printf("Escolha uma opção:\n> ");
        opcao = lerInteiro();
        switch (opcao) {
            case 1: cadastrarEvento(&listaEventos, &quantidade); break;
            case 2: mostrarTodosEventos(listaEventos, quantidade); break;
            case 3: mostrarEventosPorData(listaEventos, quantidade); break;
            case 4: mostrarEventosPorDescricao(listaEventos, quantidade); break;
            case 5: removerEvento(&listaEventos, &quantidade); break;
            case 6:
                salvarEventos(listaEventos, quantidade);
                printf("Eventos salvos. Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
                esperarEnter();
                break;
        }
    } while (opcao != 6);
    free(listaEventos);
    return 0;
}