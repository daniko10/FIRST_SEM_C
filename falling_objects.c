#include<stdio.h>
#include<time.h>
/*
  1   2    3 4   5      678 9
  *
      *    * *          *** *
           *     *
*/
int main()
{
    int bool_first=1;
    while(bool_first)
    {
    srand(time(NULL));
    int i=0, random[10]={0}, j=0, licznik=0;
    int position[10]={0}; // to sa nasze rekordy ktore odzwierciedlaja pozycje kazdego z zawodnikow
    while(i<10)
    {
        random[i]=rand()%10+1; // musza byc wylosowane rozne liczby (to sa nasi zawodnicy)
        while(j<10)
        {
            if(random[i]==random[j])
                licznik++;
            j++;
        }
        j=0;
        if(licznik==1)
        {
            licznik=0;
            i++;
        }
        licznik=0;
    }
    // kazdy player musi miec swoja predkosc
    int speed[10], bool_=1;
    while(j<10)
    {
        speed[j]=rand()%7+1;
        j++;
    }
    int fun;
    while(bool_)
    {
        fun=moves(random,speed, position);
        if(fun==5)
        break;
        system("cls");
    }
    printf("\nTo continue press 'c' ");
    char choice;
    choice=getch();
    if(choice!='c')
        return 0;
    system("cls");
    }
    printf("\n");
}
int moves( int random[], int speed[], int position[])
{
    printf("\nCompetition!\n\n ");
    int licz=0, val=0, i=0, licznik=0;
    while(licz<10)
    {
        printf(" %d  ",random[licz]);
        licz++;
    }
    printf("\n");
    licz=0;
    while(licz<10)
    {
        if(position[licz]>30)
        {
            int winner=position[licz],num=0, wart=licz;
            licz++;
            while(licz<10)
            {
                if(position[licz]==winner && num==0)
                {
                    printf("There is a draw, %d with: %d\t",random[wart],random[licz]);
                    num++;
                }
                else if(position[licz]==winner && num!=0)
                {
                    printf("%d\t",random[licz]);
                }
                licz++;
            }
            if(num==0)
            printf("\nPlayer: %d wins!\n",random[wart]);
            return 5;
        }
        licz++;
    }
    licz=0;
    while(val<30)
    {
        printf("|");
        while(i<10)
        {
            if(val==position[i])
            {
                if(random[i]==10)
                printf("%d  ",random[i]);
                else
                    printf(" %d  ",random[i]);
            }
            else
                printf("    ");
            i++;
        }
        i=0;
        printf("|\n");
        val++;
    }
    printf("====================END===================");
    while(licz<10)
    {
        position[licz]+=speed[licz];
        licz++;
    }
    sleep(1);
}

