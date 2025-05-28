#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void showTitle();
void drawMap(char map[40][40], int width, int height);
void movePlayer(char map[40][40], char input, int width, int height);
void interactWithNPC(char map[40][40], int width, int height);
void drawMap(char map[40][40], int width, int height);
void movePlayer(char map[40][40], char input, int width, int height);
void interactWithNPC(char map[40][40], int width, int height);
void villageLevel();
void levelOne();
void levelTwo();
void levelThree();
void monsterDrunk(char map[40][40], int width, int height);
void monsterIq(char map[40][40], int width, int height);
void showTitle();

int selection;
int playerX, playerY;
int monster1X, monster1Y; // Monstro bêbado 'X'
int monster2X, monster2Y; // Monstro inteligente 'V'
int teleportAX, teleportAY;
int teleportBX, teleportBY;
int hasKey = 0;
int currentLevel = 0;
char underMonster1 = ' ';
char underMonster2 = ' ';
int initialHealth = 3;

int main()
{
    int loopMainMenu = 1; // Controla o loop do menu principal
    srand(time(NULL));    // Inicializa a semente do gerador de números aleatórios

    do
    {
        SetConsoleOutputCP(65001); // Configura o terminal para UTF-8
        showTitle();               // Exibe o título do jogo

        // Menu Principal
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [1] INICIAR\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [2] CONTROLES\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [3] CREDITOS\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  [4] SAIR\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t  Escolha uma opcao: ");
        scanf("%d", &selection); // Lê a opção do usuário

        switch (selection)
        {
        case 1:               // Iniciar jogo
            currentLevel = 0; // Reinicia para a vila
            levelThree();     // Carrega a fase da vila
            break;
        case 2: // Mostrar controles
            showTitle();
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  W - cima\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  A - esquerda\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  S - baixo\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  D - direita\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  I - interagir com NPC ou objeto especial\n");
            system("pause"); // Pausa para o usuário ler
            break;
        case 3: // Créditos
            showTitle();
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  CREDITOS\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  João Paulo Koury de Mendonça\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  Pedro Antônio de Souza Fernandes Filho\n");
            system("pause");
            break;
        case 4: // Sair
            printf("\n  Goodbye!\n");
            loopMainMenu = 0; // Encerra o loop
            break;
        default: // Opção inválida
            printf("\n  Opcao invalida.\n");
            system("pause");
        }
    } while (loopMainMenu); // Repete até o usuário sair

    return 0; // Fim do programa
}

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

void drawMap(char map[40][40], int width, int height)
{
    for (int i = 0; i < height; i++)
    { // Loop pelas linhas
        for (int j = 0; j < width; j++)
        {                            // Loop pelas colunas
            printf("%c", map[i][j]); // Imprime cada caractere do mapa
        }
        printf("\n"); // Quebra de linha após cada linha do mapa
    }
}

