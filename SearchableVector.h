/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SearchableVector.h
 * Author: Chris Frey
 *
 * Created on April 8, 2018, 4:07 PM
 */

#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

class SearchableVector{
public:
    virtual unsigned int getSize() const =0;
    virtual int compareAt(unsigned int) const =0;
};

#endif /* SEARCHABLEVECTOR_H */

