//add headers here
#include <stdlib.h> 
#include  <time.h> 
#include  <stdio.h>
#include <ctype.h>
#include <string.h>



//add main
int main(void)
{
    //file to be used to store maxNum:
    //read file for new current maxNum
    FILE *fileP;
    char numRead[10];
    fileP = fopen("maxNum.txt", "r");
    scanf("%s", fgets(numRead,10,fileP));

    fclose(fileP);

    int maxNum = atoi(numRead);//convert string to int
    //display menu
    int menu = 0;
    while(menu != 3)
    {
        printf("\nPress 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        //prompt user for option, 1 to 3
        
        scanf("%d", &menu);
        

        //add game here option 1
        time_t  t;
        srand((unsigned)  time(&t));
        int gameNum = rand()  %  maxNum + 1;//random number from 1 to maxNum
        if(menu == 1)
        {
            printf("You have chosen option: 1, Number Guessing Game\n" );
            
            int choice;
            char cTest[5] = "0";
            //make random number from 1 to 10
             //prompt user for number
             //tell user if too high or low
             // loop until win or "q"
            while(choice != gameNum)
            {
                printf("Enter a number between 1-10\n");
                scanf("%s", cTest);//input as string
                

                if(cTest[0] == 'q')//quit
                {
                    break;
                }
                else
                {
                    choice = atoi(cTest);//convert string to int
                    //code to validate input
                    //printf("\nGame Number: %d\n", gameNum );
                    //printf("\nInput Number: %d\n", choice );
                    if(choice == gameNum)
                    {
                        printf("\nNumber was guessed correct!\n");
                    }
                    else if(choice > gameNum)
                    {
                        printf("\nNumber is wrong, too high\n");

                    }
                    else
                    {
                        printf("\nNumber is wrong, too low\n");
                        

                    }
                }

            }

        }
        //add option 2, change max number
    //display, tell user max number, no negatives
    //prompt user for number
    //check if number is valid
    //go back to menu
        else if(menu == 2)
        {
            printf("You have chosen option 2, change max number\n");
            printf("Max number to enter is 1000\n");//integer max
            printf("No negatives allowed!\n");
            int newMax;
            scanf(" %d", &newMax);
            while(newMax > 1000 || newMax < 0 )
            {
                printf("Number not valid! Enter again: \n");
                scanf(" %d", &newMax);
            }
            maxNum = newMax;
        }

        


    

    //add option 3, quit
    //display, thank user for playing and end program

    }
    printf("Thanks for playing!\n");

    printf("Current maxNumber: %d", maxNum);
    //new branch:
    //open file
    //write maxNum
    //close file
    char str[10];
    sprintf(str, "%d", maxNum);
    FILE *fp;
    fp = fopen("maxNum.txt", "w+");
    fputs(str,fp);


    fclose(fp);
    


    

    //return success

    /////////////////******new branch, save max number request for next time?

    return EXIT_SUCCESS;

}


