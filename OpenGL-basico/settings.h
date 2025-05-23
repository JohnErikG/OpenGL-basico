#pragma once




enum  velocidades {
	vel1, vel2, vel3
};

class settings
{
	static settings* instance;
public:
	velocidades velocidades = vel2;
	bool wireframe = false, textura = true, facetado = false;
	bool luz1 = false, luz2 = true, luz3 = false;
	
	static settings* getInstance();

};

