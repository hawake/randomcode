/*
 * Just a test with operators and classes.
 *
 * Author: hawake
 * License: GNU GPL version 3
 */

#include <iostream>
#include <math.h>
#include <string>

using namespace std ;

class Complex {
	public:
		Complex() ; // Constructor
		Complex( const double r1 , const double i1 ) ;
		Complex( const double r1 , const double i1 , const char iU ) ;
		~Complex() ; // Distructor
		double getRealPart() const ;
		double getImaginaryPart() const ;

		void setRealPart( const double rr ) ;
		void setImaginaryPart( const double ii ) ;

		Complex & operator=( const Complex & c1 ) ;

		Complex operator+( const Complex c1 ) ;
		Complex operator-( const Complex c1 ) ;
		Complex operator*( const Complex c1 ) ;
		Complex operator/( const Complex c1 ) ;

		Complex operator-() ;

		Complex & operator+=( const Complex & c1 ) ;
		Complex & operator-=( const Complex & c1 ) ;
		Complex & operator*=( const Complex & c1 ) ;
		Complex & operator/=( const Complex & c1 ) ;

		Complex operator+( const double d ) ;
		Complex operator-( const double d ) ;
		Complex operator*( const double d ) ;
		Complex operator/( const double d ) ;

		Complex & operator+=( const double d ) ;
		Complex & operator-=( const double d ) ;
		Complex & operator*=( const double d ) ;
		Complex & operator/=( const double d ) ;

		bool Compare( const Complex & c1 ) ;

		bool operator==( const Complex & c1 ) ;
		bool operator!=( const Complex & c1 ) ;

		double getAbs() ;
		double pow( double base , double exp ) ;
		double pow( Complex base , double exp ) ;

		void coniugate() ;

		void print(); ////////////////////
	private:
		double R ; // Real part
		double I ; // Imaginary part
		char imaginaryUnit ;
};
