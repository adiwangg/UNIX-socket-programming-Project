#include <iostream>
#include <fstream>


using namespace std;

int main() {
    int a[5];
    ifstream in("../test.txt");
    if (in.is_open()) {
        cout << "!!!!" << endl;
    }
    for(int i=0;i<5;i++)
        in>>a[i];
    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;
    //ofstream out("testOut.txt");

    in.close();
    //out.close();

}
