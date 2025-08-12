/*
================================================================================
💻 PROYECTO FINAL - SEMANA 4: SISTEMA INTEGRADOR
================================================================================
Archivo: proyecto_final.cpp
Objetivo: Integrar todos los conceptos aprendidos en un proyecto completo
Tiempo estimado: 8-12 horas
================================================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
================================================================================
🎯 DESCRIPCIÓN DEL PROYECTO FINAL
================================================================================

SISTEMA DE GESTIÓN ACADÉMICA COMPLETO

El proyecto consiste en crear un sistema que permita:
1. Gestionar información de estudiantes
2. Registrar calificaciones por materia
3. Calcular promedios y estadísticas
4. Generar reportes detallados
5. Simular diferentes escenarios académicos

CONCEPTOS INTEGRADOS:
✅ Variables y tipos de datos
✅ Operadores (aritméticos, lógicos, comparación)
✅ Estructuras condicionales (if-else, switch)
✅ Bucles (for, while, do-while)
✅ Arrays básicos
✅ Funciones simples
✅ Validación de datos
✅ Formateo de salida
✅ Menús interactivos

================================================================================
*/

// 🎯 CONSTANTES GLOBALES
const int MAX_ESTUDIANTES = 50;
const int MAX_MATERIAS = 10;
const double NOTA_MINIMA_APROBACION = 60.0;

// 🎯 ESTRUCTURAS DE DATOS (usando arrays paralelos)
string nombresEstudiantes[MAX_ESTUDIANTES];
int edadesEstudiantes[MAX_ESTUDIANTES];
string carrerasEstudiantes[MAX_ESTUDIANTES];
double calificaciones[MAX_ESTUDIANTES][MAX_MATERIAS];
string nombresMaterias[MAX_MATERIAS];
int totalEstudiantes = 0;
int totalMaterias = 0;

/*
================================================================================
🎓 EJEMPLO COMPLETO: FUNCIÓN DE DEMOSTRACIÓN
================================================================================
Esta función muestra cómo funciona el sistema con datos de ejemplo
================================================================================
*/

void cargarDatosEjemplo() {
    cout << "=== CARGANDO DATOS DE EJEMPLO ===" << endl;
    
    // Configurar materias
    nombresMaterias[0] = "Matemáticas";
    nombresMaterias[1] = "Física";
    nombresMaterias[2] = "Química";
    nombresMaterias[3] = "Programación";
    totalMaterias = 4;
    
    // Configurar estudiantes
    nombresEstudiantes[0] = "Ana García";
    edadesEstudiantes[0] = 20;
    carrerasEstudiantes[0] = "Ingeniería";
    calificaciones[0][0] = 85.5; // Matemáticas
    calificaciones[0][1] = 78.0; // Física
    calificaciones[0][2] = 92.5; // Química
    calificaciones[0][3] = 88.0; // Programación
    
    nombresEstudiantes[1] = "Carlos López";
    edadesEstudiantes[1] = 19;
    carrerasEstudiantes[1] = "Ingeniería";
    calificaciones[1][0] = 76.0;
    calificaciones[1][1] = 82.5;
    calificaciones[1][2] = 79.0;
    calificaciones[1][3] = 95.0;
    
    nombresEstudiantes[2] = "María Rodríguez";
    edadesEstudiantes[2] = 21;
    carrerasEstudiantes[2] = "Medicina";
    calificaciones[2][0] = 91.0;
    calificaciones[2][1] = 87.5;
    calificaciones[2][2] = 94.0;
    calificaciones[2][3] = 72.0;
    
    totalEstudiantes = 3;
    
    cout << "✅ Datos de ejemplo cargados:" << endl;
    cout << "   - " << totalEstudiantes << " estudiantes" << endl;
    cout << "   - " << totalMaterias << " materias" << endl;
    cout << "   - Calificaciones completas" << endl;
}

/*
================================================================================
📝 PLANTILLA: FUNCIÓN 1 - AGREGAR ESTUDIANTE
================================================================================
*/

