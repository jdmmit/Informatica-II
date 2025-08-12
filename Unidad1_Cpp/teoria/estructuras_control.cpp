/*
================================================================================
📚 TEORÍA AVANZADA: ESTRUCTURAS DE CONTROL EN C++ - ESTUDIO PROFUNDO
================================================================================
Archivo: estructuras_control.cpp
Propósito: Dominio completo de estructuras de control y flujo de programas
Material de referencia: 02_EstructurasDeControl.pdf
Tiempo de estudio: 10-12 horas (estudio profundo)
Nivel: Desde principiante hasta avanzado
================================================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cassert>
#include <algorithm>
using namespace std;

/*
================================================================================
📖 FUNDAMENTOS TEÓRICOS PROFUNDOS: ¿QUÉ SON LAS ESTRUCTURAS DE CONTROL?
================================================================================

🧠 CONCEPTO FUNDAMENTAL:
Las estructuras de control son construcciones del lenguaje que permiten alterar 
el flujo secuencial de ejecución de un programa. Sin ellas, los programas solo 
podrían ejecutar instrucciones en orden lineal.

🏗️ TEORÍA DE LA COMPUTACIÓN:
Según el teorema de Böhm-Jacopini (1966), cualquier algoritmo puede expresarse 
usando solo tres estructuras de control:
1. 📝 SECUENCIA: Ejecución lineal de instrucciones
2. 🔀 SELECCIÓN: Ejecución condicional (if-else)
3. 🔄 ITERACIÓN: Ejecución repetitiva (bucles)

🎯 CLASIFICACIÓN COMPLETA DE ESTRUCTURAS DE CONTROL:

1. 🔀 ESTRUCTURAS DE SELECCIÓN:
   - if simple
   - if-else
   - if-else if-else (cascada)
   - switch-case
   - Operador ternario (?:)

2. 🔄 ESTRUCTURAS DE ITERACIÓN:
   - for (contador)
   - while (condición al inicio)
   - do-while (condición al final)
   - for-each (C++11+)

3. 🚀 ESTRUCTURAS DE SALTO:
   - break (salir de bucle/switch)
   - continue (siguiente iteración)
   - return (salir de función)
   - goto (salto incondicional - no recomendado)

🔍 ANÁLISIS A NIVEL DE MÁQUINA:
- Las estructuras de control se traducen a saltos condicionales e incondicionales
- El procesador usa predicción de ramas para optimizar el rendimiento
- Los bucles se optimizan mediante desenrollado y vectorización

📊 COMPLEJIDAD COMPUTACIONAL:
- Secuencia: O(1) - tiempo constante
- Selección: O(1) - tiempo constante
- Iteración: O(n) - tiempo lineal (donde n es el número de iteraciones)

🎯 PATRONES DE DISEÑO CON ESTRUCTURAS DE CONTROL:
- Guard clauses (cláusulas de guarda)
- Early return (retorno temprano)
- Loop invariants (invariantes de bucle)
- Sentinel values (valores centinela)

================================================================================
*/

/*
================================================================================
📖 ESTUDIO PROFUNDO: ESTRUCTURAS DE SELECCIÓN - DECISIONES Y RAMAS
================================================================================

🔀 ESTRUCTURA IF - ANÁLISIS COMPLETO:

SINTAXIS BÁSICA:
if (condición) {
    // código si verdadero
}

SINTAXIS COMPLETA:
if (condición1) {
    // bloque 1
} else if (condición2) {
    // bloque 2
} else if (condición3) {
    // bloque 3
} else {
    // bloque por defecto
}

🧠 FUNCIONAMIENTO INTERNO:
1. Evalúa la condición (debe ser convertible a bool)
2. Si es verdadera (≠ 0), ejecuta el bloque
3. Si es falsa (== 0), salta al siguiente else/else if
4. Solo se ejecuta UN bloque (el primero que sea verdadero)

⚡ OPTIMIZACIONES DEL COMPILADOR:
- Branch prediction: El procesador predice qué rama se tomará
- Code reordering: Reordena código para mejorar predicción
- Dead code elimination: Elimina código inalcanzable

🎯 PATRONES AVANZADOS CON IF:

1. 🛡️ GUARD CLAUSES (Cláusulas de Guarda):
   Verifican precondiciones y salen temprano si no se cumplen.
   
   ❌ Anidamiento profundo:
   if (usuario_valido) {
       if (contraseña_correcta) {
           if (cuenta_activa) {
               // lógica principal
           }
       }
   }
   
   ✅ Guard clauses:
   if (!usuario_valido) return false;
   if (!contraseña_correcta) return false;
   if (!cuenta_activa) return false;
   // lógica principal

2. 🎯 EARLY RETURN (Retorno Temprano):
   Reduce anidamiento y mejora legibilidad.

3. 🔍 VALIDACIÓN EN CASCADA:
   Múltiples validaciones independientes.

🔀 ESTRUCTURA SWITCH - ANÁLISIS COMPLETO:

SINTAXIS:
switch (expresión) {
    case valor1:
        // código
        break;
    case valor2:
    case valor3:  // fall-through
        // código para valor2 y valor3
        break;
    default:
        // código por defecto
        break;
}

🧠 FUNCIONAMIENTO INTERNO:
- La expresión debe ser de tipo entero o enumerable
- Se compara con cada case usando ==
- Sin break, continúa ejecutando casos siguientes (fall-through)
- default es opcional pero recomendado

⚡ OPTIMIZACIONES:
- Jump table: Para muchos cases, se crea una tabla de saltos
- Binary search: Para cases dispersos, búsqueda binaria
- If-else chain: Para pocos cases, se convierte a if-else

🎯 CUÁNDO USAR SWITCH VS IF:
- Switch: Múltiples valores discretos de una variable
- If: Condiciones complejas, rangos, múltiples variables

================================================================================
*/

