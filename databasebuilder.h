#ifndef DATABASEBUILDER_H
#define DATABASEBUILDER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Bird.h"
#include "PetDatabase.h"
#include "PetDatabaseSortableByName.h"
#include "builder.h"
#include "BubbleSortIncreasing.h"

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
        std::string modifier = "Diurnal ";
        bool special = false;
        if (segments[5]=="true"){
            modifier = "Nocturnal ";
            special = true;
        }
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Bird* birdPet = new Bird(segments[1],(modifier + segments[2]),price,weight,special);
        petVector.push_back(birdPet);

    }

    virtual void addCat(string traits){
        istringstream ss(traits);
        string token = "";
        vector<string> segments;
        while (getline(ss,token,',')){
            segments.push_back(token);
        }
        std::string modifier = "";
        bool special = false;
        if (segments[5]=="true"){
            modifier = "Fluffy ";
            special = true;
        }
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Cat* catPet = new Cat(segments[1],(modifier + segments[2]),price,weight,special);
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
        Dog* dogPet = new Dog(segments[1],segments[2],price,weight,segments[5]);
        petVector.push_back(dogPet);
    }

    virtual void addFish(string traits){
        istringstream ss(traits);
        string token = "";
        vector<string> segments;
        while (getline(ss,token,',')){
            segments.push_back(token);
        }
        std::string modifier = (segments[5] + " ");
        double price = stod(segments[4]);
        unsigned int weight = stoi(segments[3]);
        Fish* fishPet = new Fish(segments[1],(modifier + segments[2]),price,weight,segments[5]);
        petVector.push_back(fishPet);
    }

    virtual PetDatabaseSortableByName* getDatabase(){
        PetDatabaseSortableByName* petDatabaseSortableByName = new PetDatabaseSortableByName(petVector);
        BubbleSortIncreasing bs;
        bs.sort(petDatabaseSortableByName);
        return petDatabaseSortableByName;
    }
};
#endif // DATABASEBUILDER_H
