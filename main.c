#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include "TicTacTeoGame.h"


uint8 Game[3][3];
sint32 countloop=0;

sint32 main()
{


    sint32  mode;
    sint32  option1;
    sint32  option2;


    while(1)
    {

        printf("\n---------Welcome In Tic Tac Toe Game ----------\n\n");

        TicTacTeoGame_VoidInitializeGame();

        printf("\n\n\n");
        printf("Press Any key to continue .");
        getch();
        system("cls");

        printf("Please Choose the mode [Enter 1 for Multi and 2 for Single]\n\n");

        printf("1- Multi  players mode \n");
        printf("2- Single player\n\n");




        int x=scanf("%d", &mode);

        while(x == 0 || !(mode==1 || mode ==2) )
        {
            printf("\n\nPlease enter a valid input .\n");

            fflush(stdin);              // discard any remaining characters in the input buffer

            x=scanf("%d", &mode);
        }
        system("cls");


        if(mode==1)
        {
            TicTacTeoGame_VoidMultiPlayersMode();
        }


        else if (mode==2)
        {
            printf("\nSelect the game difficulty [Enter 1 for Easy and 2 for Hard]...\n\n");

            printf("1- Easy Level \n");
            printf("2- Hard Level \n");
            x=scanf("%d",&option1);

            while(x==0 || !(option1 ==1 || option1 ==2))
            {
                printf("\nPlease enter a valid input .\n");

                fflush(stdin);
                x=scanf("%d",&option1);
            }

            system("cls");

            if(option1==1)
            {
                TicTacTeoGame_VoidEasySinglePlayersMode();

            }
            else if(option1==2)
            {
                TicTacTeoGame_VoidHardSinglePlayersMode();
            }

        }

        getch();
        system("cls");


        printf("\n\nDo you want to play [Enter 1 for Yes and 2 for No] !! \n\n");
        printf("1- YES\n");
        printf("2- NO\n");

        x=scanf("%d",&option2);

        while(x==0 || !(option2 ==1 || option2 ==2))
        {
            printf("\nPlease enter a valid input .\n");

            fflush(stdin);
            x=scanf("%d",&option2);
        }

        system("cls");

        if (option2 == 1)
        {
            continue;
        }
        else if(option2 == 2)
        {
            printf("\nGame Terminated .\n");
            break;
        }

    }
}

