/* 
 * File:   PetDatabaseSortableByName.h
 * Author: shellho1
 *
 * Created on February 12, 2018, 11:08 PM
 */

#ifndef PETDATABASESORTABLEBYNAME_H
#define	PETDATABASESORTABLEBYNAME_H

#include "PetDatabaseSortable.h"
#include "visitor.h"

class PetDatabaseSortableByName : public PetDatabaseSortable{
public:
    // Default Constructor
    PetDatabaseSortableByName() : PetDatabaseSortable(){}
    
    // Constructor
    PetDatabaseSortableByName(std::vector<Pet*> pets)
    : PetDatabaseSortable(pets){}
    
    // Deconstructor
    virtual ~PetDatabaseSortableByName(){}
   
    virtual bool smaller(int i, int j) const{
        if (m_pets[i]->GetName() < m_pets[j]->GetName())
            return true;
        else
            return false;
    }
    
    virtual void Accept(Visitor* v){
        v->VisitPetDatabaseSortableByName(this);
    }
    
};

#endif	/* PETDATABASESORTABLEBYNAME_H */

