/*
================================================================================
💻 PRÁCTICA SEMANA 3: PRÁCTICA 0 OFICIAL
================================================================================
Archivo: practica0.cpp
Objetivo: Resolver la práctica oficial aplicando todos los conceptos aprendidos
Material de referencia: inforII-u1-practica-0.pdf
Tiempo estimado: 6-10 horas
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
🎓 EJEMPLO DE ANÁLISIS: PROBLEMA TÍPICO DE PRÁCTICA 0
================================================================================
Este ejemplo muestra cómo abordar un problema típico paso a paso
================================================================================
*/

void ejemplo_analisis_problema() {
    cout << "=== EJEMPLO: ANÁLISIS DE PROBLEMA TÍPICO ===" << endl;
    cout << "\nPROBLEMA EJEMPLO:" << endl;
    cout << "Crear un programa que calcule el promedio de N estudiantes," << endl;
    cout << "determine cuántos aprobaron (>=60) y muestre estadísticas." << endl;
    
    cout << "\n--- ANÁLISIS DEL PROBLEMA ---" << endl;
    cout << "1. ENTRADA: Número de estudiantes, nombres y notas" << endl;
    cout << "2. PROCESO: Calcular promedio, contar aprobados" << endl;
    cout << "3. SALIDA: Promedio general, cantidad de aprobados, estadísticas" << endl;
    
    cout << "\n--- ALGORITMO ---" << endl;
    cout << "1. Pedir número de estudiantes" << endl;
    cout << "2. Para cada estudiante:" << endl;
    cout << "   - Pedir nombre y nota" << endl;
    cout << "   - Validar nota (0-100)" << endl;
    cout << "   - Acumular suma y contar aprobados" << endl;
    cout << "3. Calcular promedio general" << endl;
    cout << "4. Mostrar resultados y estadísticas" << endl;
    
    cout << "\n--- IMPLEMENTACIÓN ---" << endl;
    
    int numEstudiantes;
    double sumaNotas = 0.0;
    int aprobados = 0;
    double notaMayor = 0.0, notaMenor = 100.0;
    
    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;
    
    // Validar entrada
    while (numEstudiantes <= 0) {
        cout << "Debe ingresar un número positivo: ";
        cin >> numEstudiantes;
    }
    
    // Procesar cada estudiante
    for (int i = 1; i <= numEstudiantes; i++) {
        string nombre;
        double nota;
        
        cout << "\nEstudiante " << i << ":" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Nota: ";
        cin >> nota;
        
        // Validar nota
        while (nota < 0 || nota > 100) {
            cout << "Nota inválida. Ingrese entre 0-100: ";
            cin >> nota;
        }
        
        // Procesar datos
        sumaNotas += nota;
        if (nota >= 60) aprobados++;
        if (nota > notaMayor) notaMayor = nota;
        if (nota < notaMenor) notaMenor = nota;
        
        // Mostrar estado individual
        cout << nombre << ": " << nota << " - " 
             << (nota >= 60 ? "APROBADO" : "REPROBADO") << endl;
    }
    
    // Calcular y mostrar resultados
    double promedio = sumaNotas / numEstudiantes;
    double porcentajeAprobados = (double)aprobados / numEstudiantes * 100;
    
    cout << fixed << setprecision(2);
    cout << "\n--- ESTADÍSTICAS FINALES ---" << endl;
    cout << "Total de estudiantes: " << numEstudiantes << endl;
    cout << "Promedio general: " << promedio << endl;
    cout << "Estudiantes aprobados: " << aprobados << " (" << porcentajeAprobados << "%)" << endl;
    cout << "Estudiantes reprobados: " << (numEstudiantes - aprobados) << endl;
    cout << "Nota más alta: " << notaMayor << endl;
    cout << "Nota más baja: " << notaMenor << endl;
    
    // Análisis adicional
    if (promedio >= 80) {
        cout << "¡Excelente desempeño del grupo!" << endl;
    } else if (promedio >= 70) {
        cout << "Buen desempeño del grupo" << endl;
    } else if (promedio >= 60) {
        cout << "Desempeño regular del grupo" << endl;
    } else {
        cout << "El grupo necesita refuerzo académico" << endl;
    }
}

/*
================================================================================
📝 PLANTILLA: PROBLEMA 1 - CALCULADORA DE ESTADÍSTICAS
================================================================================
Resuelve este problema siguiendo la metodología mostrada
================================================================================
*/

