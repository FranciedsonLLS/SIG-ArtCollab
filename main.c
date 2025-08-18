#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
// Funções 
void nada() {
    printf("NADA");
};


void menu_main() {
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do {
    // MENU PRINCIPAL
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║              🌟 UniArt 🌟              ║\n");
    printf("║                                        ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  [1] ➜ Cadastro de Produtos            ║\n");
    printf("║  [2] ➜ Gestão de Estoque               ║\n");
    printf("║  [3] ➜ Cadastro de Colaborador         ║\n");
    printf("║  [4] ➜ Registrar Venda                 ║\n");
    printf("║  [5] ➜ Relatórios                      ║\n");
    printf("║  [6] ➜ ............                    ║\n");
    printf("║  [0] ➜ Sair                            ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            nada();
            break;
        case 2:
            nada();
            break;
        case 3:
            nada();
            break;
        case 0:
            printf("\nEncerrando\n");
            break;
        default:
            printf("\nOpcao Invalida\n");
        }

    } while(opcao != 0);

    
}

void func3() {
    printf("FUNC3");
}

int main() {
    int opcao;

    do {
        // Menu principal
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║                                        ║\n");
        printf("║             🌟 UniArt 🌟               ║\n");
        printf("║                                        ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Menu                            ║\n");
        printf("║  [2] ➜ Equipe                          ║\n");
        printf("║  [3] ➜ Sobre                           ║\n");
        printf("║  [0] ➜ Sair                            ║\n");
        printf("╚════════════════════════════════════════╝\n");

        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        // Limpar tela 
        system("clear||cls");

        switch(opcao) {
            case 1:
                menu_main();
                break;
            case 2:
                func3();
                break;
            case 3:
                sobre_main();
                break;
            case 0:
                printf("\nEncerrando\n");
                break;
            default:
                printf("\nOpcao Invalida\n");
        }
    } while(opcao != 0);

    return 0;
}


