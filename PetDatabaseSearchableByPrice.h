/* 
 * File:   PetDatabaseSearchableByPrice.h
 * Author: shellho1
 *
 * Created on February 13, 2018, 12:11 AM
 */

#ifndef PETDATABASESEARCHABLEBYPRICE_H
#define	PETDATABASESEARCHABLEBYPRICE_H
#include "PetDatabaseSearchable.h"
#include "PetDatabaseSortable.h"
#include "Pet.h"

class PetDatabaseSearchableByPrice : public PetDatabaseSearchable{
protected:
    double m_query;
public:
    // Default Constructor
    PetDatabaseSearchableByPrice() : PetDatabaseSearchable(){}
    
    // Constructor
    PetDatabaseSearchableByPrice(std::vector <Pet*> pets)
    : PetDatabaseSearchable(pets){}
    
    PetDatabaseSearchableByPrice(PetDatabaseSortable* sortable)
    : PetDatabaseSearchable(sortable){}
    
    // Deconstructor
    virtual ~PetDatabaseSearchableByPrice(){}
    
    // Virtual member functions to match abstract base class
    virtual int compareAt(unsigned int i) const {
        if (m_pets[i]->GetPrice() == m_query)
            return 0;
        else if (m_pets[i]->GetPrice() <= m_query)
            return -1;
        else
            return 1;
    }
    
    void setQuery(double q){
        m_query = q;
    }
    
};

#endif	/* PETDATABASESEARCHABLEBYPRICE_H */

