#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// Funções
void showTitle();
void generateMap();
void generateMapLayout(char map[10][10], int width, int height);
void drawMap(char map[10][20], int width, int height);
void movePlayer(char map[10][20], char input, int width, int height);
void moveEnemy(char map[10][10], int width, int height);
void villageLevel();
void levelOne();
void levelTwo();
void levelThree();
void interactWithNPC();


// Variáveis globais
int selection;
int enemyX, enemyY;
int playerX, playerY;
int hasKey = 0;

void showTitle()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t ▄████████    ▄████████    ▄████████  ▄█      █▄   ▄█             ▄████████ ▀████    ▐████▀    ▄████████ \n");
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

void drawMap(char map[10][20], int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char map[10][20], char input, int width, int height)
{
    int newX = playerX, newY = playerY;

    if ((input == 'w' || input == 'W')) newY--;
    else if ((input == 's' || input == 'S')) newY++;
    else if ((input == 'a' || input == 'A')) newX--;
    else if ((input == 'd' || input == 'D')) newX++;
    else if (input == 'i' || input == 'I') {
        interactWithNPC(map, width, height);
        return;
    }

    char nextTile = map[newY][newX];

    if (nextTile == '*' || nextTile == 'P' || (nextTile == 'D' && hasKey == 0) || (nextTile == '=' && hasKey == 0))
        return;

    if (nextTile == '@') {
        hasKey = 1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (map[i][j] == 'D') {
                    map[i][j] = '=';
                }
            }
        }
    }

    if (nextTile == '=' && hasKey == 1) {
        system("cls");
        printf("\nVocê usou a chave e entrou na próxima fase!\n");
        Sleep(1500);
        hasKey = 0;
        levelOne();
        return;
    }

    playerX = newX;
    playerY = newY;
}

void interactWithNPC(char map[10][20], int width, int height) {
    int dx[] = { 0,  0, -1, 1 };
    int dy[] = { -1, 1,  0, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = playerX + dx[i];
        int ny = playerY + dy[i];

        if (nx >= 0 && nx < width && ny >= 0 && ny < height && map[ny][nx] == 'P') {
            system("cls");
            drawMap(map, width, height);
            printf("\nVocê fala com o NPC:\n");
            printf("\"Olá, viajante! Boa sorte na sua jornada.\"\n");
            Sleep(1500);
            return;
        }
    }

    system("cls");
    drawMap(map, width, height);
    printf("\nNão há nenhum NPC por perto para interagir.\n");
    Sleep(1000);
}


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
        drawMap((char (*)[20])map, width, height);
        inputKey = getch();

        map[playerY][playerX] = ' ';
        map[enemyY][enemyX] = ' ';

        movePlayer((char (*)[20])map, inputKey, width, height);
        moveEnemy(map, width, height);

        map[playerY][playerX] = '&';
        map[enemyY][enemyX] = 'X';

        system("cls");
    }
}

void villageLevel()
{
    system("cls");
    srand(time(NULL));

    char map[10][20];
    char* layout[10] = {
        "**********D*********",
        "*&                 *",
        "*                  *",
        "*  ***       ***   *",
        "*                  *",
        "*            ***   *",
        "*  P             @ *",
        "*  ***       ***   *",
        "*  P            P  *",
        "********************"
    };

    int width = 20, height = 10;
    char inputKey;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&') {
                playerX = j;
                playerY = i;
            }
        }
    }

    while (1)
    {
        map[playerY][playerX] = '&';
        drawMap(map, width, height);
        inputKey = getch();
        map[playerY][playerX] = ' ';
        movePlayer(map, inputKey, width, height);
        system("cls");
    }
}

void levelOne()
{
    system("cls");
    srand(time(NULL));

    char map[10][20];
    char* layout[10] = {
        "********************",
        "*@          *      *",
        "*         *    *   *",
        "*****      *****   *",
        "*   *      *   * ***",
        "* * ****   * * * * D",
        "* *        * *   * *",
        "* ********** ***** *",
        "*         &*       *",
        "********************"
    };

    int width = 20, height = 10;
    char inputKey;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&') {
                playerX = j;
                playerY = i;
            }
        }
    }

    while (1)
    {
        map[playerY][playerX] = '&';
        drawMap(map, width, height);
        inputKey = getch();
        map[playerY][playerX] = ' ';
        movePlayer(map, inputKey, width, height);
        system("cls");
    }
}

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
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Goodbye!\n");
            loopMainMenu = 0;
            break;

        default:
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Opcao invalida.\n");
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t  ");
            system("pause");
        }

    } while (loopMainMenu == 1);

    return 0;
}
