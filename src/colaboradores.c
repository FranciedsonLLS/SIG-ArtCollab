#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/colaboradores.h"

void menu_colaboradores() {
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do {
        // MENU DE COLABORADORES
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║          👥 Menu Colaboradores         ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Colaborador           ║\n");
        printf("║  [2] ➜ Listar Colaboradores            ║\n");
        printf("║  [3] ➜ Atualizar Colaborador           ║\n");
        printf("║  [4] ➜ Excluir Colaborador             ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // CASES DO MENU (SEM FUNCIONALIDADE AINDA)
        switch(opcao) {
            case 1:
                printf("\nOpção 1 selecionada: Cadastrar Colaborador\n");
                break;
            case 2:
                printf("\nOpção 2 selecionada: Listar Colaboradores\n");
                break;
            case 3:
                printf("\nOpção 3 selecionada: Atualizar Colaborador\n");
                break;
            case 4:
                printf("\nOpção 4 selecionada: Excluir Colaborador\n");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\n❌ Opção inválida!\n");
        }

        if(opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
            getchar();
        }

    } while(opcao != 0);
}
