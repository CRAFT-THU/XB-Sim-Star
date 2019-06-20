#ifndef _CROSSBAR_CUDA_H
#define _CROSSBAR_CUDA_H
#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <curand.h>
#include <time.h>
#include <math.h>
#include "config.h"


typedef struct Crossbar
{
	float *CB_cell;
	float *std_d;
	float *input;
	float *output;
	int CB_n;
	int CB_l;
	int CB_w;
    curandGenerator_t gen;

    // for big crossbar
    Crossbar();
    ~Crossbar();
    Crossbar(int n, int l, int w);
    void init();
    void run();
	
	void init(float *CB_cells, int n, int l, int w);

	void printcrossbar();

	void get_std();//-0.0006034 * (x * 1e3) ** 2 + 0.06184 * x + 0.7240 * 1e-6

	void get_noise(float *noise);

    void printstd();

    void run(float *input, float *output, bool use_noise=true);

	void free_space();
}CROSSBAR;

extern CROSSBAR entire_cb;
#endif //_CROSSBAR_CUDA_H
