//
//  DoubleRef.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 15/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "DoubleRef.h"

// [Q28]
// BEAUCOUP BEAUCOUP d'essais et d'erreurs pour faire marcher ça.......
// ......


DoubleRef::operator const DoublePtr(){
    std::cout << "READ (cast to const DoublePtr)" <<std::endl;
    Double tmp = r;
    const DoublePtr out = DoublePtr(&tmp);
    return out;
}
Double DoubleRef::operator =(const Double& other){
    std::cout << "WRITE" <<std::endl;
    this->r = other;
    return this->r;
}
Double& DoubleRef::get_ref() const{
    std::cout << "READ (get_ref)" <<std::endl;
    return r;
}

DoubleRef::operator Double(){
    return r;
}


// Opérateur pour afficher sur un flux
std::ostream& operator<<(std::ostream& stream, const DoubleRef D){
    //return stream << D.r;
    return stream << D.get_ref();
};