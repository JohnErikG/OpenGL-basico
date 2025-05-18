#include "gamehub.h"
#include "timer.h"


gamehub* gamehub::instance = nullptr;
void gamehub::init()
{
    if (instance == nullptr) {
        instance = new gamehub();
    }
}
void gamehub::update()
{
}
void gamehub::render()
{
}
void gamehub::cleanup()
{
    
}

void gamehub::DibujarTiempo(const Uint32 segundos )
{   
	Uint32 unidades = segundos % 10 ; // Unidades de tiempo en milisegundos
	Uint32 decimas = segundos / 10; // Decimas de tiempo en milisegundos
	Uint32 minutos = unidades / 60; // Minutos
	Uint32 centenas = minutos % 10; 
	Uint32 miles = centenas / 10; // Centenas de tiempo en milisegundos
    // Convertir milisegundos a segundos
    setTiempo(unidades, instance->segundos_unidades_);
    setTiempo(decimas , instance->segundos_decena_);
    setTiempo(centenas , instance->minutos_unidades_);
    setTiempo(miles, instance->minutos_decena_);

    // Calcular minutos y segundos

    // Formatear el tiempo como "MM:SS"
    
    // Renderizar el tiempo en la pantalla (aquí puedes usar tu función de renderizado)
    // Por ejemplo, usando SDL_ttf para renderizar texto:
	// renderizarTexto(tiempoFormateado, x, y);
	glDisable(GL_TEXTURE_2D); // Desactivar texturas si es necesario
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, -1, -1, -1, -1, -1); // Ajusta el tamaño de la ventana según tu configuración
	glColor3f(1.0f, 1.0f, 1.0f); // Establecer el color del texto (blanco en este caso)
//	const Uint32 sec = Timer::getSeconds(); // Obtener el tiempo actual

//std::cout << "Tiempo: " << sec << " segundos" << std::endl; // Imprimir el tiempo en la consola
}


void gamehub::setTiempo(Uint32 num, rectangulo pos) 
{
    switch  (num) {
    case 0:
        
        break;
    case 1:
        // Código para el caso 1
        break;
    case 2:
        // Código para el caso 2
        break;
    case 3:
        // Código para el caso 3
        break;
    case 4:
        // Código para el caso 4
        break;
    case 5:
        // Código para el caso 5
        break;
    case 6:
        // Código para el caso 6
        break;
    case 7:
        // Código para el caso 7
        break;
    case 8:
        // Código para el caso 8
        break;
    case 9:
        // Código para el caso 9
        break;
    default:
        // Código para el caso por defecto
        break;
    }

}
gamehub* gamehub::getInstance(){
    if (instance == nullptr) {
        instance = new gamehub();
    }
    return instance;
}



void update()
{
}
