//
//  hand.hpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-10.
//  Copyright © 2018 JJ Davies. All rights reserved.
//

#ifndef hand_hpp
#define hand_hpp
#include "card.hpp"

class Hand
{
public:
    Hand();
    Hand(int pl);
    int getPlayer();
    void printHand();
    void addCard(Card c);
    void exchange();
    void testHand();
    bool maxHand();

private:
    vector<Card> cards;
    int player;
    int exchanges;
    int playersHandedOut;
};

#endif /* hand_hpp */
