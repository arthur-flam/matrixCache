//
//  DoublePtr,.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 06/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__DoublePtr___
#define __projetInfo_AFMC__DoublePtr___

#include <iostream>
#include "Double.h"

class DoublePtr{
public:
    DoublePtr();
    DoublePtr(Double* p);
    // Destructeur: pas besoin car pas d'affectation sur la pile
    // Copie et affectation: ici on veut copier un pointeur,
    // pas la valeur vers laquelle il pointe, donc pas besoin
    
    operator Double*();
    DoublePtr operator++(int);
    // en cpp cette signature c'est la post-incrémentation !

    //operator const Double*();
    //const Double operator*();
    DoublePtr& operator*(); // écriture
//    DoublePtr& operator*() const; // lecture

private:
    Double* P;
};




#endif /* defined(__projetInfo_AFMC__DoublePtr___) */
