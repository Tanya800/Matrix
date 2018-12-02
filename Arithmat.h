#ifndef _ARITHMAT_H
#define _ARITHMAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int **d, **p;
int a, b;



int addition(int **d, int **p,int a,int b) {
	printf("\nResult:\n");
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < b;j++) {
			d[i][j] = d[i][j] + p[i][j];
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}

}

int subtraction(int **d, int **p, int a, int b) {
	printf("\nResult:\n");
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < b;j++) {
			d[i][j] = d[i][j] - p[i][j];
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}

}


int multiplication(int **d, int a, int b, int k) {
	printf("\nResult:\n");
	for (int i = 0;i < a;i++) {
		for (int j = 0;j < b;j++) {
			d[i][j] = d[i][j] *k;
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
}


#endif
