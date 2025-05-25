#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void showTitle();
void drawMap(char map[40][40], int width, int height);
void movePlayer(char map[40][40], char input, int width, int height);
void interactWithNPC(char map[40][40], int width, int height);
void villageLevel();
void levelOne();
void levelTwo();
void levelThree();
void monsterDrunk(char map[40][40], int width, int height);
void monsterIq(char map[40][40], int width, int height);

int selection;
int playerX, playerY;
int monster1X, monster1Y; // Monstro bêbado 'X'
int monster2X, monster2Y; // Monstro inteligente 'V'
int teleportAX , teleportAY ;
int teleportBX , teleportBY ;
int hasKey = 0;
int currentLevel = 0;
char underMonster1 = ' ';
char underMonster2 = ' ';

void showTitle() {
    system("cls");
    printf("\nJOGO DE AVENTURA\n\n");
}

void drawMap(char map[40][40], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char map[40][40], char input, int width, int height) {
    int newX = playerX, newY = playerY;

    if (input == 'w' || input == 'W') newY--;
    else if (input == 's' || input == 'S') newY++;
    else if (input == 'a' || input == 'A') newX--;
    else if (input == 'd' || input == 'D') newX++;
    else if (input == 'i' || input == 'I') {
        interactWithNPC(map, width, height);
        return;
    }

    char nextTile = map[newY][newX];

    // Não anda em parede, NPC ou porta fechada
    if (nextTile == '*' || nextTile == 'P' || (nextTile == 'D' && hasKey == 0) || (nextTile == '=' && hasKey == 0))
        return;

    // Pegou chave
    if (nextTile == '@') {
        hasKey = 1;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                if (map[i][j] == 'D') map[i][j] = '=';
    }

    // Avançar de fase
    if (nextTile == '=' && hasKey == 1) {
        system("cls");
        printf("\nVocê usou a chave e entrou na próxima fase!\n");
        Sleep(1500);
        hasKey = 0;
        currentLevel++;
        if (currentLevel == 1) levelOne();
        else if (currentLevel == 2) levelTwo();
        else if (currentLevel == 3) levelThree();
        return;
    }

    if (nextTile == 'O') { //botao
    printf("\nVocê pressionou o botão!\n");
    Sleep(1000);
   
    map[5][5] = ' '; 
}

    if (nextTile == '#') {
    printf("\nVocê pisou em um espinho e morreu! Reiniciando fase...\n");
    Sleep(1500);
    if (currentLevel == 1) levelOne();
    else if (currentLevel == 2) levelTwo();
    else if (currentLevel == 3) levelThree();
    return;
}

    // Move o jogador
    playerX = newX;
    playerY = newY;

    // Verifica teletransporte
if (map[playerY][playerX] == '>') {
    // Restaura o símbolo do teletransporte na posição antiga
    if (playerX == teleportAX && playerY == teleportAY) {
        map[playerY][playerX] = '>';
        playerX = teleportBX;
        playerY = teleportBY;
    } else if (playerX == teleportBX && playerY == teleportBY) {
        map[playerY][playerX] = '>';
        playerX = teleportAX;
        playerY = teleportAY;
    }
    printf("Teletransporte ativado!\n");
    Sleep(500);
}
}


void monsterDrunk(char map[40][40], int width, int height) {
    static char underMonster1 = ' '; // persiste entre chamadas
    int newX = monster1X, newY = monster1Y;
    int mov; 
    mov = rand() % 4;

    if (mov == 0) newY--;
    else if (mov == 1) newY++;
    else if (mov == 2) newX--;
    else if (mov == 3) newX++;

    char nextTile = map[newY][newX];

    if (nextTile == '*' || nextTile == 'P' || nextTile == '@' || nextTile == 'D' || nextTile == '=')
        return;

    // Restaura o que estava na posição anterior
    map[monster1Y][monster1X] = underMonster1;

    // Salva o que o monstro vai pisar
    underMonster1 = map[newY][newX];

    // Move o monstro
    monster1X = newX;
    monster1Y = newY;

    // Desenha o monstro
    map[monster1Y][monster1X] = 'X';

    // Verifica colisão com o jogador
    if (monster1X == playerX && monster1Y == playerY) {
        printf("\nVocê foi pego pelo monstro!\n");
        Sleep(1500);
        if (currentLevel == 1) levelOne();
        else if (currentLevel == 2) levelTwo();
        else if (currentLevel == 3) levelThree();
    }
}


