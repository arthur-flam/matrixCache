//
//  Double.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "Double.h"

// Constructeur avec un double natif
Double::Double(){
    d=0;
}
// Constructeur à partir d'un double
Double::Double(double nd){
    d=nd;
}
// Constructeur par copie
Double::Double(const Double& other ){
    this->d = other.d;
}
// Opérateur d'affectation
Double& Double::operator=( const Double& other ){
    //std::cout << "wrote Double (=)" << std::endl;
    if (this == &other)
        return *this; // évitons du travail
    this->d = other.d;
    return *this;
};


// Opérateurs divers
bool Double::operator==( const Double& other ){
    return this->d == other.d;
};
Double Double::operator*( const Double& other ){
    return Double(this->d * other.d);
};
Double Double::operator+( const Double& other ){
    return Double(this->d + other.d);
};
Double Double::operator+=( const Double& other ){
    //std::cout << "wrote Double (+=)" << std::endl;
    this->d += other.d;
    return *this;
};


// Opérateur pour afficher sur un flux
std::ostream& operator<<(std::ostream& stream, const Double& D){
    return stream << D.d;
};


// Conversion en Double
//Double::operator double(){
//    //std::cout << "conversion to double" << std::endl;
//    return this->d;
//};



