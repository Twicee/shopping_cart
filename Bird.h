/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bird.h
 * Author: Chris Frey
 *
 * Created on February 11, 2018, 8:22 PM
 */

#ifndef BIRD_H
#define BIRD_H

#include "Pet.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "visitor.h"

class Bird : public Pet{
protected:
    bool m_nocturn = false;

public:
    // Default Constructor
    Bird() : Pet(){}
    
    // Constructor
    Bird(std::string name, std::string type, double price, unsigned int weight, 
            bool nocturn)
    : Pet(name,type,price,weight,"Bird"){
        m_nocturn = nocturn;
    }
    
    // Destructor
    virtual ~Bird(){}
    
    // Copy constructor
    Bird(const Bird& brd) 
    : Pet(brd){
        if (this != &brd){
            m_nocturn = brd.m_nocturn;
        }
    }
    
    // Assignment operator
    Bird& operator=(const Bird& brd){
        if (this != &brd){
            this->Pet::operator=(brd);
            m_nocturn = brd.m_nocturn;
        }
        return *this;
    }
    
    bool GetNocturnality() const {
        return m_nocturn;
    }
    
    void SetNocturnality(bool input){
        m_nocturn = input;
    }
    
    virtual void print() const {
        std::cout << std::fixed << std::setprecision(2); 
        std::cout << std::boolalpha;
        std::cout << "Name: " << m_name << "  ";
        std::cout << "Type: " << m_type << "  ";
        std::cout << "Weight: " << m_weight << "  ";
        std::cout << "Price: " << m_price << "  ";
        // Special trait
        std::cout << "Nocturnal: " << m_nocturn << "  " << std::endl;
    }
};

#endif /* BIRD_H */

