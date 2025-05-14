#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main();
void showCredits();
void showTitle();
void showHelp();
void levelOne();
void levelTwo();
void levelThree();

int selection;


void showTitle() {
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t ▄████████    ▄████████    ▄████████  ▄█     █▄   ▄█             ▄████████ ▀████    ▐████▀    ▄████████ \n");
    printf("\t\t\t\t\t\t\t\t ███    ███   ███    ███   ███    ███ ███     ███ ███            ███    ███   ███▌   ████▀    ███    ███\n");
    printf("\t\t\t\t\t\t\t\t ███    █▀    ███    ███   ███    ███ ███     ███ ███            ███    █▀     ███  ▐███      ███    █▀ \n"); 
    printf("\t\t\t\t\t\t\t\t ███         ▄███▄▄▄▄██▀   ███    ███ ███     ███ ███           ▄███▄▄▄        ▀███▄███▀     ▄███▄▄▄    \n"); 
    printf("\t\t\t\t\t\t\t\t ███        ▀▀███▀▀▀▀▀   ▀███████████ ███     ███ ███          ▀▀███▀▀▀        ████▀██▄     ▀▀███▀▀▀    \n"); 
    printf("\t\t\t\t\t\t\t\t ███    █▄  ▀███████████   ███    ███ ███     ███ ███            ███    █▄    ▐███  ▀███      ███    █▄ \n"); 
    printf("\t\t\t\t\t\t\t\t ███    ███   ███    ███   ███    ███ ███ ▄█▄ ███ ███▌    ▄      ███    ███  ▄███     ███▄    ███    ███\n"); 
    printf("\t\t\t\t\t\t\t\t ████████▀    ███    ███   ███    █▀   ▀███▀███▀  █████▄▄██  ██  ██████████ ████       ███▄   ██████████\n"); 
    printf("\t\t\t\t\t\t\t\t              ███    ███                          ▀                                                       "); 
    printf("\n\n\n\n\n\n\n\n");
    
}

void showCredits() {
    system("cls");
    showTitle();

    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t CREDITS\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tDEVELOPERS:\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tDev 1: Joao Paulo Koury de Mendonca\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tGitHub: github.com/joaopkourym\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tDev 2: Pedro Antonio de Souza Fernandes Filho\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tGitHub: github.com/pedroafernandes\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tDev 3: ChatGPT\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t[1] Comeback to menu\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Close the game\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tSelect an option: ");
    scanf(" %d", &selection);
    switch (selection) {
        case 1:
            system("cls");
            main();
            break;
    
        case 2:
            printf("Closing the game, goodbye!");
            break;
        
        default:
            printf("ERROR! Select an valid option...\n");
            printf("Digit [1] to show the credits screen again or digit any other number to close the game...\n");
            scanf(" %d", &selection);
    
            if (selection == 1) {
                system("cls");
                showCredits();
            } else {
                printf("Closing the game, goodbye!");
            }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    showTitle();
    
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  [1] START\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  [2] CONTROLS\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  [3] CREDITS\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  [4] EXIT\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tSelect an option: ");
    scanf(" %d", &selection);
    
    switch (selection) {
        case 1:
        
        break;
        
        case 2:
        showHelp();
        break;
        
        case 3:
        showCredits();
        break;

        case 4:
        system("cls");
        break;
        
        default:
        printf("ERROR! Select an valid option...\n");
        printf("Digit [1] to show the menu again or digit any other number to close the game...\n");
        scanf(" %d", &selection);
        
        if (selection == 1) {
            system("cls");
            main();
        } else {
            printf("Closing the game, goodbye!");
        }
        
        break;
    }
    
    
    
    return 0;
}

void showHelp() {
    system("cls");
    showTitle();
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tCONTROLS:\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tW to go up\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tS to go down\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tA to go left\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tD to go right\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tI interact with the object above the player\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t[1] Comeback to menu\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Close the game\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tSelect an option: ");
    scanf(" %d", &selection);
    switch (selection) {
        case 1:
            system("cls");
            main();
            break;
    
        case 2:
            printf("Closing the game, goodbye!");

            break;
        
        default:
            printf("ERROR! Select an valid option...\n");
            printf("Digit [1] to show the help screen again or digit any other number to close the game...\n");
            scanf(" %d", &selection);
            if (selection == 1) {
                system("cls");
                showHelp();
            } else {
                printf("Closing the game, goodbye!");
            }
    }
} 
