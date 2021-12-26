#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "SensorCluster.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int nic) {
   
   unsigned int hashVal;
   hashVal = nic / 100000;
        return hashVal;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int nic) {
   
   unsigned int hashVal;
   hashVal = nic % 100000;
   hashVal = hashVal / 10000;
        return hashVal;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int nic) {
  
   unsigned int hashVal;
   hashVal = nic % 10000;
   hashVal = hashVal / 1000;
   return hashVal;   		
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int nic) {
   
   unsigned int hashVal;
   hashVal = nic % 1000;
   hashVal = hashVal / 100;
   return hashVal;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int nic) {
   
    unsigned int hashVal;
    hashVal = nic % 100;
    hashVal = hashVal / 10;
    return hashVal;
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(unsigned int nic) {
    
    unsigned int hashVal;
    hashVal = nic % 10;
    return hashVal;
}

// Constructor for struct Item
Item::Item(string itemName, unsigned int nic):itemName_(itemName), nic_(nic)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void SensorNIC::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    unsigned int nic;
    while (myfile >> itemName >> nic) {
			if (itemName.size() > 0)
      	addItem(itemName, nic);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void SensorNIC::addItem(string itemName, unsigned int nic) {
  // function that adds the specified NIC to the sensor network (i.e., to all hash tables)
	
  //create item
  Item item = Item(itemName, nic);

  //add to tables
  hT1.insert({nic, item});
  hT2.insert({nic, item});
  hT3.insert({nic, item});
  hT4.insert({nic, item});
  hT5.insert({nic, item});
  hT6.insert({nic, item});
}

bool SensorNIC::removeItem(unsigned int nic) {
  // function that removes the sensor specified by the nic value from the network
  // if sensor is found, then it is removed and the function returns true
  // else returns false
    
 // if we find item, remove ans return true	
 if (hT1.find(nic) != hT1.end()) {
  //erase table 1-6
  hT1.erase(nic);
  hT2.erase(nic);
  hT3.erase(nic);
  hT4.erase(nic);
  hT5.erase(nic);
  hT6.erase(nic);
  
  return true;  
 }
 // if not, return false
 return false; 	
}

unsigned int SensorNIC::bestHashing() {
  // function that decides the best hash function, i.e. the ones among
  // fct1-fct6 that creates the most balanced sensor network for the current
  // set of NIC addresses, i.e. data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance
    
     // vars set to 0	
     unsigned int min, max, balance, htNum = 0;
  
     //1st hash table 1
     min = hT1.bucket_size(0); 
     
     for (unsigned i=0; i<10; ++i) {
    
	if (hT1.bucket_size(i) < min){
           min = hT1.bucket_size(i);
        }
    
	if (hT1.bucket_size(i) > max){
           max = hT1.bucket_size(i);
        }
	
     }
  
     balance = max - min;
     htNum = 1;
     // end hash table 1
     
      
     //2nd hash table 2
     min = hT2.bucket_size(0);
     max = 0;
     
     for (unsigned i=0; i<10; ++i) {
    
	if (hT2.bucket_size(i) < min){
            min = hT2.bucket_size(i);
        }
    
	if (hT2.bucket_size(i) > max){
            max = hT2.bucket_size(i);
        }
	
     }
    
     if (balance > (max-min) ) {
     
       balance = max - min;
       htNum = 2;
     }
     // end hash table 2
   
     //begin hash table 3
     min = hT3.bucket_size(0);
     max = 0;
    
     for (unsigned i=0; i<10; ++i) {

        if (hT3.bucket_size(i) < min){
            min = hT3.bucket_size(i);
        }
    
        if (hT3.bucket_size(i) > max){
            max = hT3.bucket_size(i);
        }

     }

      if (balance > (max-min) ) {

       balance = max - min;
       htNum = 3;
     }

    //end hash table 3
   
    //begin hash table 4
     min = hT4.bucket_size(0);
     max = 0;

     for (unsigned i=0; i<10; ++i) {

        if (hT4.bucket_size(i) < min){
            min = hT4.bucket_size(i);
        }

        if (hT4.bucket_size(i) > max){
            max = hT4.bucket_size(i);
        }

     }

      if (balance > (max-min) ) {

       balance = max - min;
       htNum = 4;
     }
    // end hash table 4
    
    //begin hash table 5
     min = hT5.bucket_size(0);
     max = 0;

     for (unsigned i=0; i<10; ++i) {

        if (hT5.bucket_size(i) < min){
            min = hT5.bucket_size(i);
        }

        if (hT5.bucket_size(i) > max){
            max = hT5.bucket_size(i);
        }

     }

      if (balance > (max-min) ) {

       balance = max - min;
       htNum = 5;
     }
    // end hash table 5
    
    //begin hash table 6
     min = hT6.bucket_size(0);
     max = 0;

     for (unsigned i=0; i<10; ++i) {

        if (hT6.bucket_size(i) < min){
            min = hT6.bucket_size(i);
        }

        if (hT6.bucket_size(i) > max){
            max = hT6.bucket_size(i);
        }

     }

      if (balance > (max-min) ) {

       balance = max - min;
       htNum = 6;
     }
    // end hash table 6

    return htNum;

    
}

// ALREADY COMPLETED
size_t SensorNIC::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
