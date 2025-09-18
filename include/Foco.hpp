#pragma once
#include <EstadoFoco.hpp>

class Foco
{
private:
    EstadoFoco estadoActual;    

public:
    Foco() { estadoActual=false; }
    ~Foco() {}
    void Encender(){}
    void Apagar(){}
    EstadoFoco MostrarEstado(){}
};