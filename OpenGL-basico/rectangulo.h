#pragma once
#include "Utils/vector3.h"

class rectangulo
{
private:
		vector3 a_, b_ , c_, d_ ;

public:
	explicit rectangulo(const vector3& a, const vector3& b, const vector3& c,const  vector3& d) : a_(a), b_(b), c_(c), d_(d) {}

	const vector3& get_a() const;
	const vector3& get_b() const;
	const vector3& get_c() const;
	const vector3& get_d() const;
};

