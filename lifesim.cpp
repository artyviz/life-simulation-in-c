//life simulation or game of life & Computer implementations of Lenia , The DFT/FFT approach automatically produces a periodic boundary condition. Efficient calculation can be achieved using fast Fourier transform


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>


// now i'm denoting (.)lowest level then (-=)gradually  increasing , (c)mid level  then (o)higher level then one of the highest level to the (#)highest level of the gradient intensity 
// Gradient intensity levels (from lowest to highest)

char level[] = " .-=coaA@#";

// char level[] = { ' ' , ' . ', ' - ', ' = ', ' c ', ' o ', ' a ' , ' A ' ,' @ ' , ' # ' }; 

#define WIDTH 100
#define HEIGHT 100

#define level_count (sizeof(level) / sizeof(level[0]) - 1)

//float alpha = 0.147;

float alpha_n = 0.028;
float alpha_m = 0.147;
float b1 = 0.278;
float b2 = 0.278;

float d1 = 0.267;	
float d2 = 0.445;
float dt = 0.05f;

float grid[HEIGHT][WIDTH] = { 0 };
float grid_diff[HEIGHT][WIDTH] = { 0 };


float rand_float(void)
{
	return (float)rand() / (float)RAND_MAX;
}

float RA = 11;

void random_grid(void)
{
	size_t w = WIDTH / 3;
	size_t h = HEIGHT / 3;
	for (size_t dy = 0; dy < h; ++dy) {
		for (size_t dx = 0; dx < w; ++dx) {
			size_t x = dx + WIDTH / 2 - w / 2;
			size_t y = dy + HEIGHT / 2 - h / 2;
			grid[y][x] = rand_float();
		}
	}
}


//void display_grid(void) 
//{
	//for (size_t y = 0; y < HEIGHT; ++y)
	//{
		//for (size_t x = 0; x < WIDTH; ++x)
		//{
			//char c = level[(int)(grid[y][x] * (level_count - 1))];
			//grid[y][x];
			//printf("%c", c);
		//}
		//printf("\n");
//	}

//}

void display_grid(float grid[HEIGHT][WIDTH])
{
	for (size_t y = 0; y < HEIGHT; ++y) {
		for (size_t x = 0; x < WIDTH; ++x) {
			char c = level[(int)(grid[y][x] * (level_count - 1))];
			fputc(c, stdout);
			fputc(c, stdout);
		}
		fputc('\n', stdout);
	}
}

int emod(int a, int b)
{
	return (a % b + b) % b;
}


//float sigma1(float x, float a) {return 1.0/(1.0 + expf(-(x - a) * 4 / alpha));}
//float sigma2(float x, float a, float b){return sigma1(x, a)* (1 - sigma1(x, b));}
//float sigmam(float x, float y, float m){return x * (1 - sigma1(m, 0.5f)) + y * sigma1(m, 0.5f);}

float sigma(float x, float a, float alpha)
{
	return 1.0f / (1.0f + expf(-(x - a) * 4 / alpha));
}

float sigman(float x, float a, float b)
{
	return sigma(x, a, alpha_n) * (1 - sigma(x, b, alpha_n));
}

float sigmam(float x, float y, float m)
{
	return x * (1 - sigma(m, 0.5f, alpha_m)) + y * sigma(m, 0.5f, alpha_m);
}

float s(float n, float m)
{
	return sigman(n, sigmam(b1, d1, m), sigmam(b2, d2, m));
}

void compute_grid_diff(void)
{
	for (int cy = 0; cy < HEIGHT; ++cy) {
		for (int cx = 0; cx < WIDTH; ++cx) {
			float m = 0, M = 0;
			float n = 0, N = 0;
			float ri = RA / 3;
			//if (sqrtf(dx * dx + dy * dy) < ri) m += grid grid[y][x]{}
			for (int dy = -(RA - 1); dy <= (RA - 1); ++dy) {
				for (int dx = -(RA - 1); dx <= (RA - 1); ++dx) {
					int x = emod(cx + dx, WIDTH);
					int y = emod(cy + dy, HEIGHT);
					if (dx * dx + dy * dy <= ri * ri) {
						m += grid[y][x];
						M += 1;
					}

					//if (sqrtf(dx * dx + dy * dy) < ri) m += grid grid[y][x];
					//else if (dx * dx + dy * dy <= ra * ra)n += grid[y][x];
					else if (dx * dx + dy * dy <= RA * RA) {
						n += grid[y][x];
						N += 1;
					}
				}
			}
			m /= M;
			n /= N;
			float q = s(n, m);
			grid_diff[cy][cx] = 2 * q - 1;
		}
	}
}
	

void clamp(float* x, float l, float h)
{
	if (*x < l) *x = l;
	if (*x > h) *x = h;
}

void apply_grid_diff(void)
{
	for (size_t y = 0; y < HEIGHT; ++y) {
		for (size_t x = 0; x < WIDTH; ++x) {
			grid[y][x] += dt * grid_diff[y][x];
			clamp(&grid[y][x], 0, 1);
		}
	}
}


int main(void)
{
	//printf("level_count = %zu\n", level_count);

	srand(time(0)); //every second i'm changing the time seeds here for better generation
	random_grid();
	display_grid(grid);
	for (;;) {
		compute_grid_diff();
		apply_grid_diff();
		display_grid(grid);
	
	}


	//MATH STUFF TO CHECK THE RESULTS 
	//size_t cx = 0;
	//size_t cy = 0;
	//float m = 0;
	//float n = 0;
	//float M = 0;
	//float N = 0;
	//float ri = RA / 3.0f;

	// ra = 3
	//m /= M;
	//n /= N;

	//printf("s(n,m)m = %f, n = %f, M\n", m, n , M , N );

	
	
	

	return 0;

}

