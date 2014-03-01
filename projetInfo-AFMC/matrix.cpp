//
//  matrice.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "matrix.h"

// Constructeur par défaut
Matrix::Matrix(){
    M = MatrixImpl();
}

// Constructeur privé avec MatrixImpl*
Matrix::Matrix(MatrixImpl* A){
    M = MatrixImpl(*A);
}

// Constructeur par copie
Matrix::Matrix(const Matrix& other ){
    this->M = other.M;
}


// Opérateur d'affectation
Matrix& Matrix::operator=( const Matrix& other ){
    if (this == &other)
        return *this; // évitons du travail
    this->M = other.M;
    return *this;
};


// Opérateur externe pour la multiplication par une matrice
Matrix operator*(Matrix& A, Matrix& B){
    MatrixImpl temp = (A.M)*(B.M);
    return Matrix(&temp);
}
// [11] chez moi cela compile sans plus de travail


double& Matrix::operator()(int i, int j){
    return (this->M(i,j)).get_double_ref();
};
// [22] Pour le moment on doit utiliser Double ici pour que ça marche
// En effet, pour le moment M contient des Doubles, qu'on ne sait pas convertir en double
// On peut tenter de caster en double, mais on renverrait une référence vers un Double et non vers un double...
// Pour le moment la classe Double est donc visible de l'utilisateur final...

void Matrix::print(){
    this->M.print();
}