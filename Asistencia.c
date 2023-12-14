//Parte 2 Ej3 en C

#include <stdio.h>

enum EstadoAsistencia {
    ASISTIO,
    FALTA,
    TARDANZA
};

struct Asistencia {
    char fecha[20];
    char materia[50];
    enum EstadoAsistencia estado;
};

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia asistencias[100];  // Selecciona un tamaño máximo para el array
    int numAsistencias;
};

void registrarAsistencia(struct Estudiante* estudiante, const struct Asistencia* asistencia) {
    if (estudiante->numAsistencias < 100) {
        estudiante->asistencias[estudiante->numAsistencias] = *asistencia;
        estudiante->numAsistencias++;
    } else {
        printf("El estudiante ha alcanzado el número máximo de asistencias.\n");
    }
}

void mostrarAsistencias(const struct Estudiante* estudiante) {
    printf("Asistencias de %s:\n", estudiante->nombre);
    for (int i = 0; i < estudiante->numAsistencias; ++i) {
        const struct Asistencia* asistencia = &estudiante->asistencias[i];
        const char* estado;
        switch (asistencia->estado) {
            case ASISTIO:
                estado = "Asistio";
                break;
            case FALTA:
                estado = "Falta";
                break;
            case TARDANZA:
                estado = "Tardanza";
                break;
        }
        printf("- Fecha: %s - Materia: %s - Estado: %s\n", asistencia->fecha, asistencia->materia, estado);
    }
}

int main() {
    struct Estudiante estudiante1 = {"Juan", 20, 8.5, {}, 0};
    struct Asistencia asistencia1 = {"2023-01-15", "Matemáticas", ASISTIO};
    struct Asistencia asistencia2 = {"2023-01-16", "Historia", FALTA};

    registrarAsistencia(&estudiante1, &asistencia1);
    registrarAsistencia(&estudiante1, &asistencia2);

    mostrarAsistencias(&estudiante1);

    return 0;
}
