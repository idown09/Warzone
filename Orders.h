#pragma once

using namespace std;
#include <iostream>
#include <list>
#include <iterator>

class Order
{
public:

	//Default Constructor
	Order();

	//Copy constructor
	Order(const Order& b);

	//Assignment operator
	Order& operator = (const Order& d2);

	//Validates an order
	virtual bool validate();

	//Executes an order
	virtual void execute();

	friend std::ostream& operator<<(std::ostream& out, const Order& b);

};

class Deploy : public Order {
	int playerID;
	string countryName;
	int countryOwner;
	int units;


public:
	//Overloaded constructor
	Deploy(int thePlayerID, string theCountryName, int theCountryOwner, int theUnits);

	//Copy constructor
	Deploy(const Deploy& d2);

	//Assignment operator
	Deploy& operator = (const Deploy& d2);

	//Validates a deploy order
	bool validate();

	//Executes a deploy order
	void execute();

	friend std::ostream& operator<<(std::ostream& out, const Deploy& b);
};

class Advance : public Order {
	int playerID;
	string countryName;
	int countryOwner;
	int units;
	int attCountryOwner;
	string attCountryName;
	int attUnits;

public:
	//Overloaded constructor
	Advance(int thePlayerID, string theCountryName, int theCountryOwner, int theUnits, int theAttCountryOwner, string theAttCountryName, int theAttUnits);

	//Copy constructor
	Advance(const Advance& b);

	//Assignment operator
	Advance& operator = (const Advance& b);

	//Validates an advance order
	bool validate();

	//Executes an advance order
	void execute();

	friend std::ostream& operator<<(std::ostream& out, const Advance& b);
};

class Bomb : public Order {
	int playerID;
	int countryOwner;
	string countryName;
	int attCountryOwner;
	string attCountryName;

public:
	//Overloaded constructor
	Bomb(int thePlayerID, string theCountryName, int theCountryOwner, int theAttCountryOwner, string theAttCountryName);

	//Copy constructor
	Bomb(const Bomb& b);

	//Assignment operator
	Bomb& operator = (const Bomb& b);

	//Validates a bomb order
	bool validate();

	//Executes a bomb order
	void execute();

	friend std::ostream& operator<<(std::ostream& out, const Bomb& b);
};

class Blockade : public Order {
	int playerID;
	string countryName;
	int countryOwner;
	int units;


public:
	//Overloaded constructor
	Blockade(int thePlayerID, string theCountryName, int theCountryOwner, int theUnits);

	//Copy constructor
	Blockade(const Blockade& b);

	//Assignment operator
	Blockade& operator = (const Blockade& b);

	//Validates a blockade order
	bool validate();

	//Executes a blockade order
	void execute();

	friend std::ostream& operator<<(std::ostream& out, const Blockade& b);
};

class Airlift : public Order {
	int playerID;
	string countryName;
	int countryOwner;
	int units;
	int attCountryOwner;
	string attCountryName;
	int attUnits;

public:
	//Overloaded constructor
	Airlift(int thePlayerID, string theCountryName, int theCountryOwner, int theUnits, int theAttCountryOwner, string theAttCountryName, int theAttUnits);

	//Copy constructor
	Airlift(const Airlift& b);

	//Assignment operator
	Airlift& operator = (const Airlift& b);

	//Validates an airlift order
	bool validate();

	//Executes an airlift order
	void execute();

	friend std::ostream& operator<<(std::ostream& out, const Airlift& b);

};

class Negotiate : public Order {
	int playerID;
	int otherPlayer;

public:
	//Overloaded constructor
	Negotiate(int thePlayerID, int theOtherPlayer);

	//Copy constructor
	Negotiate(const Negotiate& b);

	//Assignment operator
	Negotiate& operator = (const Negotiate& b);

	//Validates a negotiate order
	bool validate();

	//Executes a negotiate order
	void execute();
	
	friend std::ostream& operator<<(std::ostream& out, const Negotiate& b);
};

class OrderList {
	list <Order*> orders;

public:
	//Default Constructor
	OrderList();
	
	//Destructor
	~OrderList();

	//Add order to list
	void addOrder(Order* x);

	//Remove order to list
	void removeOrder(Order* x);

	//Swap order x with order y in the list
	void swapOrder(Order* x, Order* y);

	//Move order up or down in the list
	void moveOrder(Order* x, string move);

	//View the list of orders
	void viewOrderList();

	//Execute orders then deletes pointers to objects and clears list
	void executeOrderList();
};
