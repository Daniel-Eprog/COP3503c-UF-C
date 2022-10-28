#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#define PI 3.14159f

using namespace std;


class Shape
{
    public:
        virtual void Scale(float scaleFactor) = 0;
        virtual void Display() const = 0;
        virtual ~Shape(){};
};

/////////////////////////*2D Class Declarations*//////////////////////
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

class Square : public Shape2D
{
    private:
        float length = 0.0f;
    
    public:
        Square();
        Square(float side);
        float Area() const override;
        string GetName2D() const override;
        void Display() const override;
        void Scale(float scaleFactor) override;
};

class Triangle : public Shape2D
{
    private:
        float base = 0.0f;
        float height = 0.0f;

    public:
        Triangle();
        Triangle(float base, float height);
        float Area() const override;
        string GetName2D() const override;
        void Display() const override;
        void Scale(float scaleFactor) override;


};

class Circle : public Shape2D
{
    private:
        float radius = 0.0f;

    public:
        Circle();
        Circle(float radius);
        float Area() const override;
        string GetName2D() const override;
        void Display() const override;
        void Scale(float scaleFactor) override;
    
};

/////////////////////////////////*BREAK*////////////////////////////

///////////////////////*3D Class Declarations*//////////////////////

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

class TriangularPyramid : public Shape3D, private Triangle
{
    private:
        float height = 0.0f;
        Triangle triangle;
    public:
        TriangularPyramid();
        TriangularPyramid(float height, float tribase, float triheight);
        float Volume() const override;
        string GetName3D() const override;
        void Scale(float scaleFactor) override;
        void Display() const override;
        
};

class Cylinder : public Shape3D, private Circle
{
    private:
        float height = 0.0f;
        Circle circle;
    public:
        Cylinder();
        Cylinder(float height, float radius);
        float Volume() const override;
        string GetName3D() const override;
        void Scale(float scaleFactor) override;
        void Display() const override;

};

class Sphere : public Shape3D, private Circle
{
    private:
        float radius = 0.0f;
        Circle circle;
    public:
        Sphere();
        Sphere(float radius);
        float Volume() const override;
        string GetName3D() const override;
        void Scale(float scaleFactor) override;
        void Display() const override;

};

#endif