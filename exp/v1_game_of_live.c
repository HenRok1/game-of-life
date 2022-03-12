#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 25

void firstStep(int **M)
{
    int i, j;
    for (i = 0; i < N; i++)
        M[i][0] = M[i][N - 1] = 0;

    for (j = 1; j < N - 1; j++)
        M[0][j] = M[N - 1][j] = 0;

    for (i = 1; i < N - 1; i++)
        for (j = 1; j < N - 1; j++)
            M[i][j] = rand() % 2;
}

void showMatrix(int **M)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            if (M[i][j])
                printf("%c%c", 219, 219);
            else
                printf("%c%c", 176, 176);
        printf("\n");
    }
    printf("\n");
}

int cellDestiny(int **M, int i, int j)
{
    int neighbors = -M[i][j], k, m;
    for (k = i - 1; k <= i + 1; k++)
        for (m = j - 1; m <= j + 1; m++)
            neighbors += M[k][m];

    if (neighbors == 3 || (neighbors == 2 && M[i][j]))
        return 1;

    return 0;
}

void nextStep(int **M)
{
    int i, j;
    for (i = 1; i < N - 1; i++)
        for (j = 1; j < N - 1; j++)
            M[i][j] = cellDestiny(M, i, j);
}

int main()
{
    int count = 1, i;
    char c;
    srand((unsigned int)time(NULL));

    int **M = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
        M[i] = (int *)malloc(N * sizeof(int));

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    printf("Step %d\n", count++);
    firstStep(M);
    showMatrix(M);

    while ((c = getch()) != 27)
    {
        printf("Step %d\n", count++);
        nextStep(M);
        showMatrix(M);
    }

    return 0;
}
