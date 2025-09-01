#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/clientes.h"
#define ARQUIVO_CLIENTES "dados/clientes.txt"

// GERA ID COM BASE NO TAMANHO DO txt
int gerarId() {
    FILE *file = fopen(ARQUIVO_CLIENTES, "r");
    if (!file) return 1; // se ainda n existir vai comecar do 1

    int id = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        id++;
    }
    fclose(file);
    return id + 1;
}

// CADASTRO CLIENTE
void cadastrarCliente() {
    Cliente c;
    c.id = gerarId();

    printf("\nDigite o nome: ");
    while(getchar() != '\n'); // limpa buffer
    fgets(c.nome, sizeof(c.nome), stdin);
    c.nome[strcspn(c.nome, "\n")] = 0;

    //criar modulo de veriicacao dps para telefone cpf e email
    printf("Digite o CPF (formato 000.000.000-00): ");
    fgets(c.cpf, sizeof(c.cpf), stdin);
    c.cpf[strcspn(c.cpf, "\n")] = 0;

    printf("Digite o telefone: ");
    fgets(c.telefone, sizeof(c.telefone), stdin);
    c.telefone[strcspn(c.telefone, "\n")] = 0;

    printf("Digite o email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    FILE *file = fopen(ARQUIVO_CLIENTES, "a");
    if (!file) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    fprintf(file, "%d;%s;%s;%s;%s\n", c.id, c.nome, c.cpf, c.telefone, c.email);
    fclose(file);

    printf("\n✅ Cliente cadastrado com sucesso!\n");
}


// LISTAR CLIENTES
void listarClientes() {
    FILE *file = fopen(ARQUIVO_CLIENTES, "r");
    if (!file) {
        printf("\nNenhum cliente cadastrado ainda.\n");
        return;
    }

    char linha[256];
    printf("\n📋 Lista de Clientes:\n");
    printf("ID | Nome | CPF | Telefone | Email\n");
    printf("--------------------------------------------------------------\n");

    while (fgets(linha, sizeof(linha), file)) {
        int id;
        char nome[100], cpf[15], telefone[20], email[100];
        sscanf(linha, "%d;%99[^;];%14[^;];%19[^;];%99[^\n]", &id, nome, cpf, telefone, email);
        printf("%d | %s | %s | %s | %s\n", id, nome, cpf, telefone, email);
    }

    fclose(file);
}


// MENU CLIENTES
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
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
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