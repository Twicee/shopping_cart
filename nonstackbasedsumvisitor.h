#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H

#include "Bird.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "PetDatabaseSortableByName.h"

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

    virtual void VisitBird(Bird* bird){
        sum+=bird->GetPrice();
    }

    virtual void VisitCat(Cat* cat){
        sum+=cat->GetPrice();
    }

    virtual void VisitDog(Dog* dog){
        sum+=dog->GetPrice();
    }

    virtual void VisitFish(Fish* fish){
        sum+=fish->GetPrice();
    }

    virtual void VisitPetDatabaseSortableByName(PetDatabaseSortableByName* database){
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
