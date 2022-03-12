#include <stdio.h>
#include <stdlib.h>

#define size_h 25
#define size_l 80

int size = 20;

int count_nbr(int grid[size][size], int i, int j, int size);

void draw();

//void auto_draw(int grid[size][size]);


int main(void)
{
    int grid[20][20] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int neighbour_count[size][size];
    int i, j, steps;
    for (steps = 0; steps < 30; ++steps)
    {
        system("clear");
        for (i = 0; i < size; ++i)
        {
            draw();
            printf("\n\n");

            for (j = 0; j < size; ++j)
            {
                if (grid[i][j] == 1)
                    printf("\t*");
                else
                    printf("\t");
                neighbour_count[i][j] = count_nbr(grid, i, j, size);
            }
        }

        for (i = 0; i < size; ++i)
        {
            for (j = 0; j < size; ++j)
            {
                if (grid[i][j] >= 1)
                {
                if (neighbour_count[i][j] <= 1 || neighbour_count[i][j] >= 4)
                    grid[i][j] = 0;
                }
                else
                    if (neighbour_count[i][j] == 3)
                    grid[i][j] = 1;
            }
        }

        printf("\n\n");
        system("sleep 1.5");
    }
    return 0;
}
// void auto_draw(int grid[size][size]) {
//     draw(grid);
//     auto_draw(grid);
//     system("sleep 1.5");
// }


int count_nbr(int grid[size][size], int i, int j, int size)
{
    int n_count = 0;
    if (i - 1 >= 0 && j - 1 >= 0)
    {
        if (grid[i - 1][j - 1] >= 1)
            n_count++;
    }

    if (i - 1 >= 0)
    {
        if (grid[i - 1][j] >= 1)
            n_count++;
    }

    if (i - 1 >= 0 && j + 1 < size)
    {
        if (grid[i - 1][j + 1] >= 1)
            n_count++;
    }

    if (j - 1 >= 0)
    {
        if (grid[i][j - 1] >= 1)
            n_count++;
    }

    if (j + 1 < size)
    {
        if (grid[i][j + 1] >= 1)
            n_count++;
    }

    if (i + 1 < size && j - 1 >= 0)
    {
        if (grid[i + 1][j - 1] >= 1)
            n_count++;
    }

    if (i + 1 < size)
    {
        if (grid[i + 1][j] >= 1)
            n_count++;
    }

    if (i + 1 < size && j + 1 < size)
    {
        if (grid[i + 1][j + 1] >= 1)
            n_count++;
    }

    return n_count;
}

void draw() {
for(int i = 1; i < size; i++) {
    for (int j = 1; j < size; j++) {
        if(i == 1 || i == size - 1 || j == size - 1 || j == 1) {
            printf("*");
        }
    }
    printf("\n");
}
}

