//
//  testmemory.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "testmemory.h"


int mainXXX(int argc, const char * argv[]){
    // test des constructeurs et opérateurs d'affection
    std::cout << "Test des opérateurs" << std::endl;
    Double a = Double();
    std::cout << "constructeur "<< a << std::endl;
    Double b =Double(2.0);
    std::cout << "constructeur avec double " << b << std::endl;
    Double c = a;
    std::cout << "affectation " << c << std::endl;
    Double e=Double(a);
    std::cout << "copie "<< e << std::endl;
    Double d2 =Double(4.);
    // test des opérateurs
    std::cout << "multiplication " << b*d2 << std::endl;
    std::cout << "égalité " << (b==b) << std::endl;
    std::cout << "addition " << (b==b+b) << std::endl << std::endl << std::endl;

    
    // [25]
    std::cout << "[Q25]" << std::endl;
    DoublePtr p = new Double[100];
    std::cout << *p << std::endl; // on peut définir l'opérande d'indirection pour compiler juste cette ligne...
    delete [] p;
    std::cout << std::endl;
    // il suffit de permettre une conversion facile entre Double* et DoublePtr
    // en mettant un opérateur de conversion.
    
    // [26]
    std::cout << "[Q26]" << std::endl;
    Double d = Double(2.0);
    std::cout << d << std::endl;
    DoublePtr p2 = &d;
    std::cout << p2 << std::endl;
    std::cout << *p2 << std::endl;
    p2++;
    std::cout << p2 << std::endl << std::endl;
    // il faut définir l'opérateur de post-incrémentation sur le simili-pointeur PtrDouble
    // j'ai appris le post-incrément prennait un int en argument pour le différencier du pré-incrément (!)
    
    // [27]
    std::cout << "[Q27]" << std::endl;
    DoublePtr p3 = new Double[3];
    Double sum;
    for (int i = 0; i < 3; i++)
        p3[i] = i;
    std::cout << "init ok" << std::endl;
    for (int i = 0; i < 3; i++)
        sum += p3[i];
    // - on a défini un opérateur += dans la classe Double
    // - ça compile
    // - on intercepte visiblement les accès mémoire rien qu'avec ça, sauf si quelque chose nous échappe.
    delete [] p3;
    std::cout << sum << std::endl << std::endl;
    
    
    // Pour intercepter les accès en écriture des DoublePtr,
    // il ???? suffit d'utiliser un opérateur d'indirection attendant un const
    // (merci de l'info)
    std::cout << "Double d4;" << std::endl;
    Double d4;
    std::cout << "DoublePtr p = &d;" << std::endl;
    DoublePtr p4 = &d4;
    std::cout << "*p = 5.4;" << std::endl;
    //*p4 = 5.4;
    std::cout << "*p" << std::endl << *p4 << std::endl;

    
    
    return 0;
};
