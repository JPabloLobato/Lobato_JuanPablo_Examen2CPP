//Parte 2 Ej 2 en C

#include <stdio.h>
#include <string.h>

struct Materia {
    char nombre[50];
    double calificacion;  // Cambiado de float a double
};

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;  // Se mantiene como float si es necesario
    struct Materia materias[10];
    int numMaterias;
};

void agregarMateria(struct Estudiante* estudiante, const struct Materia* materia) {
    if (estudiante->numMaterias < 10) {
        estudiante->materias[estudiante->numMaterias] = *materia;
        estudiante->numMaterias++;
    } else {
        printf("El estudiante ya tiene el número máximo de materias.\n");
    }
}

void eliminarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i].nombre, nombreMateria) == 0) {
            // Mover las materias restantes hacia atrás para llenar el espacio eliminado
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                estudiante->materias[j] = estudiante->materias[j + 1];
            }
            estudiante->numMaterias--;
            return;
        }
    }
    printf("La materia no se encontró en las materias del estudiante.\n");
}

void mostrarMaterias(const struct Estudiante* estudiante) {
    printf("Materias de %s:\n", estudiante->nombre);
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf("- %s - Calificacion: %f\n", estudiante->materias[i].nombre, estudiante->materias[i].calificacion);
    }
}

int main() {
    struct Estudiante estudiante1 = {"Juan", 20, 8.5, {}, 0};
    struct Materia materia1 = {"Matematicas", 9.0};
    struct Materia materia2 = {"Historia", 7.5};

    agregarMateria(&estudiante1, &materia1);
    agregarMateria(&estudiante1, &materia2);

    mostrarMaterias(&estudiante1);

    eliminarMateria(&estudiante1, "Historia");

    mostrarMaterias(&estudiante1);

    return 0;
}



