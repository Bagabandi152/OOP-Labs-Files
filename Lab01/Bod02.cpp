/*2. Өгөгдсөн N ширхэг тооны хамгийн их/хамгийн багийг олох код бич.*/
#include<iostream>
using namespace std;
main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int m, mx, mn;
    cout <<"Enter "<< n << " numbers: ";
    cin >> m;
    mx = m;
    mn = m;
    for(int i = 1; i < n; i++){
        cin >> m;
        if(mn > m) mn = m;
        if(mx < m) mx = m;
    }
    cout << "Max number in given numbers: " << mx << endl;
    cout << "Min number in given numbers: " << mn << endl;
    return 0;
}
