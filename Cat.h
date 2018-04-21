/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cat.h
 * Author: Chris Frey
 *
 * Created on February 11, 2018, 8:21 PM
 */

#ifndef CAT_H
#define CAT_H

#include "Pet.h"
#include <string>
#include <iostream>
#include <iomanip>


class Cat : public Pet{
protected:
    bool m_fluffy = false;

public:
     // Default Constructor
    Cat() : Pet(){}
    
    // Constructor
    Cat(std::string name, std::string type, double price, unsigned int weight, bool fluffy)
    : Pet(name,type,price,weight,"Cat"){
        m_fluffy = fluffy;
    }
    
    // Destructor
    virtual ~Cat(){}
    
    // Copy constructor
    Cat(const Cat& Ct) 
    : Pet(Ct){
        if (this != &Ct){
            m_fluffy = Ct.m_fluffy;
        }
    }
    
    // Assignment operator
    Cat& operator=(const Cat& Ct){
        if (this != &Ct){
            this->Pet::operator=(Ct);
            m_fluffy = Ct.m_fluffy;
        }
        return *this;
    }


    bool GetFluffy() const {
        return m_fluffy;
    }
    
    void SetFluffy(bool input){
        m_fluffy = input;
    }
    
    virtual void print() const {
        cout << std::fixed << std::setprecision(2);
        std::cout << std::boolalpha;
        std::cout << "Name: " << m_name << "  ";
        std::cout << "Type: " << m_type << "  ";
        std::cout << "Weight: " << m_weight << "  ";
        std::cout << "Price: " << m_price << "  ";
        // Special trait
        std::cout << "Fluffy: " << m_fluffy << "  " << std::endl;
    }
};


#endif /* CAT_H */

