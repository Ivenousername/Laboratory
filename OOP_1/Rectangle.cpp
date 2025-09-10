#include "Rectangle.h"
Rectangle::Rectangle(int dot = 1, int lefngth = 1, int width = 1)
{
}
void Rectangle::setDot(int dot) {
	dot = dot;
}
void Rectangle::setLength(int length) {
	length = length;
}
void Rectangle::setWidth(int width) {
	width = width;
}

Rectangle::Rectangle(int dot, int length, int width)
	: dot(dot), length(length), width(width)
{
	if (length < 0) length * -1;
	else if (length == 0) length = 1;
	if (width < 0) width * -1;
	else if (width == 0) width = 1;
}
