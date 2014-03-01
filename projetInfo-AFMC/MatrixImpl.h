//
//  MatrixImpl.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__MatrixImpl__
#define __projetInfo_AFMC__MatrixImpl__

#include <iostream>
#include "Double.h"
#include "DoublePtr.h"
#include "DoubleRef.h"

#define SIZE  100

class MatrixImpl{
  public:
    MatrixImpl();
    ~MatrixImpl(); // il faut libérer le tableau alloué sur le tas
    MatrixImpl( const MatrixImpl& other ); // pour copier les données et non juste pointer desssus
    MatrixImpl& operator=( const MatrixImpl& other ); // idem
    
    //Double operator()(int x, int y);  // accès à la r-value
    //Double &operator()(int x, int y); // accès à la référence
    DoubleRef operator()(int x, int y); // accès différentié read/write
    
    friend MatrixImpl operator*(MatrixImpl& A, MatrixImpl& B);
    void print();

  private:
    //Double **tableau;
    DoublePtr *tableau;
    void alloc();
};


#endif /* defined(__projetInfo_AFMC__MatrixImpl__) */