void agregarEstudiante() {
    cout << "\n=== AGREGAR NUEVO ESTUDIANTE ===" << endl;
    
    // 🎯 TODO: Verificar si hay espacio disponible
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        cout << "❌ Error: No se pueden agregar más estudiantes (máximo " << MAX_ESTUDIANTES << ")" << endl;
        return;
    }
    
    // 🎯 TODO: Pedir datos del estudiante
    cout << "Ingrese los datos del estudiante " << (totalEstudiantes + 1) << ":" << endl;
    
    cout << "Nombre completo: ";
    cin.ignore();
    getline(cin, nombresEstudiantes[totalEstudiantes]);
    
    cout << "Edad: ";
    cin >> edadesEstudiantes[totalEstudiantes];
    
    // 🎯 TODO: Validar edad usando while
    while (edadesEstudiantes[totalEstudiantes] < 16 || edadesEstudiantes[totalEstudiantes] > 100) {
        cout << "Edad inválida. Ingrese una edad entre 16 y 100: ";
        cin >> edadesEstudiantes[totalEstudiantes];
    }
    
    cout << "Carrera: ";
    cin.ignore();
    getline(cin, carrerasEstudiantes[totalEstudiantes]);
    
    // 🎯 TODO: Inicializar calificaciones en 0
    for (int i = 0; i < MAX_MATERIAS; i++) {
        calificaciones[totalEstudiantes][i] = 0.0;
    }
    
    totalEstudiantes++;
    
    cout << "✅ Estudiante agregado exitosamente!" << endl;
    cout << "Total de estudiantes: " << totalEstudiantes << endl;
}

/*
================================================================================
📝 PLANTILLA: FUNCIÓN 2 - CONFIGURAR MATERIAS
================================================================================
*/

void configurarMaterias() {
    cout << "\n=== CONFIGURAR MATERIAS ===" << endl;
    
    cout << "Ingrese el número de materias (1-" << MAX_MATERIAS << "): ";
    cin >> totalMaterias;
    
    // 🎯 TODO: Validar número de materias
    while (totalMaterias < 1 || totalMaterias > MAX_MATERIAS) {
        cout << "Número inválido. Ingrese entre 1 y " << MAX_MATERIAS << ": ";
        cin >> totalMaterias;
    }
    
    // 🎯 TODO: Pedir nombres de materias usando for
    cout << "\nIngrese los nombres de las materias:" << endl;
    for (int i = 0; i < totalMaterias; i++) {
        cout << "Materia " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, nombresMaterias[i]);
    }
    
    cout << "✅ Materias configuradas exitosamente!" << endl;
    
    // 🎯 TODO: Mostrar lista de materias
    cout << "\nMaterias registradas:" << endl;
    for (int i = 0; i < totalMaterias; i++) {
        cout << (i + 1) << ". " << nombresMaterias[i] << endl;
    }
}

/*
================================================================================
📝 PLANTILLA: FUNCIÓN 3 - REGISTRAR CALIFICACIONES
================================================================================
*/

