/**
 * Author: hawake
 * This little code calculates the wavelenght of a Tsunami
 * through the following non-linear equation:
 * f(L) = L - [( g * T^2 )/( 2 * pi )] * tanh[ ( 2*pi*d )/L]
 *
 * It is just a test, i have to verify the results.
 *
 * This code is released under the terms of the GNU
 * General Public License version 3
 */

#include <stdio.h>
#include <math.h>
#define pi 3.1415

void welcome () ;
double funzione ( double L , double agf , double Tf , double df );
double tanh ( double x );

int main() {
	// iterations
	int iter = 0;
	int n_iter  ;

	// counter
	int i = 1;
	
	// errors and precision
	double err1 = 10;
	double err2 = 10;
	double eps  = 0 ;

	// data
	double T  ;       // period of the wave
	double d  ;       // depth
	double ag = 9.81; // gravity acceleration

	// extremes of the interval where we have to find the root
	double a , b;

	double xn , xv;

	welcome();

	// i ask for data like period and depth
	printf( "Insert the period, T = " );
	scanf( "%lf",&T );
	printf( "Insert the depth of water, d = " );
	scanf( "%lf", &d );

	// i ask for interval extremes
	printf( "Insert the infimum of the interval, a = " );
	scanf( "%lf",&a );
	printf( "Insert the maximum of the interval, b = " );
	scanf( "%lf", &b );

	xn = (a + b) / 2;

	printf( "Insert the precision of the solution, eps = " );
	scanf( "%lf" , &eps );

	if (eps == 0) {
		// if the user doesn't ask for the precision
		// i ask for the maximum number of iterations
		printf( "Insert the number of maximum iterations, n_iter = " );
		scanf( "%lf" , &n_iter );

		if (n_iter == NULL) {
			// if the user doesn't specify a number, i setup it to 30
			n_iter = 30;
		}
	} else {
		// ...else i calculate the number of iterations needed if the user specify eps
		n_iter = ceil( ( log(b-a)-log(eps) )/log(2) );
	}

	printf( "\n%4s | %14s | %14s | %14s | %14s | %14s\n" , "iter" , "a" , "b" , "xn" , "err1" , "err2" );
	// now i find the solution with a fixed number of iteration
	for ( i ; i <= n_iter ; i++ ) {
		if ( funzione(a , ag , T , d) * funzione(xn , ag , T , d))
			b = xn;
		else if ( funzione(xn , ag , T , d) * funzione( b , ag , T , d) )
			a = xn;
		xv = xn;
		xn = (a + b)/2;
		iter = i;
		err1 = abs( xn - xv );
		err2 = abs( funzione (xn , ag , T , d) );
		
		printf( "%4d | %14lf | %14lf | %14lf | %14lf | %14lf\n" , iter , a , b , xn , err1 , err2 );
	}

	return 0;
}

void welcome() {
	printf( "\n\nWelcome!" );
	printf( "\nThis little software allow you to calculate the wavelenght of a Tsunami.\n" );
	printf( "It is based on the non-linear equation:" );
	printf( "\n\t f(L) = L - [( g * T^2 )/( 2 * pi )] * tanh[ ( 2*pi*d )/L ]\n" );
	printf( "Now, insert requested data . . .\n" );
}

// Again... function of my function f(L)! :P
double funzione ( double L , double agf , double Tf , double df ) {
	double f;
	
	f = L - ( agf * pow( Tf,2 ) ) / ( 2 * pi ) * tanh( 2 * pi * df / L );

	return f;
}

// i explicit tanh( x )
double tanh ( double x ) {
	double result = ( exp( x ) - exp( -x ) ) / ( exp( x ) + exp( -x ) );

	return result;
}
