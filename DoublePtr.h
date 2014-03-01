//
//  DoublePtr,.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 06/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__DoublePtr___
#define __projetInfo_AFMC__DoublePtr___

#include "Double.h"
#include "DoubleRef.h"

class DoubleRef;

class DoublePtr{
    friend class Double;
    friend class DoubleRef;
public:
    DoublePtr();
    DoublePtr(Double* p);
    // Destructeur: pas besoin car pas d'affectation sur la pile
    // Copie et affectation: ici on veut copier un pointeur,
    // pas la valeur vers laquelle il pointe, donc pas besoin
    
    DoublePtr operator++(int);
    DoublePtr operator+(int);
    // en cpp cette signature c'est la post-incrémentation !


    // Test opérateurs
    // Double& operator*(); // écriture
    DoubleRef operator*();
    //operator Double*(); // remplacé par la ligne suivant pour interecpter READ/WRITE
    operator Double*() const;
        
private:
    Double* P;
};




#endif /* defined(__projetInfo_AFMC__DoublePtr___) */
