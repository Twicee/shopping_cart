#ifndef DATABASEBUILDER_H
#define DATABASEBUILDER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Bird.h"
#include "PetDatabase.h"
#include "PetDatabaseSortableByName.h"
#include "builder.h"

class DatabaseBuilder: public Builder {
protected:
    vector<Pet*> petVector;
public:
    virtual void addBird(string traits){
        istringstream ss(traits);
        string token = "";
        vector<string> segments;
        while (getline(ss,token,',')){
            segments.push_back(token);
        }
        bool special = false;
        if (segments[5]=="true"){
            special = true;
        }
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Bird* birdPet = new Bird(segments[1],segments[2],weight,price,special);
        petVector.push_back(birdPet);

    }

    virtual void addCat(string traits){
        istringstream ss(traits);
        string token = "";
        vector<string> segments;
        while (getline(ss,token,',')){
            segments.push_back(token);
        }
        bool special = false;
        if (segments[5]=="true"){
            special = true;
        }
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Cat* catPet = new Cat(segments[1],segments[2],weight,price,special);
        petVector.push_back(catPet);
    }

    virtual void addDog(string traits){
        istringstream ss(traits);
        string token = "";
        vector<string> segments;
        while (getline(ss,token,',')){
            segments.push_back(token);
        }
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Dog* dogPet = new Dog(segments[1],segments[2],weight,price,segments[5]);
        petVector.push_back(dogPet);
    }

    virtual void addFish(string traits){
        istringstream ss(traits);
        string token = "";
        vector<string> segments;
        while (getline(ss,token,',')){
            segments.push_back(token);
        }
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Fish* fishPet = new Fish(segments[1],segments[2],weight,price,segments[5]);
        petVector.push_back(fishPet);
    }

    virtual vector<Pet*> getDatabase(){
        return this->petVector;
    }
};
#endif // DATABASEBUILDER_H
