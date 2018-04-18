/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dog.h
 * Author: Chris Frey
 *
 * Created on February 11, 2018, 8:07 PM
 */

#ifndef DOG_H
#define DOG_H

#include "Pet.h"
#include <string>
#include <iostream>
#include <iomanip>


class Dog : public Pet{
protected:
    std::string m_breed = "";

public:
    // Default Constructor
    Dog() : Pet(){}
    
    // Constructor
    Dog(std::string name, std::string type, double price, unsigned int weight, 
            std::string breed)
    : Pet(name,type,price,weight,"Dog"){
        m_breed = breed;
    }
    
    // Destructor
    virtual ~Dog(){}
    
    // Copy constructor
    Dog(const Dog& dg) 
    : Pet(dg){
        if (this != &dg){
            m_breed = dg.m_breed;
        }
    }
    
    // Assignment operator
    Dog& operator=(const Dog& dg){
        if (this != &dg){
            this->Pet::operator=(dg);
            m_breed = dg.m_breed;
        }
        return *this;
    }

    virtual void Accept(Visitor *v){
        v->VisitDog(this);
    }

    std::string GetBreed() const {
        return m_breed;
    }
    
    void SetBreed(std::string input){
        m_breed = input;
    }
    
    virtual void print() const {
        cout << std::fixed << std::setprecision(2);
        std::cout << std::boolalpha;
        std::cout << "Name: " << m_name << "  ";
        std::cout << "Type: " << m_type << "  ";
        std::cout << "Weight: " << m_weight << "  ";
        std::cout << "Price: " << m_price << "  ";
        // Special trait
        std::cout << "Breed: " << m_breed << "  " << std::endl;
    }
};


#endif /* DOG_H */

