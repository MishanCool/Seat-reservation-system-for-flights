#include <iostream>
#include <fstream>
#include<string.h>
#include <conio.h>
#include <bits/stdc++.h> 

using namespace std;

//void flightDetails();
//int viewFlightDetails(flight *flightOb[]);
// int x;
string word[100];
string f_id;
string statement[100];


int numberofplane=0;


//****************************************************************************
class flight {
    public: 

    string flight_num;
    string dep_datetime;
    string dep_airport;
    string arri_airport;
    int seat_num;
    string clz;
    char seat_array[100];
    int seat_row_num[100];
    char seat_clz[100];
    int seat[60][6];
    int m;
    
    public:
    flight(string a,string b,string c,string d) {
        flight_num=a;
        dep_datetime=b;
        dep_airport=c;
        arri_airport=d;
    }

    public:int available_seat(int e, string f, string colum ,int x) {

         m=colum.length();
        char seat_array[m+1];
        strcpy(seat_array, colum.c_str()); // copying the contents of the string to char array

        // for(int dl=0;dl<m;dl++){
        //     cout<<seat_array[dl];
        // }

        seat_num=e;
        seat_row_num[x-1]=seat_num;
      
        clz=f;
        
        seat_clz[x-1] = clz[0];

        int val=0;

        if(clz=="B") {
            val=1;
        }
        else if(clz=="E") {
            val=2;
        }
        else{
            cout<<"Invalid class"<<endl;
        }

        for(int dl=0;dl<m;dl++){
            //cout<<seat_array[dl];
            
            if(seat_array[dl]=='A') {
                seat[seat_num-1][0]=val;
            }
            else if(seat_array[dl]=='B'){
                seat[seat_num-1][1]=val;
            }
            else if(seat_array[dl]=='C'){
                seat[seat_num-1][2]=val;
            }
            else if(seat_array[dl]=='D'){
                seat[seat_num-1][3]=val;
            }
            else if(seat_array[dl]=='E'){
                seat[seat_num-1][4]=val;
            }
            else if(seat_array[dl]=='F'){
                seat[seat_num-1][5]=val;
            }
            else{
                cout<<"Invalid colum"<<endl;
            }
        }
    }

    void viewFlightDetails() {
        cout <<"Flight Number :" << flight_num << endl;
        cout <<"Departure Date :" << dep_datetime << endl;
        cout <<"Departure Airport Code :" << dep_airport << endl;
        cout << "Arrival Airport Code :" << arri_airport << endl;

        // for(int ij=0;ij<m;ij++){
        //     cout <<"Row number :" << seat_row_num[ij]<< "\t";
        //     cout <<"Seat claz :" << seat_clz[ij] << endl;
        // }
        for(int w=0;w<60;w++) {

            for(int u=0;u<6;u++) {
                cout<<"["<<w+1<<"] ->" <<seat[w][u] <<"\t";
            }
            cout<<endl;
        }

    }

};

//****************************************************************************************************





//****************************************************************************
void flightDetails(flight *flightOb[]) {

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

    int i=0;
 
    // flight *flightOb[numberofplane];  // Object array

    int j=0;
    for(int i = 0 ; i<numberofplane ; i++) {
        //cout << "value :" << statement[i] << endl;
        string fid=statement[j];          //  flight number
        string f_datetime=statement[j+1]; //  departure date and time
        string f_dep=statement[j+2];      //  departure airport code
        string f_arri=statement[j+3];     //  arrival airport code
        
        string seat_colum;

        j=j+4;
      
        flightOb[i] =new  flight(fid, f_datetime, f_dep, f_arri);

        // cout <<"Flight Number :" << flightOb[i]->flight_num << endl;
        // cout <<"Departure Date :" << flightOb[i]->dep_datetime << endl;
        // cout <<"Departure Airport Code :" << flightOb[i]->dep_airport << endl;
        // cout << "Arrival Airport Code :" << flightOb[i]->arri_airport << endl;

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
                
                k++; 

            } while (ss); // While there is more to read 

            
            int z=0;
            int seat_count=0;
            
            while(word[z]!="") {

                int seat_row;
                // int seat_row=stoi(word[z]);     this convert is support to c++11
                stringstream row(word[z]);         // convert string to integer
                row >> seat_row;
                seat_count++;

                string seat_clz=word[z+1];

                 string s=word[z+2];
                int g = s.length();                
                
                flightOb[i]->available_seat(seat_row, seat_clz, s , seat_count);
                
                z=z+3;
            }

            // for(int ij=0;ij<seat_count;ij++){
            //     cout <<"Row number :" << flightOb[i]->seat_row_num[ij]<< "\t";
            //     cout <<"Seat claz :" << flightOb[i]->seat_clz[ij] << "\t";
            // }

            cout<<endl;
            j++;
        }

        // for(int kl=0;kl<60;kl++) {

        //     for(int kj=0;kj<6;kj++) {
        //         cout<<"["<<kl+1<<"] ->" <<flightOb[i]->seat[kl][kj] <<"\t";
        //     }
        //     cout<<endl;
        // }

    
       j++;
       cout<<"\n\n\n\n";
       //cout << "*********************************************************" << endl; 

    //    searchFlight(flightOb,numberofplane);
    //returnflightOb(i);

    }

    // close the file stream
    inFile.close();
    
}





//****************************************************************************************************
void searchFlight(flight *object2[], int a){
    cout << "Enter flight number :";
    cin >> f_id;
    int i=0;

    for(i=0;i<a;i++)
    {
        if(object2[i]->flight_num==f_id){
            break;
        }
    }
  
    if(object2[i]->flight_num == f_id){
    
        cout <<"Flight Number :" << object2[i]->flight_num << endl;
        cout <<"Departure Date :" << object2[i]->dep_datetime << endl;
        cout <<"Departure Airport Code :" << object2[i]->dep_airport << endl;
        cout << "Arrival Airport Code :" << object2[i]->arri_airport << endl;

        // for(int ij=0;ij<object2[i]->m;ij++){
        //     cout <<"Row number :" << object2[i]->seat_row_num[ij]<< "\t";
        //     cout <<"Seat claz :" << object2[i]->seat_clz[ij] << "\t";
        // }
        for(int w=0;w<60;w++) {

            for(int u=0;u<6;u++) {
                cout<<"["<<w+1<<"] ->" <<object2[i]->seat[w][u] <<"\t";
            }
            cout<<endl;
        }

    }
    else {
        cout<<"Invalied  Flight Number"<<endl;
    }
    
}


//*************************************************************************************
int main()
{
    
    flight *object[100];  // Object array

    flightDetails(object);

    int i;
    
    while(1){

        int x;

        cout << "1. Flight details" << endl;
        cout << "2. Choose Flight" << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your option :"; 
        cin >> x;

        switch (x){
            case 1 : for(i=0;i<numberofplane;i++){
                        object[i]->viewFlightDetails();
                        cout<<endl;
                    }
                    break;
            case 2 :searchFlight(object,numberofplane);
                    break;
            case 3 :
                    cout << "You passed" << endl;
                    break;
            case 4 :exit(-1);
                    break;
            default :
                    cout << "Invalid Option" << endl;
        }
    }
   
}