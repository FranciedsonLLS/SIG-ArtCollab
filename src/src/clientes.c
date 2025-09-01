#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/clientes.h"

void menu_Clientes() {
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do {
        // MENU DE CLIENTES
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║            👥 Menu Clientes            ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Cliente               ║\n");
        printf("║  [2] ➜ Listar Clientes                 ║\n");
        printf("║  [3] ➜ Atualizar Cliente               ║\n");
        printf("║  [4] ➜ Excluir cliente                 ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // CASES DO MENU (SEM FUNCIONALIDADE AINDA)
        switch(opcao) {
            case 1:
                printf("\nOpção 1 selecionada: Cadastrar cliente\n");
                break;
            case 2:
                printf("\nOpção 2 selecionada: Listar clientes\n");
                break;
            case 3:
                printf("\nOpção 3 selecionada: Atualizar cliente\n");
                break;
            case 4:
                printf("\nOpção 4 selecionada: Excluir cliente\n");
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