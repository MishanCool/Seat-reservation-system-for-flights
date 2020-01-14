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

    int i=0;
    cout << "count1 is :" << count1 << endl;

    for(int i = 0 ; i<numberofplane ; i++){
        //cout << "value :" << statement[i] << endl;
        string fid=statement[i];          //  flight number
        string f_datetime=statement[i+1];      //  departure date and time
        string f_dep=statement[i+2];       //  departure airport code
        string f_arri=statement[i+3];      //  arrival airport code
        
        i=i+4;

        flight flightOb1(fid, f_datetime, f_dep, f_arri);
        //flightOb1.flight(fid, f_datetime, f_dep, f_arri);
        //flightOb1.;
        // while(statement[i]!=""){
        //     // split
        //     // int row=
        //     // classs
        //     // 
        //     i++;
        // }
        cout<< flightOb1.flight_num<<endl;
        cout<< flightOb1.dep_datetime<<endl;
        cout<< flightOb1.dep_airport<<endl;
        cout<< flightOb1.arri_airport<<endl;

    }
   
    

    // close the file stream
    inFile.close();
}