void registrarCalificaciones() {
    cout << "\n=== REGISTRAR CALIFICACIONES ===" << endl;
    
    // 🎯 TODO: Verificar que hay estudiantes y materias
    if (totalEstudiantes == 0) {
        cout << "❌ Error: No hay estudiantes registrados" << endl;
        return;
    }
    
    if (totalMaterias == 0) {
        cout << "❌ Error: No hay materias configuradas" << endl;
        return;
    }
    
    // 🎯 TODO: Mostrar lista de estudiantes
    cout << "Estudiantes disponibles:" << endl;
    for (int i = 0; i < totalEstudiantes; i++) {
        cout << (i + 1) << ". " << nombresEstudiantes[i] << endl;
    }
    
    int indiceEstudiante;
    cout << "Seleccione un estudiante (1-" << totalEstudiantes << "): ";
    cin >> indiceEstudiante;
    
    // 🎯 TODO: Validar selección
    while (indiceEstudiante < 1 || indiceEstudiante > totalEstudiantes) {
        cout << "Selección inválida. Ingrese entre 1 y " << totalEstudiantes << ": ";
        cin >> indiceEstudiante;
    }
    
    indiceEstudiante--; // Convertir a índice de array (0-based)
    
    cout << "\nRegistrando calificaciones para: " << nombresEstudiantes[indiceEstudiante] << endl;
    
    // 🎯 TODO: Registrar calificación para cada materia
    for (int i = 0; i < totalMaterias; i++) {
        double nota;
        cout << "Calificación en " << nombresMaterias[i] << " (0-100): ";
        cin >> nota;
        
        // 🎯 TODO: Validar nota
        while (nota < 0 || nota > 100) {
            cout << "Nota inválida. Ingrese entre 0 y 100: ";
            cin >> nota;
        }
        
        calificaciones[indiceEstudiante][i] = nota;
        
        // 🎯 TODO: Mostrar estado de la materia usando operador ternario
        string estado = (nota >= NOTA_MINIMA_APROBACION) ? "APROBADA" : "REPROBADA";
        cout << "   " << nombresMaterias[i] << ": " << nota << " - " << estado << endl;
    }
    
    cout << "✅ Calificaciones registradas exitosamente!" << endl;
}

/*
================================================================================
📝 PLANTILLA: FUNCIÓN 4 - MOSTRAR REPORTE INDIVIDUAL
================================================================================
*/

void mostrarReporteIndividual() {
    cout << "\n=== REPORTE INDIVIDUAL ===" << endl;
    
    // 🎯 TODO: Verificar que hay estudiantes
    if (totalEstudiantes == 0) {
        cout << "❌ Error: No hay estudiantes registrados" << endl;
        return;
    }
    
    // 🎯 TODO: Seleccionar estudiante (similar a función anterior)
    cout << "Estudiantes disponibles:" << endl;
    for (int i = 0; i < totalEstudiantes; i++) {
        cout << (i + 1) << ". " << nombresEstudiantes[i] << endl;
    }
    
    int indice;
    cout << "Seleccione un estudiante: ";
    cin >> indice;
    indice--; // Convertir a índice de array
    
    // 🎯 TODO: Mostrar información completa del estudiante
    cout << fixed << setprecision(2);
    cout << "\n--- REPORTE DE " << nombresEstudiantes[indice] << " ---" << endl;
    cout << "Edad: " << edadesEstudiantes[indice] << " años" << endl;
    cout << "Carrera: " << carrerasEstudiantes[indice] << endl;
    
    // 🎯 TODO: Mostrar calificaciones y calcular promedio
    double sumaNotas = 0.0;
    int materiasAprobadas = 0;
    
    cout << "\nCalificaciones por materia:" << endl;
    for (int i = 0; i < totalMaterias; i++) {
        double nota = calificaciones[indice][i];
        sumaNotas += nota;
        
        if (nota >= NOTA_MINIMA_APROBACION) {
            materiasAprobadas++;
        }
        
        // 🎯 TODO: Mostrar cada materia con formato
        cout << "  " << nombresMaterias[i] << ": " << nota;
        cout << " (" << (nota >= NOTA_MINIMA_APROBACION ? "APROBADA" : "REPROBADA") << ")" << endl;
    }
    
    // 🎯 TODO: Calcular y mostrar estadísticas
    double promedio = sumaNotas / totalMaterias;
    double porcentajeAprobacion = (double)materiasAprobadas / totalMaterias * 100;
    
    cout << "\n--- ESTADÍSTICAS ---" << endl;
    cout << "Promedio general: " << promedio << endl;
    cout << "Materias aprobadas: " << materiasAprobadas << "/" << totalMaterias;
    cout << " (" << porcentajeAprobacion << "%)" << endl;
    
    // 🎯 TODO: Clasificar desempeño usando if-else
    string clasificacion;
    if (promedio >= 90) {
        clasificacion = "Excelente";
    } else if (promedio >= 80) {
        clasificacion = "Muy Bueno";
    } else if (promedio >= 70) {
        clasificacion = "Bueno";
    } else if (promedio >= 60) {
        clasificacion = "Regular";
    } else {
        clasificacion = "Insuficiente";
    }
    
    cout << "Clasificación: " << clasificacion << endl;
    
    // 🎯 TODO: Determinar estado académico
    bool estadoSatisfactorio = (materiasAprobadas == totalMaterias) && (promedio >= 70);
    cout << "Estado académico: " << (estadoSatisfactorio ? "SATISFACTORIO" : "NECESITA MEJORA") << endl;
}

