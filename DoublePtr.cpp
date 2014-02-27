//
//  DoublePtr,.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 06/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "DoublePtr.h"

// Constructeurs
DoublePtr::DoublePtr(){
}
DoublePtr::DoublePtr(Double* p){
    P=p;
}

// Casting vers Double*
//DoublePtr::operator Double*() {
//    std::cout << "casted DoublePtr -> Double*" <<std::endl;
//    return P;
//}


DoubleRef DoublePtr::operator*() {
    return DoubleRef(*P);
}
DoublePtr::operator Double*() const{
    return P;
}
    

DoublePtr DoublePtr::operator++(int) {
    return (this->P)++;
}
DoublePtr DoublePtr::operator+(int i) {
    return (this->P)=this->P+i;
}
