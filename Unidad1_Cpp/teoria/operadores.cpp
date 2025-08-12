/*
================================================================================
📚 TEORÍA AVANZADA: OPERADORES EN C++ - ESTUDIO PROFUNDO
================================================================================
Archivo: operadores.cpp
Propósito: Dominio completo de todos los operadores y su funcionamiento interno
Material de referencia: inforII-u1-operadores-de-c++.pdf
Tiempo de estudio: 8-10 horas (estudio profundo)
Nivel: Desde principiante hasta avanzado
================================================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <climits>
#include <typeinfo>
#include <chrono>
#include <cassert>
using namespace std;

/*
================================================================================
📖 FUNDAMENTOS TEÓRICOS PROFUNDOS: ¿QUÉ SON LOS OPERADORES?
================================================================================

🧠 CONCEPTO FUNDAMENTAL:
Un operador es un símbolo especial que le dice al compilador que realice 
operaciones específicas matemáticas, lógicas o de manipulación sobre uno o más 
operandos (variables, constantes o expresiones).

🏗️ ARQUITECTURA DE OPERADORES:

1. 📊 CLASIFICACIÓN POR NÚMERO DE OPERANDOS:
   - UNARIOS: Operan sobre un solo operando (++x, -y, !flag)
   - BINARIOS: Operan sobre dos operandos (a + b, x * y, p && q)
   - TERNARIOS: Operan sobre tres operandos (condición ? valor1 : valor2)

2. 🎯 CLASIFICACIÓN POR FUNCIONALIDAD:
   - ARITMÉTICOS: +, -, *, /, %, ++, --
   - RELACIONALES: ==, !=, <, >, <=, >=
   - LÓGICOS: &&, ||, !
   - BITWISE: &, |, ^, ~, <<, >>
   - ASIGNACIÓN: =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
   - OTROS: sizeof, typeid, [], (), ->, ., ::

3. 🔄 PRECEDENCIA Y ASOCIATIVIDAD:
   - PRECEDENCIA: Determina el orden de evaluación
   - ASOCIATIVIDAD: Determina la dirección (izquierda-derecha o derecha-izquierda)

📊 TABLA COMPLETA DE PRECEDENCIA (de mayor a menor):

Nivel | Operadores                    | Asociatividad | Descripción
------|-------------------------------|---------------|------------------
  1   | :: (scope)                    | Izq-Der      | Resolución de ámbito
  2   | () [] -> . ++ --              | Izq-Der      | Postfijo
  3   | ++ -- + - ! ~ (type) * & sizeof| Der-Izq     | Prefijo y unarios
  4   | * / %                         | Izq-Der      | Multiplicativo
  5   | + -                           | Izq-Der      | Aditivo
  6   | << >>                         | Izq-Der      | Desplazamiento
  7   | < <= > >=                     | Izq-Der      | Relacional
  8   | == !=                         | Izq-Der      | Igualdad
  9   | &                             | Izq-Der      | AND bitwise
 10   | ^                             | Izq-Der      | XOR bitwise
 11   | |                             | Izq-Der      | OR bitwise
 12   | &&                            | Izq-Der      | AND lógico
 13   | ||                            | Izq-Der      | OR lógico
 14   | ?:                            | Der-Izq      | Condicional ternario
 15   | = += -= *= /= %= &= |= ^= <<= >>= | Der-Izq  | Asignación
 16   | ,                             | Izq-Der      | Coma

🎯 ¿POR QUÉ ES IMPORTANTE LA PRECEDENCIA?

Ejemplo: int resultado = 2 + 3 * 4;
- Sin precedencia: (2 + 3) * 4 = 20
- Con precedencia: 2 + (3 * 4) = 14 ✓

🔍 EVALUACIÓN DE EXPRESIONES:
El compilador convierte expresiones infijas (a + b) a notación postfija o 
genera código que respeta la precedencia usando una pila de operadores.

⚡ OPTIMIZACIONES DEL COMPILADOR:
- Constant folding: 2 + 3 se calcula en tiempo de compilación
- Strength reduction: x * 2 se convierte en x << 1
- Dead code elimination: if (false) { ... } se elimina

================================================================================
*/

