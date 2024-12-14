#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Single Player
int game1()
{
    int num1,n,guess1=1;
    srand(time(0));
    num1=rand()%100+1;
    printf("\nGuess the no. between '1 to 100'\n");
    do
    {
       label3:printf("Enter: ");
       scanf("%d",&n);
       if (n>100)
       {
            printf("Invalid! Enter no. between '1 to 100'\n");
            goto label3;
       }
       
       if(n>num1)
        {   
            printf("\nLower no. please!\n");
        }
        else if (n<num1)
        {
            printf("\nHigher no. please!\n");
        }
        else
        {
            printf("\nYou guessed it in %d attempts\n",guess1);
        }
        guess1++;   
    } while (n!=num1);
    return guess1;
}

//Double Player
void game2()
{
    int num2,n,guess1=1,guess2=1;
    char name[2][10];
    srand(time(0));
    num2=rand()%100+1;
    printf("\nPlease Enter your Names -\n\nPLAYER 1: ");
    scanf("%s",name[0]);
    printf("PLAYER 2: ");
    scanf("%s",name[1]);
    //Player 1
    printf("\n%s's Turn -\n",name[0]);
    guess1 = game1();

    //Player 2
    printf("\n\n%s's Turn -\n",name[1]);
    printf("\nGuess the no. between '1 to 100'\n");
    do
    {
        label4:printf("Enter: ");
        scanf("%d",&n);
        if (n>100)
        {
            printf("Invalid! Enter no. between '1 to 100'\n");
            goto label4;
        }
        if(n>num2)
        {   
            printf("\nLower no. please!\n");
        }
        else if (n<num2)
        {
            printf("\nHigher no. please!\n");
        }
        else
        {
            printf("\nYou guessed it in '%d' attempts\n\n",guess2);
        }
        guess2++;
    } while (n!=num2);

    //Winner
    if (guess1<guess2)
    {
        printf("\n%*c%s 'WINS'\n",55,' ',name[0]);
    }
    else if (guess1>guess2)
    {
        printf("\n%*c%s 'WINS'\n",55,' ',name[1]);
    }
    else{
        printf("\nIts a 'DRAW'\n");
    }
}

//Game
int main()
{
    int n;
    char str[10];
    printf("\n\n%*cThe No. Guessing Game",50,' ');
    while(1){
        //Players
        printf("\n\nEnter no. of Player: 1/2 - ");
        label1:scanf("%d",&n);
        if(n==1){
            game1();
        }
        else if (n==2){
            game2();
        }
        else{
            printf("\n'Invalid' Please Enter 1/2 - ");
            goto label1;
        }

        //Repeat
        printf("\n%*cWanna Play Again? Y,y/N,n - ",50,' ');
        label2:scanf("%s",str);
        if (str[0]=='n'||str[0]=='N'){
            break;
        }
        else if (str[0]=='y'||str[0]=='Y'){
            continue;
        }
        else{
            printf("\n%*c'Invalid' Please Enter Y,y(yes)/N,n(no) - ",45,' ');
            goto label2;
        }
}
    printf("\n\n%*c'THANK YOU'",55,' ');
    return 0;
}