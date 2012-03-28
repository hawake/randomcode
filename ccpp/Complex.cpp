/*
 * Just a test with operators and classes.
 *
 * Author: hawake
 * License: GNU GPL version 3
 */

#include <iostream>
#include <math.h>
#include <string>

#include "Complex.h"

using namespace std ;

Complex::Complex() {
	R = 0 ;
	I = 0 ;
	imaginaryUnit = 'i' ;
}
Complex::Complex( const double r1 , const double i1 ) {
	R = r1 ;
	I = i1 ;
	imaginaryUnit = 'i' ;
}
Complex::Complex( const double r1 , const double i1 , const char iU ) {
    R = r1 ;
    I = i1 ;
    imaginaryUnit = iU;
}
Complex::~Complex() {
	cout << "Invoco il distruttore . . ." << endl ;
}
double Complex::getRealPart() const {
	return R ;
}
double Complex::getImaginaryPart() const {
	return I ;
}
void Complex::setRealPart( const double rr ) {
    this->R = rr ;
    //R = rr ;
}
void Complex::setImaginaryPart( const double ii ) {
    this->I = ii ;
    //I = ii ;
}
Complex & Complex::operator=( const Complex & c1 ) {
	if ( this != &c1 ) {
		R = c1.getRealPart() ;
		I = c1.getImaginaryPart() ;
	} else
		return *this ;
}
Complex Complex::operator+( const Complex c1 ) {
	return Complex( R + c1.getRealPart() , I + c1.getImaginaryPart() ) ;
}
Complex Complex::operator-( const Complex c1 ) {
	return Complex( R - c1.getRealPart() , I - c1.getImaginaryPart() ) ;
}
Complex Complex::operator*( const Complex c1 ) {
	return Complex( R*c1.getRealPart() - I*c1.getImaginaryPart() , R*c1.getImaginaryPart() + I*c1.getRealPart() ) ;
}
Complex Complex::operator/( const Complex c1 ) {
	double a , b ;
	if ( fabs( c1.getRealPart() ) >= fabs( c1.getImaginaryPart() ) ) {
		a = c1.getImaginaryPart() / c1.getRealPart() ;
		b = 1.0l / ( c1.getRealPart() + a * c1.getImaginaryPart() ) ;
		return Complex( ( R + a * I ) * b , ( I - a * R ) * b ) ;
	} else {
		a = c1.getRealPart() / c1.getImaginaryPart() ;
		b = 1.0l / ( c1.getRealPart() * a + c1.getImaginaryPart() ) ;
		return Complex( ( R * a + I ) * b , ( I * a - R ) * b ) ;
	}
}
Complex Complex::operator-() {
	R = -R ;
	I = -I ;
	return Complex ( R , I ) ;
}
Complex & Complex::operator+=( const Complex & c1 ) {
    R += c1.getRealPart() ;
    I += c1.getImaginaryPart() ;
    return *this ;
}

Complex & Complex::operator-=( const Complex & c1 ) {
    R -= c1.getRealPart() ;
    I -= c1.getImaginaryPart() ;
    return *this ;
}

Complex & Complex::operator*=( const Complex & c1 ) {
    R *= c1.getRealPart() ;
    I *= c1.getImaginaryPart() ;
    return *this  ;
}

Complex & Complex::operator/=( const Complex & c1 ) {
    R /= c1.getRealPart() ;
    I /= c1.getImaginaryPart() ;
    return *this ;
}

Complex Complex::operator+( const double d ) {
    R += d ;
    return Complex( R , I ) ;
}

Complex Complex::operator-( const double d ) {
    R -= d ;
    return Complex( R , I ) ;
}

Complex Complex::operator*( const double d ) {
    R *= d ;
    I *= d ;
    return Complex( R , I ) ;
}
Complex Complex::operator/( const double d ) {
    R /= d ;
    I /= d ;
    return Complex( R , I ) ;
}
Complex & Complex::operator+=( const double d ) {
    R += d ;
    return *this ;
}
Complex & Complex::operator-=( const double d ) {
    R -= d ;
    return *this ;
}
Complex & Complex::operator*=( const double d ) {
    R *= d ;
    return *this ;
}
Complex & Complex::operator/=( const double d ) {
    R /= d ;
    return *this ;
}

bool Complex::Compare( const Complex & c1 ) {
    if ( R == c1.getRealPart() || I == c1.getImaginaryPart() )
        return true ;
    else
        return false ;
}

bool Complex::operator==( const Complex & c1 ) {
    if ( R == c1.getRealPart() || I == c1.getImaginaryPart() )
        return true ;
    else
        return false ;
}

bool Complex::operator!=( const Complex & c1 ) {
    if ( R != c1.getRealPart() || I != c1.getImaginaryPart() )
        return true ;
    else
        return false ;
}

double Complex::getAbs() {
	return sqrt( pow( R , 2 ) + pow( I , 2 ) ) ;
}
double Complex::pow( double base , double exp ) {
    return pow( base , exp ) ;
}
double Complex::pow( Complex base , double exp ) {
	return ( pow( base.getRealPart() , exp ) - pow( base.getImaginaryPart() , exp ) );
}
void Complex::coniugate() {
    this->I = -I ;
}
void Complex::print() {
	if ( this->I < 0 )
        cout << this->R << " - " << this->imaginaryUnit << this->I << endl ;
    else
		cout << this->R << " + " << this->imaginaryUnit << this->I << endl ;
}
