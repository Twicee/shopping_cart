/* 
 * File:   PetDatabaseSortableByType.h
 * Author: shellho1
 *
 * Created on February 12, 2018, 11:28 PM
 */

#ifndef PETDATABASESORTABLEBYTYPE_H
#define	PETDATABASESORTABLEBYTYPE_H
#include <vector>

#include "PetDatabaseSortable.h"

class PetDatabaseSortableByType : public PetDatabaseSortable{
public:
    // Default Constructor
    PetDatabaseSortableByType() : PetDatabaseSortable(){}
    
    // Constructor
    PetDatabaseSortableByType(std::vector <Pet*> pets)
    : PetDatabaseSortable(pets){}
    
    // Deconstructor
    virtual ~PetDatabaseSortableByType(){}
    
    virtual bool smaller(int i, int j) const{
        if (m_pets[i]->GetType() < m_pets[j]->GetType())
            return true;
        else
            return false;
    }
       
};


#endif	/* PETDATABASESORTABLEBYTYPE_H */

