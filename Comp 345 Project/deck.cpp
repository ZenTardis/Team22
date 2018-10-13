//
//  deck.cpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-11.
//  Copyright © 2018 JJ Davies. All rights reserved.
//



#include "deck.hpp"
using namespace std;

//For demo Deck won't interact with a map since they're all different parts so I'll initialize a smaller deck as a
//proof of concept and comment out the deck constructor that will be use the map in the next assignment

Deck::Deck(){}
    //Size of deck will come from size of map in the next assignment
    //For this assignment each part is seperate so we'll use a default value
    Deck::Deck(int size)
    {
        
        //int numberOfCountries = size;
        
    }
    
    long Deck::getNumberOfCountries()
    {
        return deck.size(); //changed for testing should //return numberOfCountries;
    }

    void Deck::populateDeckTest()       //Populate Deck will use size given by number of countries
    {
      /*
       //In next part grab the country names from map
       for(int i=0; i < getNumberOfCountries(); i++)
        {
            deck.push_back(Card(countryNames.back(),(i%3 + 1)));
            countryNames.pop_back();
        };
        */
        
         deck.push_back(Card("Alaska",1));
         deck.push_back(Card("Alberta",2));
         deck.push_back(Card("Central America",3));
         deck.push_back(Card("Great Britain",1));
         deck.push_back(Card("Iceland",2));
         deck.push_back(Card("Northern Europe",3));
         deck.push_back(Card("China",1));
         deck.push_back(Card("India",2));
         deck.push_back(Card("Mongolia",3));
         deck.push_back(Card("Argentina",1));
         deck.push_back(Card("Egypt",2));
         deck.push_back(Card("Eastern Australia",3));
         cout << "Deck Populated Successfully!" << endl;
    }
    
    void Deck::draw(Hand* h){
        
        if(deck.empty()){
             cout << "There are no more cards left in the deck." << endl;   //check if there any cards left in a deck
        }
        else if(!(h->maxHand())){
            
                int rando = rand() % deck.size();                               //generate random number to use
                deck[rando].printCard();                                        //Print the cards values on screen for comfirmation
                Card c = deck.at(rando);
                h->addCard(c);                                                   //add chosen card to hand
                deck.erase(deck.begin()+rando);                                 //erase() will resize the vector so there will never be any empty slots
            }
            else
                cout << endl << "No room left in hand." << endl;
        }

    /*
     Build this when we need to load from a map file
     void populateDeck()
     {
     //Pseudo Pseudo Code
     Get numberOfCountries to find size
     Retrieve list of territories to find names
     Initialize the cards with the correct country names and assign random types evenly
     push them into the deck vector
     }
     
     */
    
    void Deck::printDeck()
    {
        deck[0].printCard();
        /*for(int i = 0; i < deck.size(); i++)
         {
         deck[i].printCard();
         };*/
    }
