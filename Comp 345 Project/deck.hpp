//
//  deck.hpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-11.
//  Copyright © 2018 JJ Davies. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp
#pragma once
#include "card.hpp"
#include "hand.hpp"
#include <random>
using namespace std;

//For demo Deck won't interact with a map since they're all different parts so I'll initialize a smaller deck as a
//proof of concept and comment out the deck constructor that will be use the map in the next assignment
class Deck
{
public:
    Deck();
    Deck(int size);
    long getNumberOfCountries();
    void populateDeckTest();
    void draw(Hand h);
    void printDeck();
    
private:
    vector<Card> deck;
    vector<string> countryNames;
    int numberOfCountries;
};
#endif /* deck_hpp */
