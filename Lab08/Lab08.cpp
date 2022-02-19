#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

//1. Дараах зурагт харуулсан класс диаграмын дагуу классуудаг байгуул.
//6. 0..1, 0..n болон 1, 1..n харьцаануудыг зөв програмчилсан байх шаардлагатай.
class Person{
    private:
        char*name;
        char*SSName;
        int age;
    public:
        Person(){
           name = new char(1);
           strcpy(name, "");
           SSName = new char(1);
           strcpy(SSName, "");
           age = 0;
        }

        ~Person(){
            delete name;
            delete SSName;
        }

        Person(char* name, char* SSName, int age){
             this->name = new char(strlen(name) + 1);
             strcpy(this->name, name);
             this->SSName = new char(strlen(SSName) + 1);
             strcpy(this->SSName, SSName);
             this->age = age;
        }

        char* getName(){
            return name;
        }

        char* getSSName(){
            return SSName;
        }

        int getAge(){
            return age;
        }

        void setName(char* name){
            delete this->name;
            this->name = new char(strlen(name) + 1);
            strcpy(this->name, name);
        }

        void setSSName(char* SSName){
            delete this->SSName;
            this->SSName = new char(strlen(SSName) + 1);
            strcpy(this->SSName, SSName);
        }

        void setAge(int age){
            this->age = age;
        }

        virtual void printData(){
            cout<<"Name: "<<name<<endl;
            cout<<"SSName: "<<SSName<<endl;
            cout<<"Age: "<<age<<endl;
        }
};

class Spouse:public Person{
    private:
        char* anniversaryData;
    public:
        Spouse():Person(){
            anniversaryData = new char(1);
            strcpy(anniversaryData, "");
        }

        Spouse(char* name, char* SSName, int age, char* anniversaryData):Person(name, SSName, age){
            this->anniversaryData = new char(strlen(anniversaryData) + 1);
            strcpy(this->anniversaryData, anniversaryData);
        }

        ~Spouse(){
            delete anniversaryData;
        }

        char* getAnniversaryData(){
            return anniversaryData;
        }

        void setAnniversaryData(char* anniData){
            delete anniversaryData;
            anniversaryData = new char(strlen(anniData) + 1);
            strcpy(anniversaryData, anniData);
        }

        void copyFunc(Spouse &sp){
            delete anniversaryData;
            setName(sp.getName());
            setSSName(sp.getSSName());
            setAge(sp.getAge());
            anniversaryData = new char(strlen(sp.anniversaryData) + 1);
            strcpy(anniversaryData, sp.anniversaryData);
        }

        void printData(){
            cout<<"Name: "<<getName()<<endl;
            cout<<"SSName: "<<getSSName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"AnniversaryData: "<<anniversaryData<<endl;
        }
};

class Division{
    private:
        char* divisionName;
    public:
        Division(){
            divisionName = new char(1);
            strcpy(divisionName, "");
        }

        Division(char* divisionName){
            this->divisionName = new char(strlen(divisionName) + 1);
            strcpy(this->divisionName, divisionName);
        }

        ~Division(){
            delete divisionName;
        }

        char* getDivisionName(){
            return divisionName;
        }

        void setDivisionName(char* divisionName){
            delete this->divisionName;
            this->divisionName = new char(strlen(divisionName) + 1);
            strcpy(this->divisionName, divisionName);
        }

        void copyFunc(Division &d){
            delete divisionName;
            divisionName = new char(strlen(d.divisionName) + 1);
            strcpy(divisionName, d.divisionName);
        }
        void printData(){
            cout<<"Division name: "<<divisionName<<endl;
        }
};

class JobDescription{
    private:
        char* description;
    public:
        JobDescription(){
            description = new char(1);
            strcpy(description, "");
        }

        JobDescription(char* description){
            this->description = new char(strlen(description) + 1);
            strcpy(this->description, description);
        }

        ~JobDescription(){
            delete description;
        }

        char* getDescription(){
            return description;
        }

        void setDescription(char* description){
            delete this->description;
            this->description = new char(strlen(description) + 1);
            strcpy(this->description, description);
        }

        void printData(){
            cout<<"Description: "<<description<<endl;
        }
};

