#include <iostream>
#include <string.h>
#define pricePerHour 5000
using namespace std;

class Employee {
private:
    int empid; // Ажилтаны дугаарыг private төлөвтэйгээр зарлав.
    char *name; //Ажилтны нэрийг заагч төрлөөр, ptivate төлөвтэйгээр зарлав.
    char *position; //Ажилтны албан тушаалыг заагч төрлөөр, ptivate төлөвтэйгээр зарлав.
    float wtime; //Ажилтны ажилласан цагийг зарлав.
    float ceoCalcSalary(); //Захиралын цалин бодох функцийг private төлөвтэйгээр зарлав.
public:
    Employee(); //Андагч байгуулагч функц зарлав.
    Employee(char *n, char *p, int e, float wt); //Параметртэй байгуулагч функц зарлав.
    ~Employee(); // Устгагч функц зарлав
    //Employee(Employee &); //Хуулагч байгуулагч зарлав.
    void setData(); //гишүүн өгөгдөлд гаднаас хандаж, өөрчлөлт оруулах функц
    void getData(); //гишүүн өгөгдлийн утгыг гаднаас хандаж, авах функц
    float calcSalary(); //Цалин бодох функцийг зарлав.
    int incWorkTime(float inc); //Ажилласан цагийг нэмэгдүүлэх функцийг зарлав.
};

void Employee::setData() // set фунцкцийг тодорхойлов.
{
    cout<<"Enter employee ID: ";
    cin>>empid;
    cout<<"Enter name:  ";
    cin>>name;
    cout<<"Enter position: ";
    cin>>position;
    cout<<"Enter work time: ";
    cin>>wtime;
}

void Employee::getData() // get функцийг тодорхойлов.
{
    cout<<"Employee ID: "<<empid<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Position: "<<position<<endl;
    cout<<"Work time: "<<wtime<<endl<<endl;
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
    //if(strcmp(position, "CEO") == 0)
    //уг функцийг хандалттай болгосон учраас энд заавал захирал мөн эсэхийг шадгах
    //шаардлагагүй болно.
    return wtime*pricePerHour;
}

Employee::Employee() //Анхдагч байгуулагч функц тодорхойлов. Ямар нэг параметргүйгээр тухайн классын объект байгуулах үед дуудагдана.
{
    empid = 0; //empid - д анхны утга оноов.
    name = new char(1); // name хувьсагчид char төрлийн 1 байт ой нөөцлөв.
    strcpy(name, ""); // 1 byte урттай нөөцөлсөн ойд хоосон буюу null утга оноов.

    position = new char(9);
    strcpy(position, "Employee");
    wtime = 0;
}

Employee::Employee(char* n, char* p, int e, float wt) //Параметртэй байгуулагч функц тодорхойлов.
{
    name = new char(strlen(n) + 1); // name хувьсагчид n урт дээр нэмэх 1 ойг нөөцлөв.
    strcpy(name, n); // Нөөцөлсөн ойд n параметрийн утгыг олгов.
    position = new char(strlen(p) + 1);
    strcpy(position, p);
    empid = e;
    wtime = wt;
}

/*Employee::Employee(Employee &e)
{
    name = new char(strlen(e.name) + 1);
    strcpy(name, e.name);
    position = new char(strlen(e.position) + 1);
    strcpy(position, e.position);
    empid = e.empid;
    wtime = e.wtime;
}*/

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

int main()
{
    int n;
    cout<<"Enter count of employee: ";
    cin>>n;

    Employee e[n];

    cout<<"Enter data of each employee: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"\tEmployee No"<<i + 1<<":\n";
        e[i].setData();
    }


    for(int i = 1; i < n; i++)
    {
        Employee key = e[i];
        float key_sal = e[i].calcSalary();
        int j = i - 1;
        while(j >= 0 && key_sal < e[j].calcSalary())
        {
            e[j + 1] = e[j];
            j--;
        }

        e[j + 1] = key;
    }

    cout<<"\n\nEmloyees were sorted: "<<endl;
    for(int i = 0; i < n; i++)
    {
        e[i].getData();
    }

    return 0;
}
