//
//  Double.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__Double__
#define __projetInfo_AFMC__Double__

#include <iostream>

class DoubleRef;

class Double{
    friend class DoublePtr;
    friend class DoubleRef;
    friend class Matrix; // pour cacher les détails d'implé
  public:
    // Constructeurs et méthodes spéciales
    Double();
    Double(double nd);
    Double( const Double& other );
    Double& operator=( const Double& other );
    
    bool operator==( const Double& other );
    Double operator*( const Double& other );
    Double operator+( const Double& other );
    Double operator+=( const Double& other );
    friend std::ostream& operator<<(std::ostream&, const Double&);
    friend std::ostream& operator<<(std::ostream&, const DoubleRef);

    
  private:
    double d;
};



#endif /* defined(__projetInfo_AFMC__Double__) */
