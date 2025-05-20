#include "renderMenu.h"

void renderMenu::dibujarBotonT(const boton1* bot)
{
    glBindTexture(GL_TEXTURE_2D, bot->get_textura());
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(bot->getIzqAx(), bot->getIzqAy(), 1);
    glTexCoord2f(1, 0);
    glVertex3f(bot->getIzqBx(), bot->getIzqBy(), 1);
    glTexCoord2f(1, 1);
    glVertex3f(bot->getDerBx(), bot->getDerBy(), 1);
    glTexCoord2f(0, 1);
    glVertex3f(bot->getIzqBx(), bot->getIzqBy(), 1);
    glEnd();
}

void renderMenu::dibujarBotonF(const boton1* bot)
{
    glBindTexture(GL_TEXTURE_2D, bot->get_textura2());
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(bot->getIzqAx(), bot->getIzqAy(), 1);
    glTexCoord2f(1, 0);
    glVertex3f(bot->getIzqBx(), bot->getIzqBy(), 1);
    glTexCoord2f(1, 1);
    glVertex3f(bot->getDerBx(), bot->getDerBy(), 1);
    glTexCoord2f(0, 1);
    glVertex3f(bot->getIzqBx(), bot->getIzqBy(), 1);
    glEnd();
}

void renderMenu::dibujarGH()
{
}
void renderMenu::dibujarInicio()
{
	// dibujar el menu
//	glPushMatrix();
//	glTranslatef(0.0f, 0.0f, 0.0f);
//	glScalef(1.0f, 1.0f, 1.0f);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutWireCube(2.0f); // dibuja un cubo al centro de la pantalla
//	glPopMatrix();
}

void renderMenu::dibujarsettings(menuDeSettings* Mset)
{
}