void estudio_profundo_seleccion() {
    cout << "=== ESTUDIO PROFUNDO: ESTRUCTURAS DE SELECCIÓN ===" << endl;
    
    cout << "\n🔀 ANÁLISIS DE LA ESTRUCTURA IF:" << endl;
    
    // Demostración de diferentes tipos de condiciones
    int numero = 15;
    string texto = "Hola";
    bool flag = true;
    int* ptr = &numero;
    
    cout << "Variables de prueba:" << endl;
    cout << "numero = " << numero << ", texto = \"" << texto << "\", flag = " << boolalpha << flag << noboolalpha << endl;
    
    cout << "\nTipos de condiciones válidas:" << endl;
    
    // Condición numérica
    if (numero > 10) {
        cout << "✓ Condición numérica: numero > 10 es verdadera" << endl;
    }
    
    // Condición booleana
    if (flag) {
        cout << "✓ Condición booleana: flag es verdadera" << endl;
    }
    
    // Condición de puntero
    if (ptr) {
        cout << "✓ Condición de puntero: ptr no es nullptr" << endl;
    }
    
    // Condición de string (método)
    if (!texto.empty()) {
        cout << "✓ Condición de método: texto no está vacío" << endl;
    }
    
    // Condición compleja
    if ((numero % 2 == 1) && (numero > 0) && (numero < 100)) {
        cout << "✓ Condición compleja: numero es impar, positivo y menor que 100" << endl;
    }
    
    cout << "\n🛡️ DEMOSTRACIÓN DE GUARD CLAUSES:" << endl;
    
    auto validar_usuario = [](const string& usuario, const string& password, bool activo) -> bool {
        cout << "Validando usuario: " << usuario << endl;
        
        // Guard clauses - verificaciones tempranas
        if (usuario.empty()) {
            cout << "❌ Error: Usuario vacío" << endl;
            return false;
        }
        
        if (password.length() < 6) {
            cout << "❌ Error: Contraseña muy corta" << endl;
            return false;
        }
        
        if (!activo) {
            cout << "❌ Error: Cuenta inactiva" << endl;
            return false;
        }
        
        // Si llegamos aquí, todo está bien
        cout << "✅ Usuario válido" << endl;
        return true;
    };
    
    // Probar diferentes casos
    validar_usuario("", "123456", true);        // Usuario vacío
    validar_usuario("juan", "123", true);       // Contraseña corta
    validar_usuario("juan", "123456", false);   // Cuenta inactiva
    validar_usuario("juan", "123456", true);    // Todo correcto
    
    cout << "\n🎯 COMPARACIÓN: IF-ELSE VS SWITCH:" << endl;
    
    char calificacion = 'B';
    cout << "Calificación: " << calificacion << endl;
    
    // Versión con if-else
    cout << "\nUsando if-else:" << endl;
    if (calificacion == 'A') {
        cout << "Excelente (90-100)" << endl;
    } else if (calificacion == 'B') {
        cout << "Muy bueno (80-89)" << endl;
    } else if (calificacion == 'C') {
        cout << "Bueno (70-79)" << endl;
    } else if (calificacion == 'D') {
        cout << "Regular (60-69)" << endl;
    } else if (calificacion == 'F') {
        cout << "Reprobado (0-59)" << endl;
    } else {
        cout << "Calificación inválida" << endl;
    }
    
    // Versión con switch
    cout << "\nUsando switch:" << endl;
    switch (calificacion) {
        case 'A':
            cout << "Excelente (90-100)" << endl;
            break;
        case 'B':
            cout << "Muy bueno (80-89)" << endl;
            break;
        case 'C':
            cout << "Bueno (70-79)" << endl;
            break;
        case 'D':
            cout << "Regular (60-69)" << endl;
            break;
        case 'F':
            cout << "Reprobado (0-59)" << endl;
            break;
        default:
            cout << "Calificación inválida" << endl;
            break;
    }
    
    cout << "\n🔄 DEMOSTRACIÓN DE FALL-THROUGH EN SWITCH:" << endl;
    
    int dia_semana = 3; // 1=Lunes, 2=Martes, ..., 7=Domingo
    cout << "Día de la semana: " << dia_semana << endl;
    
    switch (dia_semana) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Es día laboral" << endl;
            break;
        case 6:
        case 7:
            cout << "Es fin de semana" << endl;
            break;
        default:
            cout << "Día inválido" << endl;
            break;
    }
    
    cout << "\n🎮 EJEMPLO PRÁCTICO: MENÚ DE JUEGO:" << endl;
    
    auto mostrar_menu_juego = []() {
        cout << "\n=== MENÚ PRINCIPAL ===" << endl;
        cout << "1. Nuevo juego" << endl;
        cout << "2. Cargar partida" << endl;
        cout << "3. Opciones" << endl;
        cout << "4. Créditos" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
    };
    
    auto procesar_opcion = [](int opcion) {
        switch (opcion) {
            case 1:
                cout << "🎮 Iniciando nuevo juego..." << endl;
                cout << "Cargando nivel 1..." << endl;
                break;
                
            case 2:
                cout << "💾 Cargando partida guardada..." << endl;
                cout << "Partida cargada exitosamente" << endl;
                break;
                
            case 3:
                cout << "⚙️ Menú de opciones:" << endl;
                cout << "- Volumen: 80%" << endl;
                cout << "- Dificultad: Normal" << endl;
                cout << "- Controles: Teclado" << endl;
                break;
                
            case 4:
                cout << "👥 Créditos:" << endl;
                cout << "Desarrollado por: Equipo C++" << endl;
                cout << "Música: Compositor XYZ" << endl;
                cout << "Arte: Artista ABC" << endl;
                break;
                
            case 5:
                cout << "👋 ¡Gracias por jugar!" << endl;
                cout << "Guardando configuración..." << endl;
                break;
                
            default:
                cout << "❌ Opción inválida. Seleccione 1-5." << endl;
                break;
        }
    };
    
    // Simular selección de menú
    mostrar_menu_juego();
    int opcion_simulada = 1;
    cout << opcion_simulada << endl;
    procesar_opcion(opcion_simulada);
    
    cout << "\n📊 ANÁLISIS DE RENDIMIENTO:" << endl;
    cout << "Switch vs If-else para múltiples opciones:" << endl;
    cout << "- Switch: O(1) con jump table para casos consecutivos" << endl;
    cout << "- Switch: O(log n) con búsqueda binaria para casos dispersos" << endl;
    cout << "- If-else: O(n) evaluación secuencial" << endl;
    cout << "- Recomendación: Switch para 3+ casos discretos" << endl;
    
    cout << "\n💡 BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Usar guard clauses para reducir anidamiento" << endl;
    cout << "✅ Siempre incluir default en switch" << endl;
    cout << "✅ Usar break en cada case (salvo fall-through intencional)" << endl;
    cout << "✅ Preferir switch para múltiples valores discretos" << endl;
    cout << "✅ Usar if para condiciones complejas o rangos" << endl;
    cout << "❌ Evitar anidamiento profundo (>3 niveles)" << endl;
    cout << "❌ No usar goto (excepto casos muy específicos)" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: ESTRUCTURAS DE ITERACIÓN - BUCLES Y REPETICIÓN
