//
//  testmemory.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 05/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "testmemory.h"




int main(int argc, const char * argv[]){
    // Verbose
    bool print_matrixes = false;
    
    // Tests
    bool test_cache=false;
    bool test_DoublePtrRef=false;
    bool test_DoublePtrRefMatrices=false;
    bool test_mult=true;
    bool test_parcoursDoubleArray=false;
    

    Cache cache;
    DoubleRef::cache=cache;
    
    
    // CACHE
    if(test_cache){
        std::cout << "Test du cache" << std::endl;
        double a_ = 5.;
        double* pa_ = &a_;
        
        std::cout << a_ << std::endl;
        std::cout << "adress : " << pa_ << std::endl;
        std::cout << "tag    : " << (double*) CacheLine::get_tag(pa_) << std::endl;
        std::cout << "offset : " << CacheLine::get_offset(pa_) << std::endl;
        
        cache.get(pa_);
        cache.get(pa_);
        cache.get(pa_);
        cache.get(pa_);
        
        cache.hit_ratio();
        std::cout << std::endl<< std::endl;
    }
    if(test_DoublePtrRef){
        // test des constructeurs et opérateurs d'affection
        std::cout << "// Constructeurs " << std::endl;
        std::cout << "> Double a = Double(); a;" << std::endl;
        Double a = Double();
        std::cout << a << std::endl;
        std::cout << "> Double b =Double(2.0); b;" << std::endl;
        Double b =Double(2.0);
        std::cout << b << std::endl;
        std::cout << "// affectation " << std::endl << "Double c = a; c;" << std::endl;
        Double c = a;
        std::cout << c << std::endl;
        std::cout << "> Double e=Double(a); e;" << std::endl;
        Double e=Double(a);
        std::cout << e << std::endl;
        std::cout << "> Double d2 =Double(4.); d2;" << std::endl;
        Double d2 =Double(4.);
        std::cout << d2 << std::endl;
        // test des opérateurs
        std::cout << "b*d2 ? " << b*d2 << std::endl;
        std::cout << "b==b ? " << (b==b) << std::endl;
        std::cout << "b+b  ? " << b+b << std::endl << std::endl << std::endl;
        
        
        // [25]
        std::cout << "[Q25]" << std::endl;
        std::cout << "> DoublePtr p = new Double[100];" << std::endl;
        DoublePtr p = new Double[100];
        std::cout << "> *p;" << std::endl;
        std::cout << *p << std::endl; // on peut définir l'opérande d'indirection pour compiler juste cette ligne...
        std::cout << "> delete [] p;" << std::endl;
        delete [] p;
        std::cout << std::endl;
        // il suffit de permettre une conversion facile entre Double* et DoublePtr
        // en mettant un opérateur de conversion.
        
        // [26]
        std::cout << "[Q26]" << std::endl;
        std::cout << "> Double d = Double(2.0); d;" << std::endl;
        Double d = Double(2.0);
        std::cout << d << std::endl;
        std::cout << "> DoublePtr p = &d;" << std::endl;
        DoublePtr p2 = &d;
        std::cout << "> p;" << std::endl;
        std::cout << p2 << std::endl;
        std::cout << "> *p;" << std::endl;
        std::cout << *p2 << std::endl;
        std::cout << "> p++;" << std::endl;
        p2++;
        std::cout << "> p;" << std::endl;
        std::cout << p2 << std::endl << std::endl;
        // il faut définir l'opérateur de post-incrémentation sur le simili-pointeur PtrDouble
        // j'ai appris le post-incrément prennait un int en argument pour le différencier du pré-incrément (!)
        
        // [27]
        std::cout << "[Q27]" << std::endl;
        std::cout << "> DoublePtr p = new Double[3];" << std::endl;
        DoublePtr p3 = new Double[3];
        std::cout << "> Double sum;" << std::endl;
        Double sum;
        std::cout << "> for (int i = 0; i < 3; i++) p[i]=i;" << std::endl;
        for (int i = 0; i < 3; i++){
            std::cout << "// i=" << i << std::endl;
            p3[i] = i;
        }
        std::cout << "> for (int i = 0; i < 3; i++) sum += p[i];" << std::endl;
        for (int i = 0; i < 3; i++){
            std::cout << "// i=" << i << std::endl;
            sum += p3[i];
        }
        // - on a défini un opérateur += dans la classe Double
        // - ça compile, quelque chose nous échappe ?
        std::cout << "> delete [] p;" << std::endl;
        delete [] p3;
        std::cout << sum << std::endl << std::endl;
        
        
        std::cout << "[Q28]" << std::endl;
        std::cout << "> Double d;" << std::endl;
        Double d4;
        std::cout << "> DoublePtr p = &d;" << std::endl;
        DoublePtr p4 = &d4;
        std::cout << "> *p = 5.4;" << std::endl;
        *p4 = 5.4;
        std::cout << "> *p" << std::endl << *p4 << std::endl;
        //*p4;
    }
    if(test_DoublePtrRefMatrices){
        std::cout << std::endl << "// Test avec des matrices" << std::endl;
        std::cout << "> Matrix A = Matrix();" << std::endl;
        Matrix A = Matrix();
        std::cout << "// init" << std::endl;
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                std::cout << "> A(i,j) = i+j;" << "//i,j:"<< i << "," << j << ":" << i+j<<std::endl;
                A(i,j) = i+j;
                std::cout << A(i,j)<<std::endl;
            }
        }
        std::cout << "A:" << std::endl;
        A.print();
        //    std::cout << "---test" << std::endl;
        //    A(0,0)=0;
        //    A(1,0)=1;
        //    A(0,1)=2;
        //    A(1,1)=3;
        //    std::cout << A(0,0) << std::endl;
        //    std::cout << A(1,0) << std::endl;
        //    std::cout << A(0,1) << std::endl;
        //    std::cout << A(1,1) << std::endl;
    }
    if(test_mult){
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
                B(i,j) = j+2*i;
            }
        }
        std::cout << "> AB = A*B;" << std::endl;
        AB = A*B;
        
        if(print_matrixes){
            std::cout << "A:" << std::endl;
            A.print();
            std::cout << "B:" << std::endl;
            B.print();
            std::cout << "A*B:" << std::endl;
            AB.print();
        }
        DoubleRef::cache.hit_ratio();
    }
    if(test_parcoursDoubleArray){
        std::cout << "[Q37] Parcours d'un tableau de Double" << std::endl;
        
        DoublePtr p = new Double[100];
        for(int i=0;i<100;++i)
            std::cout << *(p+i) << std::endl;
        //delete [] p;
        DoubleRef::cache.hit_ratio();
        // Le hit ration est très mauvais
        // c'est surprenant. Visiblement la mémoire est allouée avec de gros trous
        // pourtant la taille d'un double est 8...
        
        Matrix A = Matrix();
        DoubleRef::cache.hit_ratio();

        
    }
    
    return 0;
};
