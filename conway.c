#include <stdio.h> // классека
#include <stdlib.h> // выделить память 
#include <unistd.h> // 
 
#define for_x for (int x = 0; x < w; x++) // где и чем замещаем
#define for_y for (int y = 0; y < h; y++) // где и чем замещаем
#define for_xy for_x for_y 
void process(void *u, int w, int h)
{
	int (*univ)[w] = u;
	printf("\033[H");
	for_y {
		for_x printf(univ[y][x] ? "\033[07m  \033[m" : "  ");
		printf("\033[E");
	}
	fflush(stdout); // проталкиваем накопленную инфу в поток данных
}
 
void evolve(void *u, int w, int h)
{
	unsigned (*univ)[w] = u;
	unsigned new[h][w];
 
	for_y for_x {
		int n = 0;
		for (int y1 = y - 1; y1 <= y + 1; y1++)   // вертикальное перемещение
			for (int x1 = x - 1; x1 <= x + 1; x1++)  // горизонтальное перемещение
				if (univ[(y1 + h) % h][(x1 + w) % w])
					n++;
 
		if (univ[y][x]) n--;
		new[y][x] = (n == 3 || (n == 2 && univ[y][x]));
	}
	for_y for_x univ[y][x] = new[y][x];
}
 
void game_of_live(int w, int h)
{
	unsigned univ[h][w];
	for_xy univ[y][x] = rand() < RAND_MAX / 10 ? 1 : 0;
	while (1) {
		process(univ, w, h);
		evolve(univ, w, h);
		usleep(200000); // приостановка работы потока данных
	}
}
 
int main(int c, char **v) // указатель на указатель
{
	int w = 0, h = 0;
	if (c > 1) w = atoi(v[1]);
	if (c > 2) h = atoi(v[2]);
	if (w <= 0) w = 80;
	if (h <= 0) h = 25;
	game_of_live(w, h);
}