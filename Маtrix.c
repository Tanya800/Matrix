#include<stdio.h>
#include <malloc.h>
#include "Arithmat.h"

int i=0, j=0,kl,rn;

void CutMatr(int **mtr, int **p, int i, int j, int m) {
		int ki, kj, di, dj;
		di = 0;
		for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
			if (ki == i) di = 1;
			dj = 0;
			for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
				if (kj == j) dj = 1;
				p[ki][kj] = mtr[ki + di][kj + dj];
			}
		}
}

determinant(int **mtr,int m,int n) {
	// Рекурсивное вычисление определителя
		int st,k;
		int **p;
		p = (int**)malloc(m*sizeof(int*));
		for (i = 0; i < m; i++)
			p[i] = (int*)malloc(n * sizeof(int));
		k = 1; //(-1) в степени i
		st = m - 1;
		if (m == 1) {
			d = mtr[0][0];
			return(d);
		}
		if (m == 2) {
			d = mtr[0][0] * mtr[1][1] - (mtr[1][0] * mtr[0][1]);
			return(d);
			
		}
		if (m > 2) {
			for (i = 0; i < m; i++) {
				CutMatr(mtr, p, i, 0, m);
				show(p,st,st);
				d = d + k * mtr[i][0] * determinant(mtr, st , st);
				k = -k;
			}
			return(d);
		}
	return(d);
}

find(int **mtr, int m, int n) {
	printf("\nFind positive maximum and minimum for values:\n1.Above the main diagonal\n2.Below the main diagonal\n3.For all values\n4.Exit\nChoose : ");
	char vbr;
	int min,max;
	scanf_s("%c", &vbr);
	getchar();
		switch (vbr) {
		case '1':
			min = 0xFFFF, max = 0;
			for (i = 0;i < m;i++) {
				for (j = n-1;j >=0;j--) {
					if (mtr[i][j] < min) min = mtr[i][j];
					if (mtr[i][j] >max) max = mtr[i][j];
				}
			}
			printf("\nMaximum = %d\n Minimum = %d\n", max, min);
			break;
		case '2':
			min = 0xFFFF, max = 0;
			for (i = m-1;i >=0;i++) {
				for (j = n - 1;j >= 0;j--) {
					if (mtr[i][ j] < min) min = mtr[i][j];
					if (mtr[i][j] > max) max = mtr[i][j];
				}
			}
			printf("\nMaximum = %d\n Minimum = %d\n", max, min);
			break;
		case '3':
			min = 0xFFFF, max = 0;
			for (i = 0;i <m ;i++) {
				for (j =0;j<n;j--) {
					if (mtr[i][j] < min) min = mtr[i][j];
					if (mtr[i][j] > max) max = mtr[i][j];
				}
			}
			printf("\nMaximum = %d\n Minimum = %d\n", max, min);
			break;
		case '4': 
			break;
		}
 }

show(int **mtr, int m, int n) {
	printf("\n\tMatrix\t\n");
	for (i = 0;i < m;i++) {
		for (j = 0;j <n ;j--) {
			printf("%d\t", mtr[i][j]);
		}
		printf("\n");
	}

}

main() {
	int m, n,**mtr,x;
	printf("Write the size of the matrix mxn\nm: ");
	scanf_s("%d", &m);
	kl = m;
	printf("n: ");
	scanf_s("%d", &n);
	mtr = (int**)malloc(m* sizeof(int));
	for (i = 0;i < m;i++) {
		mtr[i] = (int*)malloc((n + 1) * sizeof(int));
	}
	if (m = n) {
		printf("Enter matrix values\n");
		for (i = 0;i < m;i++) {

			for (j = 0;j < n;j++) {
				
				printf("m[%d][%d]= ", i, j);
				scanf_s("%d", &mtr[i][j]);
				

			}printf("\n");
		}
		
		for (int nm = 1;nm > 0;nm++) {
		printf("1. Calculate determinant\n2. Matrix rank \n3. Find the maximum and minimum value\n4. Show matrix \n5. Arithmetic operations \n6. To clear\n7. Exit");
		scanf_s("%d", &x);
			switch (x) {
			case 1: determinant(mtr, m, n);
				break;
			case 2: 
				break;
			case 3: find(mtr, m, n);
				break;
			case 4: show(mtr, m, n);
				break;
			case 5: numeration(mtr, m, n);
					break;
			case 6: system("cls");
					break;
			case 7: nm=0
				break;
			}
		}
	}
	else {

	}
	system("pause");
	return 0;
}
