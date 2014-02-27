//
//  main.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "main.h"

int mainXX(int argc, const char * argv[]){
    std::cout << "> Matrix A = Matrix();" << std::endl;
    Matrix A = Matrix();
    std::cout << "> Matrix B = Matrix();" << std::endl;
    Matrix B = Matrix();
    std::cout << "> Matrix AB = Matrix();" << std::endl;
    Matrix AB = Matrix();
    std::cout << "// init A, B..." << std::endl;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            A(i,j) = i+j;
            B(i,j) = j-i;
        }
    }
    std::cout << "> AB = A*B;" << std::endl;
    AB = A*B;
    std::cout << "A:" << std::endl;
    A.print();
    std::cout << "B:" << std::endl;
    B.print();
    std::cout << "A*B:" << std::endl;
    AB.print();

    return 0;
};



// Anciens Tests pour MatrixImpl
//int main(int argc, const char * argv[]){
//    std::cout << "start" << std::endl;
//    MatrixImpl A = MatrixImpl();
//    MatrixImpl B = MatrixImpl();
//    MatrixImpl AB = MatrixImpl();
//    for(int i=0;i<SIZE;i++){
//        for(int j=0;j<SIZE;j++){
//            A(i,j) = i+j;
//            B(i,j) = j-i;
//        }
//    }
//    AB=A*B;
//    std::cout << "A:" << std::endl;
//    A.print();
//    std::cout << "B:" << std::endl;
//    B.print();
//    std::cout << "A*B:" << std::endl;
//    AB.print();
//
//    Matrix M = Matrix();
//
//    std::cout << "end" << std::endl;
//    return 0;
//};