/* 
 * File:   PetDatabasseSearchableByWeight.h
 * Author: shellho1
 *
 * Created on February 13, 2018, 12:12 AM
 */

#ifndef PETDATABASSESEARCHABLEBYWEIGHT_H
#define	PETDATABASSESEARCHABLEBYWEIGHT_H
#include "PetDatabaseSearchable.h"
#include "PetDatabaseSortable.h"
#include "Pet.h"

class PetDatabaseSearchableByWeight : public PetDatabaseSearchable{
protected:
    int m_query;
public:
    // Default Constructor
    PetDatabaseSearchableByWeight() : PetDatabaseSearchable(){}
    
    // Constructor
    PetDatabaseSearchableByWeight(std::vector <Pet*> pets)
    : PetDatabaseSearchable(pets){}

    PetDatabaseSearchableByWeight(PetDatabaseSortable* sortable)
    : PetDatabaseSearchable(sortable){}
    
    // Deconstructor
    virtual ~PetDatabaseSearchableByWeight(){}
    
    // Virtual member functions to match abstract base class
    virtual int compareAt(unsigned int i) const {
        if (m_pets[i]->GetWeight() == m_query)
            return 0;
        else if (m_pets[i]->GetWeight() <= m_query)
            return -1;
        else
            return 1;
    }
    
    void setQuery(unsigned int q){
        m_query = q;
    }
    
};


#endif	/* PETDATABASSESEARCHABLEBYWEIGHT_H */

