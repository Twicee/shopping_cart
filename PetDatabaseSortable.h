/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortable.h
 * Author: Chris Frey
 *
 * Created on February 12, 2018, 8:19 PM
 */

#ifndef PETDATABASESORTABLE_H
#define PETDATABASESORTABLE_H

#include "PetDatabase.h"
#include "SortableVector.h"

class PetDatabaseSortable : public PetDatabase, public SortableVector{
public:
    // Default Constructor
    PetDatabaseSortable(){}
    
    PetDatabaseSortable(std::vector<Pet*> pets)
    : PetDatabase(pets){} 
    
    virtual ~PetDatabaseSortable(){}
    
    virtual unsigned int getSize() const{
        return m_pets.size();
    }
    // implement it
    virtual void swap(int i, int j){
        Pet* temp = m_pets[i];
        m_pets[i]=m_pets[j];
        m_pets[j]=temp;
    }

};


#endif /* PETDATABASESORTABLE_H */

