#include <iostream>
#include <memory>
using namespace std;

class Empleado{
    private: // Nacen de la relacion tienen
        char nombre[10];        // 10B
        int edad;              // 4B
        char direccion[255];    // 255B
        int telefono;           // 4B
        public: // Interfaz y Nace de la relacion usa
    int LeerEdad(){
        return edad;
    }
}; // -> 273B

int main( int argc, char const *argv[])
{
    //Tamaño de memoria Estatica
    //Enteros
    cout << "Tamaño de int " << sizeof(int) << endl;
    cout << "Tamaño de long " << sizeof(long) << endl;
    //Punteros
    cout << "Tamaño de float " << sizeof(float) << endl;
    cout << "Tamaño de double " << sizeof(double) << endl;
    //Bytes
    cout << "Tamaño de char " << sizeof(char) << endl;
    cout << "Tamaño de byte " << sizeof(byte) << endl;
    cout << "Tamaño de bool " << sizeof(bool) << endl;

    //Tamaño tipos no nativos
    Empleado empleados[10]; // <- 2730B
    cout << "Tamaño Empleado " << sizeof(Empleado) << endl;
    cout << "Empleados " << empleados[0].LeerEdad() << endl;

    // Casteos
    int a = 37;
    char b = (char)a;
    cout << b << endl;

    // Punteros en C y C++
    int* dirA = (int*)malloc(sizeof(int));  // C
    *dirA = 24;

    int* dirB = new int(24);                // C++

    // Smart Pointer
    unique_ptr<int> dirC;

    cout << *dirA << endl;
    cout << *dirB << endl;

    return 0;
}