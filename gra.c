#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int bool_1=1, a=0, b=0, c=10, count=0;
    int last=0;
    //pointers
    int  *pt, *pt1,*pt2;
    //giving pointers "values"
    pt=&a;
    pt1=&b;
    pt2=&c;
    while(bool_1)
    {
        if(*pt>60)
        odliczanie(pt2);
        else
        doliczanie(pt2);
        if(*pt2==-1)
        {
            last=-1;
            system("cls");
            printf("Too many moves out of the map => WASTED!");
            direction_1(pt,pt1,count,last);
            return 0;
        }
        direction_1(pt,pt1,count,last);
        count++;
        system("cls");
    }
}
void direction_1(int *wsk,int *wsk_1,int zm,int last)
{
    int value_1,value_2,i=0,j=0;
    value_1=*wsk;
    value_2=*wsk_1;

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
    while(j<value_2)
    {
        j++;
        printf("\n");
        if(j==value_2)
        {
            while(i<value_1)
            {
                printf(" ");
                i++;
            }
        }
    }
    printf("*");
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
