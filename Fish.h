/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fish.h
 * Author: Chris Frey
 *
 * Created on February 11, 2018, 8:21 PM
 */

#ifndef FISH_H
#define FISH_H

#include "Pet.h"
#include <string>
#include <iostream>
#include <iomanip>

class Fish : public Pet{
protected:
    std::string m_enviro = "";

public:
     // Default Constructor
    Fish() : Pet(){}
    
    // Constructor
    Fish(std::string name, std::string type, double price, unsigned int weight, 
            std::string enviro)
    : Pet(name,type,price,weight){
        m_enviro = enviro;
    }
    
    // Destructor
    virtual ~Fish(){}
    
    // Copy constructor
    Fish(const Fish& fsh) 
    : Pet(fsh){
        if (this != &fsh){
            m_enviro = fsh.m_enviro;
        }
    }
    
    // Assignment operator
    Fish& operator=(const Fish& fsh){
        if (this != &fsh){
            this->Pet::operator=(fsh);
            m_enviro = fsh.m_enviro;
        }
        return *this;
    }
    
    std::string GetEnviro() const {
        return m_enviro;
    }
    
    void SetEnviro(std::string input){
        m_enviro = input;
    }
    
    virtual void print() const {
        cout << std::fixed << std::setprecision(2);
        std::cout << std::boolalpha;
        std::cout << "Name: " << m_name << "  ";
        std::cout << "Type: " << m_type << "  ";
        std::cout << "Weight: " << m_weight << "  ";
        std::cout << "Price: " << m_price << "  ";
        // Special trait
        std::cout << "Enviroment: " << m_enviro << "  " << std::endl;
    }
};

#endif /* FISH_H */

