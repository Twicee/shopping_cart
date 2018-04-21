#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H

#include "PetDatabaseSortableByName.h"
#include "PetDatabaseSortableByPrice.h"
#include "Pet.h"
#include "PetDatabase.h"

class NonStackBasedSumVisitor: public Visitor{
private:
    NonStackBasedSumVisitor(const NonStackBasedSumVisitor& orig){};
protected:
    double sum;
public:
    NonStackBasedSumVisitor(){
        sum = 0;
    }
    virtual ~NonStackBasedSumVisitor(){};


    virtual void VisitPet(Pet* pet){
        sum+=pet->GetPrice();
    }

    virtual void VisitPetDatabase(PetDatabase* database){
        for (unsigned int i =0; i < database->getSize(); i++){
            database->getPet(i)->Accept(this);
        }
    }

    double getResult(){
        double result = sum;
        sum = 0;
        return result;
    }
};

#endif // NONSTACKBASEDSUMVISITOR_H
