//
//  DoublePtr,.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 06/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "DoublePtr.h"


DoublePtr::DoublePtr(){
}
DoublePtr::DoublePtr(Double* p){
    P=p;
}


DoublePtr::operator Double*() {
    std::cout << "DoublePtr converted to Double*" <<std::endl;
    return P;
}
    
    
Double DoublePtr::operator*() {
    std::cout << "WRITE : DoublePtr accessed for its l-value" <<std::endl;
    return *P;
}
const Double DoublePtr::operator*() const{
    std::cout << "READ : DoublePtr accessed for its l-value" <<std::endl;
    //const DoublePtr& out = *this;
    return *P;
    //return *this;
}
    
// Test PointerRef
//DoubleRef DoublePtr::operator*() {
//        std::cout << "WRITE : DoublePtr accessed for its l-value" <<std::endl;
//        return (DoubleRef) *this;
//}
    
    
DoublePtr DoublePtr::operator++(int) {
    return (this->P)++;
}