void movePlayer(char map[40][40], char input, int width, int height)
{
    int newX = playerX, newY = playerY; // Calcula nova posição

    // Atualiza coordenadas conforme a tecla pressionada
    if (input == 'w' || input == 'W')
        newY--;
    else if (input == 's' || input == 'S')
        newY++;
    else if (input == 'a' || input == 'A')
        newX--;
    else if (input == 'd' || input == 'D')
        newX++;
    else if (input == 'i' || input == 'I')
    { // Interação com NPC
        interactWithNPC(map, width, height);
        return;
    }

    char nextTile = map[newY][newX]; // Verifica o próximo tile

    // Colisões com paredes, NPCs ou portas fechadas
    if (nextTile == '*' || nextTile == 'P' || (nextTile == 'D' && hasKey == 0) || (nextTile == '=' && hasKey == 0))
        return;

    // Coleta de chave
    if (nextTile == '@')
    {
        hasKey = 1; // Ativa a chave
        // Substitui portas fechadas por abertas
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                if (map[i][j] == 'D')
                    map[i][j] = '=';
    }

    // Passar pela porta com chave
    if (nextTile == '=' && hasKey == 1)
    {
        system("cls");
        hasKey = 0;     // Reseta a chave
        currentLevel++; // Avança para a próxima fase

        // Carrega a fase correspondente
        if (currentLevel == 1)
        {
            printf("\nVoce usou a chave e entrou na Fase 1!\n");
            Sleep(1500);
            levelOne();
        }
        else if (currentLevel == 2)
        {
            printf("\nVoce usou a chave e entrou na Fase 2!\n");
            Sleep(1500);
            levelTwo();
        }
        else if (currentLevel == 3)
        {
            printf("\nVoce usou a chave e entrou na Fase Final!\n");
            Sleep(1500);
            levelThree();
        }
        else
        { // Vitória
            system("cls");
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Game Winner!!!\n");
            system("pause");
            main(); // Volta ao menu
        }
        return;
    }

    // Ativação de botão (remove espinhos)
    if (nextTile == 'O')
    {
        printf("\nVoce pressionou o botão! Um caminho foi aberto!\n");
        Sleep(1000);
        // Remove espinhos
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (map[i][j] == '#')
                    map[i][j] = ' ';
            }
        }
        map[24][17] = ' ';           // Abre passagem
        map[playerY][playerX] = ' '; // Remove o botão
    }

    // Dano por espinhos
    if (nextTile == '#')
    {
        initialHealth--; // Perde vida
        printf("\nVoce pisou em um espinho e morreu! Voce ainda tem %d vidas...\n", initialHealth);
        Sleep(1500);
        if (initialHealth < 1)
        { // Game Over
            system("cls");
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Game Over!!!\n");
            system("pause");
            main(); // Reinicia o jogo
        }
    }

    // Atualiza posição do jogador
    playerX = newX;
    playerY = newY;

    // Teletransporte
    if (map[playerY][playerX] == '>')
    {
        // Troca entre os dois pontos de teletransporte
        if (playerX == teleportAX && playerY == teleportAY)
        {
            map[playerY][playerX] = '>';
            playerX = teleportBX;
            playerY = teleportBY;
        }
        else if (playerX == teleportBX && playerY == teleportBY)
        {
            map[playerY][playerX] = '>';
            playerX = teleportAX;
            playerY = teleportAY;
        }
        printf("Teletransporte ativado!\n");
        Sleep(500);
    }
}

// Monstro com movimento aleatório
void monsterDrunk(char map[40][40], int width, int height)
{
    static char underMonster1 = ' '; // Mantém o estado do tile sob o monstro
    int newX = monster1X, newY = monster1Y;
    int mov = rand() % 4; // Direção aleatória (0-3)

    // Atualiza coordenadas
    if (mov == 0)
        newY--;
    else if (mov == 1)
        newY++;
    else if (mov == 2)
        newX--;
    else if (mov == 3)
        newX++;

    // Verifica colisões
    char nextTile = map[newY][newX];
    if (nextTile == '*' || nextTile == 'P' || nextTile == '@' || nextTile == 'D' || nextTile == '=')
        return;

    // Restaura o tile anterior
    map[monster1Y][monster1X] = underMonster1;
    underMonster1 = map[newY][newX]; // Salva o novo tile

    // Atualiza posição do monstro
    monster1X = newX;
    monster1Y = newY;
    map[monster1Y][monster1X] = 'X'; // Desenha o monstro

    // Colisão com o jogador
    if (monster1X == playerX && monster1Y == playerY)
    {
        initialHealth--;
        printf("\nVocê foi pego pelo monstro! Voce ainda tem %d vidas...\n", initialHealth);
        Sleep(1500);
        if (initialHealth < 1)
        { // Game Over
            system("cls");
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Game Over!!!\n");
            system("pause");
            main();
        }
        else
        { // Reinicia a fase
            if (currentLevel == 1)
                levelOne();
            else if (currentLevel == 2)
                levelTwo();
            else if (currentLevel == 3)
                levelThree();
        }
    }
}

