
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "TicTacTeoGame.h"


extern sint32 countloop;
extern uint8 Game[3][3];




/**
 *
 * @param  void
 * @return void
 */
void TicTacTeoGame_VoidInitializeGame(void)
{
    sint32 i,j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            Game[i][j] = ' ';
        }
    }
    sint32 count = 1;
    printf("\n\n\t  ");
    for( i = 0; i < 3; i++)
    {
        for( j = 0; j < 3; j++)
        {
            printf("%d", count++);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
            printf("\n\t------------------\n\t  ");
    }
    printf("\n\n\n");
}



/**
 *
 * @param  void
 * @return void
 */

void TicTacTeoGame_VoidShowGame(void)
{
    sint32 i,j;
    printf("\n\n\t  ");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%c", Game[i][j]);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
            printf("\n\t------------------\n\t  ");
    }
    printf("\n\n\n");
}



/**
 *
 * @param   X_O ( What symbol would you like to check about ? (X or O) )
 * @return  There is a winner or not

 *          ( 1 ) : There is a winner
 *          ( 0 ) : There is no a winner (Result is Draw )
 */


sint32 TicTacTeoGame_sint32CheckWinner(const sint8 X_O)
{
    // check all rows
    if (Game[0][0] == X_O && Game[0][1] == X_O && Game[0][2] == X_O ||
            Game[1][0] == X_O && Game[1][1] == X_O && Game[1][2] == X_O ||
            Game[2][0] == X_O && Game[2][1] == X_O && Game[2][2] == X_O)
    {
        return 1;
    }
    // check all columns
    else if (Game[0][0] == X_O && Game[1][0] == X_O && Game[2][0] == X_O ||
             Game[0][1] == X_O && Game[1][1] == X_O && Game[2][1] == X_O ||
             Game[0][2] == X_O && Game[1][2] == X_O && Game[2][2] == X_O)
    {
        return 1;
    }
    // check both diagonals
    else if (Game[0][0] == X_O && Game[1][1] == X_O && Game[2][2] == X_O ||
             Game[0][2] == X_O && Game[1][1] == X_O && Game[2][0] == X_O)
    {
        return 1;
    }

    // There is no winner
    return 0;
}


/**
 *
 * @param Index of Cell number .
 * @param X_O ( What do you want this player to play? (X or O) )
 * @return Status of the function

 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has wrong input
 */
sint32 TicTacTeoGame_sint32Player_X_O(const sint32 index,const sint8 X_O)
{
    uint8 State=E_OK;


    switch(index)
    {
    case 1:
        if(Game[0][0] == ' ')
        {
            Game[0][0]= X_O;
            countloop++;
        }
        else
        {

            printf("\nCell is already Filled !!!\n");
            State=E_NOT_OK;

        }
        break;
    case 2:

        if(Game[0][1] == ' ')
        {
            Game[0][1]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }
        break;
    case 3:

        if(Game[0][2] == ' ')
        {
            Game[0][2]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }

        break;
    case 4:

        if(Game[1][0] == ' ')
        {
            Game[1][0]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }

        break;
    case 5:

        if(Game[1][1] == ' ')
        {
            Game[1][1]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }

        break;
    case 6:

        if(Game[1][2] == ' ')
        {
            Game[1][2]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }

        break;
    case 7:

        if(Game[2][0] == ' ')
        {
            Game[2][0]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }

        break;
    case 8:

        if(Game[2][1] == ' ')
        {
            Game[2][1]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }

        break;
    case 9:

        if(Game[2][2] == ' ')
        {
            Game[2][2]= X_O;
            countloop++;
        }
        else
        {
            printf("\nCell is already Filled!\n");
            State=E_NOT_OK;
        }
        break;
    case -1:

        printf("\nGame is Over .\n");
        break;

    default:
        printf("\nCell is out of Matrix ");
            State=E_NOT_OK;
        break;

    }



    return State;
}


/**
 *
 * @param  void
 * @return void
 */