void monsterIq(char map[40][40], int width, int height) {
    int dx = 0, dy = 0;
    if (monster2X < playerX) dx = 1;
    else if (monster2X > playerX) dx = -1;
    if (monster2Y < playerY) dy = 1;
    else if (monster2Y > playerY) dy = -1;

    int newX = monster2X + dx;
    int newY = monster2Y + dy;
    char nextTile = map[newY][newX];
    if (nextTile == '*' || nextTile == 'P' || nextTile == '@' || nextTile == 'D' || nextTile == '=') return;

    map[monster2Y][monster2X] = underMonster2;
    underMonster2 = map[newY][newX];
    monster2X = newX;
    monster2Y = newY;
    map[monster2Y][monster2X] = 'V';

    if (monster2X == playerX && monster2Y == playerY) {
        printf("\nVocê foi pego pelo monstro inteligente!\n");
        Sleep(1500);
        if (currentLevel == 1) levelOne();
        else if (currentLevel == 2) levelTwo();
        else if (currentLevel == 3) levelThree();
    }
}


void interactWithNPC(char map[40][40], int width, int height) {
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = playerX + dx[i], ny = playerY + dy[i];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height && map[ny][nx] == 'P') {
            system("cls");
            drawMap(map, width, height);
            printf("\nVocê fala com o NPC:\n\"Olá, viajante! Boa sorte na sua jornada.\"\n");
            Sleep(1500);
            return;
        }
    }

    system("cls");
    drawMap(map, width, height);
    printf("\nNão há nenhum NPC por perto para interagir.\n");
    Sleep(1000);
}

void villageLevel() {
    system("cls");

    currentLevel = 0;

    char map[40][40];
    char* layout[10] = {
        "**********D*********              ",
        "*&                 *              ",
        "*                  *              ",
        "*  ***       ***   *              ",
        "*                  *              ",
        "*            ***   *              ",
        "*  P             @ *              ",
        "*  ***       ***   *              ",
        "*  P            P  *              ",
        "********************              "
    };

    int width = 33, height = 10;
    char inputKey;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&') { playerX = j; playerY = i; }
        }

    while (1) {
        map[playerY][playerX] = '&';
        drawMap(map, width, height);
        inputKey = getch();
        map[playerY][playerX] = ' ';
        movePlayer(map, inputKey, width, height);
        system("cls");
    }
}

void levelOne() {
    system("cls");
   
  

    char map[40][40];
    char* layout[10] = {
        "********************         ",
        "*@          *      *         ",
        "*         *    *   *         ",
        "*****      *****   *         ",
        "*   *      *   * ***         ",
        "* * ****   * * * * D         ",
        "* *        * *   * *         ",
        "* ********** ***** *         ",
        "*         &*       *         ",
        "********************         "
    };

    int width = 20, height = 10;
    char inputKey;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&') { playerX = j; playerY = i; }
        }

    while (1) {
        map[playerY][playerX] = '&';
        drawMap(map, width, height);
        inputKey = getch();
        map[playerY][playerX] = ' ';
        movePlayer(map, inputKey, width, height);
        system("cls");
    }
}

void levelTwo() {
    system("cls");
    teleportAX = teleportAY = -1;
teleportBX = teleportBY = -1;

    

    char map[40][40];
    char* layout[40] = {
        "********************         ",
        "*@                >*         ",
        "*   ***********    *         ",
        "*         *        *         ",
        "*   **##  *   **** *         ",
        "*   *     *        *         ",
        "*   *  #*****  *****         ",
        "*   *        *     *         ",
        "*   *****    *******         ",
        "*   *## *    *    **         ",
        "*   *   *    *    **         ",
        "*   *   *    *    **         ",
        "*   *   *    *    **         ",
        "*   *   *    *    **         ",
        "*   *   *    *    **         ",
        "*   *   *          *         ",
        "*###############X  *         ",
        "*&                D*         ",
        "*       O         >*         ",
        "********************         "
        
    };

    int width = 20, height = 20;
    char inputKey;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&') { playerX = j; playerY = i; }
            if (map[i][j] == 'X') {
    monster1X = j;
    monster1Y = i;
    }
           if (map[i][j] == '>') {
    if (teleportAX == -1) {
        teleportAX = j;
        teleportAY = i;
    } else {
        teleportBX = j;
        teleportBY = i;
    }
}
        }

    while (1) {
        map[playerY][playerX] = '&';
map[monster1Y][monster1X] = 'X'; // desenha o monstro
drawMap(map, width, height);
inputKey = getch();

if ((playerX == teleportAX && playerY == teleportAY) || 
    (playerX == teleportBX && playerY == teleportBY)) {
    map[playerY][playerX] = '>';
} else {
    map[playerY][playerX] = ' ';
}

map[monster1Y][monster1X] = ' '; // limpa monstro anterior
movePlayer(map, inputKey, width, height);
monsterDrunk(map, width, height); //

        system("cls");
    }
}

