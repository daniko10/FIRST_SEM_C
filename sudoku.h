#ifndef SUDOKU_H
#define SUDOKU_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>

#define MAX 1000

void print(char sudoku[][9], int var);
void create_sudoku( char sudoku[][9]);
void delete_sudoku( char sudoku[][9]);
void complete(char sudoku[][9]);
void poczatek();
int check_1(char sudoku[][9], int first, int second, int var);
int check(char sudoku[][9], int first, int second, int var, int x);

#endif