void TicTacTeoGame_VoidMultiPlayersMode(void)
{
    sint32 index;
    countloop=0;
    int x;
    sint32 Check=0;
    uint8 State=0;
    uint8 Names[2][12];

    printf("Welcome in MultiMode \n\n");


    printf("Enter the name of player 1: ");
    scanf("%s",&Names[0]);

    printf("Enter the name of player 2: ");
    scanf("%s",&Names[1]);

    printf("\n%s : X \n\n",Names[0]);
    printf("%s : O \n\n",Names[1]);

    printf("Press Any key to continue .");

    getch();
    system("cls");


    printf("\n\nEnter -1 at any time to exit the game . \n\n");

    TicTacTeoGame_VoidInitializeGame();

    while(countloop<9)
    {
        printf("%s's turn[ X ] : ",Names[0]);

        x=scanf("%d", &index);
        if(x==1)
        {
            State=TicTacTeoGame_sint32Player_X_O(index, 'X' );
        }

        while( x != 1 || State==1 )
        {
            printf("\nInvalid Input, Enter again !\n");

            printf("%s's turn[ X ] : ",Names[0]);

            fflush(stdin);              // discard any remaining characters in the input buffer
            x=scanf("%d", &index);

            if(x==1)
            {
                State=TicTacTeoGame_sint32Player_X_O(index, 'X' );
            }
        }





        if(index == -1)
            break;


        system("cls");

        TicTacTeoGame_VoidShowGame();
        Check=TicTacTeoGame_sint32CheckWinner('X');

        if(Check==1)
        {
            printf(" ** %s [X] Won **  ",Names[0]);
            break;
        }

        if(countloop==9)
            break;

        State=0;
        printf("%s's turn [ O ] : ",Names[1]);

        x=scanf("%d", &index);
        if(x==1)
        {
            State=TicTacTeoGame_sint32Player_X_O(index, 'O' );
        }


        while( x != 1 || State==1 )
        {
            printf("\nInvalid Input, Enter again !\n");

            printf("%s's turn [ O ] : ",Names[1]);

            fflush(stdin);              // discard any remaining characters in the input buffer
            x=scanf("%d", &index);

            if(x==1)
            {
                State=TicTacTeoGame_sint32Player_X_O(index, 'O' );
            }
        }



        if(index==-1)
            break;

        system("cls");

        TicTacTeoGame_VoidShowGame();



        Check=TicTacTeoGame_sint32CheckWinner('O');

        if(Check==1)
        {
            printf(" ** %s [O] Won **  ",Names[1]);
            break;
        }

    }

    if( Check==0 && countloop == 9 &&index != -1)
    {
        printf("%s and %s are equal !! ",Names[0],Names[1]);
    }

    printf("\n\nPress Any key to continue .");



}

/**
 *
 * @param  void
 * @return void
 */

void TicTacTeoGame_VoidEasySinglePlayersMode(void)
{
    sint32 index;
    countloop=0;
    sint32 Check=0;
    sint32 x;
    sint32 option;
    uint8 Name[12];

    printf("Welcome in Easy Single Mode \n\n");

    printf("Enter the name of player : ");
    scanf("%s",Name);


    printf("\n%s  : X \n\n",Name);
    printf("Bot : O \n\n");


    printf("Who do you want to start first, %s [Enter 1] or Bot [Enter 2]?\n\n",Name);

    printf("1- %s\n",Name);
    printf("2- Bot\n");

    x=scanf("%d",&option);

    while(x==0 || !(option ==1 || option ==2))
    {
        printf("\nPlease enter a valid input .\n");

        fflush(stdin);
        x=scanf("%d",&option);
    }


    system("cls");


    printf("Enter -1 at any time to exit the game . \n\n");

    TicTacTeoGame_VoidInitializeGame();

    if(option==2)
    {
        goto BotStart;
    }

    while(countloop<9)
    {
        uint8 State=0;

        printf("\n%s  : [X] : ",Name);

        x=scanf("%d", &index);
        if(x==1)
        {
            State=TicTacTeoGame_sint32Player_X_O(index, 'X' );
        }


        while( x != 1 || State==1 )
        {
            printf("\nInvalid Input, Enter again !\n");

            printf("\n%s  : X \n\n",Name);

            fflush(stdin);              // discard any remaining characters in the input buffer
            x=scanf("%d", &index);

            if(x==1)
            {
                State=TicTacTeoGame_sint32Player_X_O(index, 'X' );
            }
        }


        if(index==-1)
            break;

        system("cls");

        TicTacTeoGame_VoidShowGame();

        Check=TicTacTeoGame_sint32CheckWinner('X');

        if(Check==1)
        {
            printf(" ** %s [X] Won **  ",Name);
            break;
        }

        BotStart:

        TicTacTeoGame_VoidEasySmartAlgorithm();

        system("cls");
        TicTacTeoGame_VoidShowGame();

        Check=TicTacTeoGame_sint32CheckWinner('O');

        if(Check==1)
        {
            printf(" ** Bot [O] Won **  ");
            break;
        }
    }

    if(Check ==0 && index != -1 )
    {
        printf("Result is Draw !!");
    }

    printf("\n\nEnter any key to continue.");

}

/**
 *
 * @param  void
 * @return void
 */

