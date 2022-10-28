#include "shapes.h"

/*Shape2D class methods*/

void Shape2D::ShowArea() const
{
    cout << "The area of the " << this->GetName2D() << " is : " << this->Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const
{
    
    return this->Area() > rhs.Area();
    
}

bool Shape2D::operator<(const Shape2D &rhs) const
{
    return this->Area() < rhs.Area();
   
}

bool Shape2D::operator==(const Shape2D &rhs) const
{
    return this->Area() == rhs.Area();
}

/*Square class methods*/
float Square::Area() const 
{
    return pow(this->length, 2);
}

string Square::GetName2D() const 
{
    return "Square";

}

Square::Square()
{
    this->length = 0.0f;
}

Square::Square(float side)
{
    this->length = side;
}

void Square::Display() const
{
    cout << "The area of the " << this->GetName2D() << " is: " << this->Area() << endl;
    cout << "Length of a side: " << this->length << endl;
}

void Square::Scale(float scaleFactor)
{
    this->length = this->length * scaleFactor;
}

/*Triangle class methods*/
Triangle::Triangle()
{
    this->base = 0.0f;
    this->height = 0.0f;
}

Triangle::Triangle(float base, float height)
{
    this->base = base;
    this->height = height;
}

float Triangle::Area() const
{
    return (0.5 * this->base * this->height);
}

string Triangle::GetName2D() const
{
    return "Triangle";
}

void Triangle::Display() const
{
    cout << "The area of the " << this->GetName2D() << " is: " << this->Area() << endl;
    cout << "Base: " << this->base << endl;
    cout << "Height: " << this->height << endl;
}

void Triangle::Scale(float scaleFactor)
{
    this->base = this->base * scaleFactor;
    this->height = this->height * scaleFactor;
}

/*Circle class methods*/
Circle::Circle()
{
    this->radius = 0.0f;
}

Circle::Circle(float radius)
{
    this->radius = radius;
}

float Circle::Area() const
{
    return PI * pow(this->radius, 2);
}

string Circle::GetName2D() const
{
    return "Circle";
}

void Circle::Display() const
{
    cout << "The area of the " << this->GetName2D() << " is: " << this->Area() << endl;
    cout << "Radius: " << this->radius << endl;
}

void Circle::Scale(float scaleFactor)
{
    this->radius = this->radius * scaleFactor;
}

////////////////////////*BREAK*///////////////////////

/*Shape3D class methods*/

    void Shape3D::ShowVolume() const
    {
        cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl;
    }

    bool Shape3D::operator>(const Shape3D &rhs) const
    {
        return this->Volume() > rhs.Volume();
    }

    bool Shape3D::operator<(const Shape3D &rhs) const
    {
        return this->Volume() < rhs.Volume();
    }

    bool Shape3D::operator==(const Shape3D &rhs) const
    {
        return this->Volume() == rhs.Volume();
    }

/*TriangularPyramid class methods*/
    float TriangularPyramid::Volume() const
    {
        return ((1/3.0f) * triangle.Triangle::Area() * this->height);
    }
    
    string TriangularPyramid::GetName3D() const
    {
        return "TriangularPyramid";

    }

    TriangularPyramid::TriangularPyramid()
    {
        this->height = 0.0f;
        this->triangle = Triangle();

    }

    TriangularPyramid::TriangularPyramid(float height, float tribase, float triheight)
    {
        this->height = height;
        this->triangle = Triangle(tribase, triheight);
    }

    void TriangularPyramid::Scale(float scaleFactor)
    {
        this->height = this->height * scaleFactor;
        this->triangle.Triangle::Scale(scaleFactor);
    }

    void TriangularPyramid::Display() const
    {
        cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl;
        cout << "The height is: " << this->height << endl;
        triangle.Triangle::Display();
    }

/*Cylinder class methods*/
Cylinder::Cylinder()
{
    this->height = 0.0f;
    this->circle = Circle();
}

Cylinder::Cylinder(float height, float radius)
{
    this->height = height;
    this->circle = Circle(radius);
}

float Cylinder::Volume() const
{
    return (circle.Circle::Area() * this->height);
}

string Cylinder::GetName3D() const
{
    return "Cylinder";
}

void Cylinder::Scale(float scaleFactor)
{
    this->height = this->height * scaleFactor;
    this->circle.Circle::Scale(scaleFactor);
}

void Cylinder::Display() const
{
    cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl;
    cout << "The height is: " << this->height << endl;
    circle.Circle::Display();

}

/*Sphere class methods*/
Sphere::Sphere()
{
    this->radius = 0.0f;
    this->circle = Circle();
}

Sphere::Sphere(float radius)
{
    this->radius = radius;
    this->circle = Circle(radius);
}

float Sphere::Volume() const
{
    return ((4/3.0f) * this->circle.Circle::Area() * this->radius);
}

string Sphere::GetName3D() const
{
    return "Sphere";
}

void Sphere::Scale(float scaleFactor)
{
    this->radius = this->radius * scaleFactor;
    this->circle.Circle::Scale(scaleFactor);
}

void Sphere::Display() const
{
    cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl;
    circle.Circle::Display();

}