void problema_1_estadisticas() {
    cout << "\n=== PROBLEMA 1: CALCULADORA DE ESTADÍSTICAS ===" << endl;
    
    /*
    ENUNCIADO:
    Crear un programa que permita ingresar N números enteros y calcule:
    - Promedio aritmético
    - Número mayor y menor
    - Cantidad de números pares e impares
    - Cantidad de números positivos, negativos y ceros
    - Desviación estándar (opcional)
    */
    
    cout << "\n--- ANÁLISIS DEL PROBLEMA ---" << endl;
    cout << "ENTRADA: Cantidad de números y los números" << endl;
    cout << "PROCESO: Calcular estadísticas diversas" << endl;
    cout << "SALIDA: Todas las estadísticas solicitadas" << endl;
    
    // 🎯 TODO: Declara las variables necesarias
    int cantidadNumeros;
    double suma = 0.0;
    int mayor, menor;
    int pares = 0, impares = 0;
    int positivos = 0, negativos = 0, ceros = 0;
    
    // 🎯 TODO: Pide la cantidad de números y valida
    cout << "\nIngrese la cantidad de números: ";
    // Aquí va tu código
    
    // 🎯 TODO: Inicializa mayor y menor con el primer número
    cout << "Ingrese el número 1: ";
    int primerNumero;
    cin >> primerNumero;
    mayor = menor = primerNumero;
    suma += primerNumero;
    
    // 🎯 TODO: Clasifica el primer número
    // (par/impar, positivo/negativo/cero)
    
    // 🎯 TODO: Procesa los números restantes usando for
    for (int i = 2; i <= cantidadNumeros; i++) {
        int numero;
        cout << "Ingrese el número " << i << ": ";
        cin >> numero;
        
        // TODO: Actualizar suma
        // TODO: Actualizar mayor y menor
        // TODO: Clasificar par/impar
        // TODO: Clasificar positivo/negativo/cero
    }
    
    // 🎯 TODO: Calcula y muestra resultados
    double promedio = suma / cantidadNumeros;
    
    cout << fixed << setprecision(2);
    cout << "\n--- ESTADÍSTICAS ---" << endl;
    // TODO: Mostrar todos los resultados
    
    // 🎯 TODO: Análisis adicional
    // Determina qué tipo de números predominan
    // Da recomendaciones basadas en los datos
}

/*
================================================================================
📝 PLANTILLA: PROBLEMA 2 - SISTEMA DE FACTURACIÓN
================================================================================
*/

void problema_2_facturacion() {
    cout << "\n=== PROBLEMA 2: SISTEMA DE FACTURACIÓN ===" << endl;
    
    /*
    ENUNCIADO:
    Crear un sistema que permita:
    - Ingresar productos con precio y cantidad
    - Calcular subtotal por producto
    - Aplicar descuentos según reglas:
      * Si subtotal > $100: 10% descuento
      * Si subtotal > $500: 15% descuento
      * Si subtotal > $1000: 20% descuento
    - Calcular impuestos (12%)
    - Mostrar factura detallada
    */
    
    // 🎯 TODO: Declara variables necesarias
    int numeroProductos;
    double totalFactura = 0.0;
    double totalDescuentos = 0.0;
    
    cout << "=== SISTEMA DE FACTURACIÓN ===" << endl;
    cout << "Ingrese el número de productos: ";
    cin >> numeroProductos;
    
    // 🎯 TODO: Valida que sea positivo
    
    cout << "\n--- INGRESO DE PRODUCTOS ---" << endl;
    
    // 🎯 TODO: Procesa cada producto usando for
    for (int i = 1; i <= numeroProductos; i++) {
        string nombreProducto;
        double precio;
        int cantidad;
        
        cout << "\nProducto " << i << ":" << endl;
        cout << "Nombre: ";
        // TODO: Leer nombre del producto
        
        cout << "Precio unitario: $";
        // TODO: Leer y validar precio
        
        cout << "Cantidad: ";
        // TODO: Leer y validar cantidad
        
        // 🎯 TODO: Calcula subtotal
        double subtotal = precio * cantidad;
        
        // 🎯 TODO: Calcula descuento según reglas
        double descuento = 0.0;
        if (subtotal > 1000) {
            descuento = subtotal * 0.20;
        } else if (subtotal > 500) {
            // TODO: 15% descuento
        } else if (subtotal > 100) {
            // TODO: 10% descuento
        }
        
        double subtotalConDescuento = subtotal - descuento;
        totalFactura += subtotalConDescuento;
        totalDescuentos += descuento;
        
        // 🎯 TODO: Muestra detalle del producto
        cout << "Subtotal: $" << subtotal << endl;
        if (descuento > 0) {
            cout << "Descuento aplicado: $" << descuento << endl;
            cout << "Subtotal con descuento: $" << subtotalConDescuento << endl;
        }
    }
    
    // 🎯 TODO: Calcula impuestos y total final
    double impuestos = totalFactura * 0.12;
    double totalFinal = totalFactura + impuestos;
    
    // 🎯 TODO: Muestra factura final
    cout << fixed << setprecision(2);
    cout << "\n=== FACTURA FINAL ===" << endl;
    // TODO: Mostrar resumen completo
}

