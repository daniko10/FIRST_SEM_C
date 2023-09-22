#include "sudoku.h"

/* ALGORITHM WAS FULLY DEVELOPED by Daniel Czapla */

int main(void) {
    srand(time(NULL));
    
    system("cls");
    poczatek();
    system("cls");
    char sudoku[9][9];
    int is_finished = 0;
    int var;
    int licznik = 0;
    int choi = 0;

    create_sudoku(sudoku); // function creates original SUDOKU

    printf("COMPLETED SUDOKU: \n");
    print(sudoku,licznik);

    sleep(2); // time to see completed sudoku
    system("cls");
    printf("YOUR SUDOKU: \n");
    delete_sudoku(sudoku); // function changing sudoku (deleting enough elements to make it solvable)
    print(sudoku,licznik);
    sleep(2); // time to see your success or failure

    while(is_finished <= 0) {
        int first, second;

        ++licznik;

        if(choi == 1) {system("cls"); print(sudoku,licznik);}
        choi = 0;
        // giving indexes
        printf("\nPodaj pierwsza wsp: "); scanf("%d",&first); printf("Podaj druga wsp: "); scanf("%d",&second);

        printf("Inserting: "); scanf("%d",&var); 
        if(var<=0 || var > 9 || first<0 || first >9 || second < 0 || second > 9) { printf("You kiding?\n"); continue; }
        var+=48; // changing to ASCII 

        is_finished = check(sudoku,first,second,var,0); if(is_finished == 1) break; else if(is_finished == -1) licznik--;
        
        print(sudoku,licznik);
        sleep(1);

        wybor:       
        if((licznik-1)%5 == 0) {
            printf("\n ----------------------- \t ------------------------------ \t ----------------- \t ---------------------------------------------------------\n");
            printf("| To continue press '1' \t To make a new sudoku press '2' \t To quit press '3' \t To complete this sudoku '4' (since 25 moves)|\n ----------------------- \t ------------------------------ \t ----------------- \t ---------------------------------------------------------\n| Your choice: ");
            scanf("%d",&choi);
            
            if(choi == 1) continue; else if(choi == 2) { licznik = 0; create_sudoku(sudoku); delete_sudoku(sudoku); } else if(choi == 3) break; else if(choi == 4 && licznik>=25) {complete(sudoku); break;} else goto wybor;
        }

        system("cls");
        print(sudoku,licznik);
        sleep(1);
    }
    system("cls");
    printf("Your SUDOKU: \n"); print(sudoku,licznik);
    printf("\nBRAVO!!\n\n");
    system("pause");
}

