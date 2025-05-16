#pragma once
class posicionPer
{
private :
	float x, y, z;
	
public:
	posicionPer(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	void setPosicion(float _x, float _y, float _z) {
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}
	float getX() { return this->x; }
	float getY() { return this->y; }
	float getZ() { return this->z; }
	void setX(float _x) { this->x = _x; }
	void setY(float _y) { this->y = _y; }
	void setZ(float _z) { this->z = _z; }

};