================================================================================

🔄 BUCLE FOR - ANÁLISIS COMPLETO:

SINTAXIS CLÁSICA:
for (inicialización; condición; actualización) {
    // cuerpo del bucle
}

FASES DE EJECUCIÓN:
1. INICIALIZACIÓN: Se ejecuta una sola vez al inicio
2. CONDICIÓN: Se evalúa antes de cada iteración
3. CUERPO: Se ejecuta si la condición es verdadera
4. ACTUALIZACIÓN: Se ejecuta después del cuerpo
5. Vuelve al paso 2

🧠 VARIANTES DEL FOR:

1. FOR CLÁSICO (contador):
   for (int i = 0; i < 10; i++) { ... }

2. FOR CON MÚLTIPLES VARIABLES:
   for (int i = 0, j = 10; i < j; i++, j--) { ... }

3. FOR INFINITO:
   for (;;) { ... } // equivale a while(true)

4. FOR SIN INICIALIZACIÓN:
   int i = 0;
   for (; i < 10; i++) { ... }

5. FOR RANGE (C++11):
   for (auto elemento : contenedor) { ... }

🔄 BUCLE WHILE - ANÁLISIS COMPLETO:

SINTAXIS:
while (condición) {
    // cuerpo del bucle
}

CARACTERÍSTICAS:
- Condición se evalúa ANTES de cada iteración
- Si la condición es falsa inicialmente, no se ejecuta nunca
- Útil cuando no sabemos cuántas iteraciones necesitamos
- Requiere actualización manual de variables de control

🔄 BUCLE DO-WHILE - ANÁLISIS COMPLETO:

SINTAXIS:
do {
    // cuerpo del bucle
} while (condición);

CARACTERÍSTICAS:
- Condición se evalúa DESPUÉS de cada iteración
- Se ejecuta AL MENOS UNA VEZ
- Útil para menús y validaciones
- Menos común que for y while

🎯 CUÁNDO USAR CADA BUCLE:

FOR:
- Número conocido de iteraciones
- Recorrer arrays/contenedores
- Contadores y rangos definidos

WHILE:
- Número desconocido de iteraciones
- Condiciones complejas
- Lectura de archivos/entrada

DO-WHILE:
- Al menos una ejecución garantizada
- Menús interactivos
- Validación de entrada

⚡ OPTIMIZACIONES DE BUCLES:

1. LOOP UNROLLING (Desenrollado):
   El compilador puede "desenrollar" bucles pequeños para reducir overhead.

