#include "shapes.h"

/*Shape2D class methods*/
void Shape2D::ShowArea() const
{
    cout << this->Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const
{
    if(this->Area() > rhs.Area())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Square class methods*/

/*Triangle class methods*/

/*Circle class methods*/

////////////////////////*BREAK*///////////////////////

/*Shape3D class methods*/

/*TriangularPyramid class methods*/

/*Cylinder class methods*/

/*Sphere class methods*/