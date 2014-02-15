//
//  DoubleRef.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 15/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__DoubleRef__
#define __projetInfo_AFMC__DoubleRef__

#include <iostream>
#include "Double.h"

class DoubleRef{
public:
    DoubleRef();
    
    operator Double&();
    
    DoubleRef operator*(); // écriture?
    DoubleRef operator*() const; // lecture?
    
    DoubleRef(Double& r_):r(r_){}
    
private:
    Double& r;
};





#endif /* defined(__projetInfo_AFMC__DoubleRef__) */
