//6. заалтан хувьсагч (функцын параметер нь заалт байна) хоёр хувьсагчийн утгыг солих хэрэглэгчийн функц бич.
#include<iostream>
using namespace std;

void swapped(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    int a, b;
    cout<<"Enter value of a and b: ";
    cin>>a>>b;
    cout<<"Solihoos umnuh utguud "<<endl;
    cout<<"a - iin utga: "<<a<<endl<<"b - iin utga: "<<b<<endl;
    swapped(&a, &b);
    cout<<"Solisonii daraah utguud "<<endl;
    cout<<"a - iin utga: "<<a<<endl<<"b - iin utga: "<<b;
    return 0;
}
