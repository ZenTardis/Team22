//
//  hand.cpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-10.
//  Copyright © 2018 JJ Davies. All rights reserved.
//

#include "hand.hpp"
#include <string>


using namespace std;

    Hand::Hand(){}
    Hand::Hand(int pl):cards()
    {
        
    }
    int Hand::getPlayer(){
        return player;
    }
    
    void Hand::testHand()
    {
        long length;
        length = cards.size();
        cout << length << endl;
        
    }
    void Hand::printHand(){
        long int numberofCards = cards.size();
        long int numberofEmpty = 6 - numberofCards;
        int count = 1;
        for(int i = 0; i < numberofCards; i++)
        {
            cout << count << ": ";
            cards[i].printCard();
            count++;
        }
        for(int i = 0; i < numberofEmpty; i++)
        {
            cout << count << ": " << "Empty Slot" << endl;
            count++;
        }
    }
    
    void Hand::addCard(Card c){
        if(cards.size() < 6)
        {
            cards.insert(cards.end(), c);
            cout << "Added 1 card \n";
        }
        else
            cout << "Too many cards in hand.  Maximum of 6 cards in a hand at once.";
    }
    
    
    void Hand::exchange()
    {
        //First step is taking in the cards that they would like to exchange and making sure they are valid inputs
        int firstCard, secondCard, thirdCard;
        cout << "Exchanging Cards for troops:" << endl;
        printHand();
        cout << "You will now be prompted to enter the cards you would like to exchange, if you enter an invalid range it will prompt you again.";
        do{
            cout << "Which cards would you like to exchange? Enter card number for the first card you want to exchange(eg 1, 2, 3,...:  ";
            cin >> firstCard;
        }while(firstCard>6 || firstCard < 1);
        do{
            cout << "Which cards would you like to exchange? Enter card number for the second card you want to exchange(eg 1, 2, 3,...:  ";
            cin >> secondCard;
        }while(secondCard>6 || secondCard < 1);
        do{
            cout << "Which cards would you like to exchange? Enter card number for the third card you want to exchange(eg 1, 2, 3,...:  ";
            cin >> thirdCard;
        }while(thirdCard>6 || thirdCard < 1);
        
        //Next step is to verify if those selected cards match one of the acceptable exchanges
        //Valid exchanges: 111,112,113,123,221,222,223,331,332,333,
        //Start by sorting them from lowest to highest, then concatinating the results.
        vector<int> numbers;
        numbers.push_back(cards[firstCard].getGarrison());
        numbers.push_back(cards[secondCard].getGarrison());
        numbers.push_back(cards[thirdCard].getGarrison());
        sort(numbers.begin(), numbers.end());
        
        int exchanger = numbers.at(0)*100 + numbers.at(1)*10 + numbers.at(2);
        //check exchanger against all posible acceptable exchanges
        if(exchanger == 111 || exchanger == 112 || exchanger == 113 || exchanger == 123 || exchanger == 221 || exchanger == 222|| exchanger ==223|| exchanger ==331|| exchanger ==332|| exchanger ==333)
        {
            //check how many exchanges have been made and give player troops correspondingly
            if(exchanges <6)
            {
                switch(exchanges)
                {
                    case 0: playersHandedOut =4;
                    case 1: playersHandedOut =6;
                    case 2: playersHandedOut =8;
                    case 3: playersHandedOut =10;
                    case 4: playersHandedOut =12;
                    case 5: playersHandedOut =15;
                        
                }
            }
            else
                playersHandedOut = (exchanges - 5)*5 + 15;
            cout <<"Successful exchange!  You received " << playersHandedOut << " troops.";
            exchanges++;
        }
    }
