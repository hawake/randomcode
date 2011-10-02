/**
 * Author: hawake
 * This code simply makes an approximation of the root
 * of the equation: f(x) = e^x + (c/x)(e^x - 1) - d
 *
 * Released under the term of the GNU General Public License version 3
 */

#include <stdio.h>
#include <math.h>
#define c 0.435
#define d 1.564

double funzione ( double x );

int main() {
	// intervall
	double a  = 0.05;
	double b  = 0.15;

	// succession
	double xn = (a + b) / 2;
	double xv;

	// errors
	double err1 = 10;
	double err2 = 10;
	
	// counters
	int iter = 0;
	int i    = 1;

	printf("\n\n%4s | %7s  | %7s  | %8s | %8s | %7s\n", "iter","a","b","xn","err1","err2"); // output

	for (i; i>0, i<=10; i++) {
		if ( funzione( a ) * funzione( xn ) < 0)
			b = xn;
		else if (funzione( xn ) * funzione( b ) < 0 )
			a = xn;

		xv = xn;
		xn = ( a + b ) / 2;
		
		iter++;
		
		err1 = fabs( xn - xv );
		err2 = fabs( funzione( xn ) );

		printf("%4d | %7lf | %7lf | %7lf | %7lf | %7lf \n", iter, a, b, xn, err1, err2);
	}

	printf("\n\n");

	return 0;
}

// Function of the function :P
double funzione(double x) {
	double f;
	
	f = exp( x ) + ( c / x ) * ( exp( x ) - 1 ) - d;

	return f;
}
