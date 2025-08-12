/*
================================================================================
💻 PRÁCTICA SEMANA 2: CONTROL DE FLUJO
================================================================================
Archivo: control_flujo.cpp
Objetivo: Dominar estructuras condicionales y bucles
Tiempo estimado: 6-8 horas
================================================================================
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/*
================================================================================
🎓 EJERCICIO EJEMPLO: SISTEMA DE NOTAS COMPLETO
================================================================================
Este ejemplo muestra el uso integrado de todas las estructuras de control
================================================================================
*/

void ejercicio_ejemplo() {
    cout << "=== EJERCICIO EJEMPLO: SISTEMA DE NOTAS COMPLETO ===" << endl;
    
    string nombreEstudiante;
    int numeroMaterias;
    double sumaNotas = 0.0;
    int materiasAprobadas = 0;
    
    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombreEstudiante);
    
    cout << "Ingrese el número de materias: ";
    cin >> numeroMaterias;
    
    // Usar bucle for para ingresar notas
    for (int i = 1; i <= numeroMaterias; i++) {
        double nota;
        cout << "Ingrese la nota de la materia " << i << " (0-100): ";
        cin >> nota;
        
        // Validar nota usando while
        while (nota < 0 || nota > 100) {
            cout << "Nota inválida. Ingrese una nota entre 0 y 100: ";
            cin >> nota;
        }
        
        sumaNotas += nota;
        
        // Usar if para contar materias aprobadas
        if (nota >= 60) {
            materiasAprobadas++;
        }
        
        // Mostrar estado de la materia usando operador ternario
        cout << "Materia " << i << ": " << nota << " - " 
             << (nota >= 60 ? "APROBADA" : "REPROBADA") << endl;
    }
    
    double promedio = sumaNotas / numeroMaterias;
    
    cout << fixed << setprecision(2);
    cout << "\n--- REPORTE FINAL ---" << endl;
    cout << "Estudiante: " << nombreEstudiante << endl;
    cout << "Promedio general: " << promedio << endl;
    cout << "Materias aprobadas: " << materiasAprobadas << "/" << numeroMaterias << endl;
    
    // Usar if-else if para determinar clasificación
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
    
    // Estado final usando operadores lógicos
    bool aproboTodo = (materiasAprobadas == numeroMaterias);
    bool aproboMayoria = (materiasAprobadas > numeroMaterias / 2);
    
    if (aproboTodo) {
        cout << "¡FELICIDADES! Aprobaste todas las materias" << endl;
    } else if (aproboMayoria) {
        cout << "Aprobaste la mayoría de materias, pero necesitas mejorar" << endl;
    } else {
        cout << "Necesitas estudiar más para el próximo período" << endl;
    }
}

/*
================================================================================
📝 PLANTILLA 1: MENÚ DE RESTAURANTE
================================================================================
Crea un sistema de pedidos para un restaurante
================================================================================
*/

