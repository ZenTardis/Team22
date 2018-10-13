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
    Hand::Hand(int pl)
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
        cards.insert(cards.begin(), Card("Test Country",1));
        length = cards.size();
        cout << length << endl;
        this->addCard(Card("Test Country2",2));
        
    }
    void Hand::printHand()
    {
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
            //cout << "Added 1 card \n";  //Use this for testing if card was added
        }
        else
            cout << "Too many cards in hand.  Maximum of 6 cards in a hand at once." << endl;
    }
    
    bool Hand::maxHand()
        {
            if(this->cards.size() > 6)
                return true;
            else
                return false;
        }
    void Hand::exchange()
    {
        //First step is taking in the cards that they would like to exchange and making sure they are valid inputs
        int firstCard, secondCard, thirdCard;
        cout << endl << "Exchanging Cards for troops.  Here is your hand:" << endl;
        printHand();
        cout << endl << "You will now be prompted to enter the cards you would like to exchange, if you enter an invalid range it will prompt you again.  Please enter card numbers from lowest to highest." <<endl;
        
        cout << "Which cards would you like to exchange? Enter card number for the first card you want to exchange:  ";
        do{
         while(!(cin >> firstCard)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter and integer. " << endl;}
        }while (firstCard>6 || firstCard < 1);
        
        
        cout << "Which cards would you like to exchange? Enter card number for the second card you want to exchange:  ";
        do{
        while(!(cin >> secondCard)){
            cout << "Which cards would you like to exchange? Enter card number for the second card you want to exchange:  ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Please enter and integer. " << endl;}
            
        }while(secondCard>6 || secondCard < 1 || secondCard == firstCard);
        
        cout << "Which cards would you like to exchange? Enter card number for the third card you want to exchange:  ";
        do{
        while(!(cin >> thirdCard)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Please enter and integer. " << endl;
        }
        }while(thirdCard>6 || thirdCard < 1 || thirdCard == secondCard || thirdCard == firstCard);
       
        /*
            Next step is to verify if those selected cards match one of the acceptable exchanges
            Valid exchanges: 111,112,113,122,123,133,222,223,233,333.  They are all in sorted order to cut down on search time
            We take the garrison type as thats what we'll be comparing between the three cards
            Start by sorting them from lowest to highest, then concatinating the results.
       */
        vector<int> numbers;
       
        
         if(cards.size() >= (firstCard))
        {
            numbers.push_back(cards[firstCard - 1].getGarrison());
        }
            else
                numbers.push_back(9);
        if(cards.size() >= (secondCard))
        {
            numbers.push_back(cards[secondCard - 1].getGarrison());
        }else
            numbers.push_back(9);
        if(cards.size() >= (thirdCard))
        {
            numbers.push_back(cards[thirdCard - 1].getGarrison());
        }else
            numbers.push_back(9);
        
        /*
         numbers.push_back(cards[firstCard - 1].getGarrison());
        numbers.push_back(cards[secondCard - 1].getGarrison());
        numbers.push_back(cards[thirdCard - 1].getGarrison());
        sort(numbers.begin(), numbers.end());
        */
        
        int exchanger = numbers.at(0)*100 + numbers.at(1)*10 + numbers.at(2);
        cout << "Exchanges = " << exchanges << " Exchanger = "<<exchanger<<endl; //line for testing
        //check exchanger against all posible acceptable exchanges
        if(exchanger == 111 || exchanger == 112 || exchanger == 113 || exchanger == 122 ||exchanger == 123 || exchanger == 133 || exchanger == 222|| exchanger ==223|| exchanger == 233|| exchanger ==333)
        {
            //check how many exchanges have been made and give player troops correspondingly
            if(exchanges < 6)
            {
                switch(exchanges)
                {
                    case 0: playersHandedOut =4;break;
                    case 1: playersHandedOut =6;break;
                    case 2: playersHandedOut =8;break;
                    case 3: playersHandedOut =10;break;
                    case 4: playersHandedOut =12;break;
                    case 5: playersHandedOut =15;break;
                        
                }
            }
            else
            {
                playersHandedOut = (exchanges - 5)*5 + 15;
            }
            cout <<"Successful exchange!  You received " << playersHandedOut << " troops." << endl;
         
           /*
            *   Now delete cards from hand
            *   Sort into increasing order or else what you're trying to delete will have moved
            *   Check if you've been pointed to an empty slot
            */
            //Sort firstCard, secondCard, thirdCard from smallest to largest
            if(firstCard > secondCard)
            {
                int temp = firstCard;
                firstCard = secondCard;
                secondCard = temp;
            }
            if(secondCard > thirdCard)
            {
                int temp = thirdCard;
                thirdCard = secondCard;
                secondCard = temp;
            }
            if(firstCard > secondCard)
            {
                int temp = firstCard;
                firstCard = secondCard;
                secondCard = temp;
            }
            /*
             if(cards.size() > (thirdCard))
            {
                cards.erase(cards.begin() + thirdCard - 1);
            }
            if(cards.size() > (secondCard))
            {
                cards.erase(cards.begin() + secondCard - 1);
            }
            if(cards.size() > (thirdCard))
            {
                cards.erase(cards.begin() + firstCard - 1);
            }
             */
            
            cards.erase(cards.begin() + thirdCard - 1);
            cards.erase(cards.begin() + secondCard - 1);
            cards.erase(cards.begin() + firstCard - 1);
            exchanges++;
        }
        else
            cout << "Unsuccessful exchange." << endl;
        
    }
        