void levelThree() {
    system("cls");
   
    

    char map[40][40];
    char* layout[40] = {
        "***************************************",
        "*@                                    *",
        "*   **************     ************   *",
        "*   *            *     *          *   *",
        "*   *   ******** *     *  ****    *   *",
        "*   *   *      * *     *  *  *    *   *",
        "*   *   *  **  * ***** *  *  *    *   *",
        "*   *   ****   ***** * *******    *   *",
        "*   *                *            *   *",
        "*   ******************   **********   *",
        "*                                     *",
        "*   **********    **************      *",
        "*   *                                 *",
        "*   *   ****************************  *",
        "*   *                                 *",
        "*   ********************************  *",
        "*       X                             *",
        "*   ********************************  *",
        "*   *                                 *",
        "*   *   ****************************  *",
        "*   *                                 *",
        "*   ********************************  *",
        "*                                     *",
        "*   *******************************   *",
        "*   *                             *   *",
        "*   *   ***********************   *   *",
        "*   *   *                     *   *   *",
        "*   *   *   ***************   *   *   *",
        "*   *   *   *             *   *   *   *",
        "*   *   *   *   *******   *   *   *   *",
        "*   *   *   *   *     *   *   *   *   *",
        "*   *   *   *   *     *   *   *   *   *",
        "*   *   *   *   *******   *   *   *   *",
        "*   *   *   *             *   *   *   *",
        "*   *   *   ***************   *   *   *",
        "*   *                             *   *",
        "*   *******************************   *",
        "*                          V          *",
        "*&                                    D",
        "***************************************"
    };

    int width = 40, height = 40;
    char inputKey;

    // Copia o layout para o mapa real
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&') { playerX = j; playerY = i; }
             if (map[i][j] == 'X') {
    monster1X = j;
    monster1Y = i;
}
if (map[i][j] == 'V') {
    monster2X = j;
    monster2Y = i;
}

        }
    }

    while (1) {
                map[playerY][playerX] = '&';
map[monster1Y][monster1X] = 'X'; // desenha o monstro
map[monster2Y][monster2X] = 'V'; // desenha o monstro
drawMap(map, width, height);
inputKey = getch();
map[playerY][playerX] = ' ';
map[monster1Y][monster1X] = ' '; // limpa monstro anterior
map[monster2Y][monster2X] = ' '; // limpa monstro anterior
movePlayer(map, inputKey, width, height);
monsterDrunk(map, width, height); // monstro bêbado
monsterIq(map, width, height); //espertalhâo

        system("cls");
    }
}


int main() {
    int loopMainMenu = 1;
    srand(time(NULL));

    do {
        SetConsoleOutputCP(65001);
        showTitle();

        printf("  [1] INICIAR\n");
        printf("  [2] CONTROLES\n");
        printf("  [3] CREDITOS\n");
        printf("  [4] SAIR\n");
        printf("  Escolha uma opcao: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1: 
            currentLevel = 0;
            villageLevel(); 
            break;
            case 2:
                showTitle();
                printf("  W - cima | S - baixo | A - esquerda | D - direita\n");
                printf("  I - interagir com NPC ou objeto especial\n");
                system("pause");
                break;
            case 3:
                showTitle();
                printf("  CREDITOS\n\n");
                printf("  João Paulo Koury de Mendonça\n");
                printf("  Pedro Antônio de Souza Fernandes Filho\n");
                system("pause");
                break;
            case 4:
                printf("\n  Goodbye!\n");
                loopMainMenu = 0;
                break;
            default:
                printf("\n  Opcao invalida.\n");
                system("pause");
        }

    } while (loopMainMenu);

    return 0;
}
