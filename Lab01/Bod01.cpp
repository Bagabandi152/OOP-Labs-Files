/*1. a, b, c гурван тооны хамгийн ихийг олох хэрэглэгчийн функц бич.*/
#include<iostream>
using namespace std;
int max3num(int, int, int);
main(){
    int a, b, c;
    cout << "Enter 3 number: ";
    cin >> a >> b >> c;
    cout << "Max number in given numbers: " << max3num(a, b, c);
    return 0;
}

int max3num(int a, int b, int c){
    int mx;
    if(a<b) mx = b;
    else mx = a;
    if(mx < c) mx = c;
    return mx;
}

