#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// Funções do menu e do jogo
void showTitle();
void generateMap();
void generateMapLayout(char map[10][10], int width, int height);
void drawMap(char map[10][10], int width, int height);
void movePlayer(char map[10][10], char input);
void moveEnemy(char map[10][10], int width, int height);
void villageLevel();
void levelOne();
void levelTwo();
void levelThree();

// Variáveis globais
int selection;
int enemyX, enemyY;
int playerX, playerY;
int levelOneX, levelOneY;
int levelTwoX, levelTwoY;
int levelThreeX, levelThreeY;

// Título do jogo
void showTitle()
{
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

// Cria o layout do mapa com paredes nas bordas
void generateMapLayout(char map[10][10], int width, int height)
{
    playerX = 1;
    playerY = height - 2;
    enemyX = width / 2;
    enemyY = height / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                map[i][j] = '*';
            else
                map[i][j] = ' ';
        }
    }
}

// Mostra o mapa na tela
void drawMap(char map[10][10], int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// Movimento do jogador com WASD
void movePlayer(char map[10][10], char input)
{
    if ((input == 'w' || input == 'W') && map[playerY - 1][playerX] != '*')
        playerY--;
    else if ((input == 's' || input == 'S') && map[playerY + 1][playerX] != '*')
        playerY++;
    else if ((input == 'a' || input == 'A') && map[playerY][playerX - 1] != '*')
        playerX--;
    else if ((input == 'd' || input == 'D') && map[playerY][playerX + 1] != '*')
        playerX++;
}

// Movimento aleatório do inimigo
void moveEnemy(char map[10][10], int width, int height)
{
    int dx = -1 + rand() % 3;
    int dy = -1 + rand() % 3;
    int newX = enemyX + dx;
    int newY = enemyY + dy;

    if (map[newY][newX] != '*' &&
        newX > 0 && newX < width - 1 &&
        newY > 0 && newY < height - 1)
    {
        enemyX = newX;
        enemyY = newY;
    }
}

// Fase com inimigo
void generateMap()
{
    system("cls");
    srand(time(NULL));

    char map[10][10];
    char inputKey;
    int width = 10, height = 10;

    generateMapLayout(map, width, height);
    map[playerY][playerX] = '&';
    map[enemyY][enemyX] = 'X';

    while (1)
    {
        drawMap(map, width, height);
        inputKey = getch();

        map[playerY][playerX] = ' ';
        map[enemyY][enemyX] = ' ';

        movePlayer(map, inputKey);
        moveEnemy(map, width, height);

        map[playerY][playerX] = '&';
        map[enemyY][enemyX] = 'X';

        system("cls");
    }
}

// Fase da vila (sem inimigo)
void villageLevel()
{
    system("cls");
    srand(time(NULL));

    char map[10][10];
    char inputKey;
    int width = 10, height = 10;

    playerX = 1;
    playerY = height - 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                map[i][j] = '*';
            else
                map[i][j] = ' ';
        }
    }

    while (1)
    {
        map[playerY][playerX] = '&';
        drawMap(map, width, height);
        inputKey = getch();
        map[playerY][playerX] = ' ';
        movePlayer(map, inputKey);
        system("cls");
    }
}

// Menu principal
int main()
{
    int loopMainMenu = 1;

    do
    {
        SetConsoleOutputCP(65001);
        showTitle();

        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [1] INICIAR\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [2] CONTROLES\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [3] CREDITOS\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [4] SAIR\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  Escolha uma opcao: ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            villageLevel();
            break;

        case 2:
            showTitle();
            printf("\t\t\t\t\t\t\t\t\t\t\t\t   W - para cima\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t   S - para baixo\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t   A - para esquerda\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t   D - para direita\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t   I - para interagir com item\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  ");
            system("pause");
            break;

        case 3:
            showTitle();
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  CREDITOS\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  Dev 1: João Paulo Koury de Mendonça\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  Dev 2: Pedro Antônio de Souza Fernandes Filho\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  ");
            system("pause");
            break;

        case 4:
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  ");
            printf("Goodbye!\n");
            loopMainMenu = 0;
            break;

        default:
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  ");
            printf("Opcao invalida.\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  ");
            system("pause");
        }

    } while (loopMainMenu == 1);

    return 0;
}
