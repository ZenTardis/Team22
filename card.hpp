//
//  card.hpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-10.
//  Copyright © 2018 JJ Davies. All rights reserved.
//

#ifndef card_hpp
#define card_hpp
#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Card
{
public:
    /*
     Card types:
     1 = Infantry
     2 = Calvary
     3 = Artillery
     */
    Card();
    Card(string Name, int type);
    string getCountry() const;
    string getGarrisonString() const;
    void setCountry(string name);
    void setGarrisonString(string gar);
    int getGarrison();
    void printCard();
    
    
private:
    int garrison;
    string country;
    string garrisonString;
    
};
#endif /* card_hpp */
