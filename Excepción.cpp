//Parte 2 Ej 4 en C++

#include <iostream>
#include <vector>
#include <string>

enum EstadoAsistencia {
    ASISTIO,
    FALTA,
    TARDANZA
};

class FechaInvalidaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Fecha invalida.";
    }
};

class MateriaNoRegistradaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Materia no registrada.";
    }
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
    if (asistencia.fecha.length() != 10 || asistencia.fecha[4] != '-' || asistencia.fecha[7] != '-') {
        throw FechaInvalidaException();
    }

    if (asistencia.materia != "Matemáticas" && asistencia.materia != "Historia") {
        throw MateriaNoRegistradaException();
    }

    estudiante.asistencias.push_back(asistencia);
}

int main() {
    Estudiante estudiante1 = {"Juan", 20, 8.5};

    Asistencia asistencia1 = {"2023-01-15", "Matemáticas", ASISTIO};
    Asistencia asistencia2 = {"2023-01-16", "Historia", FALTA};
    Asistencia asistenciaInvalida = {"2023-01", "Biología", TARDANZA};  // Aquí estaba el error

    try {
        registrarAsistencia(estudiante1, asistencia1);
        registrarAsistencia(estudiante1, asistencia2);
        registrarAsistencia(estudiante1, asistenciaInvalida);
    } catch (const std::exception& e) {
        std::cerr << "Excepción atrapada: " << e.what() << std::endl;
    }

    return 0;
}
