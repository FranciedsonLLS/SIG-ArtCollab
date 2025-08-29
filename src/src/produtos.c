#include <stdio.h>
#include <stdlib.h>
#include "../include/produtos.h"

void menu_Produtos() {
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do {

        // MENU DE PRODUTOS
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║             🛒 Menu Produtos           ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Produto               ║\n");
        printf("║  [2] ➜ Listar Produtos                 ║\n");
        printf("║  [3] ➜ Atualizar Produto               ║\n");
        printf("║  [4] ➜ Excluir Produto                 ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // CASES DO MENU (sem implementar CRUD)
        switch(opcao) {
            case 1:
                // ADD ( ADICIONAR AQ )
                printf("\nOpção 1 selecionada: Cadastrar Produto\n");
                break;
            case 2:
                // (LISTAR (ADICIONAR AQ))
                printf("\nOpção 2 selecionada: Listar Produtos\n");
                break;
            case 3:
                // ATT (ADICIONAR AQ)
                printf("\nOpção 3 selecionada: Atualizar Produto\n");
                break;
            case 4:
                // DELETE
                printf("\nOpção 4 selecionada: Excluir Produto\n");
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
