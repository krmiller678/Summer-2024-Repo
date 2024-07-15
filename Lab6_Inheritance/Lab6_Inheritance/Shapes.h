#pragma once

#define PI 3.14159f // anytime we use PI in code it will be replaced with this
#include <math.h>
#include <string>
using std::string;

class Shape
{
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape() {};
};


class Shape2D : virtual public Shape
{
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;

	/* Comparisons in terms of area */
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D & rhs) const;

	virtual ~Shape2D() {};
};

class Shape3D : virtual public Shape
{
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;

	/* Comparisons in terms of volume */
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;

	virtual ~Shape3D() {};

};

class Square : public Shape2D
{
private:
	float _side;
public:
	Square(float side = 0); // constructor
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Triangle : public Shape2D
{
private:
	float _base;
	float _height;
public:
	Triangle(float base = 0, float height = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Circle : public Shape2D
{
private:
	float _radius;
public:
	Circle(float radius = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class TriangularPyramid : public Shape3D, private Triangle
{
private:
	float _height;
public:
	TriangularPyramid(float height = 0, float base = 0, float height2 = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Cylinder : public Shape3D, private Circle
{
private:
	float _height;
public:
	Cylinder(float height = 0, float radius = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Sphere : public Shape3D, private Circle
{
private:
	float _radius;
public:
	Sphere(float radius = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};