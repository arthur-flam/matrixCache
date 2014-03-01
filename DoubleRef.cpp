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

Cache DoubleRef::cache;

DoubleRef::operator const DoublePtr(){
    std::cout << "READ (cast to const DoublePtr)" <<std::endl;
    Double tmp = r;
    const DoublePtr out = DoublePtr(&tmp);
    return out;     
}
Double DoubleRef::operator =(const Double& other){
    // std::cout << "WRITE" <<std::endl;
    this->r = other; // mémoire principale mise à jour
    double* adress  = &(this->get_double_ref()); // [36] adresse du double où l'on écrit
    cache.write(adress); // cache mis à jour
    return this->r;
}

DoubleRef::operator Double(){
    //std::cout << "READ (to Double)" <<std::endl;
    return DoubleRef::cache.get(&(r.d));
    //return r; // sans cache
}

// Utile pour cacher les détails d'implémentations à la classe Matrix
double& DoubleRef::get_double_ref(){
    return r.d;
};


// Opérateur pour afficher sur un flux
std::ostream& operator<<(std::ostream& stream, const DoubleRef D){
    //std::cout << "READ(print)";
    return stream << DoubleRef::cache.get(&(D.r.d));
};