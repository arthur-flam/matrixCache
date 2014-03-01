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
    cases = new char[ww];
    valid = false;
}
// Destructeur: il faut libérer la mémoire allouée sur la pile
CacheLine::~CacheLine(){
    // TODO
    //delete cases;
}

// Obtention du tag corespondant à une adresse
uintptr_t CacheLine::get_tag(double* adress){
    uintptr_t adress_64 = (uintptr_t) adress;
    //std::cout<< "tag: "<<(adress_64 - adress_64 % ww) << std::endl;
    return adress_64 - adress_64 % ww;
}
// Obtention de l'offset
uintptr_t CacheLine::get_offset(double* adress){
    uintptr_t adress_64 = (uintptr_t) adress;
    uintptr_t offset = (uintptr_t) adress_64 % ww;
    // on pourrait - soustraire le tag à l'adresse (autant l'utiliser)
    //             - utiliser une opération bitwise comme >>
    // je ne sais pas quelle approche est la plus rapide...
    return offset;
}

// Chargement en mémoire d'une ligne
void CacheLine::load(double* adress){
    char* start = (char*) get_tag(adress);
    // soyons sûrs de remplir à partir du début d'une ligne
    for(int i=0;i<ww;i++){
        cases[i] = *(start+i);
    }
    tag = (uintptr_t) start;
    valid=true;
}
double CacheLine::get_case(uintptr_t offset){
    return *((double*) (cases+offset)); // on s'assure d'avoir le bon type...
}
void CacheLine::set_case(uintptr_t offset, double value){
    *((double*) (cases+offset)) = value;
}






// ============================================
// Cache
// ============================================


// Constructeur du cache
Cache::Cache(){
    lignes = new CacheLine[nn];
    for(int i=0;i<nn;i++)
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
    return (adress_int / CacheLine::ww) % nn ; // hachage
}


// I/O dans le cache
// lecture
bool Cache::is_present(double* adress){
    int l = lineIndex(adress);
    return ((lignes[l].valid==true) && (lignes[l].tag==CacheLine::get_tag(adress)));
}
double Cache::get(double* adress){
    if(!is_present(adress)){
        set(adress);
        miss+=1;
    } else {
        hit+=1;
    }
    int l = lineIndex(adress);
    uintptr_t offset = lignes[l].get_offset(adress);
    return lignes[l].get_case(offset);
}
// écriture
void Cache::set(double* adress){
    int l = lineIndex(adress);
    lignes[l].load(adress);
}
void Cache::set_unique(double* adress){
    int l = lineIndex(adress);
    uintptr_t offset = lignes[l].get_offset(adress);
    lignes[l].set_case(offset, *adress);
}
void Cache::write(double* adress){
    if(!is_present(adress)){
        set(adress);
    } else {
        set_unique(adress);
    }
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

// Vider le cache
void Cache::clear(){
    hit=0;
    miss=0;
    for(int i=0;i<nn;i++)
        lignes[i].valid=false;
}



