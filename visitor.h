#ifndef VISITOR_H
#define VISITOR_H

class Bird;
class Cat;
class Dog;
class Fish;
class PetDatabaseSortableByName;

class Visitor {
public:
    virtual void VisitBird(Bird*)=0;
    virtual void VisitCat(Cat*)=0;
    virtual void VisitDog(Dog*)=0;
    virtual void VisitFish(Fish*)=0;
    virtual void VisitPetDatabaseSortableByName(PetDatabaseSortableByName*)=0;
};
#endif // VISITOR_H
