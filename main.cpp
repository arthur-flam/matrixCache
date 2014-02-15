//
//  main.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "main.h"

int main2(int argc, const char * argv[]){
    Matrix A = Matrix();
    Matrix B = Matrix();
    Matrix AB = Matrix();
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            A(i,j) = i+j;
            B(i,j) = j-i;
        }
    }
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