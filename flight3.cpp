#include <iostream>
#include <fstream>
#include<string.h>
#include <bits/stdc++.h> 

using namespace std;

class flight {
    public: 

    string flight_num;
    string dep_datetime;
    string dep_airport;
    string arri_airport;
    
    public:
    flight(string a,string b,string c,string d){
        flight_num=a;
        dep_datetime=b;
        dep_airport=c;
        arri_airport=d;
    }
};


void splitString(string str) 
{ 
    // Used to split string around spaces. 
    istringstream ss(str); 
  
    // Traverse through all words 
    do { 
        // Read a word 
        string word; 
        ss >> word; 
  
        // Print the read word 
        cout << word << endl; 
  
        // While there is more to read 
    } while (ss); 
} 


int main()
{
    ifstream inFile;
    string statement[100];
     

    // open the file stream
    inFile.open(".\\Flights.txt");

    // check if opening a file failed
    if (inFile.fail()) {
        cerr << "Error opeing a file" << endl;
        inFile.close();
        exit(1);
    }

    int count1=0;
    int numberofplane=0;
    string line;
    
    while (getline(inFile, line))
    {
        // cout << line << endl;

        if(line==""){
            numberofplane++;
        }
        
        statement[count1]=line;
        count1++;

    }

    flight *flightOb[numberofplane];  // Object array
    int i=0;
    //cout << "count1 is :" << count1 << endl;
    
    //  flight flightOb1[numberofplane];
    int j=0;
    for(int i = 0 ; i<numberofplane ; i++){
        //cout << "value :" << statement[i] << endl;
        string fid=statement[j];          //  flight number
        string f_datetime=statement[j+1]; //  departure date and time
        string f_dep=statement[j+2];      //  departure airport code
        string f_arri=statement[j+3];     //  arrival airport code
        j=j+4;
        //cout << "c****** :" << fid << endl;
        // cout << "c****** :" << f_datetime << endl;
        // cout << "c****** :" << f_dep << endl;
        // cout << "c****** :" << f_arri << endl;

        //flight flightOb1(fid, f_datetime, f_dep, f_arri);
        flightOb[i] =new  flight(fid, f_datetime, f_dep, f_arri);

        cout << flightOb[i]->flight_num << endl;
        cout << flightOb[i]->dep_datetime << endl;
        cout << flightOb[i]->dep_airport << endl;
        cout << flightOb[i]->arri_airport << endl;

        while(statement[j]!=""){
            string str = statement[j]; 
            splitString(str);
            // int row=
            // classs
            // 
            j++;
        }

       j++;

    }
   

    // close the file stream
    inFile.close();
}