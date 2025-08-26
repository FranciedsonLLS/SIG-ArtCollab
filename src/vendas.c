#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/vendas.h"

void menu_Vendas() {
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do {
        // MENU DE VENDAS
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║             👥 Menu Vendas             ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Venda                 ║\n");
        printf("║  [2] ➜ Listar Vendas                   ║\n");
        printf("║  [3] ➜ Atualizar Venda                 ║\n");
        printf("║  [4] ➜ Excluir Venda                   ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // CASES DO MENU (SEM FUNCIONALIDADE AINDA)
        switch(opcao) {
            case 1:
                printf("\nOpção 1 selecionada: Cadastrar Venda\n");
                break;
            case 2:
                printf("\nOpção 2 selecionada: Listar Vendas\n");
                break;
            case 3:
                printf("\nOpção 3 selecionada: Atualizar Venda\n");
                break;
            case 4:
                printf("\nOpção 4 selecionada: Excluir Venda\n");
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