/*
================================================================================
📖 ESTUDIO PROFUNDO: OPERADORES ARITMÉTICOS - MATEMÁTICAS Y HARDWARE
================================================================================

🧮 OPERADORES ARITMÉTICOS BÁSICOS:

1. ➕ SUMA (+):
   - Operación más básica del procesador
   - Implementada directamente en hardware (ALU)
   - Puede causar desbordamiento en tipos enteros
   - Para flotantes: sigue reglas IEEE 754

2. ➖ RESTA (-):
   - Implementada como suma del complemento a dos
   - Unario: cambia el signo del operando
   - Binario: resta el segundo operando del primero

3. ✖️ MULTIPLICACIÓN (*):
   - Más costosa computacionalmente que suma/resta
   - Procesadores modernos tienen multiplicadores dedicados
   - Puede causar desbordamiento más fácilmente
   - Para flotantes: multiplica mantisas y suma exponentes

4. ➗ DIVISIÓN (/):
   - Operación más costosa de las básicas
   - División por cero causa comportamiento indefinido
   - División entera trunca hacia cero
   - Para flotantes: divide mantisas y resta exponentes

5. 📐 MÓDULO (%):
   - Solo para tipos enteros
   - Resto de la división entera
   - Útil para operaciones cíclicas
   - Signo del resultado depende del dividendo

🔍 ANÁLISIS DE RENDIMIENTO:
- Suma/Resta: ~1 ciclo de CPU
- Multiplicación: ~3-5 ciclos de CPU
- División: ~10-40 ciclos de CPU (dependiente del hardware)

⚠️ PROBLEMAS COMUNES:

1. 🌊 DESBORDAMIENTO ARITMÉTICO:
   int max_int = INT_MAX;
   int overflow = max_int + 1; // Comportamiento indefinido

2. 🚫 DIVISIÓN POR CERO:
   int x = 5 / 0; // Error en tiempo de ejecución
   double y = 5.0 / 0.0; // Infinito en flotantes

3. 🔄 PÉRDIDA DE PRECISIÓN:
   int resultado = 7 / 3; // 2, no 2.333...
   double preciso = 7.0 / 3.0; // 2.333...

🎯 OPERADORES DE INCREMENTO/DECREMENTO:

PREFIJO vs POSTFIJO:
- ++x (prefijo): Incrementa x, luego devuelve el nuevo valor
- x++ (postfijo): Devuelve el valor actual de x, luego incrementa

DIFERENCIAS DE RENDIMIENTO:
- Para tipos primitivos: generalmente igual
- Para objetos complejos: prefijo es más eficiente
- Razón: postfijo debe crear una copia temporal

================================================================================
*/

void estudio_profundo_aritmeticos() {
    cout << "=== ESTUDIO PROFUNDO: OPERADORES ARITMÉTICOS ===" << endl;
    
    cout << "\n🧮 OPERACIONES BÁSICAS Y SUS CARACTERÍSTICAS:" << endl;
    
    int a = 15, b = 4;
    double x = 15.0, y = 4.0;
    
    cout << "Operandos enteros: a = " << a << ", b = " << b << endl;
    cout << "Operandos flotantes: x = " << x << ", y = " << y << endl;
    
    cout << "\n📊 RESULTADOS DE OPERACIONES:" << endl;
    cout << "Operación    | Enteros | Flotantes | Observaciones" << endl;
    cout << "-------------|---------|-----------|------------------" << endl;
    cout << "a + b        | " << setw(7) << (a + b) << " | " << setw(9) << (x + y) << " | Suma directa" << endl;
    cout << "a - b        | " << setw(7) << (a - b) << " | " << setw(9) << (x - y) << " | Resta directa" << endl;
    cout << "a * b        | " << setw(7) << (a * b) << " | " << setw(9) << (x * y) << " | Multiplicación" << endl;
    cout << "a / b        | " << setw(7) << (a / b) << " | " << setw(9) << (x / y) << " | División (¡diferente!)" << endl;
    cout << "a % b        | " << setw(7) << (a % b) << " | " << setw(9) << "N/A" << " | Solo enteros" << endl;
    
    cout << "\n⚠️ ANÁLISIS DE DIVISIÓN ENTERA VS FLOTANTE:" << endl;
    cout << "15 / 4 (enteros) = " << (15 / 4) << " (truncado)" << endl;
    cout << "15.0 / 4.0 (flotantes) = " << (15.0 / 4.0) << " (preciso)" << endl;
    cout << "15 / 4.0 (mixto) = " << (15 / 4.0) << " (promoción a double)" << endl;
    
    cout << "\n🔄 OPERADOR MÓDULO - CASOS ESPECIALES:" << endl;
    cout << "Operación | Resultado | Explicación" << endl;
    cout << "----------|-----------|------------------" << endl;
    cout << " 15 % 4   |    " << (15 % 4) << "     | Resto positivo" << endl;
    cout << "-15 % 4   |    " << (-15 % 4) << "     | Resto negativo (signo del dividendo)" << endl;
    cout << " 15 % -4  |    " << (15 % -4) << "     | Resto positivo" << endl;
    cout << "-15 % -4  |    " << (-15 % -4) << "     | Resto negativo" << endl;
    
    cout << "\n🚀 DEMOSTRACIÓN DE INCREMENTO/DECREMENTO:" << endl;
    int pre = 5, post = 5;
    
    cout << "Valores iniciales: pre = " << pre << ", post = " << post << endl;
    
    int resultado_pre = ++pre;   // Prefijo: incrementa, luego asigna
    int resultado_post = post++; // Postfijo: asigna, luego incrementa
    
    cout << "Después de ++pre y post++:" << endl;
    cout << "pre = " << pre << ", resultado de ++pre = " << resultado_pre << endl;
    cout << "post = " << post << ", resultado de post++ = " << resultado_post << endl;
    
    cout << "\n⚡ ANÁLISIS DE RENDIMIENTO (conceptual):" << endl;
    cout << "Operación      | Ciclos CPU (aprox.) | Notas" << endl;
    cout << "---------------|---------------------|------------------" << endl;
    cout << "Suma/Resta     |         1           | Muy rápido" << endl;
    cout << "Multiplicación |        3-5          | Moderado" << endl;
    cout << "División       |       10-40         | Lento" << endl;
    cout << "Módulo         |       10-40         | Similar a división" << endl;
    
    cout << "\n🌊 DEMOSTRACIÓN DE DESBORDAMIENTO:" << endl;
    
    // Desbordamiento en suma
    int casi_max = INT_MAX - 1;
    cout << "INT_MAX - 1 = " << casi_max << endl;
    cout << "(INT_MAX - 1) + 1 = " << (casi_max + 1) << " (OK)" << endl;
    cout << "(INT_MAX - 1) + 2 = " << (casi_max + 2) << " (¡Desbordamiento!)" << endl;
    
    // Desbordamiento en multiplicación
    int grande = 50000;
    cout << "\nMultiplicación: " << grande << " * " << grande << " = " << (grande * grande) << endl;
    cout << "¿Es correcto? " << (grande * grande == 2500000000LL ? "SÍ" : "NO (desbordamiento)") << endl;
    
    cout << "\n🔍 CASOS DE USO PRÁCTICOS DEL MÓDULO:" << endl;
    
    // Determinar si un número es par o impar
    int numero = 17;
    cout << "¿" << numero << " es par? " << (numero % 2 == 0 ? "SÍ" : "NO") << endl;
    
    // Operaciones cíclicas (como días de la semana)
    int dia_actual = 3; // Miércoles (0=Lunes)
    int dias_adelante = 10;
    int dia_futuro = (dia_actual + dias_adelante) % 7;
    string dias[] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};
    cout << "Hoy es " << dias[dia_actual] << ", en " << dias_adelante << " días será " << dias[dia_futuro] << endl;
    
    // Extraer dígitos de un número
    int num = 12345;
    cout << "Último dígito de " << num << ": " << (num % 10) << endl;
    cout << "Penúltimo dígito de " << num << ": " << ((num / 10) % 10) << endl;
    
    cout << "\n💡 OPTIMIZACIONES DEL COMPILADOR:" << endl;
    cout << "- x * 2 puede optimizarse a x << 1 (desplazamiento)" << endl;
    cout << "- x / 2 puede optimizarse a x >> 1 (para enteros positivos)" << endl;
    cout << "- x % 8 puede optimizarse a x & 7 (para potencias de 2)" << endl;
    cout << "- Constantes se calculan en tiempo de compilación" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: OPERADORES RELACIONALES - COMPARACIONES Y LÓGICA
