#include <iostream>
#include <fstream>
#include<string.h>
#include <bits/stdc++.h> 

using namespace std;

// int x;
string word[100];
string f_id;
string statement[100];

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


// void splitString(string str) 
// { 
//     // Used to split string around spaces. 
//     istringstream ss(str);

//     int k=0; 
  
//     // Traverse through all words 
//     do { 
//         // Read a word 
//         //string word; 
//         ss >> word[k];

//          // Print the read word 
//         cout << word[k] << endl; 
//         if(word[k]==""){
//             k++;
//             // cout<<"fffff"<<endl;
//             break;
//         }
//         k++; 

//         // While there is more to read 
//     } while (ss); 
// } 

void flightDetails(){

    ifstream inFile;
     

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

        cout <<"Flight Number :" << flightOb[i]->flight_num << endl;
        cout <<"Departure Date :" << flightOb[i]->dep_datetime << endl;
        cout <<"Departure Airport Code :" << flightOb[i]->dep_airport << endl;
        cout << "Arrival Airport Code :" << flightOb[i]->arri_airport << endl;

        while(statement[j]!=""){
            string str = statement[j]; 
            // splitString(str);
            // Used to split string around spaces. 
            istringstream ss(str);

            int k=0; 
        
            // Traverse through all words 
            do { 
                // Read a word 
                //string word; 
                ss >> word[k];

                // Print the read word 
                cout << word[k] << "\t"; 
                if(word[k]==""){
                    k++;
                    // cout<<"fffff"<<endl;
                    break;
                }
                k++; 

                // While there is more to read 
            } while (ss); 
            // classs
            // 
            cout<<endl;
            j++;
        }
    
       j++;
       cout<<"\n\n\n\n";

    }
    // close the file stream
    inFile.close();

}

void searchFlight(){
    cout << "Enter flight number :";
    cin >> f_id;
    int i=0;
    
    while(statement[i]!=f_id){
        i++;
    }

    if(statement[i] == f_id){
        cout << statement[i] << endl;
    }
    
}


int main()
{
    
    while(1){

        int x;

        cout << "1. Flight details" << endl;
        cout << "2. Choose Flight" << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your option :"; 
        cin >> x;

        switch (x){
            case 1 : flightDetails();
                     break;
            case 2 :searchFlight();
                    break;
            case 3 :
                    cout << "You passed" << endl;
                    break;
            case 4 :exit(-1);
                    break;
            default :
                    cout << "Invalid grade" << endl;
        }
    }
   
}