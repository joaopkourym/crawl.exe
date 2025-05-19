#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// Funções do menu e do jogo
void showTitle();
void showControls();
void showCredits();
void comebackMenu();
void generateMap();

int selection;

// Título do jogo
void showTitle() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t ▄████████    ▄████████    ▄████████  ▄█     █▄   ▄█             ▄████████ ▀████    ▐████▀    ▄████████ \n");
    printf("\t\t\t\t\t\t ███    ███   ███    ███   ███    ███ ███     ███ ███            ███    ███   ███▌   ████▀    ███    ███\n");
    printf("\t\t\t\t\t\t ███    █▀    ███    ███   ███    ███ ███     ███ ███            ███    █▀     ███  ▐███      ███    █▀ \n"); 
    printf("\t\t\t\t\t\t ███         ▄███▄▄▄▄██▀   ███    ███ ███     ███ ███           ▄███▄▄▄        ▀███▄███▀     ▄███▄▄▄    \n"); 
    printf("\t\t\t\t\t\t ███        ▀▀███▀▀▀▀▀   ▀███████████ ███     ███ ███          ▀▀███▀▀▀        ████▀██▄     ▀▀███▀▀▀    \n"); 
    printf("\t\t\t\t\t\t ███    █▄  ▀███████████   ███    ███ ███     ███ ███            ███    █▄    ▐███  ▀███      ███    █▄ \n"); 
    printf("\t\t\t\t\t\t ███    ███   ███    ███   ███    ███ ███ ▄█▄ ███ ███▌    ▄      ███    ███  ▄███     ███▄    ███    ███\n"); 
    printf("\t\t\t\t\t\t ████████▀    ███    ███   ███    █▀   ▀███▀███▀  █████▄▄██  ██  ██████████ ████       ███▄   ██████████\n"); 
    printf("\t\t\t\t\t\t              ███    ███                          ▀                                                       "); 
    printf("\n\n\n\n\n\n\n\n");
}

// Tela de controles
void showControls() {
    showTitle();
    printf("\t\t\t\t\t\t\t\t\t\t\t\t   W - para cima\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t   S - para baixo\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t   A - para esquerda\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t   D - para direita\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t   I - para interagir com item\n");
    comebackMenu();
}

// Tela de créditos
void showCredits() {
    showTitle();
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  CREDITOS\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  Dev 1: João Paulo Koury de Mendonça\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  Dev 2: Pedro Antônio de Souza Fernandes Filho\n");
    comebackMenu();
}

// Geração e execução do mapa
void generateMap(int length, int height) {
    system("cls");
    srand(time(NULL));

    char map[length][height];
    char inputKey;
    int i, j;
    int playerX = 1, playerY = 8;
    int enemieX = height / 2, enemieY = length / 2;

    // Geração do mapa com paredes nas bordas
    for (i = 0; i < height; i++) {
        for (j = 0; j < length; j++) {
            if (i == 0 || j == 0 || i == height - 1 || j == length - 1)
                map[i][j] = '*';
            else
                map[i][j] = ' ';
        }
    }

    map[playerY][playerX] = '@';
    map[enemieY][enemieX] = '&';

    while (1) {
        // Exibe o mapa
        for (i = 0; i < height; i++) {
            for (j = 0; j < length; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        inputKey = getch();

        // Limpa posições anteriores
        map[playerY][playerX] = ' ';
        map[enemieY][enemieX] = ' ';

        // Movimento do jogador
        if ((inputKey == 'w' || inputKey == 'W') && map[playerY - 1][playerX] != '*') playerY--;
        else if ((inputKey == 'a' || inputKey == 'A') && map[playerY][playerX - 1] != '*') playerX--;
        else if ((inputKey == 's' || inputKey == 'S') && map[playerY + 1][playerX] != '*') playerY++;
        else if ((inputKey == 'd' || inputKey == 'D') && map[playerY][playerX + 1] != '*') playerX++;

        // Movimento aleatório do inimigo
        int deltaX = -1 + rand() % 3;
        int deltaY = -1 + rand() % 3;
        int newEnemieX = enemieX + deltaX;
        int newEnemieY = enemieY + deltaY;

        // Verifica se pode mover
        if (map[newEnemieY][newEnemieX] != '*' &&
            newEnemieX > 0 && newEnemieX < length - 1 &&
            newEnemieY > 0 && newEnemieY < height - 1) {
            enemieX = newEnemieX;
            enemieY = newEnemieY;
        }

        // Atualiza mapa
        map[playerY][playerX] = '@';
        map[enemieY][enemieX] = '&';
        system("cls");
    }
}

// Menu principal
int main() {
    SetConsoleOutputCP(65001);
    showTitle();

    printf("\t\t\t\t\t\t\t\t\t\t\t\t  [1] INICIAR\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  [2] CONTROLES\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  [3] CREDITOS\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  [4] SAIR\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  Escolha uma opcao: ");
    scanf("%d", &selection);

    switch (selection) {
        case 1:
            generateMap(10, 10);
            break;
        case 2:
            showControls();
            break;
        case 3:
            showCredits();
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}

// Tela de retorno ao menu
void comebackMenu() {
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t  [1] Voltar ao menu\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t  [2] Sair do jogo\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t  Escolha uma opcao: ");
    scanf(" %d", &selection);

    if (selection == 1) {
        system("cls");
        main();
    } else if (selection == 2) {
        printf("\nFechando o jogo...\n");
    } else {
        printf("ERRO! Digito invalido, reinicie o jogo!");
    }
}