================================================================================

🔍 OPERADORES DE COMPARACIÓN:

Los operadores relacionales comparan dos valores y devuelven un resultado booleano.
Son fundamentales para el control de flujo y la toma de decisiones.

1. 🟰 IGUALDAD (==):
   - Compara si dos valores son exactamente iguales
   - ⚠️ CUIDADO: Un solo = es asignación, == es comparación
   - Para flotantes: problemático debido a precisión limitada

2. 🚫 DESIGUALDAD (!=):
   - Compara si dos valores son diferentes
   - Equivale a !(a == b)
   - Mismo problema que == con flotantes

3. 📏 COMPARACIONES DE ORDEN (<, >, <=, >=):
   - Establecen relaciones de orden entre valores
   - Bien definidas para números y caracteres
   - Para strings: comparación lexicográfica (diccionario)

🔬 ANÁLISIS PROFUNDO DE COMPARACIONES:

COMPARACIÓN DE ENTEROS:
- Directa y eficiente
- Comparación bit a bit en hardware
- Signed vs unsigned puede causar problemas

COMPARACIÓN DE FLOTANTES:
- Problemática debido a errores de redondeo
- IEEE 754 define reglas especiales para NaN e infinitos
- Mejor usar tolerancia: abs(a - b) < epsilon

COMPARACIÓN DE CARACTERES:
- Basada en códigos ASCII/Unicode
- 'A' < 'B' < 'C' ... 'Z' < 'a' < 'b' ... 'z'
- Útil para ordenamiento alfabético

COMPARACIÓN DE STRINGS:
- Lexicográfica (como en diccionario)
- Carácter por carácter usando códigos ASCII
- "abc" < "abd" < "b" < "ba"

⚠️ TRAMPAS COMUNES:

1. 🎭 ASIGNACIÓN EN LUGAR DE COMPARACIÓN:
   if (x = 5) // ¡Error! Asigna 5 a x y evalúa como true
   if (x == 5) // ✓ Correcto: compara x con 5

2. 🔢 MEZCLAR SIGNED Y UNSIGNED:
   int negativo = -1;
   unsigned int positivo = 1;
   if (negativo < positivo) // ¡FALSO! -1 se convierte a número muy grande

