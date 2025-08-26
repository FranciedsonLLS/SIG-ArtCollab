#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/funcionarios.h"

void menu_Funcionarios() {
    // LIMPAR TELA
    system("clear||cls");

    int opcao;
    do {
        // MENU DE Funcionarios
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║          👥 Menu Funcionarios          ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Cadastrar Funcionario           ║\n");
        printf("║  [2] ➜ Listar Funcionarios            ║\n");
        printf("║  [3] ➜ Atualizar Funcionario           ║\n");
        printf("║  [4] ➜ Excluir Funcionario             ║\n");
        printf("║----------------------------------------║\n");
        printf("║  [0] ➜ Voltar ao Menu Principal        ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // CASES DO MENU (SEM FUNCIONALIDADE AINDA)
        switch(opcao) {
            case 1:
                printf("\nOpção 1 selecionada: Cadastrar Funcionario\n");
                break;
            case 2:
                printf("\nOpção 2 selecionada: Listar Funcionarios\n");
                break;
            case 3:
                printf("\nOpção 3 selecionada: Atualizar Funcionario\n");
                break;
            case 4:
                printf("\nOpção 4 selecionada: Excluir Funcionario\n");
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