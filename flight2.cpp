#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){

   fstream file; 
   string filename; 
   filename = "Flights.txt"; 
  
    // opening file 
    file.open(filename.c_str()); 

   if (file.is_open()){   //checking whether the file is open
      string tp;
      while(getline(file, tp)){ //read data from file object and put it into string.
         cout << tp << "\n"; //print the data of the string
      }
      file.close(); //close the file object.
   }
}