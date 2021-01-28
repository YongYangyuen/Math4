#include <stdio.h>
#define M 3
#define N 4

void get_equation(int equation[M][N]);
int compute_det(int equation[M][N]);
void compute_cramer(int equation[M][N], int det);
void re_tmp(int equation_tmp[M][N] ,int equation[M][N]);

int main() {
	int equation[M][N], det;
	
	get_equation(equation);
	det = compute_det(equation);
	printf("=======================================\n");
	printf("(a): Determinant = %d\n", det);
	printf("=======================================\n");
	compute_cramer(equation, det);
	
	return 0;
}

void get_equation(int equation[M][N]) {
	int i, j;
	
	printf("eq: _x1 _x2 _x3 = _\n");
	printf("=======================================\n");
	
	for(i = 0; i < M; i++) {
		printf("eq%d:  ", i + 1);
		for(j = 0; j < N; j++) {
			scanf("%d", &equation[i][j]);
		}
	}	
}

int compute_det(int matrix[M][N]) {
	int i, j;
	int det;
	
	det = matrix[0][0] * ( (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]) )
		- matrix[0][1] * ( (matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]) )
		+ matrix[0][2] * ( (matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]) );
	
	return det;
}

void re_tmp( int equation_tmp[M][N], int equation[M][N]) {
	int i, j;
	
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			equation_tmp[i][j] = equation[i][j];
		}
	}	
}

void compute_cramer(int equation[M][N], int det) {	
	int x1, x2, x3;
	int equation_tmp[M][N];
	re_tmp(equation_tmp, equation);

	equation_tmp[0][0] = equation[0][3];
	equation_tmp[1][0] = equation[1][3];
	equation_tmp[2][0] = equation[2][3];
	x1 = compute_det(equation_tmp) / det;
	printf("(b): x1 = %d / %d = %d\n", compute_det(equation_tmp), det, x1);
	re_tmp(equation_tmp, equation);
	
	equation_tmp[0][1] = equation[0][3];
	equation_tmp[1][1] = equation[1][3];
	equation_tmp[2][1] = equation[2][3];
	x2 = compute_det(equation_tmp) / det;
	printf("     x2 = %d / %d = %d\n", compute_det(equation_tmp), det, x2);
	re_tmp(equation_tmp, equation);
	
	equation_tmp[0][2] = equation[0][3];
	equation_tmp[1][2] = equation[1][3];
	equation_tmp[2][2] = equation[2][3];
	x3 = compute_det(equation_tmp) / det;
	printf("     x3 = %d / %d = %d\n", compute_det(equation_tmp), det, x3);
	re_tmp(equation_tmp, equation);
	
	printf("=======================================\n");
	printf("(c): RESULT = (x1, x2, x3) = (%d, %d, %d)", x1, x2, x3);
}
