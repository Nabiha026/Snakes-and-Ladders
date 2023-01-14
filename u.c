// C project for creating a Snake & Ladder Game
// By: Nabiha Hamid. /\('-')/\ 
// Rules of the game.
/*
1.The game will begin with any random dice value.
2.If a 6(six) is appeared then a chance is awarded to that player.
3.Only the location of current player is shown on the board,
  the location of other player is mentioned below the board.
4.Snakes:- 99 to  1, 65 to 40, 25 to 9.
5.Ladder:- 70 to 93, 60 to 83, 13 to 42.
*/
#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <windows.h>
void welcome();
int rd();
void displaychart(int curp, char player[4]);
int rd()
{
    
        srand(time(NULL));
        int num = ((rand() % 6) + 1);
        return num;
    
}
void displaychart(int curp, char player[4])
{
    int i, j, t, c, sft = 0, diceres, pos1, pos2;

    if (curp == 100)  
    {
       
        printf("\033[0;34m");
        printf("\n\n\t\t\t=========================\n\n");
	   printf("\t\t\t*****Congratulations*****\n\t\t\tPlayer %s wins\n", player);
       scanf("%*s");
       char ch1;
        FILE *f;
        system("Color 0B");
        f = fopen("1.txt", "r");
        do
        {
            ch1 = fgetc(f);
            printf("%c", ch1);

        } while (ch1 != EOF);
        fclose(f);
       exit(0);
    }
    for (i = 10; i > 0; i--) 
    {
        t = i - 1;
        if ((sft % 2) == 0)//diplaying even rows
        {
            c = 0;
            for (j = 10; j >= 1; j--)
            {
                diceres = (i * j) + (t * c++);

                if (curp == diceres)   //in case of equal display position else number
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        }
        else
        {
            c = 9;
            for (j = 1; j <= 10; j++)  //diplaying odd rows
            {
                diceres = (i * j) + (t * c--);

                if (curp == diceres)
                    printf("%s\t", player); //in case of equal display position else number
                else
                    printf("%d\t", diceres);
            }

            sft++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}
void main()
{
    int i, dice, cp_1 = 0, cp_2 = 0;
    char ch;
    while (1)
    {
        char ch1;
        FILE *f;
        system("Color 0A");
        f = fopen("Untitled.txt", "r");
        do
        {
            ch1 = fgetc(f);
            printf("%c", ch1);

        } while (ch1 != EOF);
        fclose(f);
        printf("\033[0;34m");
        int cp = 0;
        printf("\033[0;31m");
        printf("\n");
        printf("\t\t\t  Snakes And Ladders Games \n");
        printf("\t\t============================================\n\n");
        printf("\033[0;33m");
        printf("\t\t------------------------------------------\n");
        printf(" \t\t| |\t1. Select Player 1 \t\t| |\n");
        printf(" \t\t| |\t2. Select Palyer 2 \t\t| |\n");
        printf(" \t\t| |\t3. Exit            \t\t| |\n");
        printf("\t\t-----------------------------------------\n");
        printf("\033[0;31m");
        printf("\n\t\t------------KINDLY READ THE RULES------------\n");
        printf("\n\t\t1.The game will begin with any dice value.\n");
        
        printf("\t\tSnakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\n\t\tLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n");
        scanf("%s", &ch);
        system("cls");
        switch (ch)
        {

        case '1':
            dice = rd();
            system("cls");
            printf("\n----------\n");
            printf("||DICE:%d||", dice);
            printf("\n----------\n");
            if (dice == 6)
                printf("Dice=6: You have earned a chance to play one more time.\n");
            cp_1 = dice + cp_1;
            if (cp_1 < 101)
            {
                if (cp_1 == 99)
                {
                     printf("\t\t=====================================\n");
                     printf("\n\t\touch! You have been bit by a snake\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(1, "$P1$"); // snake
                }
                if (cp_1 == 65)
                {
                     printf("\t\t=====================================\n\n");
                     printf("\n\t\t ouch! You have been bit by a snake\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(40, "$P1$"); // snake
                }
                if (cp_1 == 25)
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n|\t\t ouch! You have been bit by a snake|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(9, "$P1$"); // snake
                }
                if (cp_1 == 70)
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n\t\t|Congrats!! You have climbed a ladder|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(93, "$P1$"); // ladder
                }
                if (cp_1 == 60)
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n\t\t|Congrats!! You have climbed a ladder|\n");
                    printf("\t\t=====================================\n\n"); 
                    displaychart(83, "$P1$"); // ladder
                }
                if (cp_1 == 13)
                {
                     printf("\t\t=====================================\n\n");
                     printf("\n\t\t|Congrats!! You have climbed a ladder|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(42, "$P1$"); // ladder
                }
                else
                {
                    displaychart(cp_1, "$P1$");
                }
            }
            else
            {
                cp_1 = cp_1 - dice;
                printf("|Range exceeded of Player 1.|\n");
                displaychart(cp_1, "$P1$");
            }
            printf("Player 2 position is %d\n", cp_2);

            break;
        case '2':
            dice = rd();
            system("cls");
            printf("\n----------\n");
            printf("||DICE:%d||", dice);
            printf("\n----------\n");
            cp_2 = dice + cp_2;
            if (cp_2 < 101)
            {
                if (cp_2 == 99) // snake
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n|\t\t ouch! You have been bit by a snake|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(1, "$P2$");
                }
                if (cp_2 == 65) // snake
                {
                     printf("\t\t=====================================\n\n");
                     printf("\n|\t\t ouch! You have been bit by a snake|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(40, "$P2$");
                }
                if (cp_2 == 25) // snake
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n|\t\touch! You have been bit by a snake|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(9, "$P2$");
                }
                if (cp_2 == 70) // ladder
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n\t\t|Congrats!! You have climbed a ladder|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(93, "$P2$");
                }
                if (cp_2 == 60) // ladder
                {
                     printf("\t\t=====================================\n\n");
                    printf("\n\t\t|Congrats!! You have climbed a ladder|\n");
                     printf("\t\t=====================================\n\n");
                    displaychart(83, "$P2$");
                }
                if (cp_2 == 13) // ladder
                {
                    printf("\t\t=====================================\n\n");
                    printf("\n\t\t|Congrats!! You have climbed a ladder|\n");
                    printf("\t\t=====================================\n\n");
                    displaychart(42, "$P2$");
                }
                else
                {
                    displaychart(cp_2, "$P2$");
                }
            }

            else
            {
                cp_2 = cp_2 - dice;
                printf("|Range exceeded of Player 2.|\n");
                displaychart(cp_2, "$P2$");
            }
            printf("Player 1 position is %d\n", cp_1);
            break;
        case '3':
            exit(0);
            break;

        default:
            printf("Incorrect choice.Try Again\n");
            
        }
    }
}
