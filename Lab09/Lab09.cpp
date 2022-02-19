#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#define pi 3.1416
using namespace std;
class Point {
public:
    float x, y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    void operator<<(char s[]){
        cout<< s << "(" << this->x << ", " << this->y << ")" << endl;
    }
};

class Shape{
protected:
    char* name;
    float side;
public:
    Shape(){
        name = new char(1);
        strcpy(name, "");
        side = 1;
    }
    Shape(float a, char *name = ""){
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
        side = a;
    }
    ~Shape(){
        delete name;
    }
    char* getName(){
        return name;
    }
    float getAside(){
        return side;
    }
    virtual float findPerimeter() = 0;
};
class TwoDimensionalShape:public Shape{
protected:
    Point startVertex;
public:
    TwoDimensionalShape(): Shape(){}
    TwoDimensionalShape(Point vertex, float a, char*name = ""): Shape(a, name){
        startVertex = vertex;
    }
    virtual float findArea() = 0;
};

class Circle:public TwoDimensionalShape{
public:
    Circle():TwoDimensionalShape(){}
    Circle(Point ct, float r, char *ner = ""):TwoDimensionalShape(ct, r, ner){}
    float findArea(){
        return side*side*pi;
    }
    float findPerimeter(){
        return 2*side*pi;
    }
    void setCenterPoint(Point ct){
        startVertex = ct;
    }
    void setRadius(float radius){
        side = radius;
    }
    void getData(){
        startVertex<<"CP";
        cout<<"Name: "<<name<<endl;
        cout<<"Radius: "<<side<<endl;
    }
};
class Square:public TwoDimensionalShape{
private:
    Point B;
    Point C;
    Point D;
    void calcOtherPoints(){
       B.x = startVertex.x + side;
       B.y = startVertex.y;
       C.x = startVertex.x + side;
       C.y = startVertex.y - side;
       D.x = startVertex.x;
       D.y = startVertex.y - side;
    }
public:
    Square():TwoDimensionalShape(){
        Point A(-1, 1);
        startVertex = A;
        calcOtherPoints();
    }
    Square(Point lt_p, float a, char *name = ""):TwoDimensionalShape(lt_p, a, name){
        setLTpoint(lt_p);
    }
    float findArea(){
        return side*side;
    }
    float findPerimeter(){
        return 4*side;
    }
    void setAside(float a){
        side = a;
        calcOtherPoints();
    }
    void setLTpoint(Point lt_p){
        startVertex = lt_p;
        calcOtherPoints();
    }
    void getData(){
        startVertex<<"A";
        B<<"B";
        C<<"C";
        D<<"D";
        cout<<"Name: "<<name<<endl;
        cout<<"A side: "<<side<<endl;
    }
};
class RightTriangle:public TwoDimensionalShape{
private:
    Point B;
    Point C;
    //BC taliig Ox tenkhlegtei parallel gj uzsen bolno.
    void calcOtherPoints(){
        B.x = startVertex.x + side/2;
        B.y = startVertex.y - sqrt(3)/2*side;
        C.x = startVertex.x - side/2;
        C.y = startVertex.y - sqrt(3)/2*side;
    }
public:
    RightTriangle(): TwoDimensionalShape(){
        Point A(0, 1);
        startVertex = A;
        calcOtherPoints();
    }
    RightTriangle(Point pt, float a, char *name = ""):TwoDimensionalShape(pt, a, name){
        setTpoint(pt);
    }
    float findArea(){
        return sqrt(3)*side*side/4;
    }
    float findPerimeter(){
        return 3*side/2;
    }
    void setAside(float a){
        side = a;
        calcOtherPoints();
    }
    void setTpoint(Point pt){
        startVertex = pt;
        calcOtherPoints();
    }
    void getData(){
        startVertex<<"A";
        B<<"B";
        C<<"C";
        cout<<"Name: "<<name<<endl;
        cout<<"A side: "<<side<<endl;
    }
};

struct Shape_square{
    char name[10];
    float area;
};
typedef Shape_square Shape_square;

void add_shape_area(Shape_square* sh_a, char *n, float a){
    sh_a->area = a;
    strcpy(sh_a->name, n);
}

int main(){
    Point ct(1, 1), st(-2, 2), tt(2, 2), ct1(1, -1);
    vector<TwoDimensionalShape*>vec;

    cout<<"Unsorted shapes: "<<endl;
    Circle c1(ct, 3, "C1");
    vec.push_back(&c1);
    cout<<"\nCircle: "<<endl;
    c1.getData();
    cout<<"Area: "<<c1.findArea()<<endl;
    cout<<"Perimeter: "<<c1.findPerimeter();
    cout<<"\n";

    Circle c2(ct, 2, "C2");
    vec.push_back(&c2);
    cout<<"\nCircle1: "<<endl;
    c2.getData();
    cout<<"Area: "<<c2.findArea()<<endl;
    cout<<"Perimeter: "<<c2.findPerimeter();
    cout<<"\n";

    Square s1(st, 2, "S1");
    vec.push_back(&s1);
    cout<<"\nSquare: "<<endl;
    s1.getData();
    cout<<"Area: "<<s1.findArea()<<endl;
    cout<<"Perimeter: "<<s1.findPerimeter();
    cout<<"\n";

    RightTriangle rt1(tt, 2, "RT1");
    vec.push_back(&rt1);
    cout<<"\nRightTrangle: "<<endl;
    rt1.getData();
    cout<<"Area: "<<rt1.findArea()<<endl;
    cout<<"Perimeter: "<<rt1.findPerimeter();
    cout<<"\n";

    int i, j;
    TwoDimensionalShape *key;

    for (i = 1; i < vec.size(); i++)
    {
        key = vec[i];
        j = i - 1;

        while (j >= 0 && vec[j]->findArea() > key->findArea())
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }


    cout<<"\n\nSorted shapes: "<<endl;
    for (vector<TwoDimensionalShape*>::iterator i = vec.begin(); i != vec.end(); ++i) {
        cout<<"Name: "<<(*i)->getName()<<" Area:"<<(*i)->findArea()<<endl;
    }

    return 0;
}


