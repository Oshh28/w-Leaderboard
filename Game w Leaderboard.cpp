#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_PLAYERS 2

void titlegame() {
    printf("\t\t\t\t -------------------------------------------\n");
    printf("\t\t\t\t|   Let's Play game Rock, Paper, Scissor:   |\n");
    printf("\t\t\t\t -------------------------------------------\n");
}

void rockpaperscissor_display() {
    printf("\t\t\t\t| [ 1 ] Rock                                |\n");
    printf("\t\t\t\t| [ 2 ] Paper                               |\n");
    printf("\t\t\t\t| [ 3 ] Scissor                             |\n");
    printf("\t\t\t\t -------------------------------------------\n\n");
}

void display_score(int player1sc, int player2sc) {
	printf("\n");
    printf("\t\t\t\tCurrent Scores:\n");
    printf("\t\t\t\tPlayer 1: %d\n", player1sc);
    printf("\t\t\t\tPlayer 2: %d\n", player2sc);
    printf("\t\t\t\t-------------------------------------------\n");
}

void update_leaderboard(int player1sc, int player2sc, int leaderboard[], int *highest_score, int *player1loss, int *player2loss) {
    if (player1sc > player2sc) {
        leaderboard[0]++;
        //(*player2loss)++;
    } else if (player2sc > player1sc) {
        leaderboard[1]++;
        //(*player1loss)++;
    }
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (leaderboard[i] > *highest_score) {
            *highest_score = leaderboard[i];
        }
    }
}

void display_leaderboard(int leaderboard[], int highest_score, int player1loss, int player2loss, int player1sc, int player2sc) {
    int rank[MAX_PLAYERS] = {0, 1};
    
    if (leaderboard[1] > leaderboard[0]) {
        rank[0] = 1;
        rank[1] = 0;
    }

    printf("\n\n\n\n\n");
    printf("\t\t\t\t -------------------------------------------\n");
    printf("\t\t\t\t|               LEADERBOARDS:               |\n");
    printf("\t\t\t\t -------------------------------------------\n");
    printf("\t\t\t\t| Player 1 Wins: %d   Loss: %d                |\n", player1sc, player1loss);
    printf("\t\t\t\t| Player 2 Wins: %d   Loss: %d                |\n", player2sc, player2loss);
    printf("\t\t\t\t -------------------------------------------\n");
    printf("\t\t\t\t|                 RANKING:                  |\n");
    printf("\t\t\t\t -------------------------------------------\n");
    printf("\t\t\t\t| 1. Player %d                               |\n", rank[0] + 1);
    printf("\t\t\t\t| 2. Player %d                               |\n", rank[1] + 1);
    printf("\t\t\t\t -------------------------------------------\n");
    printf("\t\t\t\t| Highest Score: %d                          |\n", highest_score);
    printf("\t\t\t\t -------------------------------------------\n");
}


