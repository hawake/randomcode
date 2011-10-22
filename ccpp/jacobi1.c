/**
 * This little program is just a test implementation of the Jacobi numerical
 * method to approximate the result of linear system. After getting A matrix
 * by user input, this code control if the matrix is diagonally dominant so
 * that the method MAY converge.
 * 
 * Author: hawake
 * Version: 1.0
 *
 * This software is released under terms of GNU General Public License version 3.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ** creaMatrice ( int righe , int colonne );
double * creaVettore ( int righe );

int main () {
	int i, j, k, n;	// indices for cycles
	int row , column , iter ;
	double **A ,	// starting matrix
	       **D ,	// diagonal matrix
	       **L ,	// lower triangular matrix
   	       **U ,	// upper triangular matrix
   	       **M ,	// iteration matrix
   	       **Dinv ,	// inverted diag matrix
   	       *B  ,	// know terms vector
   	       *Q  ,	// matrix equation known term
   	       *X  ,	// support vector
   	       *XO ;	// another support vector
	double max1 = 0.0 , max2 = 0.0 , sum = 0.0 ;

	printf( "\n\nInsert the number of rows for A:  " );
	scanf( "%d" , &row );
	printf( "\n\nInsert the number of columns for A: ");
	scanf( "%d" , &column );

	// Starting matrix
	A = creaMatrice( row , column );

	printf( "\n\nInsert terms for matrix A:\n" );

	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			printf( "Insert element a[%d][%d]: " , i , j );
			scanf( "%lf" , &A[i][j] );
		}
	}

	// Known terms vector
	B = creaVettore( row );
	printf( "\n\nInsert vector B of known terms...\n" );

	for ( i = 0 ; i < row ; i++ ) {
		printf( "Insert element B[%d]: " , i );
		scanf( "%lf" , &B[i] );
	}

	// Now i verify the convergence of the iteration method.
	// So, if the matrix is diagonally dominant the method converge.
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			if ( i < j ) {
				if ( A[i][i] > A[i][j])
					printf( "\nThis matrix is diagonally dominant!\n" );
				else {
					printf( "\n\nThe matrix is not diagonally dominant so" );
					printf( "the Jacobi method does not converge for this matrix!\n\n" );
					exit( EXIT_SUCCESS );
				}
			} else if ( i > j ) {
				if ( A[i][i] > A[j][i] )
					printf( "\nThis matrix is diagonally dominant!\n" );
				else {
					printf( "\n\nERROR!\n\n" );
					exit( EXIT_SUCCESS );
				}
			}
		}
	}

	// Diagonal matrix obtained from A
	D = creaMatrice( row , column );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			if ( i == j)
				D[i][j] = A[i][j];
			else
				D[i][j] = 0;
		}
	}

	// Lower triangular matrix obtained from A
	L = creaMatrice( row , column );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			if ( i > j )
				L[i][j] = A[i][j];
			else
				L[i][j] = 0;
		}
	}

	// Upper triangular matrix obtained from A
	U = creaMatrice( row , column );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			if ( i < j )
				U[i][j] = A[i][j];
			else
				U[i][j] = 0;
		}
	}

	// Inverted diagonal matrix
	Dinv = creaMatrice( row , column );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			if ( D[i][i] != 0 )
				Dinv[i][i] = 1 / D[i][i];
			else
				Dinv[i][i] = 0;
		}
	}

	// Now i have to create the iteration matrix ...
	M = creaMatrice( row , column );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			M[i][j] = - Dinv[i][j] * ( L[i][j] + U[i][j] );
		}
	}

	// Vectorial known term
	Q = creaVettore( row );
	for ( i = 0 ; i < row ; i++ ) {
		Q[i] = Dinv[i][i]*B[i];
	}
	
	printf( "\n\nOUTPUT\n\nA:\n" );
	
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			printf( "%lf " , A[i][j] );
		}
		printf( "\n" );
	}

	printf( "\n\nD:\n" );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			printf( "%lf " , D[i][j] );
		}
		printf( "\n" );
	}

	printf( "\n\nU:\n" );
	for ( i = 0; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			printf( "%lf " , U[i][j] );
		}
		printf( "\n" );
	}

	printf( "\n\nL:\n" );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0; j < column ; j++ ) {
			printf( "%lf " , L[i][j] );
		}
		printf( "\n" );
	}

	printf( "\n\nDinv:\n" );
	for ( i = 0 ; i < row ; i++ ) {
		for ( j = 0 ; j < column ; j++ ) {
			printf( "%lf " , Dinv[i][j] );
		}
		printf( "\n" );
	}

	printf( "\n\nM:\n" );
	for ( i = 0; i < row ; i++ ) {
		for ( j = 0;j < column ; j++ ){
			printf( "%lf " , M[i][j] );
		}
		printf( "\n" );
	}

	printf( "\n\nInsert number of iterations: " );
	scanf( "%d" , &iter );
	
	// So the iteration cycles...
	X = creaVettore( row );
	XO = creaVettore( row );

	for ( i = 0 ; i < row ; i++ ) {
		XO[i] = Q[i];
	}
	for ( k = 0 ; k < iter ; k++ ) {
		for ( i = 0 ; i < row ; i++ ) {
			for (j = 0 ; j < column ; j++ ) {
				X[i] = (XO[i] + M[i][j] * XO[j]) + Q[i];
			}
		}
	}
	
	// print out the result matrix
	printf( "\n\nResult matrix:\n" );
	for ( i = 0 ; i < row ; i++ ) {
		printf( "%lf" , X[i] );
		printf( "\n" );
	}

	// Let's free some memory ...
	// ... for A
	for ( i = 0 ; i < row ; i++ )
		free ( A[i] );
	free ( A );

	// ... for B
	free ( B );

	// ... for Q
	free ( Q );

	// ... for D
	for ( i = 0 ; i < row ; i++ )
		free ( D[i] );
	free ( D );

	// ... for L
	for ( i = 0 ; i < row ; i++ )
		free ( L[i] );
	free ( L );

	// ... for U
	for ( i = 0 ; i < row ; i++ )
		free ( U[i] );
	free ( U );
	
	// ... for Dinv
	for ( i = 0 ; i < row ; i++ )
		free ( Dinv[i] );
	free ( Dinv );

	// ... for M
	for ( i = 0 ; i < row ; i++ )
		free ( M[i] );
	free ( M);

	return 0;
}

// This function creates dynamically allocated matrix
double ** creaMatrice ( int righe , int colonne ) {
	int i ;
	double	**ptr ;

	ptr = ( double ** )malloc( righe * sizeof( double * ) );

	if ( ptr == NULL ) {
		printf( "\n\nWARNING! An error occurred during memory allocation!\n\n" );
		exit( EXIT_FAILURE );
	}

	for ( i = 0 ; i < righe ; i++ ) {
		ptr[i] = ( double * )malloc( colonne * sizeof( double ) );
		if ( ptr[i] == NULL ) {
			printf( "\n\nWARNING! An error occurred during memory allocation!\n\n" );
			exit( EXIT_FAILURE );

		}
	}
	
	return ptr;
}

// This function creates dynamically allocated vector
double * creaVettore ( int righe ) {
	int i ;
       	double *ptr;

	ptr = ( double * )malloc( righe * sizeof( double ) );

	if (ptr == NULL ) {
		printf( "\n\nWARNING! An error occurred during memory allocation!\n\n" );
		exit( EXIT_FAILURE );
	}

	return ptr;
}
