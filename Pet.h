/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pet.h
 * Author: Chris Frey
 *
 * Created on February 11, 2018, 7:54 PM
 */

#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>
using namespace std;

class Pet{
protected:
    std::string m_name = "";
    std::string m_type = "";
    unsigned int m_weight = 0;
    double m_price = 0;
            
public:
    // Default Constructor
    Pet(){}
    
    // Constructor
    Pet(std::string name, std::string type, double price, unsigned int weight){
        m_name = name;
        m_type = type;
        m_weight = weight;
        m_price = price;
    }
    
    // Destructor
    virtual ~Pet(){}
    
    // Copy constructor
    Pet(const Pet& p){
        if (this != &p){
            m_name = p.m_name;
            m_type = p.m_type;
            m_weight = p.m_weight;
            m_price = p.m_price;
        }
    }
    
    // Assignment operator
    Pet& operator=(const Pet& p){
        if (this != &p){
            m_name = p.m_name;
            m_type = p.m_type;
            m_weight = p.m_weight;
            m_price = p.m_price;
        }
        return *this;
    }
    
    // Getters
    std::string GetName() const{
        return m_name;
    }
    std::string GetType() const{
        return m_type;
    }
    unsigned int GetWeight() const{
        return m_weight;
    }
    double GetPrice() const{
        return m_price;
    }
    
    // Setters
    void SetName(std::string in_name){
        m_name = in_name;
    }
    void SetType(std::string in_type){
        m_type = in_type;
    }
    void SetWeight(unsigned int in_weight){
        m_weight = in_weight;
    }
    void SetPrice(double in_price){
        m_price = in_price;
    }
    
    virtual void print() const {}
    
    
};


#endif /* PET_H */

