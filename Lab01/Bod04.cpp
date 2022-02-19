/*4. Өгөгдсөн хүснэгтийн сондгой элементүүдийн арифметик дунджийг олох хэрэглэгчийн функц бич.*/
#include<iostream>
using namespace std;
float avgOdd(int a[], int n);
main(){
    int n;
    cout << "Enter s size in Array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements in Array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Odd numbers avg: " << avgOdd(a, n) << endl;
    return 0;
}

float avgOdd(int a[], int n){
    int cnt = 0;
    float sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 1){
            sum += a[i];
            cnt++;
        }
    }
    return sum/cnt;
}
