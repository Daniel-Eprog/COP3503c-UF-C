#include <iostream>
#include <cmath>
#include <string>

#define PI 3.14159f

using namespace std;

class Shape
{
    public:

        virtual void Scale(float scaleFactor) = 0;
        virtual void Display() const = 0;

};

class Shape2D : virtual public Shape
{
    public:
        virtual float Area() const = 0;
        void ShowArea() const;
        virtual string GetName2D() const = 0;
        bool operator>(const Shape2D &rhs) const;
        bool operator<(const Shape2D &rhs) const;
        bool operator==(const Shape2D &rhs) const;

};

class Shape3D : virtual public Shape
{
    public:
        virtual float Volume() const = 0;
        void ShowVolume() const;
        virtual string GetName3D() const = 0;
        bool operator>(const Shape3D &rhs) const;
        bool operator<(const Shape3D &rhs) const;
        bool operator==(const Shape3D &rhs) const;
 
};

class Square : public Shape2D
{
    private:
        float length = 0.0f;
    
    public:
        float Area() const override;
        string GetName2D() const override;
};

class Triangle : public Shape2D
{
    private:
        float base = 0.0f;
        float height = 0.0f;

    public:
        float Area() const override;
        string GetName2D() const override;


};

class Circle : public Shape2D
{
    private:
        float radius = 0.0f;

    public:
        float Area() const override;
        string GetName2D() const override;
    
};

class TriangularPyramid : public Shape3D, private Triangle
{

};

class Cylinder : public Shape3D, private Circle
{

};

class Sphere : public Shape3D, private Circle
{

};