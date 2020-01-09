#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){

   fstream file; 
   string filename; 
 //  newfile.open("Flights.txt",ios::out);  // open a file to perform write operation using file object
//    if(newfile.is_open()) //checking whether the file is open
//    {
//       newfile<<"Tutorials point \n";   //inserting text
//       newfile.close();    //close the file object
//    }
//    newfile.open("tpoint.txt",ios::in); //open a file to perform read operation using file object

    // filename of the file 
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