/*
================================================================================
📝 PLANTILLA: FUNCIÓN 5 - ESTADÍSTICAS GENERALES
================================================================================
*/

void mostrarEstadisticasGenerales() {
    cout << "\n=== ESTADÍSTICAS GENERALES ===" << endl;
    
    if (totalEstudiantes == 0) {
        cout << "❌ No hay datos para mostrar" << endl;
        return;
    }
    
    // 🎯 TODO: Calcular estadísticas generales
    double sumaPromedios = 0.0;
    int totalAprobados = 0;
    double notaMasAlta = 0.0;
    double notaMasBaja = 100.0;
    string estudianteMejor = "";
    
    cout << fixed << setprecision(2);
    cout << "Total de estudiantes: " << totalEstudiantes << endl;
    cout << "Total de materias: " << totalMaterias << endl;
    
    // 🎯 TODO: Procesar cada estudiante usando bucles anidados
    for (int i = 0; i < totalEstudiantes; i++) {
        double sumaEstudiante = 0.0;
        int materiasAprobadasEstudiante = 0;
        
        // Calcular promedio del estudiante
        for (int j = 0; j < totalMaterias; j++) {
            double nota = calificaciones[i][j];
            sumaEstudiante += nota;
            
            if (nota >= NOTA_MINIMA_APROBACION) {
                materiasAprobadasEstudiante++;
            }
            
            // Actualizar nota más alta y más baja
            if (nota > notaMasAlta) {
                notaMasAlta = nota;
                estudianteMejor = nombresEstudiantes[i];
            }
            if (nota < notaMasBaja) {
                notaMasBaja = nota;
            }
        }
        
        double promedioEstudiante = sumaEstudiante / totalMaterias;
        sumaPromedios += promedioEstudiante;
        
        // Contar estudiantes que aprobaron todas las materias
        if (materiasAprobadasEstudiante == totalMaterias) {
            totalAprobados++;
        }
    }
    
    // 🎯 TODO: Mostrar estadísticas calculadas
    double promedioGeneral = sumaPromedios / totalEstudiantes;
    double porcentajeAprobacion = (double)totalAprobados / totalEstudiantes * 100;
    
    cout << "\n--- ESTADÍSTICAS ACADÉMICAS ---" << endl;
    cout << "Promedio general del grupo: " << promedioGeneral << endl;
    cout << "Estudiantes que aprobaron todo: " << totalAprobados << "/" << totalEstudiantes;
    cout << " (" << porcentajeAprobacion << "%)" << endl;
    cout << "Nota más alta: " << notaMasAlta << " (" << estudianteMejor << ")" << endl;
    cout << "Nota más baja: " << notaMasBaja << endl;
    
    // 🎯 TODO: Análisis del desempeño grupal
    cout << "\n--- ANÁLISIS DEL GRUPO ---" << endl;
    if (promedioGeneral >= 85) {
        cout << "🏆 ¡Excelente desempeño del grupo!" << endl;
    } else if (promedioGeneral >= 75) {
        cout << "👍 Buen desempeño del grupo" << endl;
    } else if (promedioGeneral >= 65) {
        cout << "⚠️  Desempeño regular, hay oportunidades de mejora" << endl;
    } else {
        cout << "🚨 El grupo necesita refuerzo académico urgente" << endl;
    }
    
    // 🎯 TODO: Estadísticas por materia
    cout << "\n--- ESTADÍSTICAS POR MATERIA ---" << endl;
    for (int j = 0; j < totalMaterias; j++) {
        double sumaMateria = 0.0;
        int aprobadosMateria = 0;
        
        for (int i = 0; i < totalEstudiantes; i++) {
            sumaMateria += calificaciones[i][j];
            if (calificaciones[i][j] >= NOTA_MINIMA_APROBACION) {
                aprobadosMateria++;
            }
        }
        
        double promedioMateria = sumaMateria / totalEstudiantes;
        double porcentajeMateria = (double)aprobadosMateria / totalEstudiantes * 100;
        
        cout << nombresMaterias[j] << ":" << endl;
        cout << "  Promedio: " << promedioMateria << endl;
        cout << "  Aprobados: " << aprobadosMateria << "/" << totalEstudiantes;
        cout << " (" << porcentajeMateria << "%)" << endl;
    }
}

