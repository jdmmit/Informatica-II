/*
================================================================================
💻 PRÁCTICA SEMANA 1: EJERCICIOS BÁSICOS
================================================================================
Archivo: ejercicios_basicos.cpp
Objetivo: Practicar variables, tipos de datos y operadores básicos
Tiempo estimado: 4-6 horas
================================================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

/*
================================================================================
🎓 EJERCICIO EJEMPLO: INFORMACIÓN PERSONAL
================================================================================
Este es un ejemplo completo que puedes estudiar y modificar
================================================================================
*/

void ejercicio_ejemplo() {
    cout << "=== EJERCICIO EJEMPLO: INFORMACIÓN PERSONAL ===" << endl;
    
    // Declaración de variables con diferentes tipos de datos
    string nombre = "Ana García";
    int edad = 22;
    float altura = 1.65f;
    double peso = 58.5;
    char inicial = 'A';
    bool esEstudiante = true;
    
    // Cálculos usando operadores
    double imc = peso / (altura * altura);
    int diasVividos = edad * 365;
    int anosParaCien = 100 - edad;
    
    // Mostrar información organizada
    cout << fixed << setprecision(2);
    cout << "\n--- DATOS PERSONALES ---" << endl;
    cout << "Nombre completo: " << nombre << endl;
    cout << "Inicial: " << inicial << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Altura: " << altura << " metros" << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Es estudiante: " << (esEstudiante ? "Sí" : "No") << endl;
    
    cout << "\n--- CÁLCULOS ---" << endl;
    cout << "IMC: " << imc;
    if (imc < 18.5) cout << " (Bajo peso)";
    else if (imc < 25) cout << " (Peso normal)";
    else if (imc < 30) cout << " (Sobrepeso)";
    else cout << " (Obesidad)";
    cout << endl;
    
    cout << "Días vividos (aprox.): " << diasVividos << endl;
    cout << "Años para cumplir 100: " << anosParaCien << endl;
    
    // Usar operador ternario
    string categoria = (edad < 18) ? "Menor de edad" : 
                      (edad < 65) ? "Adulto" : "Adulto mayor";
    cout << "Categoría: " << categoria << endl;
}

/*
================================================================================
📝 PLANTILLA 1: TU INFORMACIÓN PERSONAL
================================================================================
Completa este ejercicio con tus propios datos
================================================================================
*/

void ejercicio_1_tu_informacion() {
    cout << "\n=== EJERCICIO 1: TU INFORMACIÓN PERSONAL ===" << endl;
    
    // 🎯 TODO: Declara variables con tu información real
    string nombre = "";           // Tu nombre completo
    int edad = 0;                // Tu edad
    float altura = 0.0f;         // Tu altura en metros
    double peso = 0.0;           // Tu peso en kilogramos
    char inicial = ' ';          // Inicial de tu primer nombre
    bool esEstudiante = false;   // ¿Eres estudiante?
    
    // 🎯 TODO: Realiza cálculos interesantes
    double imc = 0.0;            // Calcula tu IMC
    int diasVividos = 0;         // Calcula días vividos aproximados
    int anosParaCien = 0;        // Años que te faltan para 100
    
    // 🎯 TODO: Muestra la información de forma organizada
    cout << "--- MIS DATOS PERSONALES ---" << endl;
    // Aquí va tu código para mostrar la información
    
    cout << "--- MIS CÁLCULOS ---" << endl;
    // Aquí va tu código para mostrar los cálculos
    
    // 🎯 TODO: Usa operadores de comparación para clasificar tu IMC
    // 🎯 TODO: Usa operador ternario para determinar tu categoría de edad
}

/*
================================================================================
📝 PLANTILLA 2: CALCULADORA DE VIAJE
================================================================================
Crea una calculadora para planificar un viaje
================================================================================
*/

