#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Materia {
    std::string nombre;
    float calificacion;
};

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
};

void agregarMateria(Estudiante& estudiante, const Materia& materia) {
    estudiante.materias.push_back(materia);
}

void eliminarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    auto it = std::remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                             [&nombreMateria](const Materia& materia) {
                                 return materia.nombre == nombreMateria;
                             });
    estudiante.materias.erase(it, estudiante.materias.end());
}

void mostrarMaterias(const Estudiante& estudiante) {
    std::cout << "Materias de " << estudiante.nombre << ":\n";
    for (const auto& materia : estudiante.materias) {
        std::cout << "- " << materia.nombre << " - Calificación: " << materia.calificacion << "\n";
    }
}

int main() {
    Estudiante estudiante1 = {"Juan", 20, 8.5};
    Materia materia1 = {"Matemáticas", 9.0};
    Materia materia2 = {"Historia", 7.5};

    agregarMateria(estudiante1, materia1);
    agregarMateria(estudiante1, materia2);

    mostrarMaterias(estudiante1);

    eliminarMateria(estudiante1, "Historia");

    mostrarMaterias(estudiante1);

    return 0;
}