/*
================================================================================
📝 PLANTILLA: FUNCIÓN 6 - SIMULADOR DE ESCENARIOS
================================================================================
*/

void simuladorEscenarios() {
    cout << "\n=== SIMULADOR DE ESCENARIOS ===" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- TIPOS DE SIMULACIÓN ---" << endl;
        cout << "1. ¿Qué nota necesito para aprobar?" << endl;
        cout << "2. Proyección de promedio final" << endl;
        cout << "3. Análisis de riesgo académico" << endl;
        cout << "4. Comparación entre estudiantes" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // 🎯 TODO: Calcular nota necesaria para aprobar
                cout << "\n--- CALCULADORA DE NOTA NECESARIA ---" << endl;
                // Implementar lógica para calcular qué nota necesita un estudiante
                // en una materia específica para alcanzar cierto promedio
                break;
                
            case 2:
                // 🎯 TODO: Proyectar promedio final
                cout << "\n--- PROYECCIÓN DE PROMEDIO ---" << endl;
                // Simular diferentes escenarios de calificaciones futuras
                break;
                
            case 3:
                // 🎯 TODO: Identificar estudiantes en riesgo
                cout << "\n--- ANÁLISIS DE RIESGO ACADÉMICO ---" << endl;
                // Identificar estudiantes que podrían reprobar
                break;
                
            case 4:
                // 🎯 TODO: Comparar rendimiento entre estudiantes
                cout << "\n--- COMPARACIÓN ENTRE ESTUDIANTES ---" << endl;
                // Comparar estadísticas entre dos estudiantes
                break;
                
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
                
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 0);
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL - MENÚ PRINCIPAL DEL SISTEMA
================================================================================
*/

int main() {
    cout << "🎓 SISTEMA DE GESTIÓN ACADÉMICA COMPLETO" << endl;
    cout << "=======================================" << endl;
    cout << "Proyecto Final - Integración de Conceptos C++" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ PRINCIPAL ---" << endl;
        cout << "1. Cargar datos de ejemplo" << endl;
        cout << "2. Configurar materias" << endl;
        cout << "3. Agregar estudiante" << endl;
        cout << "4. Registrar calificaciones" << endl;
        cout << "5. Reporte individual" << endl;
        cout << "6. Estadísticas generales" << endl;
        cout << "7. Simulador de escenarios" << endl;
        cout << "8. Mostrar todos los estudiantes" << endl;
        cout << "9. Limpiar todos los datos" << endl;
        cout << "0. Salir del sistema" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cargarDatosEjemplo();
                break;
            case 2:
                configurarMaterias();
                break;
            case 3:
                agregarEstudiante();
                break;
            case 4:
                registrarCalificaciones();
                break;
            case 5:
                mostrarReporteIndividual();
                break;
            case 6:
                mostrarEstadisticasGenerales();
                break;
            case 7:
                simuladorEscenarios();
                break;
            case 8:
                // 🎯 TODO: Implementar función para mostrar todos los estudiantes
                cout << "\n=== LISTA DE TODOS LOS ESTUDIANTES ===" << endl;
                if (totalEstudiantes == 0) {
                    cout << "No hay estudiantes registrados" << endl;
                } else {
                    // Mostrar lista completa con información básica
                }
                break;
            case 9:
                // 🎯 TODO: Implementar función para limpiar datos
                cout << "\n¿Está seguro de que desea limpiar todos los datos? (s/n): ";
                char confirmacion;
                cin >> confirmacion;
                if (confirmacion == 's' || confirmacion == 'S') {
                    totalEstudiantes = 0;
                    totalMaterias = 0;
                    cout << "✅ Todos los datos han sido eliminados" << endl;
                }
                break;
            case 0:
                cout << "\n🎉 ¡Gracias por usar el Sistema de Gestión Académica!" << endl;
                cout << "Has completado exitosamente el proyecto final." << endl;
                cout << "¡Felicidades por dominar los fundamentos de C++!" << endl;
                break;
            default:
                cout << "❌ Opción inválida. Seleccione entre 0 y 9." << endl;
        }
        
        // Pausa para leer resultados
        if (opcion != 0) {
            cout << "\nPresiona Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 0);
    
    return 0;
}

