#ifndef VISITOR_H
#define VISITOR_H

class Pet;
class PetDatabase;
class PetDatabaseSortableByName;
class PetDatabaseSortableByPrice;


class Visitor {
public:
    virtual void VisitPet(Pet*)=0;
    virtual void VisitPetDatabase(PetDatabase*)=0;
};
#endif // VISITOR_H