2. VECTORIZACIÓN:
   Operaciones en paralelo usando instrucciones SIMD.

3. LOOP INVARIANT CODE MOTION:
   Mover cálculos constantes fuera del bucle.

4. STRENGTH REDUCTION:
   Reemplazar operaciones costosas por más baratas.

⚠️ PROBLEMAS COMUNES:

1. 🌀 BUCLES INFINITOS:
   - Condición que nunca se vuelve falsa
   - Actualización incorrecta de variables de control

2. 🔢 ERRORES DE ÍNDICE:
   - Off-by-one errors (errores por uno)
   - Acceso fuera de límites de arrays

3. 🐌 INEFICIENCIA:
   - Cálculos innecesarios dentro del bucle
   - Condiciones complejas que se evalúan repetidamente

================================================================================
*/

void estudio_profundo_iteracion() {
    cout << "\n=== ESTUDIO PROFUNDO: ESTRUCTURAS DE ITERACIÓN ===" << endl;
    
    cout << "\n🔄 ANÁLISIS COMPARATIVO DE BUCLES:" << endl;
    
    // Mismo objetivo con diferentes bucles: sumar números del 1 al 10
    int suma_for = 0, suma_while = 0, suma_do_while = 0;
    
    cout << "Objetivo: Sumar números del 1 al 10" << endl;
    
    // Versión con FOR
    cout << "\n1. BUCLE FOR:" << endl;
    cout << "for (int i = 1; i <= 10; i++) { suma += i; }" << endl;
    for (int i = 1; i <= 10; i++) {
        suma_for += i;
        cout << "i=" << i << ", suma=" << suma_for << endl;
    }
    cout << "Resultado final: " << suma_for << endl;
    
    // Versión con WHILE
    cout << "\n2. BUCLE WHILE:" << endl;
    cout << "int i = 1; while (i <= 10) { suma += i; i++; }" << endl;
    int i = 1;
    while (i <= 10) {
        suma_while += i;
        cout << "i=" << i << ", suma=" << suma_while << endl;
        i++;
    }
    cout << "Resultado final: " << suma_while << endl;
    
    // Versión con DO-WHILE
    cout << "\n3. BUCLE DO-WHILE:" << endl;
    cout << "int i = 1; do { suma += i; i++; } while (i <= 10);" << endl;
    i = 1;
    do {
        suma_do_while += i;
        cout << "i=" << i << ", suma=" << suma_do_while << endl;
        i++;
    } while (i <= 10);
    cout << "Resultado final: " << suma_do_while << endl;
    
    cout << "\n🎯 CASOS DE USO ESPECÍFICOS:" << endl;
    
    // FOR: Recorrer array
    cout << "\n📊 FOR - Recorriendo un array:" << endl;
    int numeros[] = {2, 4, 6, 8, 10};
    int tamaño = sizeof(numeros) / sizeof(numeros[0]);
    
    cout << "Array: ";
    for (int i = 0; i < tamaño; i++) {
        cout << numeros[i];
        if (i < tamaño - 1) cout << ", ";
    }
    cout << endl;
    
    // WHILE: Lectura hasta condición
    cout << "\n📖 WHILE - Lectura hasta encontrar valor:" << endl;
    vector<int> datos = {1, 3, 5, 7, 9, 4, 11, 13};
    cout << "Buscando el primer número par en: ";
    for (int n : datos) cout << n << " ";
    cout << endl;
    
    int indice = 0;
    while (indice < datos.size() && datos[indice] % 2 != 0) {
        cout << "Revisando " << datos[indice] << " - es impar" << endl;
        indice++;
    }
    
    if (indice < datos.size()) {
        cout << "¡Encontrado! " << datos[indice] << " en posición " << indice << endl;
    } else {
        cout << "No se encontró ningún número par" << endl;
    }
    
    // DO-WHILE: Menú interactivo
    cout << "\n🎮 DO-WHILE - Menú interactivo (simulado):" << endl;
    
    auto simular_menu = []() {
        int opcion;
        int iteracion = 0;
        vector<int> opciones_simuladas = {3, 1, 2, 0}; // Simular entrada del usuario
        
        do {
            cout << "\n--- MENÚ ---" << endl;
            cout << "1. Opción A" << endl;
            cout << "2. Opción B" << endl;
            cout << "3. Opción C" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione: ";
            
            // Simular entrada del usuario
            if (iteracion < opciones_simuladas.size()) {
                opcion = opciones_simuladas[iteracion];
                cout << opcion << " (simulado)" << endl;
            } else {
                opcion = 0;
                cout << "0 (simulado)" << endl;
            }
            
            switch (opcion) {
                case 1:
                    cout << "Ejecutando Opción A" << endl;
                    break;
                case 2:
                    cout << "Ejecutando Opción B" << endl;
                    break;
                case 3:
                    cout << "Ejecutando Opción C" << endl;
                    break;
                case 0:
                    cout << "Saliendo del menú..." << endl;
                    break;
                default:
                    cout << "Opción inválida" << endl;
                    break;
            }
            
            iteracion++;
        } while (opcion != 0 && iteracion < 10); // Límite para evitar bucle infinito en simulación
    };
    
    simular_menu();
    
    cout << "\n🔍 VARIANTES AVANZADAS DEL FOR:" << endl;
    
    // FOR con múltiples variables
    cout << "\n1. FOR con múltiples variables:" << endl;
    cout << "for (int i = 0, j = 10; i < j; i++, j--)" << endl;
    for (int i = 0, j = 10; i < j; i++, j--) {
        cout << "i=" << i << ", j=" << j << ", diferencia=" << (j-i) << endl;
    }
    
    // FOR anidados - tabla de multiplicar
    cout << "\n2. FOR anidados - Tabla de multiplicar (3x3):" << endl;
    for (int fila = 1; fila <= 3; fila++) {
        for (int columna = 1; columna <= 3; columna++) {
            cout << setw(4) << (fila * columna);
        }
        cout << endl;
    }
    
    // FOR range (C++11)
    cout << "\n3. FOR range (C++11):" << endl;
    vector<string> frutas = {"manzana", "banana", "naranja", "uva"};
    cout << "Frutas: ";
    for (const auto& fruta : frutas) {
        cout << fruta << " ";
    }
    cout << endl;
    
    cout << "\n⚠️ PROBLEMAS COMUNES Y SOLUCIONES:" << endl;
    
    // Error off-by-one
    cout << "\n1. Error off-by-one:" << endl;
    int array_test[] = {10, 20, 30, 40, 50};
    int size = sizeof(array_test) / sizeof(array_test[0]);
    
    cout << "❌ Incorrecto (accede fuera del array):" << endl;
    cout << "for (int i = 0; i <= size; i++) // ¡Error!" << endl;
    cout << "Tamaño del array: " << size << ", índices válidos: 0 a " << (size-1) << endl;
    
    cout << "✅ Correcto:" << endl;
    cout << "for (int i = 0; i < size; i++)" << endl;
    for (int i = 0; i < size; i++) {
        cout << "array[" << i << "] = " << array_test[i] << endl;
    }
    
    // Bucle infinito
    cout << "\n2. Prevención de bucles infinitos:" << endl;
    cout << "❌ Peligroso:" << endl;
    cout << "for (int i = 0; i != 10; i += 2) // Si i salta sobre 10, bucle infinito" << endl;
    cout << "✅ Seguro:" << endl;
    cout << "for (int i = 0; i < 10; i += 2) // Siempre terminará" << endl;
    
    // Demostración segura
    for (int i = 0; i < 10; i += 2) {
        cout << "i = " << i << endl;
    }
    
    cout << "\n⚡ OPTIMIZACIONES DE RENDIMIENTO:" << endl;
    
    // Mover cálculos fuera del bucle
    cout << "\n1. Mover cálculos invariantes fuera del bucle:" << endl;
    vector<int> grandes_datos(1000, 1);
    
    cout << "❌ Ineficiente:" << endl;
    cout << "for (int i = 0; i < datos.size(); i++) // size() se calcula cada vez" << endl;
    
    cout << "✅ Eficiente:" << endl;
    cout << "int tamaño = datos.size();" << endl;
    cout << "for (int i = 0; i < tamaño; i++) // size() se calcula una vez" << endl;
    
    // Demostración de tiempo (conceptual)
    auto inicio = chrono::high_resolution_clock::now();
    
    // Versión optimizada
    int tamaño_opt = grandes_datos.size();
    int suma_opt = 0;
    for (int i = 0; i < tamaño_opt; i++) {
        suma_opt += grandes_datos[i];
    }
    
    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);
    
    cout << "Suma calculada: " << suma_opt << " en " << duracion.count() << " microsegundos" << endl;
    
    cout << "\n💡 BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Usar for para iteraciones con contador conocido" << endl;
    cout << "✅ Usar while para condiciones complejas" << endl;
    cout << "✅ Usar do-while para al menos una ejecución" << endl;
    cout << "✅ Preferir for-range para contenedores (C++11+)" << endl;
    cout << "✅ Mover cálculos invariantes fuera del bucle" << endl;
    cout << "✅ Usar break y continue apropiadamente" << endl;
    cout << "❌ Evitar modificar variables de control dentro del bucle" << endl;
    cout << "❌ No crear bucles infinitos accidentales" << endl;
    cout << "❌ Evitar anidamiento excesivo (>3 niveles)" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: CONTROL DE FLUJO AVANZADO - BREAK, CONTINUE, RETURN
