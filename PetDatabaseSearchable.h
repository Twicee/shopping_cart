/* 
 * File:   PetDatabaseSearchable.h
 * Author: shellho1
 *
 * Created on February 13, 2018, 12:17 AM
 */

#ifndef PETDATABASESEARCHABLE_H
#define	PETDATABASESEARCHABLE_H

#include "PetDatabase.h"
#include "SearchableVector.h"
#include "PetDatabaseSortable.h"

class PetDatabaseSearchable : public PetDatabase, public SearchableVector{
public:
    // Default Constructor
    PetDatabaseSearchable(){}
    
    // Constructor
    PetDatabaseSearchable(std::vector<Pet*> pets) : PetDatabase(pets){}
    
    PetDatabaseSearchable(PetDatabaseSortable* sortable) : PetDatabase(sortable){};
      
    // Deconstructor
    virtual ~PetDatabaseSearchable(){}
    
    virtual unsigned int getSize() const{
        return m_pets.size();
    };
    

};

#endif	/* PETDATABASESEARCHABLE_H */

