//
//  DoubleRef.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 15/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__DoubleRef__
#define __projetInfo_AFMC__DoubleRef__

#include "Double.h"
#include "DoublePtr.h"
#include "Cache.h"

class DoublePtr;

class DoubleRef{
    friend class Double;
    friend class DoublePtr;
    friend class Matrix;
public:
    DoubleRef(Double& r_):r(r_){}
    static Cache cache; // I know global variables suck...
                           // let's think of it as a state machine

    
    operator const DoublePtr();
    Double operator =(const Double&);
    friend std::ostream& operator<<(std::ostream&, const DoubleRef);
    operator Double();
    double& get_double_ref();

private:
    Double& r;
};


#endif /* defined(__projetInfo_AFMC__DoubleRef__) */