int main() {
	
main_menu:
    char *bala[4] = {"Sorry", "Rock", "Paper", "Scissor"};
    int player1sc = 0, player2sc = 0;
    int player1loss = 0, player2loss = 0;
    int leaderboard[MAX_PLAYERS] = {0};
    int highest_score = 0;
    int high = 0;
    int round = 0, p1choice, p2choice;
    char user, user1;

    while(1) {
        system("cls");
        printf("\n\n\n\n\n");
        printf("\t\t\t\t -------------------------------------------\n");
        printf("\t\t\t\t|          ROCK PAPER SCISSOR GAME:         |\n");
        printf("\t\t\t\t -------------------------------------------\n\n");

        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|      [ 1 ] Play            |\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|      [ 2 ] Leaderboard     |\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|      [ 0 ] Quit            |\n");
        printf("\t\t\t\t\t ----------------------------\n");

        user = getch();
        system("cls");

        if (user == '0') {
            exit(0);
        } else if (user == '1') {
            goto chooseplayer;
        } else if (user == '2') {
            display_leaderboard(leaderboard, highest_score, player1loss, player2loss, player1sc, player2sc);
            printf("\t\t\t\tPress any key to return to the main menu...");
            getch();
            continue;
        } else {
            printf("Invalid choice, please try again.\n");
            continue;
        }

    chooseplayer:
        printf("\n\n\n\n\n");
        printf("\t\t\t\t -------------------------------------------\n");
        printf("\t\t\t\t|              CHOOSE A PLAYER:             |\n");
        printf("\t\t\t\t -------------------------------------------\n\n");

        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|       [ 1 ] Player 1       |\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|       [ 2 ] Player 2       |\n");
        printf("\t\t\t\t\t ----------------------------\n");

        user1 = getch();
        system("cls");

        if (user1 == '1') {
            goto player1menu;
        } else if (user1 == '2') {
            goto player1menu;
        } else {
            printf("Invalid choice, please try again.\n");
            continue;
        }

    player1menu:
        for (round = 1; round <= 5; round++) {
            system("cls");
            titlegame();
            rockpaperscissor_display();
            printf("\t\t\t\tRound %d/5\n", round);
            printf("\t\t\t\tYour turn Player 1:\n");
            printf("\t\t\t\t -------------------------------------------\n");
            printf("\t\t\t\t| Player 1: ");
            if (scanf("%d", &p1choice) != 1 || p1choice < 1 || p1choice > 3) {
                printf("\n");
                printf("\t\t\t\t(ERROR) Invalid Input\n\n");
                printf("\t\t\t\tPress any key to try again...");
                while (getchar() != '\n');
                getch();
                round--;
                continue;
            }

            system("cls");

            titlegame();
            rockpaperscissor_display();
            printf("\t\t\t\tRound %d/5\n", round);
            printf("\t\t\t\tYour turn Player 2:\n");
            printf("\t\t\t\t -------------------------------------------\n");
            printf("\t\t\t\t| Player 2: ");
            if (scanf("%d", &p2choice) != 1 || p2choice < 1 || p2choice > 3) {
                printf("\n");
                printf("\t\t\t\t(ERROR) Invalid Input\n\n");
                printf("\t\t\t\tPress any key to try again...");
                while (getchar() != '\n');
                getch();
                round--;
                continue;
            }
            printf("\t\t\t\t -------------------------------------------\n\n");

            if (p1choice == p2choice) {
                printf("\t\t\t\tIt's a tie!\n");
            } else if ((p1choice == 1 && p2choice == 3) ||
                       (p1choice == 2 && p2choice == 1) ||
                       (p1choice == 3 && p2choice == 2)) {
                printf("\t\t\t\tPlayer 1 wins this round!\n");
                player1sc++;
                player2loss++;
            } else {
                printf("\t\t\t\tPlayer 2 wins this round!\n");
                player2sc++;
                player1loss++;
            }
            display_score(player1sc, player2sc);
            printf("\n");
            printf("\t\t\t\tPress any key for the next round...");
            getch();
        }
        
        system("cls");
        
        printf("\n\n");
        printf("\t\t\t\t -------------------------------------------\n");
        printf("\t\t\t\t|                GAME RESULT:               |\n");
        printf("\t\t\t\t -------------------------------------------\n");
        printf("\t\t\t\t| Player 1: %d                               |\n", player1sc);
        printf("\t\t\t\t| Player 2: %d                               |\n", player2sc);
        printf("\t\t\t\t -------------------------------------------\n");
        if (player1sc > player2sc) {
        	printf("\t\t\t\t -------------------------------------------\n");
            printf("\t\t\t\t| Player 1 is the overall winner!           |\n");
            printf("\t\t\t\t -------------------------------------------\n");
        } else if (player2sc > player1sc) {
            printf("\t\t\t\t -------------------------------------------\n");
            printf("\t\t\t\t| Player 2 is the overall winner!           |\n");
            printf("\t\t\t\t -------------------------------------------\n");
        } else {
            printf("\t\t\t\tThe game is a tie!\n");
            
        }
        
        update_leaderboard(player1sc, player2sc, leaderboard, &highest_score, &player1loss, &player2loss);
        printf("\n");
        printf("\t\t\t\tPress any key to return to the main menu...");
        getch();
    }

    return 0;
}

