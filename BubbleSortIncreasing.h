/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortIncreasing.h
 * Author: Chris Frey
 *
 * Created on February 12, 2018, 8:22 PM
 */

#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H
#include "BubbleSort.h"

class BubbleSortIncreasing : public BubbleSort{
public:
    virtual bool needSwap(SortableVector* sv, int i, int j) const{
        if (sv->smaller(i,j))
            return false;
        else
            return true;
    }
};


#endif /* BUBBLESORTINCREASING_H */

