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
    
    /*
     *  First part creates a deck and populates it.
     */
    
    cout << "Welcome to Part 5: 'Cards deck/hand' \n";
    cout << "First, begin by generating a deck of cards with randomly assigned troop types." << endl;
    
    Deck myDeck(12);                                                //When reading in from a map file will create a deck of equal size
    myDeck.populateDeckTest();                                      //This method populates the deck from a given list for demo purposes
    cout << "Deck Size: "<<  myDeck.getNumberOfCountries() << endl; //For Demo will confirm how many cards are in the deck
    
    
    /*
     *  Second part creates a empty hand for player 1, then uses the draw method to fill it with cards.
     *  Will start by drawing three cards and displaying the hand, then draw the last three cards so the hand will be full.
     *  Will draw one extra after to show that it is at max because you need to exchange when you're at 5 or 6 cards
     */
    cout << endl << "Creating empty hand..."<<endl;
    Hand myHand(1);
    
    cout << "Drawing 3 cards from the deck..." <<endl;
    myDeck.draw(&myHand);
    myDeck.draw(&myHand);
    myDeck.draw(&myHand);
    myHand.printHand();
    cout << "Deck Size: "<<  myDeck.getNumberOfCountries() << endl << endl;;
    
    cout << "Drawing 3 more cards from the deck..." <<endl;
    myDeck.draw(&myHand);
    myDeck.draw(&myHand);
    myDeck.draw(&myHand);
    myHand.printHand();
    cout << "Deck Size: "<<  myDeck.getNumberOfCountries() << endl << endl;

    
    myHand.exchange();
    myHand.exchange();
    myHand.printHand();
    
    
    return 0;
    
    

    
    
    
    
 
    
    
}
