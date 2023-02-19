#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int bool_1=1, a=0, b=0, c=10, d=60, count=0,random=rand()%21+1, num=0;
    int last=0;
    char number;
    //pointers
    int  *pt, *pt1,*pt2,*pt3;
    //giving pointers "values"
    pt=&a;
    pt1=&b;
    pt2=&c;
    pt3=&d;
    //intro
    int intro=1;
    while(intro<=100)
    {
        printf("--------------------\n");
        int intr_1=0;
        while(intr_1<intro)
        {
            if(intr_1%10==0)
            printf("[]");
            intr_1++;
        }
        printf("\n--------------------\n");
        printf("Loading %d%%",intro);
        sleep(1);
        if(intro>70 && (number!='c' && number!='C') && num==0)
        {
            num++;
            printf("\nTo cancel press 'C'");
            number=getch();
            if(number=='c' || number=='C')
            {
                printf("You stopped loading the game. Bye\n");
                return 0;
            }
        }
        intro++;
        system("cls");
        if(intro==100)
            break;
    }


    //main game
    while(bool_1)
    {
        if(*pt3==0)
        {
            random=rand()%21+1; // it will choose the place of the next enemy between possbile range
            d=60;
            pt3=&d;
        }
        if(*pt>60)
        odliczanie(pt2);
        else
        doliczanie(pt2);
        if(*pt2==-1)
        {
            last=-1;
            system("cls");
            printf("Too many moves out of the map => WASTED!");
            direction_1(pt,pt1,pt3,count,last,random);
            sleep(2);
            return 0;
        }
        direction_1(pt,pt1,pt3,count,last,random);
        if(*pt==*pt3 && *pt1==-1)
        {
            printf("\nGOT YOU!\n");
            sleep(2);
            return 0;
        }
        count++;
        system("cls");
    }
}
void direction_1(int *wsk,int *wsk_1,int *wsk_2,int zm,int last, int random)
{
    int value_1,value_2,value_3,i=0,j=0,k=0;
    value_1=*wsk;
    value_2=*wsk_1;
    value_3=*wsk_2;

    char choice;

    printf("\n-------------------------PLAYGROUND--------------------------");
    if(zm==0)
    value_2+=10;
    if(value_2==0)
    while(i<value_1)
    {
        printf(" ");
        i++;
    }
    i=0;
    while(j<21)
    {
        if(random!=value_2)
        {
            if(random>value_2)
            {
                if(j==value_2)
                {
                    while(i<value_1)
                    {
                        printf(" ");
                        i++;
                    }
                    printf("*");
                }
                i=0;
                if(j==random)
                {
                    while(i<value_3)
                    {
                        printf(" ");
                        i++;
                    }
                    value_3--;
                    printf("<");
                    if(k==value_3)
                        {
                        system("cls");
                        value_3=0;
                        *wsk_2=value_3;
                        return 0;
                        }
                }
            }
            if(random<value_2)
            {
                if(j==random)
                {
                    while(i<value_3)
                    {
                        printf(" ");
                        i++;
                    }
                    printf("<");
                    value_3--;
                }
                i=0;
                if(i==value_3)
                {
                    system("cls");
                    value_3=0;
                    *wsk_2=value_3;
                    return 0;
                }
                if(j==value_2)
                {
                    while(i<value_1)
                    {
                        printf(" ");
                        i++;
                    }
                    printf("*");
                }
                i=0;
            }
            printf("\n");
        }
        else
        {
            while(j<random)
            {
                printf("\n");
                j++;
            }
            if((value_1==value_3 || (value_1+1==value_3)))
            {
                while(i<value_3)
                {
                    printf(" ");
                    i++;
                }
                printf("<&*");
                value_3--;
                i=0;
                while(j<21)
                    {
                        printf("\n");
                        j++;
                    }
                printf("-----------------------------END----------------------------");
                if(k==value_3)
                {
                    system("cls");
                    value_3=0;
                    *wsk_2=value_3;
                    return 0;
                }
                value_2=-1;
                value_1=value_3=0;
                *wsk=value_1;
                *wsk_1=value_2;
                *wsk_2=value_3;
                return 0;
            }
            if(value_3>value_1)
            {
                while(i<value_1)
                {
                    printf(" ");
                    i++;
                }
                printf("*");
                while(i<value_3)
                {
                    printf(" ");
                    i++;
                }
                printf("<");
                value_3--;
                k=0;
                if(k==value_3)
                {
                    system("cls");
                    value_3=0;
                    *wsk_2=value_3;
                    return 0;
                }
                break;
            }
            else if(value_1>value_3)
            {
                while(i<value_3)
                {
                    printf(" ");
                    i++;
                }
                printf("<");
                value_3--;
                k=0;
                if(k==value_3)
                {
                    system("cls");
                    value_3=0;
                    *wsk_2=value_3;
                    return 0;
                }
                while(i<value_1)
                {
                    printf(" ");
                    i++;
                }
                printf("*");
                break;
            }
        }
        j++;
    }
    while(j<21)
    {
        printf("\n");
        j++;
    }
    printf("-----------------------------END----------------------------");
    if(last==-1)
        return 0;
    j=0;
    choice=getch();
    switch(choice)
    {
        case 'a': {
            if(value_1>0)
            value_1--;
        }
        break;
        case 'd': {
            value_1++;
        }
        break;
        case 'w': {
            if(value_2>1)
            value_2--;
        }
        break;
        case 's': {
            if(value_2<20)
            value_2++;
        }
        break;
    }
    *wsk=value_1;
    *wsk_1=value_2;
    *wsk_2=value_3;
}
void odliczanie(int *w)
{
    int number=*w;
    if(number>=0)
    {
        printf("Available moves out of map -> %d",number);
        number--;
    }
    *w=number;
}
void doliczanie(int *w)
{
    int number=10;
    *w=number;
}
// how to make some "objects" "flying" into us
