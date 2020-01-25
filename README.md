# Seat-reservation-system-for-flights
Seat reservation system for flights using OOP concept

# Compail c++ code
g++ .\flight2.cpp -o fli.exe

# Run c++ code
.\fli.exe









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
        if(object2[i]->flight_num==f_id){
            break;
        }
    }
  
    if(object2[i]->flight_num == f_id){

        cout <<"Flight Number :" << object2[i]->flight_num << endl;
        cout <<"Departure Date :" << object2[i]->dep_datetime << endl;
        cout <<"Departure Airport Code :" << object2[i]->dep_airport << endl;
        cout << "Arrival Airport Code :" << object2[i]->arri_airport <<"\n\n";

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

        if(B+E>seat){
            cout<<seat<<" Seats are available in flight number "<<f_id<<endl;
        }
        else{
            cout<<"Seats are not available in flight number "<<f_id<<endl;
        }

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