void ejercicio_1_menu_restaurante() {
    cout << "\n=== EJERCICIO 1: MENÚ DE RESTAURANTE ===" << endl;
    
    // 🎯 TODO: Declara variables para el pedido
    double totalPedido = 0.0;
    int opcion;
    bool continuarPidiendo = true;
    
    cout << "¡Bienvenido al Restaurante C++!" << endl;
    
    // 🎯 TODO: Usa do-while para mantener el menú activo
    do {
        cout << "\n--- MENÚ PRINCIPAL ---" << endl;
        cout << "1. Hamburguesa - $12.99" << endl;
        cout << "2. Pizza - $15.50" << endl;
        cout << "3. Ensalada - $8.75" << endl;
        cout << "4. Refresco - $2.50" << endl;
        cout << "5. Postre - $6.25" << endl;
        cout << "6. Ver total y finalizar" << endl;
        cout << "0. Cancelar pedido" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        // 🎯 TODO: Usa switch-case para procesar la opción
        switch (opcion) {
            case 1:
                // TODO: Agregar hamburguesa al total
                cout << "Hamburguesa agregada" << endl;
                break;
            case 2:
                // TODO: Agregar pizza al total
                break;
            case 3:
                // TODO: Agregar ensalada al total
                break;
            case 4:
                // TODO: Agregar refresco al total
                break;
            case 5:
                // TODO: Agregar postre al total
                break;
            case 6:
                // TODO: Mostrar total y calcular propina/impuestos
                continuarPidiendo = false;
                break;
            case 0:
                // TODO: Cancelar pedido
                continuarPidiendo = false;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (continuarPidiendo);
    
    // 🎯 TODO: Si hay pedido, calcular impuestos y propina
    if (totalPedido > 0) {
        double impuestos = totalPedido * 0.08;  // 8% de impuestos
        double sugerenciaPropina = totalPedido * 0.15;  // 15% de propina
        double totalFinal = totalPedido + impuestos;
        
        cout << "\n--- RESUMEN DEL PEDIDO ---" << endl;
        // TODO: Mostrar desglose completo
        
        // 🎯 TODO: Ofrecer descuentos usando if
        // Si el total es mayor a $50, aplicar 10% de descuento
    }
}

/*
================================================================================
📝 PLANTILLA 2: GENERADOR DE PATRONES
================================================================================
Crea diferentes patrones usando bucles anidados
================================================================================
*/

void ejercicio_2_generador_patrones() {
    cout << "\n=== EJERCICIO 2: GENERADOR DE PATRONES ===" << endl;
    
    int opcion, tamaño;
    
    do {
        cout << "\n--- TIPOS DE PATRONES ---" << endl;
        cout << "1. Triángulo de asteriscos" << endl;
        cout << "2. Triángulo invertido" << endl;
        cout << "3. Pirámide" << endl;
        cout << "4. Rombo" << endl;
        cout << "5. Cuadrado hueco" << endl;
        cout << "6. Tabla de multiplicar" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione un patrón: ";
        cin >> opcion;
        
        if (opcion >= 1 && opcion <= 6) {
            cout << "Ingrese el tamaño: ";
            cin >> tamaño;
            
            // 🎯 TODO: Valida que el tamaño sea positivo usando while
            while (tamaño <= 0) {
                cout << "El tamaño debe ser positivo. Ingrese nuevamente: ";
                cin >> tamaño;
            }
        }
        
        switch (opcion) {
            case 1:
                // 🎯 TODO: Triángulo de asteriscos usando bucles anidados
                cout << "\nTriángulo de asteriscos:" << endl;
                for (int i = 1; i <= tamaño; i++) {
                    // TODO: Bucle interno para imprimir asteriscos
                }
                break;
                
            case 2:
                // 🎯 TODO: Triángulo invertido
                cout << "\nTriángulo invertido:" << endl;
                // TODO: Implementar con bucles anidados
                break;
                
            case 3:
                // 🎯 TODO: Pirámide centrada
                cout << "\nPirámide:" << endl;
                // TODO: Implementar espacios y asteriscos
                break;
                
            case 4:
                // 🎯 TODO: Rombo (pirámide + pirámide invertida)
                cout << "\nRombo:" << endl;
                // TODO: Combinar dos patrones
                break;
                
            case 5:
                // 🎯 TODO: Cuadrado hueco (solo bordes)
                cout << "\nCuadrado hueco:" << endl;
                // TODO: Usar if dentro de bucles para bordes
                break;
                
            case 6:
                // 🎯 TODO: Tabla de multiplicar
                cout << "\nTabla de multiplicar del " << tamaño << ":" << endl;
                // TODO: Usar bucle for simple
                break;
                
            case 0:
                cout << "¡Gracias por usar el generador!" << endl;
                break;
                
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 0);
}

/*
================================================================================
📝 PLANTILLA 3: JUEGO DE ADIVINANZA AVANZADO
================================================================================
Mejora el juego básico con más funcionalidades
================================================================================
*/

void ejercicio_3_juego_adivinanza_avanzado() {
    cout << "\n=== EJERCICIO 3: JUEGO DE ADIVINANZA AVANZADO ===" << endl;
    
    srand(time(0));
    int opcion;
    
    do {
        cout << "\n--- NIVELES DE DIFICULTAD ---" << endl;
        cout << "1. Fácil (1-50, 10 intentos)" << endl;
        cout << "2. Medio (1-100, 7 intentos)" << endl;
        cout << "3. Difícil (1-500, 5 intentos)" << endl;
        cout << "4. Ver estadísticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        // 🎯 TODO: Declara variables para el juego
        int numeroSecreto, maxNumero, maxIntentos;
        int intento, intentos = 0;
        bool adivinado = false;
        
        // 🎯 TODO: Configura dificultad usando switch
        switch (opcion) {
            case 1:
                maxNumero = 50;
                maxIntentos = 10;
                break;
            case 2:
                // TODO: Configurar nivel medio
                break;
            case 3:
                // TODO: Configurar nivel difícil
                break;
            case 4:
                // TODO: Mostrar estadísticas de juegos anteriores
                continue;
            case 0:
                cout << "¡Gracias por jugar!" << endl;
                continue;
            default:
                cout << "Opción inválida" << endl;
                continue;
        }
        
        // 🎯 TODO: Genera número aleatorio
        numeroSecreto = rand() % maxNumero + 1;
        
        cout << "\n¡He pensado un número entre 1 y " << maxNumero << "!" << endl;
        cout << "Tienes " << maxIntentos << " intentos" << endl;
        
        // 🎯 TODO: Bucle principal del juego usando while
        while (intentos < maxIntentos && !adivinado) {
            cout << "\nIntento " << (intentos + 1) << " de " << maxIntentos << endl;
            cout << "Ingresa tu número: ";
            cin >> intento;
            
            intentos++;
            
            // 🎯 TODO: Evalúa el intento usando if-else
            if (intento == numeroSecreto) {
                // TODO: ¡Ganó!
                adivinado = true;
            } else if (intento < numeroSecreto) {
                // TODO: Número es mayor
                cout << "El número es MAYOR que " << intento << endl;
            } else {
                // TODO: Número es menor
                cout << "El número es MENOR que " << intento << endl;
            }
            
            // 🎯 TODO: Da pistas adicionales
            if (!adivinado && intentos < maxIntentos) {
                int diferencia = abs(intento - numeroSecreto);
                // TODO: Usar if-else para dar pistas de proximidad
            }
        }
        
        // 🎯 TODO: Muestra resultado final
        if (adivinado) {
            // TODO: Mensaje de victoria con clasificación
        } else {
            // TODO: Mensaje de derrota
        }
        
        // 🎯 TODO: Pregunta si quiere jugar de nuevo
        
    } while (opcion != 0);
}

/*
================================================================================
📝 PLANTILLA 4: CALCULADORA CIENTÍFICA
================================================================================
Crea una calculadora con múltiples operaciones
================================================================================
*/

void ejercicio_4_calculadora_cientifica() {
    cout << "\n=== EJERCICIO 4: CALCULADORA CIENTÍFICA ===" << endl;
    
    double resultado = 0.0;
    bool calculadoraActiva = true;
    
    // 🎯 TODO: Usa do-while para mantener la calculadora activa
    do {
        cout << "\n--- CALCULADORA CIENTÍFICA ---" << endl;
        cout << "Resultado actual: " << resultado << endl;
        cout << "\n1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicación" << endl;
        cout << "4. División" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Raíz cuadrada" << endl;
        cout << "7. Porcentaje" << endl;
        cout << "8. Limpiar (C)" << endl;
        cout << "9. Historial" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una operación: ";
        
        int opcion;
        cin >> opcion;
        
        // 🎯 TODO: Usa switch-case para las operaciones
        switch (opcion) {
            case 1: {
                // TODO: Suma
                double numero;
                cout << "Ingrese el número a sumar: ";
                cin >> numero;
                resultado += numero;
                cout << "Resultado: " << resultado << endl;
                break;
            }
            case 2:
                // TODO: Resta
                break;
            case 3:
                // TODO: Multiplicación
                break;
            case 4:
                // TODO: División (validar división por cero)
                break;
            case 5:
                // TODO: Potencia (usar bucle for o función pow)
                break;
            case 6:
                // TODO: Raíz cuadrada (validar números negativos)
                break;
            case 7:
                // TODO: Calcular porcentaje
                break;
            case 8:
                // TODO: Limpiar resultado
                resultado = 0.0;
                cout << "Calculadora limpiada" << endl;
                break;
            case 9:
                // TODO: Mostrar historial de operaciones
                break;
            case 0:
                calculadoraActiva = false;
                cout << "¡Gracias por usar la calculadora!" << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (calculadoraActiva);
}

/*
================================================================================
📝 PLANTILLA 5: SISTEMA DE INVENTARIO
================================================================================
Crea un sistema básico de gestión de inventario
================================================================================
*/

void ejercicio_5_sistema_inventario() {
    cout << "\n=== EJERCICIO 5: SISTEMA DE INVENTARIO ===" << endl;
    
    // 🎯 TODO: Declara variables para productos (máximo 10 productos)
    string nombres[10];
    int cantidades[10];
    double precios[10];
    int totalProductos = 0;
    
    int opcion;
    
    // 🎯 TODO: Menú principal usando do-while
    do {
        cout << "\n--- SISTEMA DE INVENTARIO ---" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Actualizar cantidad" << endl;
        cout << "5. Calcular valor total" << endl;
        cout << "6. Productos con stock bajo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // 🎯 TODO: Agregar producto
                if (totalProductos < 10) {
                    cout << "Ingrese el nombre del producto: ";
                    // TODO: Leer nombre, cantidad y precio
                    // TODO: Incrementar totalProductos
                } else {
                    cout << "Inventario lleno" << endl;
                }
                break;
                
            case 2:
                // 🎯 TODO: Mostrar inventario usando for
                if (totalProductos == 0) {
                    cout << "Inventario vacío" << endl;
                } else {
                    cout << "\n--- INVENTARIO ACTUAL ---" << endl;
                    // TODO: Usar bucle for para mostrar todos los productos
                }
                break;
                
            case 3:
                // 🎯 TODO: Buscar producto por nombre
                if (totalProductos == 0) {
                    cout << "Inventario vacío" << endl;
                } else {
                    string nombreBuscar;
                    cout << "Ingrese el nombre a buscar: ";
                    cin.ignore();
                    getline(cin, nombreBuscar);
                    
                    bool encontrado = false;
                    // TODO: Usar bucle for para buscar
                    // TODO: Usar if para comparar nombres
                }
                break;
                
            case 4:
                // 🎯 TODO: Actualizar cantidad
                // TODO: Buscar producto y modificar cantidad
                break;
                
            case 5:
                // 🎯 TODO: Calcular valor total del inventario
                if (totalProductos == 0) {
                    cout << "Inventario vacío" << endl;
                } else {
                    double valorTotal = 0.0;
                    // TODO: Usar bucle for para sumar valores
                    cout << "Valor total del inventario: $" << valorTotal << endl;
                }
                break;
                
            case 6:
                // 🎯 TODO: Mostrar productos con stock bajo (menos de 5)
                cout << "\n--- PRODUCTOS CON STOCK BAJO ---" << endl;
                // TODO: Usar bucle for e if para filtrar
                break;
                
            case 0:
                cout << "¡Gracias por usar el sistema!" << endl;
                break;
                
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 0);
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL - MENÚ DE EJERCICIOS
================================================================================
*/

int main() {
    cout << "🚀 PRÁCTICA SEMANA 2: CONTROL DE FLUJO" << endl;
    cout << "=====================================" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ DE EJERCICIOS ---" << endl;
        cout << "0. Ver ejemplo completo" << endl;
        cout << "1. Menú de restaurante" << endl;
        cout << "2. Generador de patrones" << endl;
        cout << "3. Juego de adivinanza avanzado" << endl;
        cout << "4. Calculadora científica" << endl;
        cout << "5. Sistema de inventario" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione un ejercicio: ";
        cin >> opcion;
        
        switch (opcion) {
            case 0:
                ejercicio_ejemplo();
                break;
            case 1:
                ejercicio_1_menu_restaurante();
                break;
            case 2:
                ejercicio_2_generador_patrones();
                break;
            case 3:
                ejercicio_3_juego_adivinanza_avanzado();
                break;
            case 4:
                ejercicio_4_calculadora_cientifica();
                break;
            case 5:
                ejercicio_5_sistema_inventario();
                break;
            case 9:
                cout << "¡Excelente trabajo en la Semana 2!" << endl;
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
📋 CHECKLIST DE COMPLETADO - SEMANA 2
================================================================================

□ Ejercicio 0: Estudié y entendí el ejemplo del sistema de notas
□ Ejercicio 1: Completé el menú de restaurante con cálculos
□ Ejercicio 2: Implementé todos los generadores de patrones
□ Ejercicio 3: Desarrollé el juego de adivinanza con niveles
□ Ejercicio 4: Construí la calculadora científica funcional
□ Ejercicio 5: Creé el sistema de inventario completo

ESTRUCTURAS DE CONTROL PRACTICADAS:
□ if, else if, else - Condicionales simples y múltiples
□ switch-case - Menús y opciones múltiples
□ for - Bucles con contador definido
□ while - Bucles con condición al inicio
□ do-while - Bucles con condición al final
□ Bucles anidados - Patrones y matrices
□ break y continue - Control de flujo en bucles

CONCEPTOS AVANZADOS:
□ Validación de entrada de datos
□ Menús interactivos con múltiples niveles
□ Manejo de arrays básicos
□ Generación de números aleatorios
□ Formateo de salida avanzado
□ Lógica de juegos y aplicaciones

AUTOEVALUACIÓN:
□ Todos mis programas compilan correctamente
□ He probado diferentes casos de entrada
□ Mis bucles terminan correctamente (no infinitos)
□ He manejado casos de error apropiadamente
□ Mi código está bien comentado y organizado

PUNTUACIÓN: ___/100
TIEMPO INVERTIDO: _____ horas
DIFICULTAD PERCIBIDA (1-10): _____
EJERCICIO MÁS DIFÍCIL: _______________
EJERCICIO MÁS DIVERTIDO: _______________

COMENTARIOS Y REFLEXIONES:
_________________________________________________
_________________________________________________
_________________________________________________

================================================================================
*/