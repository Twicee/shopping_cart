/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.h
 * Author: Chris Frey
 *
 * Created on February 12, 2018, 8:16 PM
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "SortableVector.h"

class BubbleSort{
public:
    virtual bool needSwap(SortableVector* sv, int i, int j) const =0;

    void sort(SortableVector* sortableVector){
        bool sorted = false;
        int n=sortableVector->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(needSwap(sortableVector,i-1,i))
                {
                    sortableVector->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
    }
};

#endif /* BUBBLESORT_H */

