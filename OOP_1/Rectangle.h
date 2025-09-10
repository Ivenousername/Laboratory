#pragma once
class Rectangle
{
private:
	int dot;
	int length;
	int width;
public:

	Rectangle(int dot = 1, int length = 1, int width = 1);
	void setDot(int dot);
	void setLength(int length);
	void setWidth(int width);
	

	Rectangle(int dot, int length, int width)
		: dot(dot), length(length), width(width);
};

