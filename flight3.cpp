#include <iostream>
#include <fstream>
#include<string.h>
#include <bits/stdc++.h> 

using namespace std;

void flightDetails();

// int x;
string word[100];
string f_id;
string statement[100];
int seat[60][6];

int numberofplane=0;

void fileHandleing() {
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
    // numberofplane=0;
    string line;
    
    while (getline(inFile, line))
    {
        // cout << line << endl;

        if(line==""){
            numberofplane=numberofplane+1;
        }
        
        statement[count1]=line;
        count1++;

    }

    flightDetails();

    // close the file stream
    inFile.close();
}
//**********************************************************************

class flight {
    public: 

    string flight_num;
    string dep_datetime;
    string dep_airport;
    string arri_airport;
    string seat_num;
    string clz;

    // seat[10][1]=0;
    // seat[10][1]=1;
    // seat[10][1]=2;
    
    public:
    flight(string a,string b,string c,string d) {
        flight_num=a;
        dep_datetime=b;
        dep_airport=c;
        arri_airport=d;
    }
};
//*****************************************************

//const int Num_flight= numberofplane;


//*****************************************************


void flightDetails() {

    
    int i=0;
    //cout << "count1 is :" << count1 << endl;
    
    //  flight flightOb1[numberofplane];
    flight *flightOb[numberofplane];  // Object array

    int j=0;
    for(int i = 0 ; i<numberofplane ; i++) {
        //cout << "value :" << statement[i] << endl;
        string fid=statement[j];          //  flight number
        string f_datetime=statement[j+1]; //  departure date and time
        string f_dep=statement[j+2];      //  departure airport code
        string f_arri=statement[j+3];     //  arrival airport code
        
        string seat_colum;

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
                

                // string num_of_seat = word[k];
                // string flight_class = word[k+1];
                // string num_of_seat = word[k+2];

                // Print the read word 
                //cout << word[k] << "\t";
                
                k++; 

                // While there is more to read 
            } while (ss);

            int z=0;
            
            while(word[z]!="") {

                int seat_row;
                // int seat_row=stoi(word[z]);     this convert is support to c++11
                stringstream row(word[z]);         // convert string to integer
                row >> seat_row;

                string seat_clz=word[z+1];
                string s=word[z+2];

                int g = s.length();

                char char_array[g + 1];

                strcpy(char_array, s.c_str()); // copying the contents of the string to char array

                cout <<"Row number :" << seat_row << "\t";
                cout <<"Seat claz :" << seat_clz << "\t";
                cout <<"column :" << endl;
                for (int i = 0; i < g; i++) {
                    cout << char_array[i]; 
                }    
                cout << "\n" << endl;
        
            //    for (int i = 0; i < g; i++) {
            //         cout << char_array[i]; 
            //     }   
                

                

                // for(i=0;i<60;i++) {

                //     for(j=0;j<6;j++) {
                //         seat[i][j] = 1;
                //     }
                // } 
                z=z+3;
            }


            
            

            cout<<endl;
            j++;
        }
    
       j++;
       cout<<"\n\n\n\n";
       cout << "*********************************************************" << endl; 

    }
    

}

void searchFlight(){
    cout << "Enter flight number :";
    cin >> f_id;
    int i=0;

    while(statement[i]!=f_id){
        i++;
    }

    if(statement[i] == f_id){
        //cout << statement[i] << endl;
        cout <<"Flight Number :" << statement[i] << endl;
        cout <<"Departure Date :" << statement[i+1] << endl;
        cout <<"Departure Airport Code :" << statement[i+2] << endl;
        cout << "Arrival Airport Code :" << statement[i+3] << endl;
    }
    
}


int main()
{
    fileHandleing();
    // flightDetails();
    
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