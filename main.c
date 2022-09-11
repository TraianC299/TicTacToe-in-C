#include <stdio.h>
char arr[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


void showBoard(){
    printf("TICTAKTOE\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[1], arr[2], arr[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[4], arr[5], arr[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[7], arr[8], arr[9]);
    printf("     |     |     \n\n");
}

int checkForWin(){
    int verticals[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int horizontals[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int diagonals[2][3] = {{1, 5, 9}, {3, 5, 7}};

    for (int i = 0; i < 3; i++){
        if (arr[verticals[i][0]] == arr[verticals[i][1]] && arr[verticals[i][1]] == arr[verticals[i][2]]){
            return 1;
        }
    }

    for (int i = 0; i < 3; i++){
        if (arr[horizontals[i][0]] == arr[horizontals[i][1]] && arr[horizontals[i][1]] == arr[horizontals[i][2]]){
            return 1;
        }
    }

    for (int i = 0; i < 2; i++){
        if (arr[diagonals[i][0]] == arr[diagonals[i][1]] && arr[diagonals[i][1]] == arr[diagonals[i][2]]){
            return 1;
        }
    }
    return -1;
}
int main(){
    int player = 2;
    int choice, i;
    char mark; // X or O
    int valid = 0;
    do{
        showBoard();
        player = (player % 2 == 0) ? 1 : 2;
        printf("Player %d, enter a number (from 1 to 9): ", player);
        scanf("%i", &choice);
        mark = (player == 1) ? 'X' : 'O';
        for (i = 0; i < 10; i++){
            if (choice == i){
                arr[i] = mark;
                valid = 1;
                break;
            }
            valid = 0;
        }
        if (valid == 0){
            printf("Invalid move. Try again.\n");
            player--;
        }
        i = checkForWin();
    }while(i == -1);
    showBoard();
}