void ejercicio_2_calculadora_viaje() {
    cout << "\n=== EJERCICIO 2: CALCULADORA DE VIAJE ===" << endl;
    
    // 🎯 TODO: Declara variables para el viaje
    string destino = "";         // Destino del viaje
    double distancia = 0.0;      // Distancia en kilómetros
    double precioGasolina = 0.0; // Precio por litro
    double consumoCarro = 0.0;   // Litros por 100 km
    int diasViaje = 0;           // Duración del viaje
    double presupuestoDiario = 0.0; // Presupuesto por día
    
    // 🎯 TODO: Pide datos al usuario
    cout << "Ingrese el destino: ";
    // Aquí va tu código para pedir datos
    
    // 🎯 TODO: Realiza cálculos
    double litrosNecesarios = 0.0;    // Litros de gasolina necesarios
    double costoGasolina = 0.0;       // Costo total de gasolina
    double costoAlojamiento = 0.0;    // Costo de alojamiento
    double costoTotal = 0.0;          // Costo total del viaje
    
    // 🎯 TODO: Muestra los resultados
    cout << "\n--- RESUMEN DEL VIAJE ---" << endl;
    // Aquí va tu código para mostrar resultados
    
    // 🎯 TODO: Da recomendaciones usando operadores de comparación
    // Ejemplo: Si el costo es alto, sugerir alternativas
}

/*
================================================================================
📝 PLANTILLA 3: SISTEMA DE CALIFICACIONES
================================================================================
Crea un sistema que procese calificaciones de estudiantes
================================================================================
*/

void ejercicio_3_calificaciones() {
    cout << "\n=== EJERCICIO 3: SISTEMA DE CALIFICACIONES ===" << endl;
    
    // 🎯 TODO: Declara variables para las calificaciones
    string nombreEstudiante = "";
    double nota1 = 0.0, nota2 = 0.0, nota3 = 0.0, nota4 = 0.0;
    double promedio = 0.0;
    
    // 🎯 TODO: Pide datos al usuario
    cout << "Ingrese el nombre del estudiante: ";
    // Aquí va tu código
    
    // 🎯 TODO: Calcula el promedio
    // promedio = ...
    
    // 🎯 TODO: Determina la letra de calificación usando operadores
    char letraCalificacion = ' ';
    // A: 90-100, B: 80-89, C: 70-79, D: 60-69, F: <60
    
    // 🎯 TODO: Determina si aprobó (>=60)
    bool aprobo = false;
    
    // 🎯 TODO: Muestra los resultados
    cout << "\n--- REPORTE DE CALIFICACIONES ---" << endl;
    // Aquí va tu código para mostrar resultados
    
    // 🎯 TODO: Da comentarios según el promedio
    // Usa operadores de comparación para dar diferentes mensajes
}

/*
================================================================================
📝 PLANTILLA 4: CONVERSOR DE UNIDADES
================================================================================
Crea un conversor que maneje diferentes tipos de unidades
================================================================================
*/

void ejercicio_4_conversor_unidades() {
    cout << "\n=== EJERCICIO 4: CONVERSOR DE UNIDADES ===" << endl;
    
    // 🎯 TODO: Declara variables para conversiones
    double metros = 0.0;
    double kilogramos = 0.0;
    double celsius = 0.0;
    
    // 🎯 TODO: Pide datos al usuario
    cout << "Ingrese una distancia en metros: ";
    // Aquí va tu código
    
    // 🎯 TODO: Realiza conversiones de distancia
    double centimetros = 0.0;    // metros * 100
    double pulgadas = 0.0;       // metros * 39.3701
    double pies = 0.0;           // metros * 3.28084
    double yardas = 0.0;         // metros * 1.09361
    
    // 🎯 TODO: Pide peso y convierte
    cout << "Ingrese un peso en kilogramos: ";
    // Aquí va tu código para peso
    
    double libras = 0.0;         // kg * 2.20462
    double onzas = 0.0;          // kg * 35.274
    
    // 🎯 TODO: Pide temperatura y convierte
    cout << "Ingrese temperatura en Celsius: ";
    // Aquí va tu código para temperatura
    
    double fahrenheit = 0.0;     // (C * 9/5) + 32
    double kelvin = 0.0;         // C + 273.15
    
    // 🎯 TODO: Muestra todas las conversiones organizadamente
    cout << "\n--- CONVERSIONES ---" << endl;
    // Aquí va tu código para mostrar resultados
}

