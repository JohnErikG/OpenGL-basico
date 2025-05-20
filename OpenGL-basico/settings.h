#pragma once




enum  velocidades {
	vel1, vel2, vel3
};

class settings
{
	static settings* instance;
public:
	velocidades velocidades = vel2;
	bool wireframe = false, textura = false, facetado = false;
	bool luz1 = false, luz2 = false, luz3 = false;
	
	static settings* getInstance();

};

