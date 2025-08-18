
#include <stdio.h>
#include <stdlib.h>

// Funções 
void func1() {
    print("FUNC1");
}

void func2() {
    print("FUNC2");
    
}

void func3() {
    print("FUNC3");
}

int main() {
    int opcao;

    do {
        // Menu principal
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║                                        ║\n");
        printf("║         🌟 MENU PRINCIPAL 🌟           ║\n");
        printf("║                                        ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  [1] ➜ Func 1                          ║\n");
        printf("║  [2] ➜ Func 2                          ║\n");
        printf("║  [3] ➜ Func 3                          ║\n");
        printf("║  [0] ➜ Sair                            ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        // Limpar tela 
        system("clear||cls");

        switch(opcao) {
            case 1:
                func1();
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
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


