#include <iostream>
using namespace std;

int main(){

    //3. Доорх кодыг туршиж мөр бүрийн үр дүнг тайлбарлан бич.
    int a=125;
    int *p = &a;
    cout<<p;
    cout<<*p;
    p++;
    cout<<p;
    cout<<*p;

    return 0;
}
