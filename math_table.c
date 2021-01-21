#include <stdio.h>
#include <math.h>

double calc_xr(double xl, double xu);
double calc_err(double xl, double xu);
double calc_fx(double x);
double calc_fxu(double x);
double calc_fxr(double x);
void print_table(double xl, double xu);

int main() {
	double xl = 0.5, xu = 2;
	
	printf("=====================================================================================================================\n");
	printf("Iteration       xl           f(x)             xu             f(xu)            xr             f(xr)           err\n");
	printf("=====================================================================================================================\n");
	print_table(xl, xu);
	printf("=====================================================================================================================\n");
	
	return 0;
}

double calc_xr(double xl, double xu) {
	return (xl + xu) / 2.0;
}

double calc_err(double xl, double xu) {
	return ( (xu - xl) / (xu + xl) ) * 100.0;
}

double calc_fx(double x) {
	return log(pow(x, 2)) - 0.7;
}

double calc_fxu(double xu) {
	return log(pow(xu, 2)) - 0.7;
}

double calc_fxr(double xr) {
	return log(pow(xr, 2)) - 0.7;
}

void print_table(double xl, double xu) {
	int i = 1;
	double fx = calc_fx(xl);
	double fxu = calc_fxu(xu);
	double xr = calc_xr(xl, xu);
	double fxr = calc_fxr(xr);
	double err = calc_err(xl, xu);
	
	do {
		if(i != 1) {
			if(fxr < 0) xl = xr;
			if(fxr >= 0) xu = xr;
		}
		
		fx = calc_fx(xl);
		fxu = calc_fxu(xu);
		xr = calc_xr(xl, xu);
		fxr = calc_fxr(xr);
		err = calc_err(xl, xu);
		
		printf("%10d %10lf \t %10lf \t %10lf \t %10lf \t %10lf \t %10lf \t %10lf\n", i, xl, fx, xu, fxu, xr, fxr, err);
		i++;
	} while(err >= 1);
}
