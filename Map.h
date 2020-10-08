//
// Created by Claudia on 2020-10-07.
//

#ifndef WARZONE_MAP_H
#define WARZONE_MAP_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class Continent{
public:
    //constructor
    Continent(string pos, string continentsString);

    //attributes
    string name;
    string id;                            // node number

    //methods
    friend ostream& operator<<(ostream &os, const  Continent& n);
};

class Territory{
public:
    //constructor
    explicit Territory(string territoryString, string borderString);

    //attributes
    string name;
    string id;                             // node number

    //methods
    string getContinentID();
    vector<string> getAdjacentNodes();
    bool isAdjacentNode(string _node);
    int getArmies();
    void setArmiesNumber(int amount);
    Player getOwner();
    void setOwner(Player _owner);
    friend ostream& operator<<(ostream &os, const  Territory& n);

private:
    //attributes
    string continentID;
    vector<string> adjacent;                // adjacent nodes
    int armiesNumber;
    Player owner;
};


class Map{
public:
    //constructor
    Map(string _name, vector<string> mapData);

    //attributes
    string name;

    //methods
    bool validate();                        //  whether the map contains all necessary info
    vector<Territory> getTerritories();
    vector<Continent> getContinents();
    Territory getTerritoryById(string territoryID);
    vector<Territory> getAdjacentTerritories(string territoryID);
    friend ostream& operator<<(ostream &os, const  Map& n);

private:
    //attributes
    vector<Territory> territories;
    vector<Continent> continents;

    //methods
    void setTerritories(vector<string> _territoriesData, vector<string> _bordersData);
    void setContinents(vector<string> _continentsData);

};

#endif //WARZONE_MAP_H