3. 🌊 COMPARACIÓN DE FLOTANTES:
   double a = 0.1 + 0.2;
   if (a == 0.3) // ¡Probablemente FALSO!

🎯 OPERADOR SPACESHIP (<=> - C++20):
Nuevo operador que devuelve:
- < 0 si a < b
- 0 si a == b  
- > 0 si a > b

================================================================================
*/

void estudio_profundo_relacionales() {
    cout << "\n=== ESTUDIO PROFUNDO: OPERADORES RELACIONALES ===" << endl;
    
    cout << "\n🔍 COMPARACIONES BÁSICAS:" << endl;
    int a = 10, b = 20, c = 10;
    
    cout << "Variables: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "\nOperador | Expresión | Resultado | Descripción" << endl;
    cout << "---------|-----------|-----------|------------------" << endl;
    cout << "   ==    |  a == c   |    " << boolalpha << (a == c) << "    | Igualdad" << noboolalpha << endl;
    cout << "   !=    |  a != b   |    " << boolalpha << (a != b) << "    | Desigualdad" << noboolalpha << endl;
    cout << "   <     |  a < b    |    " << boolalpha << (a < b) << "    | Menor que" << noboolalpha << endl;
    cout << "   >     |  b > a    |    " << boolalpha << (b > a) << "    | Mayor que" << noboolalpha << endl;
    cout << "   <=    |  a <= c   |    " << boolalpha << (a <= c) << "    | Menor o igual" << noboolalpha << endl;
    cout << "   >=    |  b >= a   |    " << boolalpha << (b >= a) << "    | Mayor o igual" << noboolalpha << endl;
    
    cout << "\n⚠️ PROBLEMA: ASIGNACIÓN VS COMPARACIÓN:" << endl;
    int x = 5;
    cout << "Valor inicial de x: " << x << endl;
    
    // Demostración del error común
    cout << "Evaluando if (x = 10):" << endl;
    if (x = 10) {  // ¡Error! Asigna 10 a x
        cout << "  Condición es verdadera, x ahora vale: " << x << endl;
    }
    
    x = 5; // Restaurar valor
    cout << "Evaluando if (x == 10):" << endl;
    if (x == 10) {  // Correcto: compara
        cout << "  x es igual a 10" << endl;
    } else {
        cout << "  x NO es igual a 10, x vale: " << x << endl;
    }
    
    cout << "\n🔢 PROBLEMA: SIGNED VS UNSIGNED:" << endl;
    int negativo = -1;
    unsigned int positivo = 1;
    
    cout << "int negativo = " << negativo << endl;
    cout << "unsigned int positivo = " << positivo << endl;
    cout << "negativo < positivo: " << boolalpha << (negativo < positivo) << noboolalpha << endl;
    cout << "¿Por qué es falso? Porque -1 se convierte a " << (unsigned int)negativo << endl;
    
    cout << "\n🌊 PROBLEMA: COMPARACIÓN DE FLOTANTES:" << endl;
    double suma = 0.1 + 0.2;
    double esperado = 0.3;
    
    cout << fixed << setprecision(20);
    cout << "0.1 + 0.2 = " << suma << endl;
    cout << "0.3 =       " << esperado << endl;
    cout << "¿Son iguales? " << boolalpha << (suma == esperado) << noboolalpha << endl;
    
    // Comparación correcta con tolerancia
    double tolerancia = 1e-15;
    bool son_iguales = abs(suma - esperado) < tolerancia;
    cout << "Con tolerancia (" << tolerancia << "): " << boolalpha << son_iguales << noboolalpha << endl;
    
    cout << "\n🔤 COMPARACIÓN DE CARACTERES:" << endl;
    char letra1 = 'A', letra2 = 'Z', letra3 = 'a';
    
    cout << "Caracteres: '" << letra1 << "' (" << (int)letra1 << "), '"
         << letra2 << "' (" << (int)letra2 << "), '"
         << letra3 << "' (" << (int)letra3 << ")" << endl;
    
    cout << "'" << letra1 << "' < '" << letra2 << "': " << boolalpha << (letra1 < letra2) << noboolalpha << endl;
    cout << "'" << letra2 << "' < '" << letra3 << "': " << boolalpha << (letra2 < letra3) << noboolalpha << endl;
    cout << "Orden ASCII: A-Z (65-90) < a-z (97-122)" << endl;
    
    cout << "\n📝 COMPARACIÓN DE STRINGS:" << endl;
    string str1 = "abc", str2 = "abd", str3 = "b", str4 = "ABC";
    
    cout << "Strings: \"" << str1 << "\", \"" << str2 << "\", \"" << str3 << "\", \"" << str4 << "\"" << endl;
    cout << "\"" << str1 << "\" < \"" << str2 << "\": " << boolalpha << (str1 < str2) << noboolalpha << " (lexicográfico)" << endl;
    cout << "\"" << str2 << "\" < \"" << str3 << "\": " << boolalpha << (str2 < str3) << noboolalpha << " (longitud no importa)" << endl;
    cout << "\"" << str4 << "\" < \"" << str1 << "\": " << boolalpha << (str4 < str1) << noboolalpha << " (mayúsculas < minúsculas)" << endl;
    
    cout << "\n🎯 CASOS DE USO PRÁCTICOS:" << endl;
    
    // Validación de rangos
    int edad = 25;
    bool es_adulto = edad >= 18;
    bool es_senior = edad >= 65;
    cout << "Edad " << edad << ": adulto=" << boolalpha << es_adulto 
         << ", senior=" << es_senior << noboolalpha << endl;
    
    // Validación de calificaciones
    double calificacion = 85.5;
    char letra_calificacion;
    if (calificacion >= 90) letra_calificacion = 'A';
    else if (calificacion >= 80) letra_calificacion = 'B';
    else if (calificacion >= 70) letra_calificacion = 'C';
    else if (calificacion >= 60) letra_calificacion = 'D';
    else letra_calificacion = 'F';
    
    cout << "Calificación " << calificacion << " = " << letra_calificacion << endl;
    
    // Ordenamiento de tres números
    int num1 = 15, num2 = 8, num3 = 23;
    cout << "Números originales: " << num1 << ", " << num2 << ", " << num3 << endl;
    
    if (num1 > num2 && num1 > num3) {
        cout << "El mayor es: " << num1 << endl;
    } else if (num2 > num3) {
        cout << "El mayor es: " << num2 << endl;
    } else {
        cout << "El mayor es: " << num3 << endl;
    }
    
    cout << "\n💡 BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Usar paréntesis para clarificar: if ((a == b) && (c > d))" << endl;
    cout << "✅ Para flotantes, usar tolerancia en lugar de ==" << endl;
    cout << "✅ Cuidado con signed/unsigned en comparaciones" << endl;
    cout << "✅ Usar constantes nombradas: if (edad >= EDAD_ADULTO)" << endl;
    cout << "❌ Evitar if (variable == true), usar if (variable)" << endl;
    cout << "❌ No confundir = (asignación) con == (comparación)" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: OPERADORES LÓGICOS - ÁLGEBRA BOOLEANA Y OPTIMIZACIONES
================================================================================

🧠 FUNDAMENTOS DEL ÁLGEBRA BOOLEANA:

Los operadores lógicos implementan las operaciones fundamentales del álgebra 
booleana, desarrollada por George Boole en el siglo XIX.

1. 🔗 AND LÓGICO (&&):
   - Verdadero solo si AMBOS operandos son verdaderos
   - Implementa la conjunción lógica
   - Evaluación perezosa: si el primer operando es falso, no evalúa el segundo

2. 🔗 OR LÓGICO (||):
   - Verdadero si AL MENOS UNO de los operandos es verdadero
   - Implementa la disyunción lógica
   - Evaluación perezosa: si el primer operando es verdadero, no evalúa el segundo

3. 🚫 NOT LÓGICO (!):
   - Invierte el valor de verdad del operando
   - Implementa la negación lógica
   - Operador unario (solo un operando)

🚀 EVALUACIÓN PEREZOSA (SHORT-CIRCUIT EVALUATION):

Esta es una optimización crucial que:
1. Mejora el rendimiento (evita cálculos innecesarios)
2. Previene errores (evita accesos a memoria inválida)
3. Permite patrones de programación seguros

Ejemplos:
- if (ptr != nullptr && ptr->valor > 0) // Seguro
- if (divisor != 0 && numero / divisor > 1) // Seguro

📊 LEYES DEL ÁLGEBRA BOOLEANA:

1. LEYES DE IDENTIDAD:
   - A && true = A
   - A || false = A

2. LEYES DE DOMINACIÓN:
   - A && false = false
   - A || true = true

3. LEYES DE IDEMPOTENCIA:
   - A && A = A
   - A || A = A

4. LEYES DE COMPLEMENTO:
   - A && !A = false
   - A || !A = true

5. LEYES DE DE MORGAN:
   - !(A && B) = !A || !B
   - !(A || B) = !A && !B

6. LEYES DISTRIBUTIVAS:
   - A && (B || C) = (A && B) || (A && C)
   - A || (B && C) = (A || B) && (A || C)

🎯 DIFERENCIAS ENTRE LÓGICOS Y BITWISE:

LÓGICOS (&&, ||, !):
- Operan sobre valores de verdad (true/false)
- Evaluación perezosa
- Resultado siempre booleano
- Para control de flujo

BITWISE (&, |, ^, ~):
- Operan bit por bit
- Siempre evalúan ambos operandos
- Resultado puede ser cualquier número
- Para manipulación de bits

================================================================================
*/

void estudio_profundo_logicos() {
    cout << "\n=== ESTUDIO PROFUNDO: OPERADORES LÓGICOS ===" << endl;
    
    cout << "\n📊 TABLA DE VERDAD COMPLETA:" << endl;
    cout << "A     | B     | A&&B  | A||B  | !A    | !B" << endl;
    cout << "------|-------|-------|-------|-------|------" << endl;
    
    bool valores[] = {false, true};
    for (bool a : valores) {
        for (bool b : valores) {
            cout << boolalpha << setw(5) << a << " | " << setw(5) << b << " | "
                 << setw(5) << (a && b) << " | " << setw(5) << (a || b) << " | "
                 << setw(5) << (!a) << " | " << setw(5) << (!b) << noboolalpha << endl;
        }
    }
    
    cout << "\n⚡ DEMOSTRACIÓN DE EVALUACIÓN PEREZOSA:" << endl;
    
    // Contador para demostrar cuándo se ejecutan las funciones
    int contador = 0;
    
    auto funcion_a = [&contador]() -> bool {
        contador++;
        cout << "  [Ejecutando función A - llamada #" << contador << "]" << endl;
        return false;
    };
    
    auto funcion_b = [&contador]() -> bool {
        contador++;
        cout << "  [Ejecutando función B - llamada #" << contador << "]" << endl;
        return true;
    };
    
    cout << "\n1. Evaluando: funcion_a() && funcion_b()" << endl;
    contador = 0;
    bool resultado1 = funcion_a() && funcion_b();
    cout << "   Resultado: " << boolalpha << resultado1 << noboolalpha << endl;
    cout << "   Funciones ejecutadas: " << contador << " (solo A, porque A es false)" << endl;
    
    cout << "\n2. Evaluando: funcion_b() || funcion_a()" << endl;
    contador = 0;
    bool resultado2 = funcion_b() || funcion_a();
    cout << "   Resultado: " << boolalpha << resultado2 << noboolalpha << endl;
    cout << "   Funciones ejecutadas: " << contador << " (solo B, porque B es true)" << endl;
    
    cout << "\n3. Evaluando: funcion_a() || funcion_b()" << endl;
    contador = 0;
    bool resultado3 = funcion_a() || funcion_b();
    cout << "   Resultado: " << boolalpha << resultado3 << noboolalpha << endl;
    cout << "   Funciones ejecutadas: " << contador << " (ambas, porque A es false)" << endl;
    
    cout << "\n🛡️ PATRONES SEGUROS CON EVALUACIÓN PEREZOSA:" << endl;
    
    // Patrón 1: Verificación de puntero nulo
    int* ptr = nullptr;
    cout << "1. Verificación segura de puntero:" << endl;
    if (ptr != nullptr && *ptr > 0) {
        cout << "   Puntero válido y valor positivo" << endl;
    } else {
        cout << "   Puntero nulo o valor no positivo" << endl;
    }
    
    // Patrón 2: División segura
    int dividendo = 10, divisor = 0;
    cout << "\n2. División segura:" << endl;
    if (divisor != 0 && dividendo / divisor > 1) {
        cout << "   División válida y resultado > 1" << endl;
    } else {
        cout << "   División por cero o resultado <= 1" << endl;
    }
    
    // Patrón 3: Acceso seguro a array
    int array[] = {1, 2, 3, 4, 5};
    int indice = 10;
    int tamaño = sizeof(array) / sizeof(array[0]);
    
    cout << "\n3. Acceso seguro a array:" << endl;
    if (indice >= 0 && indice < tamaño && array[indice] > 0) {
        cout << "   Índice válido y valor positivo: " << array[indice] << endl;
    } else {
        cout << "   Índice inválido o valor no positivo" << endl;
    }
    
    cout << "\n🔍 COMPARACIÓN: LÓGICOS VS BITWISE:" << endl;
    
    int a = 3, b = 5;  // 3 = 011, 5 = 101 en binario
    cout << "Variables: a = " << a << " (" << bitset<8>(a) << "), "
         << "b = " << b << " (" << bitset<8>(b) << ")" << endl;
    
    cout << "\nOperadores lógicos (resultado booleano):" << endl;
    cout << "a && b = " << boolalpha << (bool)(a && b) << noboolalpha 
         << " (ambos son ≠ 0, resultado = " << (a && b) << ")" << endl;
    cout << "a || b = " << boolalpha << (bool)(a || b) << noboolalpha 
         << " (al menos uno ≠ 0, resultado = " << (a || b) << ")" << endl;
    
    cout << "\nOperadores bitwise (resultado numérico):" << endl;
    cout << "a & b = " << (a & b) << " (" << bitset<8>(a & b) << ") - AND bit a bit" << endl;
    cout << "a | b = " << (a | b) << " (" << bitset<8>(a | b) << ") - OR bit a bit" << endl;
    cout << "a ^ b = " << (a ^ b) << " (" << bitset<8>(a ^ b) << ") - XOR bit a bit" << endl;
    
    cout << "\n📚 LEYES DEL ÁLGEBRA BOOLEANA - VERIFICACIÓN:" << endl;
    
    bool p = true, q = false;
    cout << "Variables: p = " << boolalpha << p << ", q = " << q << noboolalpha << endl;
    
    // Ley de De Morgan
    bool ley1_izq = !(p && q);
    bool ley1_der = !p || !q;
    cout << "\nLey de De Morgan 1: !(p && q) = !p || !q" << endl;
    cout << "!(p && q) = " << boolalpha << ley1_izq << noboolalpha << endl;
    cout << "!p || !q = " << boolalpha << ley1_der << noboolalpha << endl;
    cout << "¿Son iguales? " << boolalpha << (ley1_izq == ley1_der) << noboolalpha << endl;
    
    bool ley2_izq = !(p || q);
    bool ley2_der = !p && !q;
    cout << "\nLey de De Morgan 2: !(p || q) = !p && !q" << endl;
    cout << "!(p || q) = " << boolalpha << ley2_izq << noboolalpha << endl;
    cout << "!p && !q = " << boolalpha << ley2_der << noboolalpha << endl;
    cout << "¿Son iguales? " << boolalpha << (ley2_izq == ley2_der) << noboolalpha << endl;
    
    cout << "\n🎯 CASOS DE USO COMPLEJOS:" << endl;
    
    // Sistema de autenticación
    bool usuario_valido = true;
    bool contraseña_correcta = true;
    bool cuenta_activa = true;
    bool intentos_excedidos = false;
    
    bool puede_acceder = usuario_valido && contraseña_correcta && cuenta_activa && !intentos_excedidos;
    
    cout << "Sistema de autenticación:" << endl;
    cout << "- Usuario válido: " << boolalpha << usuario_valido << noboolalpha << endl;
    cout << "- Contraseña correcta: " << boolalpha << contraseña_correcta << noboolalpha << endl;
    cout << "- Cuenta activa: " << boolalpha << cuenta_activa << noboolalpha << endl;
    cout << "- Intentos excedidos: " << boolalpha << intentos_excedidos << noboolalpha << endl;
    cout << "¿Puede acceder? " << boolalpha << puede_acceder << noboolalpha << endl;
    
    // Validación de formulario
    string email = "usuario@ejemplo.com";
    string password = "123456";
    int edad = 25;
    bool acepta_terminos = true;
    
    bool email_valido = !email.empty() && email.find('@') != string::npos;
    bool password_valido = password.length() >= 6;
    bool edad_valida = edad >= 18 && edad <= 120;
    
    bool formulario_valido = email_valido && password_valido && edad_valida && acepta_terminos;
    
    cout << "\nValidación de formulario:" << endl;
    cout << "- Email válido: " << boolalpha << email_valido << noboolalpha << endl;
    cout << "- Password válido: " << boolalpha << password_valido << noboolalpha << endl;
    cout << "- Edad válida: " << boolalpha << edad_valida << noboolalpha << endl;
    cout << "- Acepta términos: " << boolalpha << acepta_terminos << noboolalpha << endl;
    cout << "¿Formulario válido? " << boolalpha << formulario_valido << noboolalpha << endl;
    
    cout << "\n💡 OPTIMIZACIONES Y BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Aprovechar la evaluación perezosa para eficiencia" << endl;
    cout << "✅ Colocar condiciones más probables primero en ||" << endl;
    cout << "✅ Colocar condiciones menos probables primero en &&" << endl;
    cout << "✅ Usar paréntesis para clarificar precedencia" << endl;
    cout << "✅ Evitar !(!condicion), usar directamente condicion" << endl;
    cout << "❌ No confundir && con & (lógico vs bitwise)" << endl;
    cout << "❌ No asumir que ambos operandos siempre se evalúan" << endl;
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL MEJORADA - SISTEMA DE APRENDIZAJE COMPLETO
================================================================================
*/

int main() {
    cout << "📚 TEORÍA AVANZADA: OPERADORES EN C++ - ESTUDIO PROFUNDO" << endl;
    cout << "=========================================================" << endl;
    cout << "🎓 Sistema de Aprendizaje Completo e Interactivo" << endl;
    cout << "🔧 Desde fundamentos hasta optimizaciones avanzadas" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ DE ESTUDIOS PROFUNDOS DE OPERADORES ---" << endl;
        cout << "1. 🧮 Operadores aritméticos - Matemáticas y hardware" << endl;
        cout << "2. 🔍 Operadores relacionales - Comparaciones y lógica" << endl;
        cout << "3. ⚡ Operadores lógicos - Álgebra booleana" << endl;
        cout << "4. 🔧 Operadores bitwise - Manipulación de bits" << endl;
        cout << "5. 📝 Operadores de asignación - Eficiencia y patrones" << endl;
        cout << "6. 🎯 Operador ternario - Expresiones condicionales" << endl;
        cout << "7. 📊 Precedencia y asociatividad - Orden de evaluación" << endl;
        cout << "8. 🚀 Optimizaciones del compilador" << endl;
        cout << "9. 🧪 Laboratorio de experimentación" << endl;
        cout << "10. 📋 Resumen completo y tablas de referencia" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                estudio_profundo_aritmeticos();
                break;
            case 2:
                estudio_profundo_relacionales();
                break;
            case 3:
                estudio_profundo_logicos();
                break;
            case 4:
                // TODO: Implementar estudio profundo de operadores bitwise
                cout << "\n🚧 Estudio profundo de operadores bitwise - En desarrollo" << endl;
                break;
            case 5:
                // TODO: Implementar estudio profundo de operadores de asignación
                cout << "\n🚧 Estudio profundo de operadores de asignación - En desarrollo" << endl;
                break;
            case 6:
                // TODO: Implementar estudio profundo del operador ternario
                cout << "\n🚧 Estudio profundo del operador ternario - En desarrollo" << endl;
                break;
            case 7:
                // TODO: Implementar estudio profundo de precedencia
                cout << "\n🚧 Estudio profundo de precedencia - En desarrollo" << endl;
                break;
            case 8:
                // TODO: Implementar estudio de optimizaciones
                cout << "\n🚧 Estudio de optimizaciones del compilador - En desarrollo" << endl;
                break;
            case 9:
                // TODO: Implementar laboratorio de experimentación
                cout << "\n🚧 Laboratorio de experimentación - En desarrollo" << endl;
                break;
            case 10:
                // TODO: Implementar resumen completo
                cout << "\n🚧 Resumen completo - En desarrollo" << endl;
                break;
            case 0:
                cout << "\n🎉 ¡Excelente! Has completado el estudio profundo de operadores." << endl;
                cout << "🧠 Ahora tienes un conocimiento sólido de cómo funcionan internamente." << endl;
                cout << "🚀 Continúa con estructuras de control para dominar el flujo de programas." << endl;
                break;
            default:
                cout << "❌ Opción inválida. Seleccione entre 0 y 10." << endl;
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
📝 PLANTILLA AVANZADA PARA EXPERIMENTACIÓN CON OPERADORES
================================================================================

#include <iostream>
#include <bitset>
#include <chrono>
#include <climits>
using namespace std;

int main() {
    cout << "=== LABORATORIO DE EXPERIMENTACIÓN CON OPERADORES ===" << endl;
    
    // 🎯 EXPERIMENTO 1: Rendimiento de operadores
    cout << "\n1. MIDIENDO RENDIMIENTO DE OPERADORES:" << endl;
    // TODO: Medir tiempo de suma vs multiplicación vs división
    // TODO: Comparar operadores lógicos vs bitwise
    // TODO: Analizar impacto de la evaluación perezosa
    
    // 🎯 EXPERIMENTO 2: Límites y desbordamientos
    cout << "\n2. EXPLORANDO LÍMITES Y DESBORDAMIENTOS:" << endl;
    // TODO: Probar desbordamientos en diferentes tipos
    // TODO: Analizar comportamiento de división por cero
    // TODO: Experimentar con números muy grandes
    
    // 🎯 EXPERIMENTO 3: Precisión de flotantes
    cout << "\n3. ANALIZANDO PRECISIÓN DE FLOTANTES:" << endl;
    // TODO: Crear casos donde float vs double importa
    // TODO: Demostrar errores de redondeo acumulativos
    // TODO: Probar comparaciones problemáticas
    
    // 🎯 EXPERIMENTO 4: Optimizaciones del compilador
    cout << "\n4. OBSERVANDO OPTIMIZACIONES:" << endl;
    // TODO: Crear código que el compilador puede optimizar
    // TODO: Comparar versiones optimizadas vs no optimizadas
    // TODO: Analizar código ensamblador generado
    
    // 🎯 EXPERIMENTO 5: Patrones avanzados
    cout << "\n5. IMPLEMENTANDO PATRONES AVANZADOS:" << endl;
    // TODO: Crear calculadora con todos los operadores
    // TODO: Implementar sistema de flags con bitwise
    // TODO: Desarrollar validador complejo con lógicos
    
    return 0;
}

================================================================================
🎯 EJERCICIOS DE INVESTIGACIÓN AVANZADA - OPERADORES
================================================================================

1. 🔬 ANÁLISIS DE RENDIMIENTO:
   - Mide el tiempo de 1 millón de operaciones de cada tipo
   - Compara diferentes tipos de datos (int vs double)
   - Analiza el impacto de las optimizaciones del compilador

2. 🧮 IMPLEMENTACIÓN DE ALGORITMOS:
   - Implementa algoritmos de ordenamiento usando solo operadores básicos
   - Crea funciones matemáticas (potencia, raíz) sin usar bibliotecas
   - Desarrolla algoritmos de cifrado simples con operadores bitwise

3. 🎯 CASOS LÍMITE:
   - Encuentra todos los casos donde los operadores fallan
   - Documenta comportamientos indefinidos
   - Crea funciones "seguras" que manejen casos límite

4. 🔍 ANÁLISIS DE CÓDIGO ENSAMBLADOR:
   - Compila código con diferentes niveles de optimización
   - Analiza cómo se traducen los operadores a instrucciones de máquina
   - Compara eficiencia de diferentes enfoques

5. 🚀 OPTIMIZACIONES MANUALES:
   - Reescribe código para ser más eficiente
   - Usa trucos de bits para operaciones rápidas
   - Implementa versiones optimizadas de operaciones comunes

================================================================================
*/