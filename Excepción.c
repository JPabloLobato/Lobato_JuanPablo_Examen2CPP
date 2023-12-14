//Parte 2 Ej4 en C

#include <stdio.h>
#include <string.h>

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
    struct Asistencia asistencias[100];
    int numAsistencias;
};

enum CodigoError {
    EXITO,
    FECHA_INVALIDA,
    MATERIA_NO_REGISTRADA
};

int registrarAsistencia(struct Estudiante* estudiante, const struct Asistencia* asistencia) {
    // Validar la fecha (formato simplificado)
    if (strlen(asistencia->fecha) != 10 || asistencia->fecha[4] != '-' || asistencia->fecha[7] != '-') {
        return FECHA_INVALIDA;
    }

    // Validar la materia (simulado con una materia fija)
    if (strcmp(asistencia->materia, "Matemáticas") != 0 && strcmp(asistencia->materia, "Historia") != 0) {
        return MATERIA_NO_REGISTRADA;
    }

    if (estudiante->numAsistencias < 100) {
        estudiante->asistencias[estudiante->numAsistencias] = *asistencia;
        estudiante->numAsistencias++;
        return EXITO;
    } else {
        return FECHA_INVALIDA;
    }
}

int main() {
    struct Estudiante estudiante1 = {"Juan", 20, 8.5, {}, 0};
    struct Asistencia asistencia1 = {"2023-01-15", "Matemáticas", ASISTIO};
    struct Asistencia asistencia2 = {"2023-01-16", "Historia", FALTA};
    struct Asistencia asistenciaInvalida = {"2023-01", "Biología", TARDANZA};

    int resultado;

    resultado = registrarAsistencia(&estudiante1, &asistencia1);
    if (resultado != EXITO) {
        printf("Error al registrar asistencia: %d\n", resultado);
    }

    resultado = registrarAsistencia(&estudiante1, &asistencia2);
    if (resultado != EXITO) {
        printf("Error al registrar asistencia: %d\n", resultado);
    }

    resultado = registrarAsistencia(&estudiante1, &asistenciaInvalida);
    if (resultado != EXITO) {
        printf("Error al registrar asistencia: %d\n", resultado);
    }

    return 0;
}

