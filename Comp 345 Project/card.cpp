//
//  card.cpp
//  Comp 345 Project
//
//  Created by JJ Davies on 2018-10-10.
//  Copyright © 2018 JJ Davies. All rights reserved.
//


#include "card.hpp"
using namespace std;


    /*
     Card types:
     1 = Infantry
     2 = Calvary
     3 = Artillery
     */
    Card::Card(){}

Card::Card(string Name, int type):country(Name),garrison(type)
    {
       //this->country = Name;
       // int garrison = type;
       // string garrisonString;
        //Verify that garisson is one of the three acceptable types
        if(garrison < 1 || garrison > 3)
        {
            do
            {
                cout << "Invalid Garrison type entered.  Please enter a valid garrison type between 1 and 3: ";
                cin >> garrison;
                
            }while (garrison < 1 || garrison > 3);
        };
        
        if(garrison == 1)
            garrisonString = "Infantry";
        if(garrison == 2)
            garrisonString = "Calvary";
        if(garrison == 3)
            garrisonString = "Artillery";
        cout << "New Card Created Successfully:  " << country << " of type: " << garrisonString << "." << endl;
    };
    
    string Card::getCountry() const{
        return country;
    }
    
    string Card::getGarrisonString() const{
        return garrisonString;
    }
    
    void Card::setCountry(string name){
        country = name;
    }
    
    void Card::setGarrisonString(string gar){
        garrisonString = gar;
    }
    
    int Card::getGarrison()
    {
        return garrison;
    }
    void Card::printCard(){
        cout << "Card: " << getCountry() << " of type: " << getGarrisonString() <<"." << endl;
    }
    

