//
//  Cache.cpp
//  projetInfo-AFMC
//
//  Created by Arthur Flam on 06/02/2014.
//  Copyright (c) 2014 AFlam. All rights reserved.
//

#include "Cache.h"

// ============================================
// CacheLine
// ============================================

// Contructeur
CacheLine::CacheLine(){
    cases = new int[2^w];
}
// Destructeur: il faut libérer la mémoire allouée sur la pile
CacheLine::~CacheLine(){
    // TODO
    //delete cases;
}

// Obtention du tag corespondant à une adresse
uint64_t CacheLine::get_tag(double* adress){
    uint64_t adress_64 = (uint64_t) adress;
    return adress_64 - adress_64 % 2^w;
}
// Obtention de l'offset
uint16_t CacheLine::get_offset(double* adress){
    uint64_t adress_64 = (uint64_t) adress;
    uint16_t offset = (uint16_t) adress_64 % 2^w;
    // on pourrait - soustraire le tag à l'adresse (autant l'utiliser)
    //             - utiliser une opération bitwise comme >>
    // je ne sais pas quelle approche est la plus rapide...
    return offset;
}

// Chargement en mémoire d'une ligne
void CacheLine::load(double* adress){
    int* start = (int*) get_tag(adress);
    // soyons sûrs de remplir à partir du début d'une ligne
    int nb = 2^w;
    for(int i=0;i<nb;i++){
        cases[i] = *(start+i);
    }
    // effectivement, on n'a pas de certitudes sur la mémoire avant l'adress
    // 
    tag = (uint64_t) start;
    valid=true;
}
double CacheLine::get_case(unsigned int offset){
    return cases[offset];
};



// ============================================
// Cache
// ============================================


// Constructeur du cache
Cache::Cache(){
    lignes = new CacheLine[n];
    int nb_l = 2^n;
    for(int i=0;i<nb_l;i++)
        lignes[i] = CacheLine();
}
// Destructeur pour libérer la mémoire allouée sur la pile
Cache::~Cache(){
    delete [] lignes;
}

// Index de la ligne pour une adresse donnée
int Cache::lineIndex(double* adress){
    uint64_t adress_int = (uint64_t) adress;
    return (adress_int / 2^w) % 2^n ; // hachage
}


// I/O dans le cache
// lecture
double Cache::get(double* adress){
    int l = lineIndex(adress);
    if(lignes[l].valid==0 || lignes[l].tag!=CacheLine::get_tag(adress)){
        set(adress);
        miss+=1;
    } else {
        hit+=1;
    }
    unsigned int offset = lignes[l].get_offset(adress);
    return lignes[l].get_case(offset);
}
// écriture
void Cache::set(double* adress){
    int l = lineIndex(adress);
    lignes[l].load(adress);
}

// Obtention du hit ratio
void Cache::hit_ratio(){
    double ratio;
    if(miss==0) ratio=1.;
    else ratio= hit/ (double) (miss+hit);
    std::cout << "Hits   : " << hit << std::endl;
    std::cout << "Misses : " << miss << std::endl;
    std::cout << "Ratio  : " << ratio << std::endl;
}


int mainGERSF(int argc, const char * argv[]){
    std::cout << "Test du cache" << std::endl;
    double a = 5.;
    double* pa = &a;
    
    std::cout << a << std::endl;
    std::cout << "adress : " << pa << std::endl;
    std::cout << "tag    : " << (double*) CacheLine::get_tag(pa) << std::endl;
    std::cout << "offset : " << CacheLine::get_offset(pa) << std::endl;
    
    Cache cache;
    cache.get(pa);
    cache.get(pa);
    cache.get(pa);
    cache.get(pa);
    
    cache.hit_ratio();
    //std::cout << r << std::endl;

    
    
    return 0;
};


