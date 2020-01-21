#include <iostream>
#include <fstream>
#include<string.h>
#include <conio.h>
#include <bits/stdc++.h> 

using namespace std;

//void flightDetails();

// int x;
string word[100];
string f_id;
string statement[100];
int seat[60][6];

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
    char seat_array[];
    int seat_row_num[];
    char seat_clz[];
    
    public:
    flight(string a,string b,string c,string d) {
        flight_num=a;
        dep_datetime=b;
        dep_airport=c;
        arri_airport=d;
    }

    public:int available_seat(int e, string f, string colum ,int x){

        //cout<<"***********clazz*********"<<endl;


        // for(int dl=0;dl<m;dl++){
        //     seat_array[dl]=array[dl];
        // }
        int m=colum.length();
        char seat_array[m+1];
        strcpy(seat_array, colum.c_str()); // copying the contents of the string to char array

        for(int dl=0;dl<m;dl++){
            cout<<seat_array[dl];
        }

        seat_num=e;
        seat_row_num[x-1]=seat_num;
        // cout<<"row"<<seat_num<<"num"<<x-1<<endl;

        // cout<<seat_row_num[x-1]<<endl;
        //cout<<"***********clazz end*********"<<endl;

        //cout<<"class"<<f<<"num"<<x-1<<endl;
        clz=f;
        //cout<<"class"<<clz<<"num"<<x-1<<endl;
        seat_clz[x-1] = clz[0];
        //strcpy(seat_clz, clz.c_str());
        

        //cout<<"class"<<seat_clz[x-1]<<"num"<<x-1<<endl;
    
    }

    //  public: int available_seat(int e, string f, char array[], int m ,int x){

    //     for(int d=0;d<m;d++){
    //         seat_array[d]=array[d];
    //     }  

    //     seat_num=e;
    //     seat_row_num[x]=seat_num;

    //     clz=f;
    //     seat_clz[x]=clz;

    //     int val=0;

    //             if(clz=="B") {
    //                 val=1;
    //             }
    //             else if(clz=="E") {
    //                 val=2;
    //             }
    //             else{
    //                 cout<<"Invalid class"<<endl;
    //             }
        
    //            for (int i = 0; i < m; i++) {
    //                if(seat_array[i]=='A') {
    //                    seat[seat_num-1][0]=val;
    //                }
    //                else if(seat_array[i]=='B'){
    //                    seat[seat_num-1][1]=val;
    //                }
    //                else if(seat_array[i]=='C'){
    //                    seat[seat_num-1][1]=val;
    //                }
    //                else if(seat_array[i]=='D'){
    //                    seat[seat_num-1][1]=val;
    //                }
    //                else if(seat_array[i]=='E'){
    //                    seat[seat_num-1][1]=val;
    //                }
    //                else if(seat_array[i]=='F'){
    //                    seat[seat_num-1][1]=val;
    //                }
    //                else{
    //                    cout<<"Invalid colum"<<endl;
    //                }
                     
    //             }     
    //  }
};



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
                // char char_array[g + 1];
                // strcpy(char_array, s.c_str()); // copying the contents of the string to char array

                
                
                flightOb[i]->available_seat(seat_row, seat_clz, s , seat_count);
                //flightOb[i] =new  flight(seat_row, seat_clz, char_array , g , seat_count);
                //cout<<"***********Find Wrong*********"<<endl;

                // cout <<"Row number :" << flightOb[i]->seat_num<< "\t";
                // cout <<"Seat claz :" << flightOb[i]->clz << "\t";
                // cout <<"column :";
                //     for (int h = 0; h < g+1; h++) {
                //         cout << flightOb[i]->seat_array[h];
                //     }    
                // cout << "\n" << endl;

                z=z+3;
            }

            for(int ij=0;ij<seat_count;ij++){
                cout <<"Row number :" << flightOb[i]->seat_row_num[ij]<< "\t";
                cout <<"Seat claz :" << flightOb[i]->seat_clz[ij] << "\t";
            }


            cout<<endl;
            j++;
        }
    
       j++;
       cout<<"\n\n\n\n";
       cout << "*********************************************************" << endl; 

    //    searchFlight(flightOb,numberofplane);

    }

    // for(i=0;i<60;i++) {

    //     for(j=0;j<6;j++) {
    //         cout<<"["<<i+1<<"] ->" <<seat[i][j] <<"\t";
    //     }
    //     cout<<endl;
    // } 

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
    // while(object[i]->flight_num!=f_id){
    //     i++;
    // }

    if(object2[i]->flight_num == f_id){
    
        // cout <<"Flight Number :" << statement[i] << endl;
        // cout <<"Departure Date :" << statement[i+1] << endl;
        // cout <<"Departure Airport Code :" << statement[i+2] << endl;
        // cout << "Arrival Airport Code :" << statement[i+3] << endl;

        cout <<"Flight Number :" << object2[i]->flight_num << endl;
        cout <<"Departure Date :" << object2[i]->dep_datetime << endl;
        cout <<"Departure Airport Code :" << object2[i]->dep_airport << endl;
        cout << "Arrival Airport Code :" << object2[i]->arri_airport << endl;

    }
    
}


//*************************************************************************************
int main()
{
    int i , j;
    for(i=0;i<60;i++) {
        for(j=0;j<6;j++) {
            seat[i][j] =0;
        }
    } 
    // flight *fli[100];
    flight *object[100];  // Object array

    flightDetails(object);
    // flightDetails();

    
    while(1){

        int x;

        cout << "1. Flight details" << endl;
        cout << "2. Choose Flight" << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your option :"; 
        cin >> x;

        switch (x){
            // case 1 : flightDetails();
            //          break;
            case 2 :searchFlight(object,numberofplane);
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