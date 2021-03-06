//
//  minOccSorter.hpp
//  myKconf
//
//  Created by David on 27/07/15.
//  Copyright (c) 2015 david. All rights reserved.
//

#ifndef __myKconf__minOccSorter__
#define __myKconf__minOccSorter__

#include <stdio.h>
#include <map>
#include <string>

#include "variableSorter.hpp"

class minOccSorter : public variableSorter {
    
public:
    minOccSorter(const std::map<std::string, int>& occ) : variableSorter(occ) {};
    
    bool operator()(const std::string& a, const std::string& b) {
        int x = occurrences.at(a);
        int y = occurrences.at(b);
        
        return x < y;
    }
    
    void mysort(std::vector<std::string>::iterator beg, std::vector<std::string>::iterator end) {
        std::sort(beg, end, *this);
    }

};
#endif /* defined(__myKconf__minOccSorter__) */