/*
================================================================================
📋 CHECKLIST DE COMPLETADO - PROYECTO FINAL
================================================================================

FUNCIONALIDADES BÁSICAS:
□ Cargar datos de ejemplo funciona correctamente
□ Configurar materias permite definir las materias del curso
□ Agregar estudiante valida datos y los almacena
□ Registrar calificaciones funciona para todos los estudiantes
□ Reporte individual muestra información completa
□ Estadísticas generales calcula correctamente

FUNCIONALIDADES AVANZADAS:
□ Simulador de escenarios está implementado
□ Mostrar todos los estudiantes funciona
□ Limpiar datos funciona con confirmación
□ Validación de entrada en todas las funciones
□ Manejo de errores apropiado
□ Formateo de salida profesional

CONCEPTOS INTEGRADOS:
□ Variables y tipos de datos (string, int, double, bool)
□ Arrays paralelos para almacenar datos
□ Operadores aritméticos para cálculos
□ Operadores de comparación para validaciones
□ Operadores lógicos para condiciones complejas
□ Operador ternario para expresiones concisas
□ Estructuras if-else para lógica condicional
□ Switch-case para menús
□ Bucles for para iteraciones definidas
□ Bucles while para validaciones
□ Bucles do-while para menús
□ Bucles anidados para matrices de datos
□ Funciones para modularizar código
□ Constantes para valores fijos

CALIDAD DEL CÓDIGO:
□ Código bien comentado y documentado
□ Nombres de variables descriptivos
□ Funciones con propósito específico
□ Validación de entrada consistente
□ Manejo de casos límite
□ Salida formateada y profesional
□ Estructura lógica y organizada

TESTING:
□ Probado con datos de ejemplo
□ Probado con entrada inválida
□ Probado con casos límite (0 estudiantes, etc.)
□ Probado con diferentes escenarios
□ Verificado que no hay errores de compilación
□ Verificado que no hay errores de ejecución

DOCUMENTACIÓN:
□ Comentarios explicativos en código complejo
□ Descripción de cada función principal
□ Ejemplos de uso documentados
□ Casos de prueba documentados

AUTOEVALUACIÓN FINAL:
□ El proyecto compila sin errores
□ Todas las funcionalidades básicas funcionan
□ El código es legible y mantenible
□ He aplicado todos los conceptos aprendidos
□ Estoy orgulloso del resultado final

PUNTUACIÓN FINAL: ___/100
TIEMPO TOTAL INVERTIDO: _____ horas
FUNCIONALIDAD MÁS DIFÍCIL: _______________
CONCEPTO MÁS ÚTIL APRENDIDO: _______________

REFLEXIÓN FINAL:
¿Qué aprendí con este proyecto?
_________________________________________________
_________________________________________________

¿Qué haría diferente la próxima vez?
_________________________________________________
_________________________________________________

¿Cómo puedo mejorar este proyecto en el futuro?
_________________________________________________
_________________________________________________

================================================================================
*/