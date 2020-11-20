//main
#include <iostream>
#include<memory>
#include<vector>
#include "shape.h"
#include "line.h"
#include "circle.h"
/*
Create a Shape pointer of type Line
Create vector of Shape pointers
iterate with auto
*/
using std::unique_ptr; using std::make_unique;

int main() 
{
	Circle* ptr_circle = nullptr;//declare a pointer to Circle but it's currently pointing to nothing
	//can also make it = 0 or = NULL and it would be the same thing.
	//not initializing it may make the pointer point to something that was there before, giving weird/inconsistent results
	
	Circle circle0;
	
	ptr_circle = &circle0;//now ptr_circle is pointing to something that exists
	ptr_circle->draw();//dereferencing the pointer (using * behind the scenes)
	(*ptr_circle).draw();//this also works since *ptr_circle is just the object circle0.

	Shape* s = nullptr;
	Circle c;
	c.draw();
	s = &c;
	s->draw();//this works because Shape is an abstract class and Circle is inheriting from Shape
	
	
	unique_ptr<Shape> shape;
	
	shape = make_unique<Circle>();

	shape = make_unique<Line>();

	unique_ptr<Shape> circle = make_unique<Circle>();
	circle->draw();

	unique_ptr<Shape> line = make_unique<Line>();
	line->draw();
	std::cout<<"\n\n";
	std::vector<unique_ptr<Shape>> shapes;
	shapes.push_back(std::move(circle));
	shapes.push_back(std::move(line));

	for(auto& shape: shapes)
	{
		shape->draw();
		//out<<*shape
	}
	Shape* ptr = new Circle[3];
	ptr[0].draw();

	//use ptr

	std::cout<<"pointer to pointer dyanmic array"\n;
	Shape** shapes1 = new Shape*[3];//pointer to a pointer of type Shape
	shapes1[0] = new Circle();
	shapes1[1] = new Line();
	shapes1[2] = new Circle();

	shapes1[0]->draw();
	shapes1[1]->draw();
	shapes1[2]->draw();

	std::cout<<"\n ENDpointer to pointer dynamic array\n";



	Circle circles[3];//array of 3 circles...created on the stack
	circles[0].draw();
	circles[1].draw();
	circles[2].draw();

	Circle c = circles[0];
	c.draw();

	
	return 0;
}