void TicTacTeoGame_VoidHardSinglePlayersMode(void)
{
    sint32 index;
    countloop=0;
    sint32 Check=0;
    sint32 x;
    sint32 option;
    uint8 Name[12];

    printf("Welcome in Hard Single Mode \n\n");

    printf("Enter the name of player : ");
    scanf("%s",Name);


    printf("\n%s  : X \n\n",Name);
    printf("Bot : O \n\n");


    printf("Who do you want to start first, %s [Enter 1] or Bot [Enter 2] ?\n\n",Name);

    printf("1- %s\n",Name);
    printf("2- Bot\n");

    x=scanf("%d",&option);

    while(x==0 || !(option ==1 || option ==2))
    {
        printf("\nPlease enter a valid input .\n");

        fflush(stdin);
        x=scanf("%d",&option);
    }

    system("cls");

    printf("Enter -1 at any time to exit the game . \n\n");
    TicTacTeoGame_VoidInitializeGame();


    if(option==2)
    {
        goto BotStart;
    }

    while(countloop<9)
    {
        uint8 State=0;

        printf("\n%s  [ X ] : ",Name);

        x=scanf("%d", &index);
        if(x==1)
        {
            State=TicTacTeoGame_sint32Player_X_O(index, 'X' );
        }


        while( x != 1 || State==1 )
        {
            printf("\nInvalid Input, Enter again !\n");

            printf("\n%s  [ X ] : ",Name);

            fflush(stdin);              // discard any remaining characters in the input buffer
            x=scanf("%d", &index);

            if(x==1)
            {
                State=TicTacTeoGame_sint32Player_X_O(index, 'X' );
            }
        }


        if(index==-1)
            break;

        system("cls");

        TicTacTeoGame_VoidShowGame();

        Check=TicTacTeoGame_sint32CheckWinner('X');

        if(Check==1)
        {
            printf(" ** %s [X] Won **  ",Name);
            break;
        }

        BotStart:

        TicTacTeoGame_VoidHardSmartAlgorithm();

        system("cls");
        TicTacTeoGame_VoidShowGame();

        Check=TicTacTeoGame_sint32CheckWinner('O');

        if(Check==1)
        {
            printf(" ** Bot [O] Won **  ");
            break;
        }
    }

    if(Check ==0 && index!=-1)
    {
        printf("Result is Draw !!");
    }

    printf("\n\nEnter any key to continue.");

}

/**
 *
 * @param  void
 * @return void
 */

