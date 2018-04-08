/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortDecreasing.h
 * Author: Chris Frey
 *
 * Created on February 12, 2018, 8:22 PM
 */

#ifndef BUBBLESORTDECREASING_H
#define BUBBLESORTDECREASING_H

#include "BubbleSort.h"

class BubbleSortDecreasing : public BubbleSort{
public:
    virtual bool needSwap(SortableVector* sv, int i, int j) const{
        if (sv->smaller(i,j))
            return true;
        else
            return false;
    }
};


#endif /* BUBBLESORTDECREASING_H */

