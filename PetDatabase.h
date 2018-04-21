/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabase.h
 * Author: Chris Frey
 *
 * Created on April 8, 2018, 3:36 PM
 */

#ifndef PETDATABASE_H
#define PETDATABASE_H

#include <vector>
#include "Pet.h"
#include "visitor.h"

class PetDatabase{
protected:
    std::vector<Pet*> m_pets;
    
public:
    PetDatabase(){}
    
    PetDatabase(std::vector<Pet*> pets){
        m_pets = pets;
    }
    
    PetDatabase(PetDatabase* sortable){
        for(unsigned int i = 0; i < sortable->getSize(); i++){
            AddPet(sortable->getPet(i));
        }
    }
    
    virtual ~PetDatabase(){}
    
    virtual unsigned int getSize() const =0;
    
    Pet* getPet(int index){
        return m_pets[index];
    }
    
    void AddPet(Pet* pet){
        m_pets.push_back(pet);
    }
    
    void DisplayRecords(){
        for (unsigned int i = 0; i < m_pets.size(); i++){
            m_pets[i]->print();
        }
    }

    std::vector<Pet*> returnDatabase(){
        return m_pets;
    }

    // for adding price
    void Accept(Visitor* v){
        v->VisitPetDatabase(this);
    }

    
};

#endif /* PETDATABASE_H */

