#include "boton.hpp"

using namespace std;
class MiBoton : public Boton {
public:
    using Boton::Boton; // hereda constructor

    void onClick() override {
        cout<<"¡Mi botón fue presionado!";
    }
};
