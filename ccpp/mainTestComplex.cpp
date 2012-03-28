/*
 * Just a test code for the Complex number header.
 *
 * Given parameters of the second degree equation,
 * it calculates roots of the equation using the
 * Complex numbers header.
 *
 * So... nothing of special! :)
 *
 * Author: hawake
 */


#include <iostream>
#include <math.h>
#include "Complex.h"

using namespace std;

int main() {
    int A , B , C , delta , tempo ;
    Complex x1 , x2 ;

    cout << endl << "\n\nPlease, insert numerical coefficients Inserire i coefficienti dell'equazione di secondo grado " << endl
        << "Ax^2 + Bx + C = 0 per risolverla . . ." << endl ;
    cout << "A: " ;
    cin >> A ;
    cout << endl << "B: " ;
    cin >> B ;
    cout << endl << "C: " ;
    cin >> C ;

    cout << endl << "Calcolo il delta . . ." ;
    delta = pow( B , 2 ) - 4 * A * C ;
    cout << " OK!" << endl << "delta = " << delta << endl ;

    if ( delta > 0 ) {
        tempo = ( sqrt(delta) - B )  / ( 2 * A ) ;

        x1.setRealPart( tempo ) ;
        x1.setImaginaryPart( 0 ) ;

        tempo = ( - sqrt(delta) - B )  / ( 2 * A ) ;

        x2.setRealPart( tempo ) ;
        x2.setImaginaryPart( 0 ) ;

        cout << "\n\n" << x1.getRealPart() << "\t" << x1.getImaginaryPart() << endl ;
        cout << "\n\n" << x2.getRealPart() << "\t" << x2.getImaginaryPart() << endl ;
    } else if ( delta == 0 ) {
        tempo = ( - B ) / ( 2 * A ) ;

        x1.setRealPart( tempo ) ;
        x1.setImaginaryPart( 0 ) ;

        x2 = x1 ;

        cout << "\n\n" << x1.getRealPart() << "\t" << x1.getImaginaryPart() << endl ;
        cout << "\n\n" << x2.getRealPart() << "\t" << x2.getImaginaryPart() << endl ;
    } else if ( delta < 0 ) {
        tempo = ( - B )  / ( 2 * A ) ;

        x1.setRealPart( tempo ) ;
        x1.setImaginaryPart( sqrt( - delta ) / ( 2 * A ) ) ;

        x2.setRealPart( x1.getRealPart() );
        x2.setRealPart( - sqrt( - delta ) / ( 2 * A ) );

        cout << "\n\n" << x1.getRealPart() << "\t" << x1.getImaginaryPart() << endl ;
        cout << "\n\n" << x2.getRealPart() << "\t" << x2.getImaginaryPart() << endl ;
    }

    cout << "Valore di x1: " ;
    x1.print() ;
    cout << endl << "Valore di x2: " ;
    x2.print() ;
    cout << endl ;

    x1.~Complex() ;
    x2.~Complex() ;

    return 0;
}
