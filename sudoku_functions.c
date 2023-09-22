#include "sudoku.h"

void create_sudoku(char sudoku[][9]) {
    srand(time(NULL));
    int var =0;
    int tries = 0;

    poczatek:
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) sudoku[i][j] = ' '; // deleting elements

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            var = 0;
            
            etykieta:
            ++var;
            if(var == MAX) goto poczatek;
            
            sudoku[i][j] = rand()%9 + 49;
            for(int k=0; k<9; k++) {
                int row = (j/3) * 3; 
                int col = (i/3) * 3; 
                int a = row, b= col;

                if(((sudoku[i][j] == sudoku[i][k]) && j!=k) || ((sudoku[i][j] == sudoku[k][j]) && i!=k) ) { goto etykieta;} 

                    for(int d=col; d<=b+2; d++) {
                        for(int c = row; c <= a+2; c++)
                        if((sudoku[d][c] == sudoku[i][j]) && (c!=j && d!=i)) {   goto etykieta;} 
                   }
            
                
            } 
        }
    }
    sleep(1);
    system("cls");
}

void print(char sudoku[][9], int var) {
    
    for(int i=0; i<9; i++) {
        int j=0;
        if(i%3==0) printf("\n");
        for(; j<9; j++) { if(j%3 == 0) printf("|"); printf("%c ",sudoku[i][j]);} if(i != 0 && i != 1 && i != 2) printf("\n");
        if(i == 0 && j == 9) printf("\t---------------\n");
        if(i == 1 && j == 9) printf("\tYOUR MOVES: %d\n", var);
        if(i == 2 && j == 9) printf("\t---------------\n");
    }
    
}

void delete_sudoku(char sudoku[][9]) {
    srand(time(NULL));

    for(int i=0; i<45; ) {
        int first = rand()%9;
        int second = rand()%9;
        if(sudoku[first][second] != ' ') { i++; sudoku[first][second] = ' '; }
    }
}

int check(char sudoku[][9], int first, int second, int var, int x) {
    if(sudoku[first][second] != ' ') { system("cls");
        printf("Its already taken!\n"); return -1;
    } else {
                    for(int k=0; k<9; k++) {
                        int row = (second/3) * 3; 
                        int col = (first/3) * 3; 
                        int a = row, b= col;

                        if(((var == sudoku[first][k]) && second!=k) || ((var == sudoku[k][second]) && first!=k) ) { system("cls"); if(x==0) printf("Blad w wierszu lub kolumnie!\n"); return -1;} 
                            for(int d=col; d<=b+2; d++) {
                                for(int c = row; c <= a+2; c++)
                                if((sudoku[d][c] == var) && (c!=second && d!=first)) { system("cls"); if(x==0) printf("Blad w 3x3!\n"); return -1;} 
                        }
                    
                        
                    }

        sudoku[first][second] = var;
        system("cls");
        printf("You can put it!");
        
        for(int i=0; i<9; i++) {
            for(int j=0;j<9;j++) if(sudoku[i][j] == ' ') return 0;
        }
        return 1;
    }
}

void complete(char sudoku[][9]) {
    srand(time(NULL));
    int var, key, licz = 0;
    int tab[9] = {0};
    char temp[9][9];
    for(int i=0; i<9; i++) for(int j = 0; j<9; j++) temp[i][j] = sudoku[i][j];
    
    etykieta:
    for(int i=0; i<9; i++) {
        licz = 0;
        tab[i] = rand()%9 + 49;
        for(int j= 0; j<9; j++) {
            if(tab[i] == tab[j]) licz++;
        }
        if(licz != 1) goto etykieta;
    }
    for(int i=0; i<9; i++) for(int j = 0; j<9; j++) sudoku[i][j] = temp[i][j];
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(sudoku[i][j] == ' ') {
                for(int k=0; k<9; k++) {
                    int key = check_1(sudoku,i,j,tab[k]);
                    if( key != -1) break; }
                if(sudoku[i][j] == ' ') goto etykieta;
            }
        }
    }

    return;
}

int check_1(char sudoku[][9], int first, int second, int var) {
    for(int k=0; k<9; k++) {
            int row = (second/3) * 3; 
            int col = (first/3) * 3; 
            int a = row, b= col;

            if(((var == sudoku[first][k]) && second!=k) || ((var == sudoku[k][second]) && first!=k) ) { return -1;} 
                        for(int d=col; d<=b+2; d++) {
                            for(int c = row; c <= a+2; c++)
                             if((sudoku[d][c] == var) && (c!=second && d!=first)) { return -1;} 
                    }              
            }
    sudoku[first][second] = var;

    for(int i=0; i<9; i++) {
        for(int j=0;j<9;j++) if(sudoku[i][j] == ' ') return 0;
    }
       return 1;
}

void poczatek() {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 100000;
    
    char napis[] = "ALGORITHM FULLY DEVELOPED BY Daniel Czapla";
    int i = 0, var = 49, a = 0, temp, n = sizeof(napis)/sizeof(char);
    
    while(1) {
        for(int i=0; i< var; i++) printf(" ");
        temp = var;
        
        while(temp < 50) { if(i < n) printf("%c",napis[i++]); temp++;}
        
        if(var != 0) { i = 0; var--;}
        else i = a++;

        system("cls");

        if(a == n) break;
    }
    printf("Your sudoku is being generated"); sleep(1);
}