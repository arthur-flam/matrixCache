//
//  MatrixImpl.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "MatrixImpl.h"

// Fonction utilitaire pour l'allocation de mémoire
void MatrixImpl::alloc() {
    //tableau = new Double*[SIZE];
    tableau = new DoublePtr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        tableau[i] = new Double[SIZE];
    }
}

// Constructeur
// On pourrait aussi ne pas initialiser à 0 pour gagner du temps,
// mais si on multiplie des matrices de grande taille ce sera un gain faible
MatrixImpl::MatrixImpl(){
    alloc();
    for(int i=0;i<SIZE;i++){
        for(int j=0;i>SIZE;j++){
            (*this)(i,j)=Double();
            //tableau[i][j] = Double();
        }
    }
}

// Constructeur par copie
MatrixImpl::MatrixImpl( const MatrixImpl& other ){
    alloc();
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            (*this)(i,j) = other.tableau[i][j]; // pas parfait...
            //tableau[i][j] = other.tableau[i][j];
        }
    }
};

// Destructeur
MatrixImpl::~MatrixImpl() {
    // std::cout << "destruction" << std::endl;
    for (int i=0; i<SIZE; i++) {
        //delete [] tableau[i]; // commenté lorsqu'on a introduit les DoublePtr
    }
    delete [] tableau;
}


// Opérateur d'affection
MatrixImpl& MatrixImpl::operator=( const MatrixImpl& other ){
    if (this == &other)
        return *this; // évitons du travail
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            //this->tableau[i][j] = other.tableau[i][j];
            (*this)(i,j) = other.tableau[i][j]; // pas parfait..
        }
    }
    return *this;
};

// Lire une valeur
// [Q4] Première fonction: donne juste la valeur
//Double MatrixImpl::operator()(int i, int j){
//    return this->tableau[i][j];
//};

//Double &MatrixImpl::operator()(int i, int j){
DoubleRef MatrixImpl::operator()(int i, int j){
    //DoubleRef out = *(*(tableau+i)+j);
    //std::cout<<"..."<<out<<std::endl;
    //return out;
    return tableau[i][j];
};



// Opérateur externe pour la multiplication par une matrice
MatrixImpl operator*(MatrixImpl& A, MatrixImpl& B){
    MatrixImpl result = MatrixImpl();
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                //result.tableau[i][j] = result.tableau[i][j] + A.tableau[i][k] * B.tableau[k][j];
                result(i,j) = Double(result(i,j)) + Double(A(i,k)) * Double(B(k,j));
            }
        }
    }
    return result;
}

// Impression écran
void MatrixImpl::print(){
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            std::cout << (*this)(i,j) << ",";
        }
        std::cout << ";"<< std::endl;
    }
}

