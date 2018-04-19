/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortableByPrice.h
 * Author: Chris Frey
 *
 * Created on February 12, 2018, 8:25 PM
 */

#ifndef PETDATABASESORTABLEBYPRICE_H
#define PETDATABASESORTABLEBYPRICE_H
#include <vector>

#include "PetDatabaseSortable.h"
#include "visitor.h"


class PetDatabaseSortableByPrice : public PetDatabaseSortable{
public:
    // Default Constructor
    PetDatabaseSortableByPrice() : PetDatabaseSortable(){}
    
    // Constructor
    PetDatabaseSortableByPrice(std::vector <Pet*> pets)
    : PetDatabaseSortable(pets){}
    
    // Deconstructor
    virtual ~PetDatabaseSortableByPrice(){}
    
    virtual bool smaller(int i, int j) const{
        if (m_pets[i]->GetPrice() < m_pets[j]->GetPrice())
            return true;
        else
            return false;
    }
    
    virtual void Accept(Visitor* v){
        v->VisitPetDatabaseSortableByPrice(this);
    }

};


#endif /* PETDATABASESORTABLEBYPRICE_H */

