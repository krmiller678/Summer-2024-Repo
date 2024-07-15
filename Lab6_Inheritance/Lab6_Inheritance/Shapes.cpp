#include "Shapes.h"
#include <iostream>
using std::cout; using std::endl;

// Shape2D
void Shape2D::ShowArea() const
{
	cout << GetName2D() << endl;
	cout << Area() << endl;
}
bool Shape2D::operator>(const Shape2D& rhs) const
{
	if (this->Area() > rhs.Area())
		return true;
	return false;
}
bool Shape2D::operator<(const Shape2D& rhs) const
{
	if (this->Area() < rhs.Area())
		return true;
	return false;
}
bool Shape2D::operator==(const Shape2D& rhs) const
{
	if (this->Area() == rhs.Area())
		return true;
	return false;
}

// Shape3D
void Shape3D::ShowVolume() const
{
	cout << GetName3D() << endl;
	cout << Volume() << endl;
}
bool Shape3D::operator>(const Shape3D& rhs) const
{
	if (this->Volume() > rhs.Volume())
		return true;
	return false;
}
bool Shape3D::operator<(const Shape3D& rhs) const
{
	if (this->Volume() < rhs.Volume())
		return true;
	return false;
}
bool Shape3D::operator==(const Shape3D& rhs) const
{
	if (this->Volume() == rhs.Volume())
		return true;
	return false;
}

// Now for the Shapes!!
// 2D virtuals needed: Scale, Display, Area, GetName2D
// 3D virtuals needed: Scale, Display, Volume, GetName3D

// Square
Square::Square(float side)
{
	_side = side;
}
void Square::Scale(float scaleFactor)
{
	_side *= scaleFactor;
}
void Square::Display() const
{
	cout << "The area of the Square is : " << Area() << endl;
	cout << "Length of a side : " << _side << endl;
}
float Square::Area() const
{
	return (_side * _side);
}
string Square::GetName2D() const
{
	return "The area of the Square is : ";
}

// Triangle
Triangle::Triangle(float base, float height)
{
	_base = base;
	_height = height;
}
void Triangle::Scale(float scaleFactor)
{
	_base *= scaleFactor;
	_height *= scaleFactor;
}
void Triangle::Display() const
{
	cout << "The area of the Triangle is : " << Area() << endl;
	cout << "Base: " << _base << endl;
	cout << "Height: " << _height << endl;
}
float Triangle::Area() const
{
	return (0.5f * _base * _height);
}
string Triangle::GetName2D() const
{
	return "The area of the Triangle is : ";
}

// Circle
Circle::Circle(float radius)
{
	_radius = radius;
}
void Circle::Scale(float scaleFactor)
{
	_radius *= scaleFactor;
}
void Circle::Display() const
{
	cout << "The area of the Circle is : " << Area() << endl;
	cout << "Radius: " << _radius << endl;
}
float Circle::Area() const
{
	return (PI * _radius * _radius);
}
string Circle::GetName2D() const
{
	return "The area of the Circle is : ";
}

// TriangularPyramid
TriangularPyramid::TriangularPyramid(float height, float base, float height2)
	: Triangle(base, height2), _height(height)
{
}
void TriangularPyramid::Scale(float scaleFactor)
{
	_height *= scaleFactor;
	Triangle::Scale(scaleFactor);
}
void TriangularPyramid::Display() const
{
	cout << "The volume of the TriangularPyramid is : " << Volume() << endl;
	cout << "The height is: " << _height << endl;
	Triangle::Display();
}
float TriangularPyramid::Volume() const
{
	return (Triangle::Area() * _height / 3);
}
string TriangularPyramid::GetName3D() const
{
	return "The volume of the TriangularPyramid is : ";
}

// Cylinder
Cylinder::Cylinder(float height, float radius)
	: Circle(radius), _height(height)
{
}
void Cylinder::Scale(float scaleFactor)
{
	_height *= scaleFactor;
	Circle::Scale(scaleFactor);
}
void Cylinder::Display() const
{
	cout << "The volume of the Cylinder is : " << Volume() << endl;
	cout << "The height is: " << _height << endl;
	Circle::Display();
}
float Cylinder::Volume() const
{
	return (Circle::Area() * _height);
}
string Cylinder::GetName3D() const
{
	return "The volume of the Cylinder is : ";
}

// Sphere
Sphere::Sphere(float radius)
	: Circle(radius), _radius(radius)
{
}
void Sphere::Scale(float scaleFactor)
{
	_radius *= scaleFactor;
	Circle::Scale(scaleFactor);
}
void Sphere::Display() const
{
	cout << "The volume of the Sphere is : " << Volume() << endl;
	Circle::Display();
}
float Sphere::Volume() const
{
	return (Circle::Area() * _radius * 4 / 3);
}
string Sphere::GetName3D() const
{
	return "The volume of the Sphere is : ";
}