// Monstro que persegue o jogador
void monsterIq(char map[40][40], int width, int height)
{
    int dx = 0, dy = 0;
    // Calcula direção em relação ao jogador
    if (monster2X < playerX)
        dx = 1;
    else if (monster2X > playerX)
        dx = -1;
    if (monster2Y < playerY)
        dy = 1;
    else if (monster2Y > playerY)
        dy = -1;

    int newX = monster2X + dx;
    int newY = monster2Y + dy;

    // Verifica colisões
    char nextTile = map[newY][newX];
    if (nextTile == '*' || nextTile == 'P' || nextTile == '@' || nextTile == 'D' || nextTile == '=')
        return;

    // Atualiza posição do monstro
    map[monster2Y][monster2X] = underMonster2;
    underMonster2 = map[newY][newX];
    monster2X = newX;
    monster2Y = newY;
    map[monster2Y][monster2X] = 'V'; // Desenha o monstro

    // Colisão com o jogador
    if (monster2X == playerX && monster2Y == playerY)
    {
        printf("\nVocê foi pego pelo monstro inteligente!\n");
        Sleep(1500);
        // Reinicia a fase
        if (currentLevel == 1)
            levelOne();
        else if (currentLevel == 2)
            levelTwo();
        else if (currentLevel == 3)
            levelThree();
    }
}

void interactWithNPC(char map[40][40], int width, int height)
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nx = playerX + dx[i], ny = playerY + dy[i];

        if (nx >= 0 && nx < width && ny >= 0 && ny < height && map[ny][nx] == 'P')
        {
            system("cls");
            drawMap(map, width, height);

            // Verifica a posição do NPC
            if (ny == 6 && nx == 3) // NPC da linha 6, coluna 4 (índice base 0)
            {
                printf("\nNPC 1: \"O mundo lá fora é perigoso. Leve essa chave e vá com cuidado.\"\n");
            }
            else if (ny == 8 && nx == 3) // NPC da linha 8, coluna 4
            {
                printf("\nNPC 2: \"Ouvi dizer que há monstros nas cavernas ao sul.\"\n");
            }
            else if (ny == 8 && nx == 17) // NPC da linha 8, coluna 18
            {
                printf("\nNPC 3: \"Se encontrar um botão, pressione. Ele pode revelar passagens escondidas.\"\n");
            }
            else
            {
                // Caso genérico (opcional)
                printf("\nNPC: \"Olá, viajante! Boa sorte na sua jornada.\"\n");
            }

            Sleep(2000);
            return;
        }
    }

    system("cls");
    drawMap(map, width, height);
    printf("\nNão há nenhum NPC por perto para interagir.\n");
    Sleep(1000);
}