/*
================================================================================
📝 PLANTILLA 5: CALCULADORA FINANCIERA
================================================================================
Crea una calculadora para manejar finanzas personales
================================================================================
*/

void ejercicio_5_calculadora_financiera() {
    cout << "\n=== EJERCICIO 5: CALCULADORA FINANCIERA ===" << endl;
    
    // 🎯 TODO: Declara variables financieras
    double salarioMensual = 0.0;
    double gastosVivienda = 0.0;    // Renta, servicios
    double gastosComida = 0.0;      // Alimentación
    double gastosTransporte = 0.0;  // Transporte
    double gastosOtros = 0.0;       // Entretenimiento, etc.
    
    // 🎯 TODO: Pide datos al usuario
    cout << "Ingrese su salario mensual: $";
    // Aquí va tu código
    
    // 🎯 TODO: Calcula totales
    double totalGastos = 0.0;
    double dineroRestante = 0.0;
    double porcentajeAhorro = 0.0;
    
    // 🎯 TODO: Calcula proyecciones anuales
    double ahorroAnual = 0.0;
    double gastoAnual = 0.0;
    
    // 🎯 TODO: Muestra análisis financiero
    cout << "\n--- ANÁLISIS FINANCIERO ---" << endl;
    // Aquí va tu código
    
    // 🎯 TODO: Da recomendaciones usando operadores de comparación
    // Si ahorra menos del 20%, dar consejos
    // Si gasta más del 80% en necesidades básicas, alertar
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL - MENÚ DE EJERCICIOS
================================================================================
*/

int main() {
    cout << "🚀 PRÁCTICA SEMANA 1: EJERCICIOS BÁSICOS" << endl;
    cout << "=======================================" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ DE EJERCICIOS ---" << endl;
        cout << "0. Ver ejemplo completo" << endl;
        cout << "1. Tu información personal" << endl;
        cout << "2. Calculadora de viaje" << endl;
        cout << "3. Sistema de calificaciones" << endl;
        cout << "4. Conversor de unidades" << endl;
        cout << "5. Calculadora financiera" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione un ejercicio: ";
        cin >> opcion;
        
        switch (opcion) {
            case 0:
                ejercicio_ejemplo();
                break;
            case 1:
                ejercicio_1_tu_informacion();
                break;
            case 2:
                ejercicio_2_calculadora_viaje();
                break;
            case 3:
                ejercicio_3_calificaciones();
                break;
            case 4:
                ejercicio_4_conversor_unidades();
                break;
            case 5:
                ejercicio_5_calculadora_financiera();
                break;
            case 9:
                cout << "¡Excelente trabajo en la Semana 1!" << endl;
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
📋 CHECKLIST DE COMPLETADO - SEMANA 1
================================================================================

□ Ejercicio 0: Estudié y entendí el ejemplo completo
□ Ejercicio 1: Completé mi información personal con cálculos
□ Ejercicio 2: Creé la calculadora de viaje funcional
□ Ejercicio 3: Implementé el sistema de calificaciones
□ Ejercicio 4: Desarrollé el conversor de unidades
□ Ejercicio 5: Construí la calculadora financiera

CONCEPTOS PRACTICADOS:
□ Declaración de variables de diferentes tipos
□ Uso de operadores aritméticos
□ Uso de operadores de comparación
□ Uso de operadores lógicos
□ Uso del operador ternario
□ Entrada y salida de datos con cin/cout
□ Formateo de salida con setprecision
□ Conversiones entre tipos de datos

AUTOEVALUACIÓN:
□ Mi código compila sin errores
□ Mi código produce resultados correctos
□ He comentado mi código adecuadamente
□ He probado diferentes casos de entrada
□ Entiendo todos los conceptos utilizados

PUNTUACIÓN: ___/100
TIEMPO INVERTIDO: _____ horas
DIFICULTAD PERCIBIDA (1-10): _____
COMENTARIOS: ________________________________

================================================================================
*/