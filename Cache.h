//
//  Cache.h
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 06/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#ifndef __projetInfo_AFMC__Cache__
#define __projetInfo_AFMC__Cache__

#include <iostream>

//   Adresse P:
//   ---------nnnnnnn---- : line number 0 to 2^n-1
//   ----------------wwww :
//   ----------------0000 : tag
//   ----------------**** : les adresses dedans st cachées
//   fort          faible


// CacheLigne:
// double[2^w]   |  tag   |   valid

//   Cache
//     ||
//     \/
// |-------------| tag valid   <- ligne0
// |-------------| tag valid   <- ligne1
// |-------------| tag valid   <- ligne2
//      ....          ....
// |-------------| tag valid   <- ligne 2^n-1



class CacheLine{
    friend class Cache;
  public:
    CacheLine();
    ~CacheLine();
    bool valid=false;
    uintptr_t tag;
    
    static uintptr_t get_tag(double* adresse);
    static uintptr_t get_offset(double* adresse); // should be large enough
    void load(double* adress);
    double get_case(uintptr_t offset);
    
  private:
    static const unsigned int w=4; // nombre de bits pour l'offset
    static const unsigned int ww=16; // // 2^w
    char* cases; // contient les doubles mis en cache (#2^n)
};


class Cache{
  public:
    Cache();
    ~Cache();
    int lineIndex(double* adress);
    double get(double* adress);
    void set(double* adress);
    void hit_ratio();
  private:
    static const unsigned int n=5;
    static const unsigned int nn=32; // 2^n

    CacheLine* lignes;
    unsigned long int miss=0, hit=0;
};


#endif /* defined(__projetInfo_AFMC__Cache__) */