================================================================================

🚀 INSTRUCCIONES DE SALTO:

Las instrucciones de salto alteran el flujo normal de ejecución, permitiendo
salir de bucles, saltar iteraciones o terminar funciones prematuramente.

1. 🛑 BREAK:
   - Sale inmediatamente del bucle o switch más interno
   - No afecta bucles externos en estructuras anidadas
   - Transfiere control a la primera instrucción después del bucle

2. ⏭️ CONTINUE:
   - Salta el resto de la iteración actual
   - Continúa con la siguiente iteración del bucle
   - En for: ejecuta la actualización, luego evalúa la condición
   - En while/do-while: va directamente a evaluar la condición

3. 🔙 RETURN:
   - Termina la ejecución de la función actual
   - Puede devolver un valor (en funciones no void)
   - Transfiere control al punto donde se llamó la función

4. 🎯 GOTO (no recomendado):
   - Salto incondicional a una etiqueta
   - Puede crear código difícil de seguir ("spaghetti code")
   - Uso limitado a casos muy específicos

🎯 PATRONES AVANZADOS:

1. 🔍 BÚSQUEDA CON BREAK:
   Salir del bucle cuando se encuentra lo que se busca.

2. 🧹 FILTRADO CON CONTINUE:
   Saltar elementos que no cumplen criterios.