void TicTacTeoGame_VoidHardSmartAlgorithm(void)
{
    sint32 i,j,flag_2=0;
    printf("Computer [ O ] : \n");

    countloop++;

    // for column 1 .
    if(Game[0][0]=='O' && Game[1][0]=='O' &&  Game[2][0]==' ')
        Game[2][0]='O';
    else if(Game[0][0]=='O' && Game[2][0]=='O' && Game[1][0]==' ')
        Game[1][0]='O';
    else if(Game[1][0]=='O' && Game[2][0]=='O' &&  Game[0][0]==' ')
        Game[0][0]='O';

    //for Column 2 .
    else if(Game[0][1]=='O' && Game[1][1]=='O' &&  Game[2][1]==' ')
        Game[2][1]='O';
    else if(Game[0][1]=='O' && Game[2][1]=='O' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='O' && Game[2][1]=='O' &&  Game[0][1]==' ')
        Game[0][1]='O';

    //for Column 3 .
    else if(Game[0][2]=='O' && Game[1][2]=='O' &&  Game[2][2]==' ')
        Game[2][2]='O';
    else if(Game[0][2]=='O' && Game[2][2]=='O' && Game[1][2]==' ')
        Game[1][2]='O';
    else if(Game[1][2]=='O' && Game[2][2]=='O' &&  Game[0][2]==' ')
        Game[0][2]='O';


    // for Row 1 .
    else if(Game[0][0]=='O' && Game[0][1]=='O' &&  Game[0][2]==' ')
        Game[0][2]='O';
    else if(Game[0][0]=='O' && Game[0][2]=='O' && Game[0][1]==' ')
        Game[0][1]='O';
    else if(Game[0][1]=='O' && Game[0][2]=='O' && Game[0][0]==' ')
        Game[0][0]='O';

    // for Row 2 ........0
    else if(Game[1][0]=='O' && Game[1][1]=='O' &&  Game[1][2]==' ')
        Game[1][2]='O';
    else if(Game[1][0]=='O' && Game[1][2]=='O' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='O' && Game[1][2]=='O' && Game[1][0]==' ')
        Game[1][0]='O';

    // for Row 3 .
    else if(Game[2][0]=='O' && Game[2][1]=='O' &&  Game[2][2]==' ')
        Game[2][2]='O';
    else if(Game[2][0]=='O' && Game[2][2]=='O' && Game[2][1]==' ')
        Game[2][1]='O';
    else if(Game[2][1]=='O' && Game[2][2]=='O' && Game[2][0]==' ')
        Game[2][0]='O';




    else if(Game[0][0]=='O' && Game[1][1]=='O' && Game[2][2]==' ')
        Game[2][2]='O';
    else if(Game[0][0]=='O' && Game[2][2]=='O' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='O' && Game[2][2]=='O' && Game[0][0]==' ')
        Game[0][0]='O';

    else if(Game[0][2]=='O' && Game[1][1]=='O' && Game[2][0]==' ')
        Game[2][0]='O';
    else if(Game[0][2]=='O' && Game[2][0]=='O' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='O' && Game[2][0]=='O' && Game[0][2]==' ')
        Game[0][2]='O';

    // for column 1 .
    else if(Game[0][0]=='X' && Game[1][0]=='X' &&  Game[2][0]==' ')
        Game[2][0]='O';
    else if(Game[0][0]=='X' && Game[2][0]=='X' && Game[1][0]==' ')
        Game[1][0]='O';
    else if(Game[1][0]=='X' && Game[2][0]=='X' &&  Game[0][0]==' ')
        Game[0][0]='O';

    //for Column 2 .
    else if(Game[0][1]=='X' && Game[1][1]=='X' &&  Game[2][1]==' ')
        Game[2][1]='O';
    else if(Game[0][1]=='X' && Game[2][1]=='X' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='X' && Game[2][1]=='X' &&  Game[0][1]==' ')
        Game[0][1]='O';

    //for Column 3 .
    else if(Game[0][2]=='X' && Game[1][2]=='X' &&  Game[2][2]==' ')
        Game[2][2]='O';
    else if(Game[0][2]=='X' && Game[2][2]=='X' && Game[1][2]==' ')
        Game[1][2]='O';
    else if(Game[1][2]=='X' && Game[2][2]=='X' &&  Game[0][2]==' ')
        Game[0][2]='O';


    // for Row 1 .
    else if(Game[0][0]=='X' && Game[0][1]=='X' &&  Game[0][2]==' ')
        Game[0][2]='O';
    else if(Game[0][0]=='X' && Game[0][2]=='X' && Game[0][1]==' ')
        Game[0][1]='O';
    else if(Game[0][1]=='X' && Game[0][2]=='X' && Game[0][0]==' ')
        Game[0][0]='O';

    // for Row 2 .
    else if(Game[1][0]=='X' && Game[1][1]=='X' &&  Game[1][2]==' ')
        Game[1][2]='O';
    else if(Game[1][0]=='X' && Game[1][2]=='X' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='X' && Game[1][2]=='X' && Game[1][0]==' ')
        Game[1][0]='O';

    // for Row 3 .
    else if(Game[2][0]=='X' && Game[2][1]=='X' &&  Game[2][2]==' ')
        Game[2][2]='O';
    else if(Game[2][0]=='X' && Game[2][2]=='X' && Game[2][1]==' ')
        Game[2][1]='O';
    else if(Game[2][1]=='X' && Game[2][2]=='X' && Game[2][0]==' ')
        Game[2][0]='O';




    else if(Game[0][0]=='X' && Game[1][1]=='X' && Game[2][2]==' ')
        Game[2][2]='O';
    else if(Game[0][0]=='X' && Game[2][2]=='X' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='X' && Game[2][2]=='X' && Game[0][0]==' ')
        Game[0][0]='O';

    else if(Game[0][2]=='X' && Game[1][1]=='X' && Game[2][0]==' ')
        Game[2][0]='O';
    else if(Game[0][2]=='X' && Game[2][0]=='X' && Game[1][1]==' ')
        Game[1][1]='O';
    else if(Game[1][1]=='X' && Game[2][0]=='X' && Game[0][2]==' ')
        Game[0][2]='O';
    else
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(Game[i][j]==' ')
                {
                    flag_2=1;
                    Game[i][j]='O';
                    break;
                }
            }
            if(flag_2==1)
                break;
        }
    }


}

/**
 *
 * @param  void
 * @return void
 */

void TicTacTeoGame_VoidEasySmartAlgorithm(void)
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(Game[i][j]==' ')
                break;
        }
        if(Game[i][j]==' ')
            break;
    }

    if(i*j==9)
    {
        printf("draw\n");
        exit(0);
    }
    else
        Game[i][j] = 'O';
}
