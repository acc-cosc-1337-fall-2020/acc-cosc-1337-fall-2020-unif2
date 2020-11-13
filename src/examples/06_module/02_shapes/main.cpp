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
	
	return 0;
}

for(auto& game: games)
{
	out<<*game;//*game gives value

	
}

(unique ponter to tictactoe reference)