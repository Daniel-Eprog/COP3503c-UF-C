#include "shapes.h"
#include <vector>

using namespace std;

int main()
{

    	cout << std::fixed << setprecision(2);
    vector<Shape2D*> shapes2vector;

    Square * square1 = new Square(12.2f);
    Triangle * triangle1 = new Triangle(12.1f, 3.4f);
    Circle * circle1 = new Circle(10.4f);
    TriangularPyramid * pyramid1 = new TriangularPyramid(10.0f, 12.1f, 3.4f);
    Cylinder * cylinder1 = new Cylinder(10.0f, 10.4f);
    Sphere * sphere1 = new Sphere(10.4f);

    pyramid1->Display();
    triangle1->Display();
    cylinder1->Display();
    circle1->Display();
    sphere1->Display();
    

    shapes2vector.push_back(triangle1);
    shapes2vector.push_back(square1);
    shapes2vector.push_back(circle1);

    delete pyramid1;


    // for(size_t i = 0; i < shapes2vector.size(); i++)
    // {
    //     for(size_t j = 0; j < shapes2vector.size(); j++)
    //     {
    //         if(*shapes2vector[i] > *shapes2vector[j])
    //         {
    //             shapes2vector[i]->Display();
    //             cout << "is greater than " << endl;
    //             shapes2vector[j]->Display();
    //         }
    //         else if (*shapes2vector[i] == *shapes2vector[j])
    //         {
    //             shapes2vector[i]->Display();
    //             cout << "is equal to " << endl;
    //             shapes2vector[j]->Display();
    //         }
    //         else if(*shapes2vector[i] < *shapes2vector[j])
    //         {
    //             shapes2vector[i]->Display();
    //             cout << "is less than" << endl;
    //             shapes2vector[j]->Display();

    //         }
    //     }
    // }

    
    return 0;


}