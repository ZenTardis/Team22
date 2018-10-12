//
//  main.cpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-04.
//  Copyright © 2018 JJ Davies. All rights reserved.
//

#include "hand.hpp"
#include "deck.hpp"
#include "card.hpp"


int main(int argc, const char * argv[]) {
    cout << "Welcome to Part 5: 'Cards deck/hand' \n";
    cout << "First start by generating a deck of cards with randomly assigned troop types." << endl;
    
    Deck myDeck(12);
    myDeck.populateDeckTest();
    cout << "Deck Size: "<<  myDeck.getNumberOfCountries() << endl;
    myDeck.printDeck();
    
    cout << "Creating empty hand..."<<endl;
    Hand myHand(1);
    cout << "Print empty hand:" <<  endl;
    myHand.printHand();
    cout << "Drawing 3 cards from the deck..." <<endl;
    myDeck.draw(myHand);
    myDeck.draw(myHand);
    myDeck.draw(myHand);
    myDeck.draw(myHand);
  
    myHand.testHand();
    
    cout << "Print new hand:" <<  endl;
    myHand.printHand();
    
    
    return 0;
    
    

    
    
    
    
 
    
    
}