/*
================================================================================
📝 PLANTILLA: PROBLEMA 3 - ANÁLISIS DE TEXTO
================================================================================
*/

void problema_3_analisis_texto() {
    cout << "\n=== PROBLEMA 3: ANÁLISIS DE TEXTO ===" << endl;
    
    /*
    ENUNCIADO:
    Crear un programa que analice una frase ingresada por el usuario:
    - Contar total de caracteres (con y sin espacios)
    - Contar vocales y consonantes
    - Contar palabras
    - Determinar si es palíndromo (opcional)
    - Mostrar estadísticas
    */
    
    string frase;
    cout << "Ingrese una frase para analizar: ";
    cin.ignore();
    getline(cin, frase);
    
    // 🎯 TODO: Declara contadores
    int totalCaracteres = frase.length();
    int caracteresConEspacios = totalCaracteres;
    int caracteressinEspacios = 0;
    int vocales = 0, consonantes = 0;
    int palabras = 1; // Empezamos con 1 palabra
    int espacios = 0;
    
    // 🎯 TODO: Analiza cada carácter usando for
    for (int i = 0; i < totalCaracteres; i++) {
        char c = frase[i];
        
        // TODO: Convierte a minúscula para análisis
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // Convierte a minúscula
        }
        
        // 🎯 TODO: Clasifica el carácter
        if (c == ' ') {
            espacios++;
            palabras++; // Cada espacio indica nueva palabra
        } else if (c >= 'a' && c <= 'z') {
            caracteressinEspacios++;
            
            // TODO: Determina si es vocal o consonante
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        }
    }
    
    // 🎯 TODO: Muestra resultados
    cout << "\n--- ANÁLISIS DE LA FRASE ---" << endl;
    cout << "Frase: \"" << frase << "\"" << endl;
    // TODO: Mostrar todas las estadísticas
    
    // 🎯 TODO: Análisis adicional
    // Determina qué tipo de caracteres predominan
    // Calcula porcentajes
}

/*
================================================================================
📝 PLANTILLA: PROBLEMA 4 - JUEGO DE MATEMÁTICAS
================================================================================
*/

void problema_4_juego_matematicas() {
    cout << "\n=== PROBLEMA 4: JUEGO DE MATEMÁTICAS ===" << endl;
    
    /*
    ENUNCIADO:
    Crear un juego educativo que:
    - Genere operaciones matemáticas aleatorias
    - Permita elegir dificultad (suma, resta, multiplicación, división)
    - Lleve puntaje de respuestas correctas/incorrectas
    - Muestre estadísticas al final
    - Permita múltiples rondas
    */
    
    srand(time(0));
    
    int opcion;
    int respuestasCorrectas = 0, respuestasIncorrectas = 0;
    int totalPreguntas = 0;
    
    // 🎯 TODO: Menú principal usando do-while
    do {
        cout << "\n--- JUEGO DE MATEMÁTICAS ---" << endl;
        cout << "1. Suma (fácil)" << endl;
        cout << "2. Resta (fácil)" << endl;
        cout << "3. Multiplicación (medio)" << endl;
        cout << "4. División (difícil)" << endl;
        cout << "5. Modo mixto (experto)" << endl;
        cout << "6. Ver estadísticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion >= 1 && opcion <= 5) {
            int numeroPreguntas;
            cout << "¿Cuántas preguntas quiere resolver? ";
            cin >> numeroPreguntas;
            
            // 🎯 TODO: Genera preguntas según la opción
            for (int i = 1; i <= numeroPreguntas; i++) {
                int num1, num2, respuestaCorrecta, respuestaUsuario;
                char operador;
                
                // TODO: Genera números según dificultad
                switch (opcion) {
                    case 1: // Suma
                        num1 = rand() % 50 + 1;
                        num2 = rand() % 50 + 1;
                        operador = '+';
                        respuestaCorrecta = num1 + num2;
                        break;
                    case 2: // Resta
                        // TODO: Implementar resta
                        break;
                    case 3: // Multiplicación
                        // TODO: Implementar multiplicación
                        break;
                    case 4: // División
                        // TODO: Implementar división (asegurar división exacta)
                        break;
                    case 5: // Mixto
                        // TODO: Elegir operación aleatoria
                        break;
                }
                
                // 🎯 TODO: Presenta la pregunta
                cout << "\nPregunta " << i << ": " << num1 << " " << operador << " " << num2 << " = ";
                cin >> respuestaUsuario;
                
                // 🎯 TODO: Evalúa la respuesta
                if (respuestaUsuario == respuestaCorrecta) {
                    cout << "¡Correcto!" << endl;
                    respuestasCorrectas++;
                } else {
                    cout << "Incorrecto. La respuesta era: " << respuestaCorrecta << endl;
                    respuestasIncorrectas++;
                }
                
                totalPreguntas++;
            }
        } else if (opcion == 6) {
            // 🎯 TODO: Muestra estadísticas
            if (totalPreguntas > 0) {
                double porcentajeAciertos = (double)respuestasCorrectas / totalPreguntas * 100;
                cout << "\n--- ESTADÍSTICAS ---" << endl;
                // TODO: Mostrar estadísticas completas
            } else {
                cout << "No hay estadísticas aún" << endl;
            }
        }
        
    } while (opcion != 0);
    
    // 🎯 TODO: Mensaje de despedida con estadísticas finales
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL - MENÚ DE PROBLEMAS
================================================================================
*/