3. 🛡️ VALIDACIÓN CON RETURN:
   Salir temprano de funciones si las condiciones no se cumplen.

4. 🎮 CONTROL DE MENÚS:
   Usar break para salir de menús infinitos.

⚠️ CONSIDERACIONES IMPORTANTES:

1. BUCLES ANIDADOS:
   - break/continue solo afectan el bucle más interno
   - Para salir de múltiples niveles, usar flags o funciones

2. RENDIMIENTO:
   - break puede mejorar eficiencia al evitar iteraciones innecesarias
   - continue puede ser menos eficiente que restructurar la lógica

3. LEGIBILIDAD:
   - Uso excesivo puede hacer código difícil de seguir
   - Preferir estructuras claras cuando sea posible

================================================================================
*/

void estudio_profundo_control_flujo() {
    cout << "\n=== ESTUDIO PROFUNDO: CONTROL DE FLUJO AVANZADO ===" << endl;
    
    cout << "\n🛑 DEMOSTRACIÓN DE BREAK:" << endl;
    
    // Búsqueda en array con break
    vector<int> numeros = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int objetivo = 10;
    int posicion = -1;
    
    cout << "Buscando " << objetivo << " en el array: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;
    
    for (int i = 0; i < numeros.size(); i++) {
        cout << "Revisando posición " << i << ": " << numeros[i] << endl;
        if (numeros[i] == objetivo) {
            posicion = i;
            cout << "¡Encontrado! Saliendo del bucle con break" << endl;
            break; // Sale inmediatamente del bucle
        }
    }
    
    if (posicion != -1) {
        cout << "Resultado: " << objetivo << " encontrado en posición " << posicion << endl;
    } else {
        cout << "Resultado: " << objetivo << " no encontrado" << endl;
    }
    
    cout << "\n⏭️ DEMOSTRACIÓN DE CONTINUE:" << endl;
    
    // Procesar solo números pares
    vector<int> datos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Procesando solo números pares de: ";
    for (int n : datos) cout << n << " ";
    cout << endl;
    
    cout << "Números pares procesados:" << endl;
    for (int numero : datos) {
        if (numero % 2 != 0) {
            cout << "Saltando " << numero << " (es impar)" << endl;
            continue; // Salta el resto de esta iteración
        }
        
        // Este código solo se ejecuta para números pares
        cout << "Procesando " << numero << " -> " << (numero * numero) << endl;
    }
    
    cout << "\n🔄 BREAK Y CONTINUE EN BUCLES ANIDADOS:" << endl;
    
    cout << "Matriz 5x5, buscando el número 13:" << endl;
    bool encontrado = false;
    
    for (int fila = 0; fila < 5 && !encontrado; fila++) {
        cout << "Fila " << fila << ": ";
        for (int columna = 0; columna < 5; columna++) {
            int valor = fila * 5 + columna + 1; // Valores 1-25
            cout << setw(3) << valor;
            
            if (valor == 13) {
                cout << " <- ¡ENCONTRADO!";
                encontrado = true;
                break; // Sale del bucle interno
            }
        }
        cout << endl;
        
        if (encontrado) {
            cout << "Saliendo del bucle externo también" << endl;
        }
    }
    
    cout << "\n🎮 EJEMPLO PRÁCTICO: MENÚ CON CONTROL DE FLUJO:" << endl;
    
    auto menu_avanzado = []() {
        vector<int> opciones_simuladas = {1, 3, 2, 4, 0}; // Simular entrada
        int iteracion = 0;
        
        while (true) { // Bucle infinito controlado por break
            cout << "\n=== MENÚ AVANZADO ===" << endl;
            cout << "1. Procesar datos" << endl;
            cout << "2. Mostrar estadísticas" << endl;
            cout << "3. Configuración" << endl;
            cout << "4. Ayuda" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opción: ";
            
            // Simular entrada
            int opcion;
            if (iteracion < opciones_simuladas.size()) {
                opcion = opciones_simuladas[iteracion];
                cout << opcion << " (simulado)" << endl;
            } else {
                opcion = 0;
                cout << "0 (simulado)" << endl;
            }
            
            // Validación con continue
            if (opcion < 0 || opcion > 4) {
                cout << "❌ Opción inválida. Intente de nuevo." << endl;
                iteracion++;
                continue; // Vuelve al inicio del bucle
            }
            
            // Procesar opción válida
            switch (opcion) {
                case 1:
                    cout << "📊 Procesando datos..." << endl;
                    cout << "Datos procesados exitosamente" << endl;
                    break;
                    
                case 2:
                    cout << "📈 Estadísticas:" << endl;
                    cout << "- Registros procesados: 1,234" << endl;
                    cout << "- Tiempo promedio: 2.5ms" << endl;
                    break;
                    
                case 3:
                    cout << "⚙️ Configuración:" << endl;
                    cout << "- Modo debug: Activado" << endl;
                    cout << "- Auto-guardado: Cada 5 min" << endl;
                    break;
                    
                case 4:
                    cout << "❓ Ayuda:" << endl;
                    cout << "Para más información, consulte el manual" << endl;
                    break;
                    
                case 0:
                    cout << "👋 ¡Hasta luego!" << endl;
                    return; // Sale de la función (y del bucle)
            }
            
            iteracion++;
            if (iteracion >= 10) break; // Límite de seguridad para simulación
        }
    };
    
    menu_avanzado();
    
    cout << "\n🔍 PATRONES AVANZADOS DE BÚSQUEDA:" << endl;
    
    // Búsqueda con múltiples criterios
    struct Producto {
        string nombre;
        double precio;
        int stock;
    };
    
    vector<Producto> inventario = {
        {"Laptop", 999.99, 5},
        {"Mouse", 29.99, 0},
        {"Teclado", 79.99, 15},
        {"Monitor", 299.99, 8},
        {"Webcam", 89.99, 0}
    };
    
    cout << "Buscando productos disponibles (stock > 0) y baratos (< $100):" << endl;
    
    for (const auto& producto : inventario) {
        // Saltar productos sin stock
        if (producto.stock == 0) {
            cout << "❌ " << producto.nombre << " - Sin stock, saltando" << endl;
            continue;
        }
        
        // Saltar productos caros
        if (producto.precio >= 100.0) {
            cout << "💰 " << producto.nombre << " - Muy caro ($" << producto.precio << "), saltando" << endl;
            continue;
        }
        
        // Este producto cumple todos los criterios
        cout << "✅ " << producto.nombre << " - $" << producto.precio 
             << " (Stock: " << producto.stock << ")" << endl;
    }
    
    cout << "\n🎯 FUNCIÓN CON MÚLTIPLES RETURNS:" << endl;
    
    auto validar_password = [](const string& password) -> string {
        cout << "Validando password: \"" << password << "\"" << endl;
        
        // Validaciones con early return
        if (password.length() < 8) {
            return "❌ Muy corta (mínimo 8 caracteres)";
        }
        
        if (password.length() > 50) {
            return "❌ Muy larga (máximo 50 caracteres)";
        }
        
        bool tiene_mayuscula = false;
        bool tiene_minuscula = false;
        bool tiene_numero = false;
        bool tiene_especial = false;
        
        for (char c : password) {
            if (c >= 'A' && c <= 'Z') tiene_mayuscula = true;
            else if (c >= 'a' && c <= 'z') tiene_minuscula = true;
            else if (c >= '0' && c <= '9') tiene_numero = true;
            else tiene_especial = true;
        }
        
        if (!tiene_mayuscula) {
            return "❌ Debe tener al menos una mayúscula";
        }
        
        if (!tiene_minuscula) {
            return "❌ Debe tener al menos una minúscula";
        }
        
        if (!tiene_numero) {
            return "❌ Debe tener al menos un número";
        }
        
        if (!tiene_especial) {
            return "❌ Debe tener al menos un carácter especial";
        }
        
        return "✅ Password válida";
    };
    
    // Probar diferentes passwords
    vector<string> passwords = {
        "123",
        "password",
        "Password",
        "Password1",
        "Password1!"
    };
    
    for (const string& pwd : passwords) {
        cout << validar_password(pwd) << endl;
    }
    
    cout << "\n💡 BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Usar break para salir de bucles cuando se encuentra lo buscado" << endl;
    cout << "✅ Usar continue para filtrar elementos no deseados" << endl;
    cout << "✅ Usar return temprano para validaciones" << endl;
    cout << "✅ Usar flags para salir de bucles anidados" << endl;
    cout << "✅ Preferir estructuras claras sobre goto" << endl;
    cout << "❌ Evitar break/continue excesivos que confundan el flujo" << endl;
    cout << "❌ No usar goto excepto en casos muy específicos" << endl;
    cout << "❌ Evitar múltiples returns si hacen el código confuso" << endl;
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL MEJORADA - SISTEMA DE APRENDIZAJE COMPLETO
================================================================================
*/

int main() {
    cout << "📚 TEORÍA AVANZADA: ESTRUCTURAS DE CONTROL EN C++" << endl;
    cout << "====================================================" << endl;
    cout << "🎓 Sistema de Aprendizaje Profundo e Interactivo" << endl;
    cout << "🔀 Dominio completo del flujo de control de programas" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ DE ESTUDIOS PROFUNDOS ---" << endl;
        cout << "1. 🔀 Estructuras de selección (if, switch)" << endl;
        cout << "2. 🔄 Estructuras de iteración (for, while, do-while)" << endl;
        cout << "3. 🚀 Control de flujo avanzado (break, continue, return)" << endl;
        cout << "4. 🎯 Operador ternario y expresiones condicionales" << endl;
        cout << "5. 📊 Análisis de complejidad y rendimiento" << endl;
        cout << "6. 🧪 Patrones de diseño con estructuras de control" << endl;
        cout << "7. ⚡ Optimizaciones del compilador" << endl;
        cout << "8. 🎮 Proyecto integrador: Sistema de menús avanzado" << endl;
        cout << "9. 📋 Resumen completo y mejores prácticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                estudio_profundo_seleccion();
                break;
            case 2:
                estudio_profundo_iteracion();
                break;
            case 3:
                estudio_profundo_control_flujo();
                break;
            case 4:
                // TODO: Implementar estudio profundo del operador ternario
                cout << "\n🚧 Estudio profundo del operador ternario - En desarrollo" << endl;
                break;
            case 5:
                // TODO: Implementar análisis de complejidad
                cout << "\n🚧 Análisis de complejidad y rendimiento - En desarrollo" << endl;
                break;
            case 6:
                // TODO: Implementar patrones de diseño
                cout << "\n🚧 Patrones de diseño - En desarrollo" << endl;
                break;
            case 7:
                // TODO: Implementar optimizaciones
                cout << "\n🚧 Optimizaciones del compilador - En desarrollo" << endl;
                break;
            case 8:
                // TODO: Implementar proyecto integrador
                cout << "\n🚧 Proyecto integrador - En desarrollo" << endl;
                break;
            case 9:
                // TODO: Implementar resumen completo
                cout << "\n🚧 Resumen completo - En desarrollo" << endl;
                break;
            case 0:
                cout << "\n🎉 ¡Excelente! Has completado el estudio profundo de estructuras de control." << endl;
                cout << "🧠 Ahora dominas el flujo de control en programación." << endl;
                cout << "🚀 Estás listo para crear programas complejos y eficientes." << endl;
                break;
            default:
                cout << "❌ Opción inválida. Seleccione entre 0 y 9." << endl;
        }
        
        if (opcion != 0) {
            cout << "\n📚 Presiona Enter para continuar con tu aprendizaje profundo...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 0);
    
    return 0;
}

/*
================================================================================
📝 PLANTILLA AVANZADA PARA EXPERIMENTACIÓN CON ESTRUCTURAS DE CONTROL
================================================================================

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

int main() {
    cout << "=== LABORATORIO DE ESTRUCTURAS DE CONTROL ===" << endl;
    
    // 🎯 EXPERIMENTO 1: Comparación de rendimiento de bucles
    cout << "\n1. COMPARANDO RENDIMIENTO DE BUCLES:" << endl;
    // TODO: Medir tiempo de for vs while vs do-while
    // TODO: Analizar impacto de diferentes tamaños de datos
    // TODO: Comparar bucles simples vs anidados
    
    // 🎯 EXPERIMENTO 2: Optimización de condiciones
    cout << "\n2. OPTIMIZANDO CONDICIONES:" << endl;
    // TODO: Comparar if-else vs switch para diferentes casos
    // TODO: Analizar impacto del orden de condiciones
    // TODO: Medir efecto de la predicción de ramas
    
    // 🎯 EXPERIMENTO 3: Patrones de control de flujo
    cout << "\n3. PATRONES DE CONTROL DE FLUJO:" << endl;
    // TODO: Implementar diferentes patrones de búsqueda
    // TODO: Comparar eficiencia de break vs flags
    // TODO: Analizar legibilidad vs rendimiento
    
    // 🎯 EXPERIMENTO 4: Estructuras anidadas complejas
    cout << "\n4. ESTRUCTURAS ANIDADAS COMPLEJAS:" << endl;
    // TODO: Crear algoritmos con múltiples niveles de anidamiento
    // TODO: Implementar alternativas más legibles
    // TODO: Medir impacto en rendimiento y mantenibilidad
    
    // 🎯 EXPERIMENTO 5: Casos límite y edge cases
    cout << "\n5. CASOS LÍMITE:" << endl;
    // TODO: Probar bucles con 0 iteraciones
    // TODO: Analizar comportamiento con datos extremos
    // TODO: Implementar manejo robusto de errores
    
    return 0;
}

================================================================================
🎯 EJERCICIOS DE INVESTIGACIÓN AVANZADA - ESTRUCTURAS DE CONTROL
================================================================================

1. 🔬 ANÁLISIS DE COMPLEJIDAD:
   - Calcula la complejidad temporal de algoritmos con bucles anidados
   - Compara diferentes enfoques para el mismo problema
   - Analiza el impacto de las optimizaciones del compilador

2. 🎮 IMPLEMENTACIÓN DE JUEGOS:
   - Crea un juego completo usando solo estructuras de control básicas
   - Implementa IA simple con árboles de decisión
   - Desarrolla sistemas de menús complejos e intuitivos

3. 🧮 ALGORITMOS CLÁSICOS:
   - Implementa algoritmos de ordenamiento (bubble, selection, insertion)
   - Desarrolla algoritmos de búsqueda (lineal, binaria)
   - Crea algoritmos de generación de patrones y fractales

4. 📊 ANÁLISIS DE DATOS:
   - Procesa grandes conjuntos de datos con bucles eficientes
   - Implementa filtros y transformaciones complejas
   - Desarrolla sistemas de validación robustos

5. 🚀 OPTIMIZACIÓN AVANZADA:
   - Implementa técnicas de loop unrolling manual
   - Desarrolla algoritmos cache-friendly
   - Crea versiones paralelas de algoritmos secuenciales

================================================================================
*/