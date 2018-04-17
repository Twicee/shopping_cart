#ifndef BUILDER_H
#define BUILDER_H
#include <string>
using namespace std;
#include "Pet.h"
#include "PetDatabase.h"
#include "PetDatabaseSortableByName.h"

class Builder {
public:
    virtual void addCat(string)=0;
    virtual void addDog(string)=0;
    virtual void addFish(string)=0;
    virtual void addBird(string)=0;
    virtual vector<Pet*> getDatabase()=0;
};

#endif // BUILDER_H