int main() {
    cout << "🚀 PRÁCTICA SEMANA 3: PRÁCTICA 0 OFICIAL" << endl;
    cout << "=======================================" << endl;
    
    cout << "\nEsta semana resolverás problemas similares a los de la práctica oficial." << endl;
    cout << "Cada problema está diseñado para aplicar todos los conceptos aprendidos." << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ DE PROBLEMAS ---" << endl;
        cout << "0. Ver ejemplo de análisis" << endl;
        cout << "1. Calculadora de estadísticas" << endl;
        cout << "2. Sistema de facturación" << endl;
        cout << "3. Análisis de texto" << endl;
        cout << "4. Juego de matemáticas" << endl;
        cout << "5. Resolver práctica oficial (cuando esté disponible)" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione un problema: ";
        cin >> opcion;
        
        switch (opcion) {
            case 0:
                ejemplo_analisis_problema();
                break;
            case 1:
                problema_1_estadisticas();
                break;
            case 2:
                problema_2_facturacion();
                break;
            case 3:
                problema_3_analisis_texto();
                break;
            case 4:
                problema_4_juego_matematicas();
                break;
            case 5:
                cout << "\n🎯 PRÁCTICA OFICIAL" << endl;
                cout << "Cuando recibas la práctica oficial:" << endl;
                cout << "1. Lee el enunciado completamente" << endl;
                cout << "2. Identifica entrada, proceso y salida" << endl;
                cout << "3. Diseña el algoritmo paso a paso" << endl;
                cout << "4. Implementa siguiendo buenas prácticas" << endl;
                cout << "5. Prueba con diferentes casos" << endl;
                cout << "6. Documenta tu solución" << endl;
                break;
            case 9:
                cout << "¡Excelente trabajo en la Semana 3!" << endl;
                cout << "Estás listo para la práctica oficial." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        
        if (opcion != 9 && opcion >= 0 && opcion <= 5) {
            cout << "\nPresiona Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 9);
    
    return 0;
}

/*
================================================================================
📋 CHECKLIST DE PREPARACIÓN - PRÁCTICA OFICIAL
================================================================================

ANTES DE LA PRÁCTICA:
□ He completado todos los ejercicios de preparación
□ Domino la sintaxis básica de C++
□ Puedo usar todas las estructuras de control
□ Sé validar entrada de datos
□ Puedo manejar arrays básicos
□ Entiendo cómo analizar problemas paso a paso

DURANTE LA PRÁCTICA:
□ Leo el enunciado completo antes de empezar
□ Identifico claramente entrada, proceso y salida
□ Diseño el algoritmo en papel primero
□ Escribo código limpio y comentado
□ Pruebo con diferentes casos de entrada
□ Valido que mi programa no tenga errores

METODOLOGÍA DE RESOLUCIÓN:
1. 📖 LEER: Entender completamente el problema
2. 🎯 ANALIZAR: Identificar qué necesito hacer
3. 📝 DISEÑAR: Crear el algoritmo paso a paso
4. 💻 IMPLEMENTAR: Escribir el código
5. 🧪 PROBAR: Verificar con diferentes casos
6. 📋 DOCUMENTAR: Comentar y explicar la solución

PUNTOS CLAVE A RECORDAR:
□ Validar siempre la entrada del usuario
□ Usar nombres de variables descriptivos
□ Comentar las partes importantes del código
□ Manejar casos especiales (división por cero, etc.)
□ Formatear la salida de manera clara
□ Probar con casos límite

AUTOEVALUACIÓN:
□ Mi código compila sin errores
□ Produce los resultados esperados
□ Maneja casos de error apropiadamente
□ Está bien documentado y es legible
□ Sigue buenas prácticas de programación

CONFIANZA PARA LA PRÁCTICA OFICIAL: ___/10
ÁREA QUE MÁS NECESITO REPASAR: _______________
TIEMPO ESTIMADO PARA RESOLVER LA PRÁCTICA: _____ horas

================================================================================
*/