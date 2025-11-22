#include "definitions.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    SetConsoleOutputCP(CP_UTF8); // Possibilita o uso de caracteres especiais
    FILE *arquivo;
    int opcaoEscolhida;
    menuInicial();
    

    do {
        opcaoEscolhida = lerInteiro();

        switch (opcaoEscolhida){
            case 1:
                cadastraEvento();
                break;
            case 2: 
                mostraEventos();
                break;
            case 3:
                mostraEventosData();
                break;
            case 4:
                mostraEventosDesc();
                break;
            case 5:
                removeEvento();
                break;
            case 6: break;
            default:
                erroDigitoInvalido();
                break;
        }
    } while (opcaoEscolhida != 6);
}