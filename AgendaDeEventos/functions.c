#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include <windows.h>

void limparTela() {
    system("cls");
}

void pcenter(char texto[]) {
    int largura = 135;
    int tamanho = strlen(texto);
    int espacos = (largura - tamanho) / 2;

    for (int i = 0; i < espacos; i++)
        printf(" ");

    printf("%s", texto);
}

void esperarEnter() {
    printf("\nAperte ENTER para voltar ao menu...");
    getchar();
}

int lerInteiro() {
    int valor;
    char lixo;

    while (scanf("%d", &valor) != 1) {
        while ((lixo = getchar()) != '\n' && lixo != EOF);
        printf("Entrada inválida. Digite um número:\n> ");
    }

    while ((lixo = getchar()) != '\n' && lixo != EOF);

    return valor;
}

void exibirMenu() {
    limparTela();

    pcenter("=============================================================\n");
    printf("                                           █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗\n");
    printf("                                          ██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗\n");
    printf("                                          ███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║\n");
    printf("                                          ██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║\n");
    printf("                                          ██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║\n");
    printf("                                          ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝\n");
    pcenter("A G E N D A   D E   E V E N T O S\n");
    pcenter("=============================================================\n");
    pcenter("1. Cadastrar novo evento\n");
    pcenter("2. Mostrar todos os eventos\n");
    pcenter("3. Buscar evento por data\n");
    pcenter("4. Buscar evento por descrição\n");
    pcenter("5. Remover evento\n");
    pcenter("6. Sair\n");
}

void cadastrarEvento(Evento **lista, int *quantidade) {
    Evento novo;

    printf("Dia:\n> ");
    novo.data.dia = lerInteiro();

    printf("Mês:\n> ");
    novo.data.mes = lerInteiro();

    printf("Ano:\n> ");
    novo.data.ano = lerInteiro();

    printf("Hora início:\n> ");
    novo.inicio.hora = lerInteiro();

    printf("Minuto início:\n> ");
    novo.inicio.minuto = lerInteiro();

    printf("Hora fim:\n> ");
    novo.fim.hora = lerInteiro();

    printf("Minuto fim:\n> ");
    novo.fim.minuto = lerInteiro();

    printf("Descrição:\n> ");
    fgets(novo.descricao, 50, stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    printf("Local:\n> ");
    fgets(novo.local, 50, stdin);
    novo.local[strcspn(novo.local, "\n")] = '\0';

    *lista = realloc(*lista, (*quantidade + 1) * sizeof(Evento));
    (*lista)[*quantidade] = novo;
    (*quantidade)++;

    printf("\nEvento cadastrado!\n");
    esperarEnter();
}

void mostrarTodosEventos(Evento *lista, int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum evento cadastrado.\n");
        esperarEnter();
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        Evento e = lista[i];

        printf("\nEvento %d:\n", i + 1);
        printf("Data: %02d/%02d/%04d\n", e.data.dia, e.data.mes, e.data.ano);
        printf("Início: %02d:%02d\n", e.inicio.hora, e.inicio.minuto);
        printf("Fim: %02d:%02d\n", e.fim.hora, e.fim.minuto);
        printf("Descrição: %s\n", e.descricao);
        printf("Local: %s\n", e.local);
    }

    esperarEnter();
}

void mostrarEventosPorData(Evento *lista, int quantidade) {
    int dia, mes, ano;
    int achou = 0;

    printf("Dia:\n> ");
    dia = lerInteiro();
    printf("Mês:\n> ");
    mes = lerInteiro();
    printf("Ano:\n> ");
    ano = lerInteiro();

    for (int i = 0; i < quantidade; i++) {
        if (lista[i].data.dia == dia &&
            lista[i].data.mes == mes &&
            lista[i].data.ano == ano) {

            Evento e = lista[i];

            printf("\nEvento encontrado:\n");
            printf("Início: %02d:%02d\n", e.inicio.hora, e.inicio.minuto);
            printf("Fim: %02d:%02d\n", e.fim.hora, e.fim.minuto);
            printf("Descrição: %s\n", e.descricao);
            printf("Local: %s\n", e.local);

            achou = 1;
        }
    }

    if (!achou)
        printf("\nNenhum evento nesta data.\n");

    esperarEnter();
}

void mostrarEventosPorDescricao(Evento *lista, int quantidade) {
    char busca[50];
    int achou = 0;

    printf("Descrição exata:\n> ");
    fgets(busca, 50, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(lista[i].descricao, busca) == 0) {
            Evento e = lista[i];

            printf("\nEvento encontrado:\n");
            printf("Data: %02d/%02d/%04d\n", e.data.dia, e.data.mes, e.data.ano);
            printf("Início: %02d:%02d\n", e.inicio.hora, e.inicio.minuto);
            printf("Fim: %02d:%02d\n", e.fim.hora, e.fim.minuto);
            printf("Local: %s\n", e.local);

            achou = 1;
        }
    }

    if (!achou)
        printf("\nNenhum evento com essa descrição.\n");

    esperarEnter();
}

void removerEvento(Evento **lista, int *quantidade) {

    if (*quantidade == 0) {
        printf("Nenhum evento para remover.\n");
        esperarEnter();
        return;
    }

    int indice;

    printf("Número do evento para remover (1 a %d, ou 0 para cancelar):\n> ", *quantidade);
    indice = lerInteiro();

    if (indice == 0) {
        printf("Remoção cancelada.\n");
        esperarEnter();
        return;
    }

    while (indice < 0 || indice > *quantidade) {
        printf("Índice inválido!\n");
        printf("Digite um número entre 1 e %d, ou 0 para cancelar:\n> ", *quantidade);
        indice = lerInteiro();

        if (indice == 0) {
            printf("Remoção cancelada.\n");
            esperarEnter();
            return;
        }
    }

    for (int i = indice - 1; i < *quantidade - 1; i++)
        (*lista)[i] = (*lista)[i + 1];

    (*quantidade)--;

    *lista = realloc(*lista, (*quantidade) * sizeof(Evento));

    printf("Evento removido com sucesso.\n");
    esperarEnter();
}

void salvarEventos(Evento *lista, int quantidade) {
    FILE *arq = fopen("eventos.txt", "w");
    if (!arq) return;

    for (int i = 0; i < quantidade; i++) {
        Evento e = lista[i];

        fprintf(arq,
            "%d %d %d %d %d %d %d \"%s\" \"%s\"\n",
            e.data.dia, e.data.mes, e.data.ano,
            e.inicio.hora, e.inicio.minuto,
            e.fim.hora, e.fim.minuto,
            e.descricao, e.local
        );
    }

    fclose(arq);
}

void carregarEventos(Evento **lista, int *quantidade) {
    FILE *arq = fopen("eventos.txt", "r");
    if (!arq) return;

    Evento temp;

    while (fscanf(arq,
        "%d %d %d %d %d %d %d \"%49[^\"]\" \"%49[^\"]\"",
        &temp.data.dia, &temp.data.mes, &temp.data.ano,
        &temp.inicio.hora, &temp.inicio.minuto,
        &temp.fim.hora, &temp.fim.minuto,
        temp.descricao, temp.local
    ) == 9) {
        *lista = realloc(*lista, (*quantidade + 1) * sizeof(Evento));
        (*lista)[*quantidade] = temp;
        (*quantidade)++;
    }

    fclose(arq);
}