class Child: public Person{
    private:
        char* favoriteToy;
    public:
        Child():Person(){
            favoriteToy = new char(1);
            strcpy(favoriteToy, "");
        }

        Child(char* name, char* SSName, int age, char*favoriteToy):Person(name, SSName, age){
            this->favoriteToy = new char(strlen(favoriteToy) + 1);
            strcpy(this->favoriteToy, favoriteToy);
        }

        ~Child(){
            delete favoriteToy;
        }

        char* getFavoriteToy(){
            return favoriteToy;
        }

        void setFavoriteToy(char* favoriteToy){
            delete this->favoriteToy;
            this->favoriteToy = new char(strlen(favoriteToy) + 1);
            strcpy(this->favoriteToy, favoriteToy);
        }

        void printData(){
            cout<<"Name: "<<getName()<<endl;
            cout<<"SSName: "<<getSSName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"FavoriteToy: "<<favoriteToy<<endl;
        }
};

class Employee:public Person{
    private:
        char* companyID;
        char* title;
        char* startDate;
        Spouse sp;
        Division div;
        vector<JobDescription>jobDesc_vec;
        vector<Child>ch_vec;
        void printJobDesc(){
            cout<<"\nJob description: "<<endl;
            for(int i = 0; i < getLenJD(); i++){
                jobDesc_vec[i].printData();
            }
        }

        void printChildren(){
            cout<<"\nChildren: "<<endl;
            for(int i = 0; i < getNumChild(); i++){
                ch_vec[i].printData();
            }
        }
    public:
        Employee():Person(){
            companyID = new char(4);
            strcpy(companyID, "cID");
            title = new char(6);
            strcpy(title, "title");
            startDate = new char(1);
            strcpy(startDate, "");
            Division d;
            div.copyFunc(d);
            JobDescription jbd;
            jobDesc_vec.push_back(jbd);
        }

        Employee(char* name, char* SSName, int age, char* companyID, char* title, char* startDate, Division &d, JobDescription &jbd):Person(name, SSName, age){
            this->companyID = new char(strlen(companyID) + 1);
            strcpy(this->companyID, companyID);
            this->title = new char(strlen(title) + 1);
            strcpy(this->title, title);
            this->startDate = new char(strlen(startDate) + 1);
            strcpy(this->startDate, startDate);
            div.copyFunc(d);
            jobDesc_vec.push_back(jbd);
        }

        ~Employee(){
            delete companyID;
            delete title;
            delete startDate;
        }

        char* getCompanyID(){
            return companyID;
        }

        char* getTitle(){
            return title;
        }

        char* getStartDate(){
            return startDate;
        }

        void setCompanyID(char* companyID){
            delete this->companyID;
            this->companyID = new char(strlen(companyID) + 1);
            strcpy(this->companyID, companyID);
        }

        void setTitle(char *title){
            delete this->title;
            this->title = new char(strlen(title) + 1);
            strcpy(this->title, title);
        }

        void setStartDate(char* startDate){
            delete this->startDate;
            this->startDate = new char(strlen(startDate) + 1);
            strcpy(this->startDate, startDate);
        }

        void setDivision(Division &d){
            div.copyFunc(d);
        }

        Division* getDivision(){
            return &div;
        }

        void setSpouse(Spouse &s){
            sp.copyFunc(s);
        }

        Spouse* getSpouse(){
            return &sp;
        }

        void addJobDsec(JobDescription &j){
            jobDesc_vec.push_back(j);
        }

        int getLenJD(){
            return jobDesc_vec.size();
        }

        JobDescription* getJobDesc(int idx){
            if(0 <= idx && idx < getLenJD())
                return &jobDesc_vec[idx];
            else return NULL;
        }

        void insertJobDesc(int idx, JobDescription &j){
            if(0 <= idx && idx < getLenJD()){
                    jobDesc_vec.insert(jobDesc_vec.begin() + idx, j);
            }
            else cout<<"Wrong position."<<endl;
        }

        void eraseJobDesc(int idx){
            if(0 <= idx && idx < getLenJD()){
                if(getLenJD() == 1)
                    cout<<"Not able erase."<<endl;
                else{
                   jobDesc_vec.erase(jobDesc_vec.begin() + idx);
                }
            }else{
                cout<<"Wrong position."<<endl;
            }
        }

