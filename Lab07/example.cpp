#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    int x, y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void operator<<(char s[]){
        cout<<s<<endl;
        cout << "(" << x << ", " << y << ")";
    }

    Point* operator+(Point p)   {
        Point add;
        add.x = x + p.x;
        add.y = y + p.y;
        return &add;
    }

    Point* operator-(Point p)   {
        Point subtract;
        subtract.x = x - p.x;
        subtract.y = y - p.y;
        return &subtract;
    }
};

class Shape {
protected:
    float height, width;
public:
    Shape() {
        height = 0;
        width = 0;
    }
    Shape(float h, float w) {
        height = h;
        width = w;
    }

    /*
    int Display() {
        //Do something..... Create a display function
        return 0;
    }
    int BoundingBox() {
        //Do something again......
        return 0;
    }
    */
    virtual float Area() const = 0;
    virtual float Circumference() const = 0;

    virtual ~Shape()  {};
};

class Circle: public Shape  {
    Point center;
    float radius;
public:
    Circle(): Shape()  {};
    Circle (Point p1, float r)  { //Takes center point object, and given radius.
        center = p1;
        radius = r;
    }
    virtual float Area() const override { // Calculates circle area
        return(M_PI * radius * radius);
    }
    virtual float Circumference() const override { // Calculates circumference
        return(float (M_PI * 2 * radius));
    }
    virtual ~Circle() {};
};

class Square: public Shape  {
    Point first, second, third, fourth;
public:
    Square(): Shape()  {};
    Square(Point p1, Point p2, Point p3, Point p4) { // Takes four point arguments and initializes them
        first = p1;
        second = p2;
        third = p3;
        fourth = p4;
        height = second.x - first.x; //calculates the height and width from points
        width = third.y - first.y;
    }
    virtual float Circumference() const override  {
        return 0; //Errors without the return statement
    }
    virtual float Area() const override{ // Calculates area by measuring the difference between given points
        return(height * width);
    }
    virtual ~Square() {};
};

class Triangle: public Shape    {
    Point first, second, third;
public:
    Triangle(): Shape()  {};
    Triangle(Point p1, Point p2, Point p3)  { // Takes three point arguments and initializes them
        first = p1;
        second = p2;
        third = p3;
        height = third.y - first.y;// due to the nature of the question, this only works for flat triangles.
        width = second.x - first.x;
    }
    virtual float Circumference() const override  {
        return 0; //Errors without the return statement
    }
    virtual float Area() const override {
        return ((height * width) / 2);
    }
    virtual ~Triangle() {};
};


int main()  {
    Point p1(0, 0), p2(25, 0), p3(0, 25), p4(25, 25), p5(20, 0), p6(30, 0);
    Circle c1(p1, 23); // Circle with origin (0, 0) and a radius of 23
    Square s1(p1, p2, p3, p4); // Square with 4 points and the origin
    Triangle t1(p1, p5, p6); // Extraordinarily flat triangle with origin
    cout << c1.Circumference() << endl;
    cout << s1.Area() << endl;
    cout << t1.Area() << endl;
}
