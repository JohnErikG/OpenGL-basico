#pragma once
class vector2_2
{
	float x, y;
public:	
	vector2_2() : x(0.0), y(0.0) {}
	explicit vector2_2(const float x_,const  float y_) : x(x_), y(y_) {}
	float getx() const;
	float gety() const;


};

