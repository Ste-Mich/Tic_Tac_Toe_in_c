#include <stdio.h>
#include <stdbool.h>

int gameStatus(char gameBoard[10], int turnsPassed)
{
    int gameStatus = -1;

    if (turnsPassed >= 9)
    {
        gameStatus = 0;
    }

    if (gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2])
    {
        gameStatus = 1;
    }
    else if (gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5])
    {
        gameStatus = 1;
    }
    else if (gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8])
    {
        gameStatus = 1;
    }
    else if (gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6])
    {
        gameStatus = 1;
    }
    else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7])
    {
        gameStatus = 1;
    }
    else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8])
    {
        gameStatus = 1;
    }
    else if (gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8])
    {
        gameStatus = 1;
    }
    else if (gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6])
    {
        gameStatus = 1;
    }

    return gameStatus;
}

void displayBoard(char gameBoard[10])
{
    printf("              |   |   \n");
    printf("            %c | %c | %c \n", gameBoard[0], gameBoard[1], gameBoard[2]);
    printf("              |   |   \n");
    printf("           ---+---+---\n");
    printf("              |   |   \n");
    printf("            %c | %c | %c \n", gameBoard[3], gameBoard[4], gameBoard[5]);
    printf("              |   |   \n");
    printf("           ---+---+---\n");
    printf("              |   |   \n");
    printf("            %c | %c | %c \n", gameBoard[6], gameBoard[7], gameBoard[8]);
    printf("              |   |   \n");
}

void markBoard(char gameBoard[10], bool playerOnePlaying)
{
    printf("Player %c is playing, Choose a position: ", playerOnePlaying == true ? '1' : '2');
    int input = 10;
    while (input > 9 || input < 1 || gameBoard[input - 1] == 'X' || gameBoard[input - 1] == 'O')
    {
        scanf("%i", &input);
        if (input > 9 || input < 1 || gameBoard[input - 1] == 'X' || gameBoard[input - 1] == 'O')
        {
            printf("\nInvalid Move");
        }
    }

    gameBoard[input - 1] = playerOnePlaying == true ? 'O' : 'X';

    return;
}

int main()
{
    //initialize variables
    char gameBoard[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool playerOnePlaying = true;
    int turnsPassed = 0;

    //gameloop
    while (gameStatus(gameBoard, turnsPassed) == -1)
    {

        printf("\nPlayer 1 = O   ||    Player 2 = X\n\n");

        displayBoard(gameBoard);

        markBoard(gameBoard, playerOnePlaying);

        playerOnePlaying = (playerOnePlaying == true) ? false : true;

        turnsPassed++;
    }

    displayBoard(gameBoard);

    printf("\n");

    if (gameStatus(gameBoard, turnsPassed) == 0)
    {
        printf("Its a tie.\n");
    }
    else
    {
        printf("Game ended, Player %i has won.", (playerOnePlaying == true) ? 2 : 1);
    }

    return 0;
}