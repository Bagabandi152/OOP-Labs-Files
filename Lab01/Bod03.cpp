/*3. Өгөгдсөн хүснэгтийн тэгш элементүүдийн тоог олох хэрэглэгчийн функц бич.*/
#include<iostream>
using namespace std;
int countEven(int a[], int n);
main(){
    int n;
    cout << "Enter s size in Array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements in Array: " << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Even numbers count: " << countEven(a, n) << endl;
    return 0;
}

int countEven(int a[], int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 0) cnt++;
    }
    return cnt;
}
