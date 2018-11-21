#include<stdio.h>

int i=0, j=0,kl,rn;

determinant(int *mtr,int m,int n) {
	int rez = 0;
	if (m == 1) printf("\nDeterminant=%d\n", mtr[0*n + 0]);
	else if (m ==2) {
		int u1, u2;
		u1 = u2= 1;
		for (i = 0;i < 2;i++) {
			for (j = 0;j < 2;j++) {
				if ((i == 0 && j == 0) || (i == 1 && j == 1)) u1 = u1 * mtr[i * 2 + j];
				if ((i == 0 && j == 1) || (i == 1 && j == 0)) u2 = u2 * mtr[i * 2 + j];
			}
		}
		printf("\nDeterminant=%d\n", u1-u2);
		if (u1 - u2 != 0) rn = 2;
		else rn = 1;
	}
	else if (m==3) {
		int u1, u2, u3, u4, u5, u6;
		u1 = u2 = u3 = u4 = u5 = u6 = 1;
		for (i = 0;i < 3;i++) {
			for (j = 0;j < 3;j++) {
				if ((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 2)) u1 = u1 * mtr[i *3 + j];
				if ((i == 0 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 0)) u2 = u2 * mtr[i *3 + j];
				if ((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 2)) u3 = u3 * mtr[i * 3 + j];
				if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) u4 = u4 * mtr[i * 3 + j];
				if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 2 && j == 2)) u5 = u5 * mtr[i *3 + j];
				if ((i == 0 && j == 0) || (i == 2 && j == 1) || (i == 1 && j == 2)) u6 = u6 * mtr[i * 3 + j];
			}
		}
		if (rez != 0) rn = 3;
		else rn = 1;
		rez = u1 + u2 + u3 - u4 - u5 - u6;
		printf("\nDeterminant=%d\n", rez);
	}
	else if (m == 4) {
		int yy = 1,w=0;
		if (mtr[0*4+0]==1)
		{ /* 
			for (i = 1,j = 0;i < 4;i++) {
				w = mtr[0 * 4 + 0] *(-1)*mtr[i * 4 + 0];printf("%d\n", w);
				for (;j < 4;j++) {
					mtr[i * 4 + j] = w + mtr[i * 4 + j];
					printf("%d\t", i, j, mtr[i * 4 + j]);
				}printf("\n");
			}
		 			*/ 
		}
	}
	return rn;
}

find(int *mtr, int m, int n) {
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
					if (mtr[i*n + j] < min) min = mtr[i*n + j];
					if (mtr[i*n + j] >max) max = mtr[i*n + j];
				}
			}
			printf("\nMaximum = %d\n Minimum = %d\n", max, min);
			break;
		case '2':
			min = 0xFFFF, max = 0;
			for (i = m-1;i >=0;i++) {
				for (j = n - 1;j >= 0;j--) {
					if (mtr[i*n + j] < min) min = mtr[i*n + j];
					if (mtr[i*n + j] > max) max = mtr[i*n + j];
				}
			}
			printf("\nMaximum = %d\n Minimum = %d\n", max, min);
			break;
		case '3':
			min = 0xFFFF, max = 0;
			for (i = 0;i <m ;i++) {
				for (j =0;j<n;j--) {
					if (mtr[i*n + j] < min) min = mtr[i*n + j];
					if (mtr[i*n + j] > max) max = mtr[i*n + j];
				}
			}
			printf("\nMaximum = %d\n Minimum = %d\n", max, min);
			break;
		case '4': goto m1;
			break;
		}
	m1:return 0;
 }

show(int *mtr, int m, int n) {
	printf("\n\tMatrix\t\n");
	for (i = 0;i < m;i++) {
		for (j = 0;j <n ;j--) {
			printf("%d\t", mtr[i*n + j]);
		}
		printf("\n");
	}

}

main() {
	int m, n,*mtr,x;
	printf("Write the size of the matrix mxn\nm: ");
	scanf_s("%d", &m);
	kl = m;
	printf("n: ");
	scanf_s("%d", &n);
	mtr = (int*)malloc((n+1)*(m+1)* sizeof(int));
	if (m = n) {
		printf("Enter matrix values\n");
		for (i = 0;i < m;i++) {

			for (j = 0;j < n;j++) {
				
				printf("m[%d][%d]= ", i, j);
				scanf_s("%d", &mtr[i*n + j]);
				

			}printf("\n");
		}
		printf("1. Calculate determinant\n2. Matrix rank \n3. Find the maximum and minimum value\n4. Show matrix \n5. To clear \n6. Exit\nChoose action: ");
		scanf_s("%d", &x);
		for (int nm = 1;nm > 0;nm++) {
			switch (x) {
			case 1: determinant(mtr, m, n);
				break;
			case 2: printf("Matrix rank= %d\n", determinant(mtr, m, n));
				break;
			case 3: find(mtr, m, n);
				break;
			case 4: show(mtr, m, n);
				break;
			case 5: system("cls");
				break;
			case 6: goto M3;
				break;
			}
			printf("1. Calculate determinant\n2. Matrix rank \n3. Find the maximum and minimum value\n4. Show matrix \n5. To clear \n6. Exit\nChoose action: ");
			scanf_s("%d", &x);
		}
	M3:;
	}
	else {

	}
	system("pause");
	return 0;
}