/*class Circle{
private:
    char* name;
    Point cp;
    float r;
public:
    Circle(){
        name = new char(1);
        strcpy(name, "");
        r = 1;
    }
    Circle(Point ct, float r, char *ner = ""){
        cp = ct;
        this->r = r;
        name = new char(strlen(ner) + 1);
        strcpy(name, ner);
    }
    ~Circle(){
        delete name;
    }
    float findArea(){
        return r*r*pi;
    }
    float findPerimeter(){
        return 2*r*pi;
    }
    void setCenterPoint(Point ct){
        cp = ct;
    }
    void setRadius(float radius){
        r = radius;
    }
    void getData(){
        cp<<"CP";
        cout<<"Name: "<<name<<endl;
        cout<<"Radius: "<<r<<endl;
    }
};
class Square{
private:
    Point A;
    Point B;
    Point C;
    Point D;
    float a;
    char*name;
    void calcOtherPoints(Point lt_p, float side){
       B.x = lt_p.x + side;
       B.y = lt_p.y;
       C.x = lt_p.x + side;
       C.y = lt_p.y - side;
       D.x = lt_p.x;
       D.y = lt_p.y - side;
    }
public:
    Square(){
        name = new char(1);
        strcpy(name, "");
        A.x = -1;
        A.y = 1;
        a = 2;
        calcOtherPoints(A, a);
    }
    Square(Point lt_p, float a, char *name = ""){
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
        this->a = a;
        setLTpoint(lt_p);
    }
    ~Square(){
        delete name;
    }
    float findArea(){
        return a*a;
    }
    float findPerimeter(){
        return 4*a;
    }
    void setAside(float a){
        this->a = a;
        calcOtherPoints(A, a);
    }
    void setLTpoint(Point lt_p){
        A = lt_p;
        calcOtherPoints(A, a);
    }

    void getData(){
        A<<"A";
        B<<"B";
        C<<"C";
        D<<"D";
        cout<<"Name: "<<name<<endl;
        cout<<"A side: "<<a<<endl;
    }
};
class RightTriangle{
private:
    Point A;
    Point B;
    Point C;
    float a;
    char* name;
    //BC taliig Ox tenkhlegtei parallel gj uzsen bolno.
    void calcOtherPoints(Point tp, float side){
        B.x = tp.x + side/2;
        B.y = tp.y - sqrt(3)/2*side;
        C.x = tp.x - a/2;
        C.y = tp.y - sqrt(3)/2*side;
    }
public:
    RightTriangle(){
        name = new char(1);
        strcpy(name, "");
        A.x = 0;
        A.y = 1;
        a = 3;
        calcOtherPoints(A, a);
    }
    RightTriangle(Point pt, float a, char *name = ""){
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
        this->a = a;
        setTpoint(pt);
    }
    ~RightTriangle(){
        delete name;
    }
    float findArea(){
        return sqrt(3)*a*a/4;
    }
    float findPerimeter(){
        return 3*a/2;
    }
    void setAside(float a){
        this->a = a;
        calcOtherPoints(A, a);
    }
    void setTpoint(Point pt){
        A = pt;
        calcOtherPoints(A, a);
    }

    void getData(){
        A<<"A";
        B<<"B";
        C<<"C";
        cout<<"Name: "<<name<<endl;
        cout<<"A side: "<<a<<endl;
    }
};
*/
