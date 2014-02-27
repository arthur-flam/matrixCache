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
#include "DoublePtr.h"

class DoublePtr;


class DoubleRef{
public:
    DoubleRef(Double& r_):r(r_){}
    
    operator const DoublePtr();
    Double operator =(const Double&);
    Double& get_ref() const;
    friend std::ostream& operator<<(std::ostream&, const DoubleRef);
    operator Double();

private:
    Double& r;
};


#endif /* defined(__projetInfo_AFMC__DoubleRef__) */
