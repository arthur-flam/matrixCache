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
uintptr_t CacheLine::get_tag(double* adress){
    uintptr_t adress_64 = (uintptr_t) adress;
    return adress_64 - adress_64 % 2^w;
}
// Obtention de l'offset
uintptr_t CacheLine::get_offset(double* adress){
    uintptr_t adress_64 = (uintptr_t) adress;
    uintptr_t offset = (uintptr_t) adress_64 % 2^w;
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
double CacheLine::get_case(uintptr_t offset){
    return *((double*) cases+offset); // on s'assure d'avoir le bon type...
    // faudrait un template...
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
    // delete [] lignes;
    // j'ai du l'enlever à cause d'une erreur... je ne devrais pas pourtant !
}

// Index de la ligne pour une adresse donnée
int Cache::lineIndex(double* adress){
    uintptr_t adress_int = (uintptr_t) adress;
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
    uintptr_t offset = lignes[l].get_offset(adress);
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

    
    
    return 0;
};


