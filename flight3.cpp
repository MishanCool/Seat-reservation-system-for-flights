#include <iostream>
#include <fstream>
#include<string.h>

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


// void removeDupWord(string str) 
// { 
//    string word = ""; 
//    for (auto x : str) 
//    { 
//        if (x == ' ') 
//        { 
//            cout << word << endl; 
//            word = ""; 
//        } 
//        else
//        { 
//            word = word + x; 
//        } 
//    }  
//    cout << word << endl; 
// } 


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
     flight *flightOb[numberofplane];
    int i=0;
    cout << "count1 is :" << count1 << endl;
    
    //  flight flightOb1[numberofplane];
    int j=0;
    for(int i = 0 ; i<numberofplane ; i++){
        //cout << "value :" << statement[i] << endl;
        string fid=statement[j];          //  flight number
        string f_datetime=statement[j+1]; //  departure date and time
        string f_dep=statement[j+2];      //  departure airport code
        string f_arri=statement[j+3];     //  arrival airport code
        j=j+4;
        cout << "c****** :" << fid << endl;
        // cout << "c****** :" << f_datetime << endl;
        // cout << "c****** :" << f_dep << endl;
        // cout << "c****** :" << f_arri << endl;
        
        //i=i+4;

        //flight flightOb1(fid, f_datetime, f_dep, f_arri);
        flightOb[i] =new  flight(fid, f_datetime, f_dep, f_arri);
        //cout << "c****** :" << f_arri << endl;

        cout << "c###### :" << flightOb[i]->flight_num << endl;
        // cout << "c###### :" << flightOb[i].dep_datetime << endl;
        // cout << "c###### :" << flightOb[i].dep_airport << endl;
        // cout << "c###### :" << flightOb[i].arri_airport << endl;

        // while(statement[i]!=""){
        //     // split
        //     // int row=
        //     // classs
        //     // 
        //     i++;
        // }
        // cout<< flightOb[i].flight_num<<endl;
        // cout<< flightOb[i].dep_datetime<<endl;
        // cout<< flightOb[i].dep_airport<<endl;
        // cout<< flightOb[i].arri_airport<<endl;
        //cout << "c****** :" << flightOb[i].arri_airport << endl;
        // j++;


        while(statement[j]!=""){
            // string str = statement[i]; 
            // removeDupWord(str);
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



