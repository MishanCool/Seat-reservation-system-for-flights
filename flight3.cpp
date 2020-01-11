#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;
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
    string line;
    while (getline(inFile, line))
    {
        // cout << line << endl;
        statement[count1]=line;
        count1++;

    }

    cout << "count1 is :" << count1 << endl;

    for(int i = 0 ; i<=count1 ; i++){
        cout << "value :" << statement[i] << endl;
    }

    // close the file stream
    inFile.close();
}

class flight {
    flight(){
        cout<< "dddd";
    }
};