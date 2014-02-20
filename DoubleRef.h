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
    DoubleRef(Double& r_):r(r_){}
    DoubleRef(Double* r_):r(*r_){}
    operator Double&();
    operator Double&() const;
    operator Double();
    
private:
    Double& r;
};





#endif /* defined(__projetInfo_AFMC__DoubleRef__) */
