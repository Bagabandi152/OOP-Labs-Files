#include <iostream>
#include <string.h>
#include <math.h>
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
    Point startVertex;
    float side;
public:
    Shape(){
        name = new char(1);
        strcpy(name, "");
        float side = 1;
    }
    Shape(Point vertex, float a, char *name = ""){
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
        startVertex = vertex;
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
    void setAside(float a){
        side = a;
    }
    Point* getVertex(){
        return &startVertex;
    }
    void setVertex(Point pt){
        startVertex = pt;
    }
};
class TwoDimensionalShape:public Shape{
public:
    TwoDimensionalShape(): Shape(){}
    TwoDimensionalShape(Point vertex, float a, char*name = ""): Shape(vertex, a, name){}
    float findArea();
    float findPerimeter();
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
    void calcOtherPoints(Point lt_p, float side){
       B.x = lt_p.x + side;
       B.y = lt_p.y;
       C.x = lt_p.x + side;
       C.y = lt_p.y - side;
       D.x = lt_p.x;
       D.y = lt_p.y - side;
    }
public:
    Square():TwoDimensionalShape(){
        Point A(-1, 1);
        float a = 2;

        startVertex = A;
        side = a;
        calcOtherPoints(startVertex, side);
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
        calcOtherPoints(startVertex, side);
    }
    void setLTpoint(Point lt_p){
        startVertex = lt_p;
        calcOtherPoints(startVertex, side);
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
    void calcOtherPoints(Point tp, float a){
        B.x = tp.x + side/2;
        B.y = tp.y - sqrt(3)/2*side;
        C.x = tp.x - a/2;
        C.y = tp.y - sqrt(3)/2*side;
    }
public:
    RightTriangle(): TwoDimensionalShape(){
        Point A(0, 1);
        startVertex = A;
        float a = 3;
        side = a;
        calcOtherPoints(startVertex, side);
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
        calcOtherPoints(startVertex, side);
    }
    void setTpoint(Point pt){
        startVertex = pt;
        calcOtherPoints(startVertex, side);
    }
    void getData(){
        startVertex<<"A";
        B<<"B";
        C<<"C";
        cout<<"Name: "<<name<<endl;
        cout<<"A side: "<<side<<endl;
    }
};

int main(){
    Point ct(1, 1), st(-2, 2), tt(2, 2);

    Circle c1(ct, 3, "C1");
    cout<<"Circle: "<<endl;
    c1.getData();
    cout<<"Area: "<<c1.findArea()<<endl;
    cout<<"Length: "<<c1.findPerimeter();
    cout<<"\n\n";

    Square s1(st, 2, "S1");
    cout<<"Square: "<<endl;
    s1.getData();
    cout<<"Area: "<<s1.findArea()<<endl;
    cout<<"Length: "<<s1.findPerimeter();
    cout<<"\n\n";

    RightTriangle rt1(tt, 2, "RT1");
    cout<<"RightTrangle: "<<endl;
    rt1.getData();
    cout<<"Area: "<<rt1.findArea()<<endl;
    cout<<"Length: "<<rt1.findPerimeter();
    cout<<"\n\n";

    return 0;
}
