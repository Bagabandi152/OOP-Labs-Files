#include <iostream>
#include <string.h>
#define pricePerHour 5000
using namespace std;

class Employee {
private:
    int empid;
    char name[20];
    char position[10];
    float wtime;
public:
    Employee(){
        empid = 0;
        strcpy(name, "");
        strcpy(position, "Employee");
        wtime = 0;
    }
    void getData(void){
        cout<<"Enter employee ID: ";
        cin>>empid;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter position: ";
        cin>>position;
        cout<<"Enter work time: ";
        cin>>wtime;
    }
    void showData(){
        cout<<"Employee ID: "<<empid<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Position: "<<position<<endl;
        cout<<"Work time: "<<wtime<<endl;
    }
    float calcuSalary(){
        if(strcmp(position, "Director") == 0){
            return wtime*pricePerHour + dirCalcuSalary();
        }
        return wtime*pricePerHour;
    }
    float dirCalcuSalary(){
        return wtime*2*pricePerHour;
    }
    int incWorkTime(float inc){
        if(0 < inc && inc <= 24) return 1;
        return 0;
    }
};


int main(){
    Employee e1, e2;
    e1.showData();
    e1.getData();
    e1.showData();
    cout<<"Salary: "<<e1.calcuSalary()<<endl;
    e2.showdata();
    return 0;
}
