/* 
 * File:   PetDatabaseSearchableByName.h
 * Author: shellho1
 *
 * Created on February 13, 2018, 12:10 AM
 */

#ifndef PETDATABASESEARCHABLEBYNAME_H
#define	PETDATABASESEARCHABLEBYNAME_H

#include "PetDatabaseSearchable.h"
#include "PetDatabaseSortable.h"
#include "Pet.h"

class PetDatabaseSearchableByName : public PetDatabaseSearchable{
protected:
    string m_query;
public:
    // Default Constructor
    PetDatabaseSearchableByName() : PetDatabaseSearchable(){}
    
    // Constructor
    PetDatabaseSearchableByName(std::vector<Pet*> pets)
    : PetDatabaseSearchable(pets){}
    
    PetDatabaseSearchableByName(PetDatabaseSortable* sortable)
    : PetDatabaseSearchable(sortable){}
    
    // Destructor
    virtual ~PetDatabaseSearchableByName(){}
    
    // Virtual member functions to match abstract base class
    virtual int compareAt(unsigned int i) const {
        if (m_pets[i]->GetName() == m_query)
            return 0;
        else if (m_pets[i]->GetName() <= m_query)
            return -1;
        else
            return 1;
    }
    
    void setQuery(string q){
        m_query = q;
    }
    
};

#endif	/* PETDATABASESEARCHABLEBYNAME_H */

