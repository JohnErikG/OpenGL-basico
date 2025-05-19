#pragma once


enum colorDeLuces {
	luz1, luz2, luz3
};;

enum  velocidades {
	vel1, vel2, vel3
};

class settings
{
	static settings* instance;
public:
	velocidades velocidades = vel2;
	bool wireframe = false, textura = false, facetado = false;
	colorDeLuces colorDeLuces = luz1;

	static settings* getInstance();

};

