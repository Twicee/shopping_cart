/* 
 * File:   PetDatabaseSearchablebyType.h
 * Author: shellho1
 *
 * Created on February 13, 2018, 12:11 AM
 */

#ifndef PETDATABASESEARCHABLEBYTYPE_H
#define	PETDATABASESEARCHABLEBYTYPE_H
#include "PetDatabaseSearchable.h"
#include "PetDatabaseSortable.h"
#include "Pet.h"

class PetDatabaseSearchableByType : public PetDatabaseSearchable{
protected:
    string m_query;
public:
    // Default Constructor
    PetDatabaseSearchableByType() : PetDatabaseSearchable(){}
    
    // Constructor
    PetDatabaseSearchableByType(std::vector <Pet*> pets)
    : PetDatabaseSearchable(pets){}
    
    PetDatabaseSearchableByType(PetDatabaseSortable* sortable)
    : PetDatabaseSearchable(sortable){}
    
    // Destructor
    virtual ~PetDatabaseSearchableByType(){}
    
    // Virtual member functions to match abstract base class
    virtual int compareAt(unsigned int i) const {
        if (m_pets[i]->GetType() == m_query)
            return 0;
        else if (m_pets[i]->GetType() <= m_query)
            return -1;
        else
            return 1;
    }
    
    void setQuery(string q){
        m_query = q;
    }
    
};


#endif	/* PETDATABASESEARCHABLEBYTYPE_H */

