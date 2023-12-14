//Parte 1 Ej1 en C++

#include <iostream>
#include <string>

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
}

int main() {
    Estudiante estudiante1 = {"Juan", 20, 8.5};
    mostrarEstudiante(estudiante1);

    return 0;
}

