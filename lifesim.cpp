//life simulation or game of life & Computer implementations of Lenia , The DFT/FFT approach automatically produces a periodic boundary condition. Efficient calculation can be achieved using fast Fourier transform

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>


// now i'm denoting (.)lowest level then (-=)gradually  increasing , (c)mid level  then (o)higher level then one of the highest level to the (#)highest level of the gradient intensity 
// Gradient intensity levels (from lowest to highest)
char level[] = " .-=coaA@#";

 // char level[] = { ' ' , ' . ', ' - ', ' = ', ' c ', ' o ', ' a ' , ' A ' ,' @ ' , ' # ' }; 

#define WIDTH 100
#define HEIGHT 100

#define level_count (sizeof(level) / sizeof(level[0]) - 1)

#define ra = =21;

float grid[WIDTH][HEIGHT] = { 0 };

float rand_float(void)
{
	return (float)rand() / (float)RAND_MAX;
}

void random_grid(void) 
{
	for (size_t y = 0; y < HEIGHT; ++y)
	{
		for (size_t x = 0; x < WIDTH; ++x)
		{
			grid[y][x] = rand_float();
		}
	}
}

void display_grid(void) 
{
	for (size_t y = 0; y < HEIGHT; ++y)
	{
		for (size_t x = 0; x < WIDTH; ++x)
		{
			char c = level[(int)(grid[y][x] * (level_count - 1))];
			grid[y][x];
			printf("%c", c);
		}
		printf("\n");
	}

}

int emod(int a, int b)
{
	return (a % b + b) % b;
}


int main(void)
{
	//printf("level_count = %zu\n", level_count);

	srand(time(0)); //every second i'm changing the time seeds here for better generation
	random_grid();
	
	size_t cx = 0;
	size_t cy = 0;
	float m = 0;
	float n = 0;
	float ri = ra / 3;


	// ra = 21
	for (int dy = -(ra - 1); dy <= (ra - 1); ++dy)
	{
		for (int dx = -(ra - 1); dx <= (ra - 1); ++dx)
		{
			int x = emod(cx + dx , WIDTH);
			int y = emod(cy + dy, HEIGHT);
			grid[y][x];
		}
	}
	display_grid();
	
	

	return 0;

}

