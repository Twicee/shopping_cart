/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortableByWeight.h
 * Author: Chris Frey
 *
 * Created on February 12, 2018, 9:55 PM
 */

#ifndef PETDATABASESORTABLEBYWEIGHT_H
#define PETDATABASESORTABLEBYWEIGHT_H
#include <vector>

#include "PetDatabaseSortable.h"

class PetDatabaseSortableByWeight : public PetDatabaseSortable{
public:
    // Default Constructor
    PetDatabaseSortableByWeight() : PetDatabaseSortable(){}
    
    // Constructor
    PetDatabaseSortableByWeight(std::vector <Pet*> pets)
    : PetDatabaseSortable(pets){}
    
    // Deconstructor
    virtual ~PetDatabaseSortableByWeight(){}
    
    virtual bool smaller(int i, int j) const{
        if (m_pets[i]->GetWeight() < m_pets[j]->GetWeight())
            return true;
        else
            return false;
    }
       
};

#endif /* PETDATABASESORTABLEBYWEIGHT_H */

