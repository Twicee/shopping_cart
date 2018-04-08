/* 
 * File:   BinarySearch.h
 * Author: shellho1
 *
 * Created on February 13, 2018, 12:10 AM
 */

#ifndef BINARYSEARCH_H
#define	BINARYSEARCH_H

#include "SearchableVector.h"

class BinarySearch{
public:
    int search(SearchableVector* ptr){
        int right = (ptr->getSize() - 1);
        int left = 0;
        while (left <= right){
            int middle = (left+right)/2;
            int result = ptr->compareAt(middle);
            if (result == 0)
                return middle;
            else if (result == 1)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
};
#endif	/* BINARYSEARCH_H */

