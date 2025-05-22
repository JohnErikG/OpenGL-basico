#include "renderMenu.h"
#include "boton1.hpp"
#include "timer.h"
#include "gamehub.h"
#include "rectangulo.h"
#include "Utils/vector3.h"


void renderMenu::dibujarRecR(const rectangulo& rec)
{
    glBegin(GL_QUADS);
	dibujarvec3(rec.get_a());
	dibujarvec3(rec.get_b());
	dibujarvec3(rec.get_c());
	dibujarvec3(rec.get_d());
	glEnd();
}

void renderMenu::dibujarvec3(const vector3& vec)
{
    glVertex3f(vec.get_x(), vec.get_y(),vec.get_z());
}

void renderMenu::dibujarBotonT(const boton1* bot)
{
    glBindTexture(GL_TEXTURE_2D, manejadorT::botont().getId());
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
	glVertex3f(bot->getIzqBx(), bot->getIzqBy(), 1);
    glTexCoord2f(1, 0);
	glVertex3f(bot->getDerBx(), bot->getDerBy(), 1);
    glTexCoord2f(1, 1);
	glVertex3f(bot->getDerAx(), bot->getDerAy(), 1);
    glTexCoord2f(0, 1);
	glVertex3f(bot->getIzqAx(), bot->getIzqAy(), 1);
    glEnd();
	
}

void renderMenu::dibujarBotonF(const boton1* bot)
{
	glBindTexture(GL_TEXTURE_2D, manejadorT::botonf().getId());
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(bot->getIzqBx(), bot->getIzqBy(), 1);
	glTexCoord2f(1, 0);
	glVertex3f(bot->getDerBx(), bot->getDerBy(), 1);
	glTexCoord2f(1, 1);
	glVertex3f(bot->getDerAx(), bot->getDerAy(), 1);
	glTexCoord2f(0, 1);
	glVertex3f(bot->getIzqAx(), bot->getIzqAy(), 1);
	glEnd();

	
}

void renderMenu::dibujarGH()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLoadIdentity();
	glOrtho(-1200, 1200, -720, 720, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	const Uint32 time = Timer::getSeconds();
	gamehub::getInstance()->DibujarTiempo(time);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

}
void renderMenu::dibujarInicio()
{
	// dibujar el menu
	glMatrixMode(GL_PROJECTION);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();
	glLoadIdentity();
    glOrtho(-600, 600, -360, 360,-1, 1 );
	glEnable(GL_TEXTURE_2D);

    glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

}
void renderMenu::dibujarBoton(const boton1* bot) {
	if (bot->get_click()) {
		dibujarBotonT(bot);
	}
	else {
		dibujarBotonF(bot);
	}

}
void renderMenu::dibujarsettings(menuDeSettings* Mset)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLoadIdentity();
	glOrtho(-600, 600, -360, 360, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, manejadorT::Settings().getId());
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex3f(-400, -250, 0);

	glTexCoord2f(1, 0);
	glVertex3f(400, -250, 0);

	glTexCoord2f(1, 1);
	glVertex3f(400, 250, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-400, 250, 0);
	glEnd();
	for (const auto bot : Mset->getBotones()) dibujarBoton(bot);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

}