void villageLevel()
{
    system("cls");

    currentLevel = 0;

    currentLevel = 0;

    char map[40][40];
    char *layout[10] = {
        "**********D*********              ",
        "*&                 *              ",
        "*                  *              ",
        "*  ***       ***   *              ",
        "*                  *              ",
        "*            ***   *              ",
        "*  P             @ *              ",
        "*  ***       ***   *              ",
        "*  P            P  *              ",
        "********************              "};

    int width = 33, height = 10;
    char inputKey;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&')
            {
                playerX = j;
                playerY = i;
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

    char map[40][40];
    char *layout[10] = {
        "********************         ",
        "*@          *      *         ",
        "*         *    *   *         ",
        "*****      *****   *         ",
        "*   *      *   * ***         ",
        "* * ****   * * * * D         ",
        "* *        * *   * *         ",
        "* ********** ***** *         ",
        "*         &*       *         ",
        "********************         "};

    int width = 20, height = 10;
    char inputKey;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&')
            {
                playerX = j;
                playerY = i;
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

void levelTwo()
{
    system("cls");
    teleportAX = teleportAY = -1;
    teleportBX = teleportBY = -1;

    char map[40][40];
    char *layout[40] = {
        "********************         ",
        "*@        #       >*         ",
        "*         #        *         ",
        "*         #        *         ",
        "*##################*         ",
        "*                  *         ",
        "*                  *         ",
        "*  O               *         ",
        "*                  *         ",
        "*                  *         ",
        "*                  *         ",
        "*         X        *         ",
        "*                  *         ",
        "*                  *         ",
        "*                  *         ",
        "*                  *         ",
        "*                  *         ",
        "*&                 D         ",
        "*                 >*         ",
        "********************         "

    };

    int width = 20, height = 20;
    char inputKey;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&')
            {
                playerX = j;
                playerY = i;
            }
            if (map[i][j] == 'X')
            {
                monster1X = j;
                monster1Y = i;
            }
            if (map[i][j] == '>')
            {
                if (teleportAX == -1)
                {
                    teleportAX = j;
                    teleportAY = i;
                }
                else
                {
                    teleportBX = j;
                    teleportBY = i;
                }
            }
        }

    while (1)
    {
        map[playerY][playerX] = '&';
        map[monster1Y][monster1X] = 'X'; // desenha o monstro
        drawMap(map, width, height);
        inputKey = getch();

        if ((playerX == teleportAX && playerY == teleportAY) ||
            (playerX == teleportBX && playerY == teleportBY))
        {
            map[playerY][playerX] = '>';
        }
        else
        {
            map[playerY][playerX] = ' ';
        }

        map[monster1Y][monster1X] = ' '; // limpa monstro anterior
        movePlayer(map, inputKey, width, height);
        monsterDrunk(map, width, height); //

        system("cls");
    }
}

void levelThree()
{
    system("cls");

    teleportAX = teleportAY = -1;
    teleportBX = teleportBY = -1;

    char map[40][40];
    char *layout[40] = {
        "***************************************",
        "*                                     *",
        "*   >                                 *",
        "*                                     *",
        "*                           ##########*",
        "*                 X                   *",
        "*                           #     ####*",
        "*                           #     #   *",
        "*                           #        @*",
        "***************************************",
        "*                   V        #   #    *",
        "*                        #  #       # D",
        "*                              #      *",
        "********                     #      # *",
        "*                               #     *",
        "*                                     *",
        "*                   #############     *",
        "*                                     *",
        "*            ####                     *",
        "*                   ###############   *",
        "*                                     *",
        "***********                           *",
        "*                     *****************",
        "*                                     *",
        "*              *******                *",
        "*              *     *                *",
        "*              *  >  *                *",
        "*              *     *                *",
        "*              **************         *",
        "*                                     *",
        "*                   *                 *",
        "*########           *                 *",
        "*                ****                 *",
        "*                                     *",
        "*            O                        *",
        "*************************             *",
        "*                                     *",
        "*                                     *",
        "*&                                    *",
        "***************************************"};

    int width = 40, height = 40;
    char inputKey;

    // Copia o layout para o mapa real
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = layout[i][j];
            if (map[i][j] == '&')
            {
                playerX = j;
                playerY = i;
            }
            if (map[i][j] == 'X')
            {
                monster1X = j;
                monster1Y = i;
            }
            if (map[i][j] == 'V')
            {
                monster2X = j;
                monster2Y = i;
            }
            if (map[i][j] == '>')
            {
                if (teleportAX == -1)
                {
                    teleportAX = j;
                    teleportAY = i;
                }
                else
                {
                    teleportBX = j;
                    teleportBY = i;
                }
            }
        }
    }

    while (1)
    {
        // Restaura o símbolo de teleporte se o jogador saiu dele
        if ((playerX == teleportAX && playerY == teleportAY) || (playerX == teleportBX && playerY == teleportBY))
            map[playerY][playerX] = '>';
        else
            map[playerY][playerX] = ' ';

        // Limpa os monstros das posições anteriores
        map[monster1Y][monster1X] = ' ';
        map[monster2Y][monster2X] = ' ';

        // Pega entrada e move jogador
        inputKey = getch();
        movePlayer(map, inputKey, width, height);

        // Atualiza monstros
        monsterDrunk(map, width, height);
        monsterIq(map, width, height);

        // Redesenha o jogador e monstros nas novas posições
        map[playerY][playerX] = '&';
        map[monster1Y][monster1X] = 'X';
        map[monster2Y][monster2X] = 'V';

        // Desenha o mapa
        system("cls");
        drawMap(map, width, height);
    }
}
