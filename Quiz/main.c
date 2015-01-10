//
//  main.c
//  Quiz
//
//  Created by Rubyist on 02/01/15.
//  Copyright (c) 2015 Sayawan Devs. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <stdarg.h>

// DON'T ERASE THE VARIABLE AND FUNCTION
char grid[20][20];
void printGrid()
{
    int a,b;
    
    printf("\n\n   ");
    
    for(b=0; b<40; b++)
        if(b%2==0) printf(" "); else printf("%2d ",b/2);
    printf("\n");
    for(a=0; a<41; a++)
    {
        if(a%2==0) printf("   "); else printf("%2d ",a/2);
        for(b=0; b<40; b++)
        {
            if(a==0)
            {
                if(b==0) printf("..");
                else if(b%2==0) printf(".."); else printf("..");
            }
            else if(a==40)
            {
                if(b==0) printf("..");
                else if(b%2==0) printf(".."); else printf("..");
            }
            else
            {
                if(a%2==0)
                    if(b==0) printf("..");
                    else if(b%2==0) printf(".."); else printf("..");
                    else
                        if(b%2==0) printf(". "); else printf("%c ",grid[a/2][b/2]);
            }
        }
        if(a==0) printf(".\n");
        else if(a==40) printf(".\n");
        else if(a%2==0) printf(".\n");
        else printf(".\n");
    }
    
    printf("\n\n");
}

// USE THIS SPACE TO WRITE YOUR FUNCTIONS

struct Coordinates {
    int x;
    int y;
};

void addHospital()
{
    int count, a, b;
    printf("How many hospitals do you want to add : ");
    scanf("%d", &count);
    srand((unsigned)time(NULL));
    
    for (int i=0; i<count; i++) {
        a = rand() % 20;
        b = rand() % 20;
    
        grid[a][b] = 72;
        
        //printf("Added a Hospital to [%d,%d]\n", a, b);
    }
    
    printf("Addition Completed\n");
};

void addPolice() {
    int count, a, b;
    printf("How many police stations do you want to add : ");
    scanf("%d", &count);
    srand((unsigned)time(NULL));
    
    for (int i=0; i<count; i++) {
        a = rand() % 20;
        b = rand() % 20;
        
        grid[a][b] = 80;
        
        //printf("Added a Police station to [%d,%d]\n", a, b);
    }
    
    printf("Addition Completed\n");
};

struct Coordinates findHospital(int x, int y, int extra) {
    int nx, ny;
    float d, min = 999.0;
    struct Coordinates r = { x, y };
    
    for (int i = 0; i<20; i++)
    {
        for (int j = 0; j<20; j++)
        {
            // printf("[%d,%d] %c\n", j, i, grid[j][i]);
            // grid[x][y] = "0";
            if (grid[j][i] == 72 && grid[j][i] != grid[x][y])
            {
                d = sqrtf(pow((j-x), 2) + pow((i-y),2));
                // printf("[%d, %d] = %.2f\n", j, i, d);
                if (d < min)
                {
                    min = d;
                    nx = j;
                    ny = i;
                }
            }
        }
    }

    if (!nx && !ny) {
        printf("There isnt any hospitals in the map");
    } else {
        r.x = nx;
        r.y = ny;
        printf("\nNearest hospital : <%d,%d>", nx, ny);
        if (extra) { printf("\nDistance : %.2f", min); }
    }
    printf("\n");
    return r;
};

struct Coordinates findPolice(int x, int y, int extra) {
    int nx, ny;
    float d, min = 999.0;
    struct Coordinates r = { x, y };
    
    for (int i = 0; i<20; i++)
    {
        for (int j = 0; j<20; j++)
        {
            // printf("[%d,%d] %c\n", j, i, grid[j][i]);
            // grid[x][y] = "0";
            if (grid[j][i] == 80 && grid[j][i] != grid[x][y])
            {
                d = sqrtf(pow((j-x), 2) + pow((i-y),2));
                // printf("[%d, %d] = %.2f\n", j, i, d);
                if (d < min)
                {
                    min = d;
                    nx = j;
                    ny = i;
                }
            }
        }
    }
    
    if (!nx && !ny) {
        printf("There isnt any police stations in the map");
    } else {
        r.x = nx;
        r.y = ny;
        printf("\nNearest police station : <%d,%d>", nx, ny);
        if (extra) { printf("\nDistance : %.2f", min); }
    }
    printf("\n");
    return r;
};

void findBoth() {
    int hx, hy;
    struct Coordinates r;
    
    printf("Where are you? Enter the coordinates : ");
    scanf("%d %d", &hx, &hy);
    
    r = findHospital(hx, hy, 0);
    findPolice(r.x, r.y, 0);
};

void showMap() {};

void someFunc()
{
    int choice, x, y;
    printf("\n");
    printf("Welcome to Information Desk\n");
    printf("1. Add hospitals(s) \n");
    printf("2. Add police stations(s) \n");
    printf("3. Find nearest hospital \n");
    printf("4. Find nearest police \n");
    printf("5. Find nearest hospital then police \n");
    printf("6. Show the current map \n");
    printf("0. Exit \n \n");
    printf("Select an option : ");
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            printf("\nThanks. Come back again!!!\n");
            exit(0);
            break;
        case 1:
            addHospital();
            break;
        case 2:
            addPolice();
            break;
        case 3:
            printf("Where are you? Enter the coordinates : ");
            scanf("%d %d", &x, &y);
            findHospital(x, y, 1);
            break;
        case 4:
            printf("Where are you? Enter the coordinates : ");
            scanf("%d %d", &x, &y);
            findPolice(x, y, 1);
            break;
        case 5:
            findBoth();
            break;
        case 6:
            printGrid();
            break;
        default:
            printf("\n---------------------");
            printf("\nSorry Wrong option!!!");
            printf("\n---------------------\n");
             break;
    }

}

int main()
{
    int a,b;
    
    for(a=0; a<20; a++)
        for(b=0; b<20; b++)
            grid[a][b] = ' ';
    
    //printGrid();	// Remove this line after testing the program whether it is working or not
    
    while(1>0) {
        someFunc();
    }
    
    return 0;
}


