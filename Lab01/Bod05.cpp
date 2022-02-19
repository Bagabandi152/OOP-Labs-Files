/* 5. Өгөгдсөн натурал тооны оронгийн тоо болон цифрүүдийг олох хэрэглэгчийн функц бич.*/
#include<iostream>
using namespace std;
int otoo(int a, int ci[]);
main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int ciqr[100];
    int c = otoo(n, ciqr);
    cout << "Orongiin too: " << c << endl;
    cout << "Ciqruud: " << endl;
    for(int i = 0; i < c; i++)
        cout << ciqr[i] << " ";
    return 0;
}

int otoo(int a, int ci[]){
    int ot = 0;
    while(a > 0){
        int c = a%10;
        ci[ot++] = c;
        a /= 10;
    }
    return ot;
}

