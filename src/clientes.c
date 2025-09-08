#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/clientes.h"
#define ARQUIVO_CLIENTES "clientes.txt" // constante do local de dados de clientes

// GERA ID COM BASE NO TAMANHO DO txt (OBS: CORRECAO DO ERRO LOGICO)
// ANTES podia gerar um novo cliente com id de outro ja existente
// Agora ele n leva em consideração so o tamanho do txt, leva em consideracao o maior ID encontrado
int gerarId() {
    FILE *file = fopen(ARQUIVO_CLIENTES, "r");
    if (!file) return 1; // se n existe começa do 1

    int maxId = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        int id;
        sscanf(linha, "%d;", &id); 
        if (id > maxId) maxId = id;
    }
    fclose(file);
    return maxId + 1;
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


// ATUALIZAR CLIENTE
void atualizarCliente() {
    FILE *file = fopen(ARQUIVO_CLIENTES, "r");
    if (!file) {
        printf("\nNenhum cliente cadastrado ainda.\n");
        return;
    }

    Cliente clientes[1000];
    int total = 0;
    char linha[256];

    // Lê todos os clientes do arquivo
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%14[^;];%19[^;];%99[^\n]",
               &clientes[total].id,
               clientes[total].nome,
               clientes[total].cpf,
               clientes[total].telefone,
               clientes[total].email);
        total++;
    }
    fclose(file);

    int idAtualizar;
    printf("\nDigite o ID do cliente que deseja atualizar: ");
    scanf("%d", &idAtualizar);
    getchar(); // limpa buffer

    int encontrado = 0, indice = -1;
    for (int i = 0; i < total; i++) {
        if (clientes[i].id == idAtualizar) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Cliente com ID %d não encontrado!\n", idAtualizar);
        return;
    }

    // Mostra os dados atuais
    printf("\n🔎 Cliente encontrado:\n");
    printf("ID: %d\n", clientes[indice].id);
    printf("Nome: %s\n", clientes[indice].nome);
    printf("CPF: %s\n", clientes[indice].cpf);
    printf("Telefone: %s\n", clientes[indice].telefone);
    printf("Email: %s\n", clientes[indice].email);

    // Confirma atualização
    char opcao;
    printf("\nDeseja atualizar os dados deste cliente? (s/n): ");
    scanf("%c", &opcao);
    getchar(); // limpa buffer

    if (opcao != 's' && opcao != 'S') {
        printf("\n❌ Atualização cancelada.\n");
        return;
    }

    // Solicita novos dados (opcional)
    printf("\nDigite o novo nome (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(clientes[indice].nome, linha);
    }

    printf("Digite o novo CPF (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(clientes[indice].cpf, linha);
    }

    printf("Digite o novo telefone (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(clientes[indice].telefone, linha);
    }

    printf("Digite o novo email (deixe em branco para manter): ");
    fgets(linha, sizeof(linha), stdin);
    if (linha[0] != '\n') {
        linha[strcspn(linha, "\n")] = 0;
        strcpy(clientes[indice].email, linha);
    }

    // Reescreve o arquivo com os dados atualizados
    file = fopen(ARQUIVO_CLIENTES, "w");
    if (!file) {
        printf("\nErro ao salvar as alterações!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%s;%s;%s\n",
                clientes[i].id,
                clientes[i].nome,
                clientes[i].cpf,
                clientes[i].telefone,
                clientes[i].email);
    }

    fclose(file);
    printf("\n✅ Cliente atualizado com sucesso!\n");
}


//EXCLUIR CLIENTE

void excluirCliente() {
    FILE *file = fopen(ARQUIVO_CLIENTES, "r");
    if (!file) {
        printf("\nNenhum cliente cadastrado ainda.\n");
        return;
    }

    Cliente clientes[1000];
    int total = 0;
    char linha[256];

    // Lê todos os clientes
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%14[^;];%19[^;];%99[^\n]",
               &clientes[total].id,
               clientes[total].nome,
               clientes[total].cpf,
               clientes[total].telefone,
               clientes[total].email);
        total++;
    }
    fclose(file);

    int idExcluir;
    printf("\nDigite o ID do cliente que deseja excluir: ");
    scanf("%d", &idExcluir);
    getchar();

    int encontrado = 0;
    int indice = -1;
    for (int i = 0; i < total; i++) {
        if (clientes[i].id == idExcluir) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Cliente com ID %d não encontrado!\n", idExcluir);
        return;
    }

    // Mostra os dados do cliente antes de excluir
    printf("\n⚠️  Cliente encontrado:\n");
    printf("ID: %d\n", clientes[indice].id);
    printf("Nome: %s\n", clientes[indice].nome);
    printf("CPF: %s\n", clientes[indice].cpf);
    printf("Telefone: %s\n", clientes[indice].telefone);
    printf("Email: %s\n", clientes[indice].email);

    // add caso de confirmacao
    char confirmar;
    printf("\nDeseja realmente excluir este cliente? (s/n): ");
    scanf("%c", &confirmar);
    getchar();

    if (confirmar != 's' && confirmar != 'S') {
        printf("\n❌ Exclusão cancelada.\n");
        return;
    }

    // Remove o cliente do array
    for (int i = indice; i < total - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    total--;

    // Sobrescreve o arquivo
    file = fopen(ARQUIVO_CLIENTES, "w");
    for (int i = 0; i < total; i++) {
        fprintf(file, "%d;%s;%s;%s;%s\n",
                clientes[i].id,
                clientes[i].nome,
                clientes[i].cpf,
                clientes[i].telefone,
                clientes[i].email);
    }
    fclose(file);

    printf("\n✅ Cliente excluído com sucesso!\n");
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
                atualizarCliente();
                break;
            case 4:
                excluirCliente();
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
        }

    } while(opcao != 0);
}