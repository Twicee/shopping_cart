#ifndef PETDATABUILDER_H
#define PETDATABUILDER_H

#include "builder.h"
#include <vector>
#include "PetDatabaseSearchableByName.h"
#include "Fish.h"
#include "Bird.h"
#include "Dog.h"
#include "Cat.h"

class PetDataBuilder : public Builder{
protected:
    vector<Pet*>* m_petVect;
public:
    virtual void buildThis(vector<Pet*>* petVect){
        m_petVect = petVect;
    }

    virtual void add(std::vector<std::string> row){
        m_petVect->push_back(makePet(row));
    }

    Pet* makePet(std::vector<std::string> row){
        bool val = 0;
        if (row[0] == "Bird"){
            if (row[6] == "FALSE")
                val = false;
            else
                val = true;
            Bird bird(row[1],row[0],std::stod(row[4]),std::stod(row[3]),val);
            return &bird;
        }
        else if (row[0] == "Dog"){
            Dog dog(row[1],row[0],std::stod(row[4]),std::stod(row[3]),row[6]);
            return &dog;
        }
        else if (row[0] == "Fish"){
           Fish fish(row[1],row[0],std::stod(row[4]),std::stod(row[3]),row[6]);
           return &fish;
        }
        else if (row[0] == "Cat"){
            if (row[6] == "FALSE")
                val = false;
            else
                val = true;
            Cat cat(row[1],row[0],std::stod(row[4]),std::stod(row[3]),val);
            return &cat;
        }
    }

};

#endif // PETDATABUILDER_H
