#include <iostream>
#include <fstream>
#include<string.h>
#include <conio.h>
#include <bits/stdc++.h> 

using namespace std;

string word[100];
string f_id;
string statement[100];
int seat;


int numberofplane=0;


//***************************************************************************************
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
        cout << "Arrival Airport Code :" << arri_airport << "\n\n";
        cout<<"Seat Structure In Flight"<<endl;
        for(int w=0;w<60;w++) {

            for(int u=0;u<6;u++) {
                cout<<"["<<w+1<<"] ->" <<seat[w][u] <<"\t";
            }
            cout<<endl;
        }

    }

};


//***********************************************************************************************
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
    string line;
    
    while (getline(inFile, line))
    {
        
        if(line==""){
            numberofplane=numberofplane+1;
        }
        
        statement[count1]=line;
        count1++;

    }

    int i=0;
 
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

        while(statement[j]!=""){
            string str = statement[j];  
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
                // int seat_row=stoi(word[z]);     //this convert is support to c++11
                stringstream row(word[z]);         // convert string to integer
                row >> seat_row;
                seat_count++;

                string seat_clz=word[z+1];

                 string s=word[z+2];
                int g = s.length();                
                
                flightOb[i]->available_seat(seat_row, seat_clz, s , seat_count);
                
                z=z+3;
            }

            j++;
        }
    
       j++;

    }

    // close the file stream
    inFile.close();
    
}


//****************************************************************************************************
void searchFlight(flight *object2[], int a){
    cout << "Enter flight number :";
    cin >> f_id;
    cout<<endl;
    int i=0;

    int B=0;
    int E=0;

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
        cout << "Arrival Airport Code :" << object2[i]->arri_airport << "\n\n";

        for(int w=0;w<60;w++) {

            for(int u=0;u<6;u++) {
                if(object2[i]->seat[w][u]==1){
                    B++;
                }
                else if(object2[i]->seat[w][u]==2) {
                    E++;
                }
            }
        }

        cout<<"Number of available seats in B class: "<< B <<"\t\t";
        cout<<"Number of available seats in E class: "<< E <<"\n\n";

        cout<<"Seat Structure In Flight"<<endl;
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


//*******************************************************************************************
void findSeats(flight *object3[], int a){
    cout << "Enter flight number :";
    cin >> f_id;
    cout<<endl;
    cout << "Enter number of seats you need :";
    cin >> seat;
    cout<<endl;

    int i=0;

    int B=0;
    int E=0;

    for(i=0;i<a;i++)
    {
        if(object3[i]->flight_num==f_id){
            break;
        }
    }
  
    if(object3[i]->flight_num == f_id){

        for(int w=0;w<60;w++) {

            for(int u=0;u<6;u++) {
                if(object3[i]->seat[w][u]==1){
                    B++;
                }
                else if(object3[i]->seat[w][u]==2) {
                    E++;
                }
            }
        }

        if(B+E>seat){
            cout <<"Flight Number :" << object3[i]->flight_num << endl;
            cout <<"Departure Date :" << object3[i]->dep_datetime << endl;
            cout <<"Departure Airport Code :" << object3[i]->dep_airport << endl;
            cout << "Arrival Airport Code :" << object3[i]->arri_airport <<"\n\n";
            cout<<"Available Seats :"<<B+E<<endl;
            cout<<seat<<" Seats are available in flight number "<<f_id<<"\n\n";
            cout<<"Seat Structure In Flight"<<endl;
            for(int w=0;w<60;w++) {

                for(int u=0;u<6;u++) {
                    cout<<"["<<w+1<<"] ->" <<object3[i]->seat[w][u] <<"\t";
                }
                cout<<endl;
            }
        }
        else{
            cout<<"Available Seats :"<<B+E<<endl;
            cout<<seat<<"Seats are not available in flight number "<<f_id<<"\n\n";
        }

    }
    else {
        cout<<"Invalied  Flight Number"<<endl;
    }
}


//*******************************************************************************************
int main()
{
    
    flight *object[100];  // Object array

    flightDetails(object);

    int i;
    
    while(1){

        int x;
        cout<<"\n\n\n\n\n";
        cout<<"****** WELLCOME TO  Virgin Airline ***************"<<"\n\n";
        cout <<"## Gide Line ##"<<endl;
        cout <<"Allready book seats  represant from Number 0"<<endl;
        cout <<"Available B class seats represant from Number 1"<<endl;
        cout <<"Available E class seats represant from Number 2"<<"\n\n";
        cout << "1. All flights details" << endl;
        cout << "2. Choose Flight" << endl;
        cout << "3. Find Seats" << endl;
        cout << "4. Exit " <<"\n\n";
        cout<<"**************************************************"<<"\n\n";
        cout << "Enter your option : "; 
        cin >> x;
        cout<<endl;

        switch (x){
            case 1 : for(i=0;i<numberofplane;i++){
                        object[i]->viewFlightDetails();
                        cout<<endl;
                    }
                    break;
            case 2 :searchFlight(object,numberofplane);
                    break;
            case 3 :findSeats(object,numberofplane);
                    break;
            case 4 :exit(-1);
                    break;
            default :
                    cout << "Invalid Option.....................!" << endl;
        }
    }
   
}