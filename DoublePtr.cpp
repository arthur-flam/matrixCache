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
    std::cout << "READ : DoublePtr converted to Double*" <<std::endl;
    return P;
}
    
    
DoublePtr& DoublePtr::operator*() {
    std::cout << "WRITE : DoublePtr accessed for its l-value" <<std::endl;
    return *this;
}
//DoublePtr& DoublePtr::operator*() const{
//    std::cout << "READ : DoublePtr accessed for its l-value" <<std::endl;
//    return *this;
//}
    
DoublePtr DoublePtr::operator++(int) {
    return (this->P)++;
}


//    std::cout << "Double d4;" << std::endl;
//    Double d4;
//    std::cout << "DoublePtr p = &d;" << std::endl;
//    DoublePtr p4 = &d4;
//    std::cout << "*p = 5.4;" << std::endl;
//    //*p4 = 5.4;
//    std::cout << "*p" << std::endl << *p4 << std::endl;
