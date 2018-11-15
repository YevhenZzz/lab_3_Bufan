#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define SIZE 5

void findSeredne(int mas[SIZE]){
	double Dobutok = mas[0];


	for (int row= 1; row < SIZE; ++row){
		Dobutok *= mas[row];
	}
	printf("\n Dobutok Sum: %f", Dobutok);

	printf("\n Seredn'e: %lf", pow(fabs(Dobutok), 1.0 / SIZE));


}

void sortChoice(int mas[SIZE][SIZE]){
	float tmp;
	int pos;
	const int n = SIZE, k = SIZE;
	

	for (int col = 0; col < k; ++col){
		for (int row = 0; row < n; ++row)
		{
			pos = row;
			tmp = mas[row][col];
			for (int h = row + 1; h < SIZE; ++h) 
			{
				if (mas[h][col] < tmp)
				{
					pos = h;
					tmp = mas[h][col];
				}
			}
			mas[pos][col] = mas[row][col];
			mas[row][col] = tmp; 
		}
	}
	for (int row = 0; row<SIZE; ++row){
		printf("\n");
		for (int col = 0; col<SIZE; ++col){
			printf("%d\t", mas[row][col]);
		}
	}

	printf("\nSums of sorted matrix:\n");
	int SUM;
	for (int row = 0; row < SIZE; ++row){
		SUM = 0;
		for (int col = 0; col < SIZE; ++col){
			SUM += mas[row][col];

		}
		printf("\nSum of %d th row=\n%d\n", row + 1, SUM);


	}
}



int main(){

	int mas[SIZE][SIZE];
	for (int row = 0; row < SIZE; ++row){
		for (int col = 0; col < SIZE; ++col){
			scanf("%d", &mas[row][col]);
		}
	}


	printf("Your matrix:\n");

	for (int row = 0; row < SIZE; ++row){
		printf("\n");
		for (int col = 0; col < SIZE; ++col){
			printf("%d\t", mas[row][col]);
		}
	}



	int MasOfSums[SIZE];
	for (int row = 0; row < SIZE; ++row){
		int SUM = 0;
		for (int col = 0; col < SIZE; ++col){
			SUM += mas[row][col];

		}
		MasOfSums[row] = SUM;

	}
	findSeredne(MasOfSums);

	printf("\nSorted array:\n");

	sortChoice(mas);


	getchar();
	getchar();
	return 0;
}