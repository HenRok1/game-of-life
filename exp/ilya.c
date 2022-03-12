#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define for_x for (int x = 0; x < w; x++)
#define for_y for (int y = 0; y < h; y++)
#define for_xy for_x for_y

int size_height = 20;
int size_width = 20;

void draw(int size_height, int size_width);
void game_of_live(int w, int h);
void process(void *u, int w, int h);
void evolve (void *u, int w, int h);

int count_nbr(int grid[size_height][size_width], int i, int j, int size_height, int size_width);



int main(int c, char **v){
	draw(80, 25);
	int grid[20][20] = {
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                    };

	int nbr_count[size_height][size_width];

	
	for (int steps = 0; steps < 30; steps++){
		system("cls"); //на mac "clear"
		for (int i = 0; i < size_width; i++) {
			printf("\n\n");
			for (int j = 0; j < size_height; j++) {
				if (grid[i][j] == 1) {
					printf("\t**");
				} else {
					printf("\t");
				}
				nbr_count[i][j] = count_nbr(grid, i, j, size_height, size_width);
			}
		}

		for (int i = 0; i < size_height; i++) {
			for (int j = 0; j < size_width; j++) {
				if (grid[i][j] >= 1) {
					if (nbr_count[i][j] <= 1 || nbr_count[i][j] >= 4) {
						grid[i][j] = 0;
						}
					} else {
						if (nbr_count[i][j] == 3) 
						grid[i][j] = 1;
				}


			}
		}
	    printf("\n\n");
		usleep(20000);
	}

	return 0;
}

int count_nbr(int grid[size_height][size_width], int i, int j, int size_height, int size_width) {
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

    if (i - 1 >= 0 && j + 1 < size_width)
    {
        if (grid[i - 1][j + 1] >= 1)
            n_count++;
    }

    if (j - 1 >= 0)
    {
        if (grid[i][j - 1] >= 1)
            n_count++;
    }

    if (j + 1 < size_width)
    {
        if (grid[i][j + 1] >= 1)
            n_count++;
    }

    if (i + 1 < size_height && j - 1 >= 0)
    {
        if (grid[i + 1][j - 1] >= 1)
            n_count++;
    }

    if (i + 1 < size_height)
    {
        if (grid[i + 1][j] >= 1)
            n_count++;
    }

    if (i + 1 < size_height && j + 1 < size_width)
    {
        if (grid[i + 1][j + 1] >= 1)
            n_count++;
    }

    return n_count;
}


void draw(int size_height, int size_width)
{
    for (int y = 0; y < size_width; y++)
    {
        for (int x = 0; x < size_height; x++)
        {
            if (y == 0 || y == size_width - 1)
                printf("#");
            else if (x == 0 || x == size_height - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}