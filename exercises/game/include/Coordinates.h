#ifndef __COORDINATES_H__
#define __COORDINATES_H__

#include <iostream>
#include <string>

class Coordinates { 
public:
	Coordinates(const Coordinates &coordinates)
	{
		x = coordinates.x;
		y = coordinates.y;
	}

	const Coordinates & operator=(const Coordinates &coordinates)
	{	
		if(this != &coordinates)
		{
			Coordinates(coordinates).swap(this*);
		}
		return *this;
	}
	void oordinates & operator+(const Coordinates &coordinates)
	{	
		x += coordinates.x;
		y += coordinates.y;
	}
	void oordinates & operator-(const Coordinates &coordinates)
	{	
		x -= coordinates.x;
		y -= coordinates.y;
	}
private:
	int x, y;
};

#endif // __COORDINATES_H__
