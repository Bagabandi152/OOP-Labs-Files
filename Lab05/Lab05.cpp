#include <iostream>
#include <string.h>
#define pricePerHour 5000
using namespace std;


class Employee {
private:
    int empid;
    char *name;
    char *position;
    float wtime;
    float ceoCalcSalary();
public:
    Employee(); //Андагч байгуулагч функц зарлав.
    Employee(char *n, char *p, int e, float wt); //Параметртэй байгуулагч функц зарлав.
    ~Employee(); // Устгагч функц зарлав
    Employee(Employee &); //Хуулагч байгуулагч зарлав.
    void empCopy(Employee &); //Хуулагч функц зарлав.
    void setEmpid(int);
    void setPosition(char*);
    void setWtime(int);
    void setName(char*);
    char* getName(); //гишүүн өгөгдлийн утгыг гаднаас хандаж, авах функц
    char* getPosition();
    int getEmpid();
    int getWtime();
    float calcSalary(); //Цалин бодох функцийг зарлав.
    int incWorkTime(float inc); //Ажилласан цагийг нэмэгдүүлэх функцийг зарлав.
};

void Employee::setName(char* name) // set фунцкцийг тодорхойлов.
{
    this->name = name;
}

void Employee::setPosition(char* pos) // set фунцкцийг тодорхойлов.
{
    position = pos;
}

void Employee::setWtime(int wt) // set фунцкцийг тодорхойлов.
{
    wtime = wt;
}

void Employee::setEmpid(int empid) // set фунцкцийг тодорхойлов.
{
    this->empid = empid;
}

int Employee::getEmpid() // get функцийг тодорхойлов.
{
    return empid;
}
char* Employee::getName() // get функцийг тодорхойлов.
{
    return name;
}
char* Employee::getPosition() // get функцийг тодорхойлов.
{
    return position;
}
int Employee::getWtime() // get функцийг тодорхойлов.
{
    return wtime;
}

float Employee::calcSalary() //цалин бодох функцийг тодорхойлов.
{
    if(strcmp(position, "CEO") == 0){
        return wtime*pricePerHour + ceoCalcSalary();
    }
    return wtime*pricePerHour;
}

float Employee::ceoCalcSalary() // захирлын цалин бодох функцийг тодорхойлов.
{
    return wtime*pricePerHour;
}

Employee::Employee()
{
    empid = 0; //empid - д анхны утга оноов.
    name = new char(1); // name хувьсагчид char төрлийн 1 байт ой нөөцлөв.
    strcpy(name, ""); // 1 byte урттай нөөцөлсөн ойд хоосон буюу null утга оноов.

    position = new char(9);
    strcpy(position, "Employee");
    wtime = 0;
}

Employee::Employee(char* n, char* p, int e, float wt)
{
    name = new char(strlen(n) + 1); // name хувьсагчид n урт дээр нэмэх 1 ойг нөөцлөв.
    strcpy(name, n); // Нөөцөлсөн ойд n параметрийн утгыг олгов.
    position = new char(strlen(p) + 1);
    strcpy(position, p);
    empid = e;
    wtime = wt;
}

Employee::Employee(Employee &e)
{
    name = new char(strlen(e.name) + 1);
    strcpy(name, e.name);
    position = new char(strlen(e.position) + 1);
    strcpy(position, e.position);
    empid = e.empid;
    wtime = e.wtime;
}

void Employee::empCopy(Employee &e)
{
    delete name;
    delete position;
    name = new char(strlen(e.name) + 1);
    strcpy(name, e.name);
    position = new char(strlen(e.position) + 1);
    strcpy(position, e.position);
    empid = e.empid;
    wtime = e.wtime;
}

Employee::~Employee() //устгагч функцийг тодорхойлов.
{
    cout<<"\n deleted " << name <<endl;
    delete name;
    delete position;
}

int Employee::incWorkTime(float inc) //ажилласан цаг нэмэгдүүлэх функцийг тодорхойлов.
{

    if(0 < inc && inc <= 24){
        wtime += inc;
        return 1;
    }

    return 0;
}

int checkId(int emps[], int n, int empid){
    for(int i = 0; i < n; i++){
        if(emps[i] == empid) return 0;
    }

    return 1;
}

int main()
{
    int n;
    cout<<"Enter count of employee: ";
    cin>>n;

    Employee *Employees[n];
    Employee *EmpPtr;
    int empsid[n] = {0};
    cout<<"Enter data of each employee: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"\tEmployee No"<<i + 1<<":\n";
        EmpPtr = new Employee();
        char name[20], pos[20];
        int empid, wt;

        cout<<"Enter empid: "<<endl;
        cin>>empid;

        int avail = checkId(empsid, n, empid);
        while(avail == 0){
            cout<<"Enter empid again /repeated/: "<<endl;
            cin>>empid;
            avail = checkId(empsid, n, empid);
        }

        EmpPtr->setEmpid(empid);

        empsid[i] = empid;

        cout<<"Enter name: "<<endl;
        cin>>name;
        EmpPtr->setName(name);

        cout<<"Enter position: "<<endl;
        cin>>pos;
        EmpPtr->setPosition(pos);

        cout<<"Enter wtime: "<<endl;
        cin>>wt;
        EmpPtr->setWtime(wt);
        Employees[i] = EmpPtr;
    }


    for(int i = 1; i < n; i++)
    {
        Employee *key = Employees[i];
        char *key_name = new char(strlen(Employees[i]->getName()) + 1);
        strcpy(key_name, Employees[i]->getName());
        int j = i - 1;
        char *j_name = new char(strlen(Employees[j]->getName()) + 1);
        strcpy(j_name, Employees[j]->getName());
        while(j >= 0 && strcmp(key_name, j_name) < 0)
        {
            Employees[j + 1]->empCopy(*Employees[j]);
            j--;
        }
        Employees[j + 1]->empCopy(*key);
        delete key_name;
        delete j_name;
    }

    cout<<"\n\nEmloyees were sorted by name: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<endl;
        cout<<Employees[i]->getEmpid()<<endl;
        cout<<Employees[i]->getName()<<endl;
        cout<<Employees[i]->getPosition()<<endl;
        cout<<Employees[i]->getWtime()<<endl;
    }


    for(int i = 0; i < n; i++)
    {
        delete Employees[i];
    }

    return 0;
}
