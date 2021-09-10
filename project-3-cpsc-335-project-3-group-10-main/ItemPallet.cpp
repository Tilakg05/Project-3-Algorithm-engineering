#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemPallet.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int sku) {
  // TODO: implement this function, then delete the return statement below
	return (sku/100000 % 10);
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return (sku/10000 % 10);
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return (sku/1000 % 10);
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below
	return (sku/100 % 10);
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int sku) {
    // TODO: implement this function, then delete the return statement below
	return (sku/10 % 10);
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int sku) {
    // TODO: implement this function, then delete the return statement below
	return (sku/1 % 10);
}

// Constructor for struct Item
Item::Item(string itemName, unsigned int sku):itemName_(itemName), sku_(sku)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemPallet::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    unsigned int sku;
    while (myfile >> itemName >> sku) {
			if (itemName.size() > 0)
      	addItem(itemName, sku);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemPallet::addItem(string itemName, unsigned int sku) {
  // TO BE COMPLETED
  // function that adds the specified SKU to the pallet (i.e., to all hash tables)
	//declare Item newItem(itemName,sku);
	hT1[itemName,sku];
	hT2[itemName,sku];
	hT3[itemName,sku];
	hT4[itemName,sku];
	hT5[itemName,sku];
	hT6[itemName,sku];

}

bool ItemPallet::removeItem(unsigned int sku) {
   // TODO: implement this function, then delete the return statement below

  // function that removes the pair of glasses specified by the sku from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false

bool found = false;

auto iterate = hT1.begin();
while (iterate != hT1.end())
{
	if (sku == iterate->first)
	{
		found = true;
		break;
	}
	iterate ++;
}
if (found)
{
	hT1.erase(sku);
	hT2.erase(sku);
	hT3.erase(sku);
	hT4.erase(sku);
	hT5.erase(sku);
	hT6.erase(sku);
}
return found;
}

unsigned int ItemPallet::bestHashing() {
  // TODO: implement this function, then delete the return statement below

  // function that decides the best has function, i.e. the ones among
  // fct1-fct6 that creates the most balanced hash table for the current
  // ItemPallet data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/

	// Then, calculate the lowest balance

	//hT1.bucket_size


	CustomHashTable palletList[6] = {hT1, hT2, hT3, hT4, hT5, hT6};
	int max[6] = {-1,-1,-1,-1,-1,-1};
	int min[6] = {-1,-1,-1,-1,-1,-1};
	int balance[6] = {};
	for (int k = 0; k < 6; k++)
	{
		balance [k] = 0;
		for (int i = 0; i < 10; i++)
		{
			int size = palletList[k].bucket_size(i);
			if (max[k] == NULL || size > max[k]) max[k] = size;
			if (min[k] == -1 || size < min[k]) min[k] = size;
		}
		balance[k] = max[k] - min[k];
	}
	int lowest = 0;
	for (int m = 0; m < 6; m++)
	{
		if (balance[m] < balance[lowest]) lowest = m;
	}
		return ++lowest;
	}

// ALREADY COMPLETED
size_t ItemPallet::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");

	return hT1.size();
}