        void popJobDesc(){
            if(getLenJD() == 1) cout<<"Not able erase."<<endl;
            else jobDesc_vec.pop_back();
        }

        void addChild(Child &c){
            ch_vec.push_back(c);
        }

        int getNumChild(){
            return ch_vec.size();
        }

        Child* getChild(int idx){
            if(0 <= idx && idx < getNumChild())
                return &ch_vec[idx];
            else return NULL;
        }

        void insertChild(int idx, Child &c){
            if(0 <= idx && idx < getNumChild()){
                    ch_vec.insert(ch_vec.begin() + idx, c);
            }
            else cout<<"Wrong position."<<endl;
        }

        void eraseChild(int idx){
            if(0 <= idx && idx < getNumChild()){
                ch_vec.erase(ch_vec.begin() + idx);
            }else{
                cout<<"Wrong position."<<endl;
            }
        }

        void popChild(){
            ch_vec.pop_back();
        }

        void printData(){
            cout<<"\n\nName: "<<getName()<<endl;
            cout<<"SSName: "<<getSSName()<<endl;
            cout<<"Age: "<<getAge()<<endl;
            cout<<"Company ID: "<<companyID<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Startdate: "<<startDate<<endl;
            cout<<"Division: "<<endl;
            div.printData();
            cout<<"Spouse: "<<endl;
            sp.printData();
            printJobDesc();
            printChildren();
        }
};

int main(){
    //2. Division болон JobDescription классуудын хэд хэдэн объект байгуул.
    Division div[3];
    JobDescription jd[3];
    int i;
    for(i = 0; i < 3; i++){
        char dName[10];
        cout<<"\nEnter division name in "<<i + 1<<" element"<<endl;
        cout<<"Name: ";
        cin>>dName;
        div[i].setDivisionName(dName);
        char desc[10];
        cout<<"\nEnter job description in "<<i + 1<<" element"<<endl;
        cout<<"Description: ";
        cin>>desc;
        jd[i].setDescription(desc);
    }

    //3. Employee классын хэд хэдэн объект байгуулж тус бүрийн Division, JobDescription –ийг зааж өг.
    Employee a("Bagaa", "MT01252114", 20, "Sync2325", "Sync Systems LLC", "2021.08.18", div[0], jd[0]);
    a.addJobDsec(jd[1]);
    a.addJobDsec(jd[2]);
    a.addJobDsec(jd[3]);
    Employee b("Galaa", "TL89251214", 32, "Malo2325", "Malo LLC", "2011.06.11", div[1], jd[0]);
    b.addJobDsec(jd[1]);
    b.addJobDsec(jd[2]);
    b.addJobDsec(jd[0]);
    b.addJobDsec(jd[1]);
    Employee c("Bat", "OJ98262214", 23, "Tbo2325", "TBO LLC", "2016.07.06", div[3], jd[0]);
    c.addJobDsec(jd[1]);
    c.addJobDsec(jd[3]);

    //4. Employee классын объект тус бүрд Spouse, Child – уудыг тохируулж өг
    Spouse as, bs("Otgoo", "DB91212435", 30, "2013.01.08"), cs;
    Child ch[3];
    for(i = 0; i < 1; i++){
        cout<<"Child: "<<endl;
        char name[10], ssname[10], age, ft[10];
        cout<<"Name: ";
        cin>>name;
        ch[i].setName(name);
        cout<<"SSName: ";
        cin>>ssname;
        ch[i].setSSName(ssname);
        cout<<"Age: ";
        cin>>age;
        ch[i].setAge(age);
        cout<<"Favorite toy: ";
        cin>>ft;
        ch[i].setFavoriteToy(ft);
    }
    a.setSpouse(as);
    b.setSpouse(bs);
    b.addChild(ch[0]);
    b.addChild(ch[1]);
    b.addChild(ch[2]);
    c.setSpouse(cs);
    c.addChild(ch[0]);

    //5. Employee классын объект тус бүрийн бүх мэдээллийг хэвлэ.
    a.printData();
    b.printData();
    c.printData();
    return 0;
}

