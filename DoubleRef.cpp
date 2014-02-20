//
//  DoubleRef.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 15/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "DoubleRef.h"

DoubleRef::operator Double&() const{
    std::cout << "???WRITE : DoublePtr converted to Double*" <<std::endl;
    return r;
}
DoubleRef::operator Double&() {
    std::cout << "??????READ : DoublePtr converted to Double*" <<std::endl;
    return r;
}
DoubleRef::operator Double() {
        std::cout << ".." <<std::endl;
        return r;
}
    


