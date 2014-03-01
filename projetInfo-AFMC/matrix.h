//
//  Matrix.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__Matrix__
#define __projetInfo_AFMC__Matrix__

#include <iostream>
#include "MatrixImpl.h"



class Matrix{
public:
    Matrix();
    // pas besoin de destructeur car le destructeur par défaut
    // appelle celui de MatrixImpl. On peut le vérifier en imprimant
    // à l'écran quand le destructeur est appellé.
    
    Matrix( const Matrix& other ); // pour copier les données et non juste pointer desssus
    Matrix& operator=( const Matrix& other ); // idem
    
    double& operator()(int x, int y); // on a caché les détails d'implémentation
    friend Matrix operator*(Matrix& A, Matrix& B);
    void print();
    
private:
    MatrixImpl M;
    Matrix(MatrixImpl* A);
};


#endif /* defined(__projetInfo_AFMC__Matrix__) */
