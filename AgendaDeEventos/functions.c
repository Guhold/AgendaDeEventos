#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuInicial() {
    printf("\n\n                           =============================================================\n");
    printf("                                                             \n");
    printf("                                  █████╗  ██████╗ ███████╗███╗   ██╗██████╗  █████╗        \n");
    printf("                                 ██╔══██╗██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔══██╗       \n");
    printf("                                 ███████║██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████║       \n");
    printf("                                 ██╔══██║██║   ██║██╔══╝  ██║╚██╗██║██║  ██║██╔══██║       \n");
    printf("                                 ██║  ██║╚██████╔╝███████╗██║ ╚████║██████╔╝██║  ██║       \n");
    printf("                                 ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝       \n");
    printf("                                                             \n");
    printf("                                         A G E N D A   D E   E V E N T O S           \n");
    printf("                                                             \n");
    printf("                           ==============================================================\n\n");
    printf("                                            1. Cadastrar um novo evento\n");
    printf("                                            2. Mostrar todos os eventos\n");
    printf("                                            3. Procurar evento por data\n");
    printf("                                          4. Procurar evento por descrição\n");
    printf("                                                 5. Remover evento\n");
    printf("                                                6. Sair do Programa\n");
}

int lerInteiro() {
    int valor;
    int c;

    while (1) {
        printf("> ");
        if (scanf("%d", &valor) == 1) {
            while ((c = getchar()) != '\n' && c != EOF) { }
            return valor;
        }

        printf("                                         Entrada inválida. Digite um número:\n");
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

void cadastraEvento() {
    // codigo
}

void mostraEventos() {
    // codigo
}

void mostraEventosData() {
    // codigo
}

void mostraEventosDesc() {
    // codigo
}

void removeEvento() {
    // codigo
}

void erroDigitoInvalido() {
    printf("                                     Dígito inválido! Escreva um valor entre 1-6: \n");
}