#include "menuDeSettings.h"

menuDeSettings::menuDeSettings(const int width, const int height)
{
	// Constructor implementation
	// Initialize the menu with the given width and height
	// Load textures, set up buttons, etc.
}

std::array<Boton*, 7> menuDeSettings::getBotones() const
{
	return std::array<Boton*, 7>();
}

void menuDeSettings::click(int x, int y)
{
}

GLuint menuDeSettings::getTextureId() const
{
	return GLuint();
}
