// moge skakac w grze
#include<stdio.h>
#include<conio.h>

#define true 1

int main()
{
    int *position, pt_position=0, *jumping, pt_jumping=0, *enemy_position, pt_enemy=100, result,score=0, value=0, last=-1, moves_w=0, level=1,highscore, defeat=0, temp=-1;
    char move;
    position=&pt_position;
    jumping=&pt_jumping;
    enemy_position=&pt_enemy;

    while(true)
    {
        if(kbhit())
        {
            move=getch();
            if(move=='w')
                {
                    jump(jumping);
                    moves_w++;
                }
        }
        printf("----------------\nYour score: %d | \t Level: %d\n----------------\n",score,level);
        movement(position,jumping,enemy_position);
        printf("\n--------------------\nAvailable moves: %d |\n--------------------\n",10-moves_w);
        if(defeat!=0)
        {
            printf("\n--------------------\nYour highscore: %d |\n--------------------\n",temp);
        }
        if(moves_w==10)
        {
            printf("\nYou lost!\n");
            sleep(3);
            return 0;
        }
        if((pt_position==pt_enemy || pt_position==pt_enemy-1 || pt_position==pt_enemy-2) && *jumping==0)
        {
            system("cls");
            pt_position++;
            *position=pt_position;
            *enemy_position=pt_position;
            explosion(position,0,score,0);
            printf("\n--------------------\nAvailable moves: %d |\n--------------------\n",moves_w);
            result=1;
        }
        if(result==1)
        {
            defeat++;
            printf("\nYou lost!\nTo continue press c..\n");
            temp=score;
            char choice;
            sleep(3);
            choice=getch();
            if(choice=='c')
            {
                result=0;
                score=0;
                level=1;
                pt_enemy=100;
                pt_position=0;
            }
            else
                return 0;
        }
        if(pt_position==100)
            {
                level++;
                pt_position=0;
            }
        if(pt_enemy<=0)
        {
            pt_enemy=101;
        }
        *jumping=0;
        pt_position++;
        if(level==1)
        pt_enemy-=2;
        else
        {
            pt_enemy=pt_enemy-2-level+1;
        }
        *position=pt_position;
        *enemy_position=pt_enemy;
        usleep(60000);
        system("cls");
        score++;
        if(!kbhit())
            moves_w=0;
    }
}
void movement(int *position, int *jumping, int *enemy_position)
{
    int i=0, j=0, enemy=0, l=0, key=0;
    while(i<5)
    {
        printf("\n");
        i++;
        if(i==4 && *jumping==1)
            break;
    }
    while(j<*position)
    {
        if(*position>*enemy_position-1 && l==0 && i==5 && *enemy_position!=-1)
        {
            while(j<*enemy_position-1)
            {
                printf(" ");
                j++;
            }
            printf("<-");
            l++;
        }
        if((*position==*enemy_position || *position==*enemy_position-2) && *jumping==0)
        {
            while(j<*enemy_position)
                {
                    printf(" ");
                    j++;
                }
            key++;
            break;
        }
        printf(" ");
        j++;
    }
    if(*position>*enemy_position && i==4)
        printf("  ");
    printf("*");
    if(i==4 && key==0)
    {
        printf("\n");
        if(enemy<*enemy_position)
        {
            while(enemy<*enemy_position)
            {
                printf(" ");
                enemy++;
            }
            printf("<-");
        }
        printf("\n");
    }
    else
    {
        if(j<*enemy_position)
        {
            while(j<*enemy_position)
            {
                printf(" ");
                j++;
            }
            printf("<-");
        }
        printf("\n");
    }
    i=0;
    while(i<102)
    {
        printf("-");
        i++;
    }
    printf("\nDONT DIE FROM A BULLET \n");
}
void jump(int *jumping)
{
    *jumping=1;
}
void explosion(int *position,int value, int score,int moves_w)
{
    int i=0,j=0, k=0;
    while(value<5)
    {
        printf("----------------\nYour score: %d |\n----------------\n",score);
        while(i<5)
        {
            if(i==value)
            {
                while(j<*position)
                {
                    printf(" ");
                    j++;
                }
            j=0;
            printf("|");
            }
            printf("\n");
            i++;
        }
        i=0;
    while(k<*position)
    {
        printf(" ");
        k++;
    }
    k=0;
    printf("*\n");
    i=0;
    while(i<102)
    {
        printf("-");
        i++;
    }
    printf("\nDONT DIE FROM A BULLET \n");
    i=0;
    sleep(1);
    if(value!=4)
    system("cls");
    if(value==4)
    {
        system("cls");
        printf("---------------\nYour score: %d\n---------------\n",score);
        while(i<5)
        {
            printf("\n");
            i++;
        }
        while(k<*position)
        {
            printf(" ");
            k++;
        }
        k=0;
        printf("+\n");
        i=0;
            while(i<102)
            {
                printf("-");
                i++;
            }
    }
    value++;
    }
}
