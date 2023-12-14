//Parte 2 Ej 3 en C++

#include <iostream>
#include <string>
#include <vector>

enum EstadoAsistencia {
    ASISTIO,
    FALTA,
    TARDANZA
};

struct Asistencia {
    std::string fecha;
    std::string materia;
    EstadoAsistencia estado;
};

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Asistencia> asistencias;
};

void registrarAsistencia(Estudiante& estudiante, const Asistencia& asistencia) {
    estudiante.asistencias.push_back(asistencia);
}

void mostrarAsistencias(const Estudiante& estudiante) {
    std::cout << "Asistencias de " << estudiante.nombre << ":\n";
    for (const auto& asistencia : estudiante.asistencias) {
        std::string estado;
        switch (asistencia.estado) {
            case ASISTIO:
                estado = "Asistió";
                break;
            case FALTA:
                estado = "Falta";
                break;
            case TARDANZA:
                estado = "Tardanza";
                break;
        }
        std::cout << "- Fecha: " << asistencia.fecha << " - Materia: " << asistencia.materia << " - Estado: " << estado << "\n";
    }
}

int main() {
    Estudiante estudiante1 = {"Juan", 20, 8.5};
    Asistencia asistencia1 = {"2023-01-15", "Matemáticas", ASISTIO};
    Asistencia asistencia2 = {"2023-01-16", "Historia", FALTA};

    registrarAsistencia(estudiante1, asistencia1);
    registrarAsistencia(estudiante1, asistencia2);

    mostrarAsistencias(estudiante1);

    return 0;
}
