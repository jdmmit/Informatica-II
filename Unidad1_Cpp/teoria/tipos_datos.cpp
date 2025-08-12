/*
================================================================================
📚 TEORÍA AVANZADA: TIPOS DE DATOS Y VARIABLES EN C++ - ESTUDIO PROFUNDO
================================================================================
Archivo: tipos_datos.cpp
Propósito: Dominio completo y profundo de los tipos de datos fundamentales
Material de referencia: inforII-u1-declaracion-de-variables-y-tipos-de-datos-fundamentales-en-c.pdf
Tiempo de estudio: 6-8 horas (estudio profundo)
Nivel: Desde principiante hasta intermedio-avanzado
================================================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>      // Límites de tipos enteros
#include <cfloat>       // Límites de tipos flotantes
#include <typeinfo>     // Para obtener información de tipos
#include <cmath>        // Funciones matemáticas
#include <bitset>       // Para mostrar representación binaria
#include <sstream>      // Para conversiones avanzadas
using namespace std;

/*
================================================================================
📖 FUNDAMENTOS TEÓRICOS PROFUNDOS: ¿QUÉ SON REALMENTE LAS VARIABLES?
================================================================================

🧠 CONCEPTO FUNDAMENTAL A NIVEL DE MEMORIA:
Una variable es una abstracción que representa una ubicación específica en la 
memoria RAM del computador. Cada variable tiene:

1. 📍 DIRECCIÓN DE MEMORIA: Ubicación física en RAM (ej: 0x7fff5fbff6ac)
2. 🏷️ NOMBRE SIMBÓLICO: Identificador que usamos en el código (ej: edad)
3. 📦 TAMAÑO: Cantidad de bytes que ocupa (ej: int = 4 bytes)
4. 🔢 VALOR: Datos almacenados en esa ubicación
5. 🏗️ TIPO: Interpretación de los bits almacenados

🔍 ANALOGÍA DETALLADA - LA CIUDAD DE LA MEMORIA:
Imagina la memoria RAM como una ciudad con millones de casas numeradas:
- Cada CASA es un byte de memoria (dirección única)
- El NÚMERO DE CASA es la dirección de memoria
- El NOMBRE EN EL BUZÓN es el nombre de la variable
- El CONTENIDO de la casa es el valor almacenado
- El TIPO DE CASA determina cómo interpretar el contenido

📊 REPRESENTACIÓN BINARIA:
Todo en el computador se almacena como secuencias de 0s y 1s (bits).
El TIPO DE DATO determina cómo interpretar estos bits:
- 01000001 como char = 'A' (ASCII)
- 01000001 como unsigned char = 65 (número)
- 01000001 como bool = true (cualquier valor ≠ 0)

🎯 ¿POR QUÉ EXISTEN DIFERENTES TIPOS?

1. 💾 EFICIENCIA DE MEMORIA:
   - char (1 byte) vs int (4 bytes) vs long long (8 bytes)
   - Usar el tipo mínimo necesario ahorra memoria

2. 🎯 PRECISIÓN Y RANGO:
   - float (7 dígitos) vs double (15 dígitos)
   - int (-2B a +2B) vs long long (-9 trillones a +9 trillones)

3. ⚡ VELOCIDAD DE PROCESAMIENTO:
   - Operaciones con int son más rápidas que con double
   - El procesador tiene instrucciones específicas para cada tipo

4. 🛡️ SEGURIDAD DE TIPOS:
   - Previene errores: no puedes sumar un número con un texto
   - El compilador verifica compatibilidad de tipos

5. 📝 EXPRESIVIDAD DEL CÓDIGO:
   - bool hace el código más legible que int para verdadero/falso
   - string es más claro que array de char para texto

================================================================================
*/

/*
================================================================================
📖 ESTUDIO PROFUNDO: TIPOS ENTEROS - ARQUITECTURA Y REPRESENTACIÓN
================================================================================

🏗️ ARQUITECTURA DE COMPUTADORES Y TIPOS ENTEROS:

Los tipos enteros están íntimamente relacionados con la arquitectura del procesador:
- Los procesadores modernos son de 64 bits
- Pueden procesar 64 bits (8 bytes) en una sola operación
- Los tipos más pequeños requieren conversiones internas

🔢 ANÁLISIS DETALLADO POR TIPO:

1. 📏 char (1 byte = 8 bits):
   ┌─┬─┬─┬─┬─┬─┬─┬─┐
   │7│6│5│4│3│2│1│0│ ← Posiciones de bits
   └─┴─┴─┴─┴─┴─┴─┴─┘
   
   - Bit 7: Bit de signo (0=positivo, 1=negativo)
   - Bits 0-6: Valor absoluto
   - Rango signed: -128 a +127
   - Rango unsigned: 0 a 255
   
   🎯 USOS ESPECÍFICOS:
   - Almacenar caracteres ASCII (0-127)
   - Flags booleanos múltiples (usando bits individuales)
   - Pequeños contadores o índices
   - Códigos de error o estado

2. 📏 short (2 bytes = 16 bits):
   ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐
   │F│E│D│C│B│A│9│8│7│6│5│4│3│2│1│0│ ← Posiciones hexadecimales
   └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘
   
   - Rango signed: -32,768 a +32,767
   - Rango unsigned: 0 a 65,535
   
   🎯 USOS ESPECÍFICOS:
   - Coordenadas en gráficos 2D
   - Años (1900-2100 caben perfectamente)
   - Temperaturas en Celsius (-50 a +50)
   - Puertos de red (0-65535)

3. 📏 int (4 bytes = 32 bits): ⭐ EL MÁS IMPORTANTE
   ┌────────────────┬────────────────┐
   │  16 bits altos │  16 bits bajos │
   └────────────────┴────────────────┘
   
   - Rango signed: -2,147,483,648 a +2,147,483,647
   - Rango unsigned: 0 a 4,294,967,295
   
   🎯 USOS ESPECÍFICOS:
   - Contadores generales
   - Índices de arrays
   - Identificadores únicos
   - Cálculos matemáticos enteros
   - Tamaños de colecciones

4. 📏 long (4 u 8 bytes, dependiente del sistema):
   - En sistemas de 32 bits: igual que int
   - En sistemas de 64 bits: igual que long long
   
   🎯 CONSIDERACIÓN IMPORTANTE:
   - Evita usar long por su ambigüedad
   - Prefiere int o long long según necesidades

5. 📏 long long (8 bytes = 64 bits):
   ┌────────────────────────────────┬────────────────────────────────┐
   │         32 bits altos          │         32 bits bajos          │
   └────────────────────────────────┴────────────────────────────────┘
   
   - Rango signed: -9,223,372,036,854,775,808 a +9,223,372,036,854,775,807
   - Rango unsigned: 0 a 18,446,744,073,709,551,615
   
   🎯 USOS ESPECÍFICOS:
   - Timestamps (milisegundos desde 1970)
   - Identificadores únicos globales
   - Cálculos financieros de alta precisión
   - Contadores de eventos masivos
   - Distancias astronómicas en metros

🔍 REPRESENTACIÓN EN COMPLEMENTO A DOS:
Los números negativos se representan usando "complemento a dos":
1. Invertir todos los bits del número positivo
2. Sumar 1 al resultado

Ejemplo para -5 en 8 bits:
5 = 00000101
Invertir: 11111010
Sumar 1: 11111011 = -5

🎯 VENTAJAS DEL COMPLEMENTO A DOS:
- Suma y resta usan las mismas operaciones
- Solo hay una representación para el cero
- Rango simétrico (casi) para positivos y negativos

⚠️ PROBLEMAS COMUNES CON ENTEROS:

1. 🌊 DESBORDAMIENTO (OVERFLOW):
   int max_int = 2147483647;
   int overflow = max_int + 1; // Resultado: -2147483648 (¡negativo!)

2. 🔄 DESBORDAMIENTO CIRCULAR:
   unsigned char c = 255;
   c++; // Resultado: 0 (vuelve al inicio)

3. 🔀 MEZCLAR SIGNED Y UNSIGNED:
   int negativo = -1;
   unsigned int positivo = 1;
   if (negativo < positivo) // ¡FALSO! -1 se convierte a un número muy grande

================================================================================
*/

void estudio_profundo_enteros() {
    cout << "=== ESTUDIO PROFUNDO: TIPOS ENTEROS ===" << endl;
    
    cout << "\n🏗️ ARQUITECTURA Y TAMAÑOS EN ESTE SISTEMA:" << endl;
    cout << "Tamaño de char: " << sizeof(char) << " byte(s)" << endl;
    cout << "Tamaño de short: " << sizeof(short) << " byte(s)" << endl;
    cout << "Tamaño de int: " << sizeof(int) << " byte(s)" << endl;
    cout << "Tamaño de long: " << sizeof(long) << " byte(s)" << endl;
    cout << "Tamaño de long long: " << sizeof(long long) << " byte(s)" << endl;
    cout << "Tamaño de puntero: " << sizeof(void*) << " byte(s)" << endl;
    
    cout << "\n📊 RANGOS EXACTOS EN ESTE SISTEMA:" << endl;
    cout << "char: " << (int)CHAR_MIN << " a " << (int)CHAR_MAX << endl;
    cout << "unsigned char: 0 a " << (int)UCHAR_MAX << endl;
    cout << "short: " << SHRT_MIN << " a " << SHRT_MAX << endl;
    cout << "unsigned short: 0 a " << USHRT_MAX << endl;
    cout << "int: " << INT_MIN << " a " << INT_MAX << endl;
    cout << "unsigned int: 0 a " << UINT_MAX << endl;
    cout << "long: " << LONG_MIN << " a " << LONG_MAX << endl;
    cout << "unsigned long: 0 a " << ULONG_MAX << endl;
    cout << "long long: " << LLONG_MIN << " a " << LLONG_MAX << endl;
    cout << "unsigned long long: 0 a " << ULLONG_MAX << endl;
    
    cout << "\n🔍 REPRESENTACIÓN BINARIA DE NÚMEROS:" << endl;
    char c = 65;  // 'A' en ASCII
    short s = 1000;
    int i = -42;
    
    cout << "char 65 ('A'): " << bitset<8>(c) << endl;
    cout << "short 1000: " << bitset<16>(s) << endl;
    cout << "int -42: " << bitset<32>(i) << endl;
    
    cout << "\n⚠️ DEMOSTRACIÓN DE DESBORDAMIENTO:" << endl;
    
    // Desbordamiento en char
    char max_char = CHAR_MAX;
    cout << "char máximo: " << (int)max_char << endl;
    max_char++;
    cout << "char máximo + 1: " << (int)max_char << " (¡desbordamiento!)" << endl;
    
    // Desbordamiento en unsigned
    unsigned char max_uchar = UCHAR_MAX;
    cout << "unsigned char máximo: " << (int)max_uchar << endl;
    max_uchar++;
    cout << "unsigned char máximo + 1: " << (int)max_uchar << " (vuelve a 0)" << endl;
    
    cout << "\n🎯 CASOS DE USO ESPECÍFICOS POR TIPO:" << endl;
    
    // char para códigos ASCII
    cout << "\n📝 char para caracteres y códigos:" << endl;
    for (char letra = 'A'; letra <= 'E'; letra++) {
        cout << "'" << letra << "' = " << (int)letra << " (ASCII)" << endl;
    }
    
    // short para coordenadas
    cout << "\n📍 short para coordenadas de pantalla:" << endl;
    short x = 1920, y = 1080;  // Resolución Full HD
    cout << "Resolución: " << x << " x " << y << " píxeles" << endl;
    
    // int para contadores
    cout << "\n🔢 int para contadores y cálculos:" << endl;
    int estudiantes = 150;
    int promedio_edad = 22;
    int total_edad = estudiantes * promedio_edad;
    cout << estudiantes << " estudiantes × " << promedio_edad << " años = " << total_edad << " años totales" << endl;
    
    // long long para timestamps
    cout << "\n⏰ long long para timestamps:" << endl;
    long long timestamp_actual = 1640995200000LL;  // 1 enero 2022 en milisegundos
    long long milisegundos_por_dia = 24LL * 60 * 60 * 1000;
    long long dias_desde_epoca = timestamp_actual / milisegundos_por_dia;
    cout << "Timestamp: " << timestamp_actual << " ms" << endl;
    cout << "Días desde época Unix: " << dias_desde_epoca << endl;
    
    cout << "\n💡 OPTIMIZACIONES DEL COMPILADOR:" << endl;
    cout << "- El compilador puede optimizar operaciones con tipos nativos" << endl;
    cout << "- int suele ser el tipo más eficiente en la arquitectura actual" << endl;
    cout << "- Usar tipos más pequeños no siempre ahorra tiempo de ejecución" << endl;
    cout << "- Los registros del procesador son de 64 bits en sistemas modernos" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: NÚMEROS DE PUNTO FLOTANTE - IEEE 754 Y PRECISIÓN
================================================================================

🔬 REPRESENTACIÓN IEEE 754:

Los números de punto flotante siguen el estándar IEEE 754, que divide los bits en:
1. 🏷️ SIGNO (S): 1 bit - determina si es positivo (0) o negativo (1)
2. 🔢 EXPONENTE (E): varios bits - determina la magnitud del número
3. 📊 MANTISA/FRACCIÓN (M): resto de bits - determina la precisión

📏 FORMATO FLOAT (32 bits):
┌─┬─────────┬───────────────────────┐
│S│    E    │           M           │
│1│  8 bits │       23 bits         │
└─┴─────────┴───────────────────────┘

📏 FORMATO DOUBLE (64 bits):
┌─┬───────────┬─────────────────────────────────────────────────────┐
│S│     E     │                        M                            │
│1│  11 bits  │                    52 bits                          │
└─┴───────────┴─────────────────────────────────────────────────────┘

🧮 CÁLCULO DEL VALOR:
valor = (-1)^S × (1 + M/2^23) × 2^(E-127)  [para float]
valor = (-1)^S × (1 + M/2^52) × 2^(E-1023) [para double]

🎯 NÚMEROS ESPECIALES EN IEEE 754:

1. 🔢 CERO: Exponente = 0, Mantisa = 0
   - +0.0 y -0.0 son diferentes pero se comparan como iguales

2. ♾️ INFINITO: Exponente = máximo, Mantisa = 0
   - +∞ y -∞ representan desbordamiento

3. 🚫 NaN (Not a Number): Exponente = máximo, Mantisa ≠ 0
   - Resultado de operaciones inválidas (0/0, √(-1))

4. 🔬 NÚMEROS DENORMALIZADOS: Exponente = 0, Mantisa ≠ 0
   - Números muy pequeños cerca de cero

⚠️ LIMITACIONES FUNDAMENTALES:

1. 🎯 PRECISIÓN LIMITADA:
   - float: ~7 dígitos decimales significativos
   - double: ~15-17 dígitos decimales significativos
   
2. 🔄 ERRORES DE REDONDEO:
   - No todos los decimales se pueden representar exactamente
   - 0.1 + 0.2 ≠ 0.3 en aritmética de punto flotante

3. 📊 DISTRIBUCIÓN NO UNIFORME:
   - Más precisión cerca del cero
   - Menos precisión en números grandes

4. ⚡ VELOCIDAD VS PRECISIÓN:
   - float es más rápido pero menos preciso
   - double es más lento pero más preciso

🔍 CASOS PROBLEMÁTICOS COMUNES:

1. 💰 DINERO Y FINANZAS:
   ❌ float precio = 0.1f + 0.2f; // No es exactamente 0.3
   ✅ Usar enteros para centavos: int centavos = 10 + 20; // 30 centavos

2. 🔄 BUCLES CON INCREMENTOS DECIMALES:
   ❌ for (float x = 0.0f; x != 1.0f; x += 0.1f) // Puede ser infinito
   ✅ for (int i = 0; i < 10; i++) { float x = i * 0.1f; }

3. 🎯 COMPARACIONES EXACTAS:
   ❌ if (resultado == 0.3)
   ✅ if (abs(resultado - 0.3) < 1e-9)

================================================================================
*/

void estudio_profundo_flotantes() {
    cout << "\n=== ESTUDIO PROFUNDO: NÚMEROS DE PUNTO FLOTANTE ===" << endl;
    
    cout << "\n🏗️ CARACTERÍSTICAS IEEE 754 EN ESTE SISTEMA:" << endl;
    cout << "float - Tamaño: " << sizeof(float) << " bytes, Precisión: " << FLT_DIG << " dígitos" << endl;
    cout << "double - Tamaño: " << sizeof(double) << " bytes, Precisión: " << DBL_DIG << " dígitos" << endl;
    cout << "long double - Tamaño: " << sizeof(long double) << " bytes, Precisión: " << LDBL_DIG << " dígitos" << endl;
    
    cout << "\n📊 RANGOS Y LÍMITES:" << endl;
    cout << fixed << scientific;
    cout << "float mínimo: " << FLT_MIN << endl;
    cout << "float máximo: " << FLT_MAX << endl;
    cout << "double mínimo: " << DBL_MIN << endl;
    cout << "double máximo: " << DBL_MAX << endl;
    cout << "Épsilon float: " << FLT_EPSILON << endl;
    cout << "Épsilon double: " << DBL_EPSILON << endl;
    
    cout << "\n🔬 DEMOSTRACIÓN DE PRECISIÓN:" << endl;
    cout << fixed << setprecision(20);
    
    float f1 = 0.1f, f2 = 0.2f, f3 = 0.3f;
    double d1 = 0.1, d2 = 0.2, d3 = 0.3;
    
    cout << "FLOAT:" << endl;
    cout << "0.1f = " << f1 << endl;
    cout << "0.2f = " << f2 << endl;
    cout << "0.1f + 0.2f = " << (f1 + f2) << endl;
    cout << "0.3f = " << f3 << endl;
    cout << "¿Son iguales? " << ((f1 + f2) == f3 ? "SÍ" : "NO") << endl;
    
    cout << "\nDOUBLE:" << endl;
    cout << "0.1 = " << d1 << endl;
    cout << "0.2 = " << d2 << endl;
    cout << "0.1 + 0.2 = " << (d1 + d2) << endl;
    cout << "0.3 = " << d3 << endl;
    cout << "¿Son iguales? " << ((d1 + d2) == d3 ? "SÍ" : "NO") << endl;
    
    cout << "\n🎯 COMPARACIÓN CORRECTA CON TOLERANCIA:" << endl;
    double diferencia = abs((d1 + d2) - d3);
    double tolerancia = 1e-15;
    cout << "Diferencia: " << diferencia << endl;
    cout << "Tolerancia: " << tolerancia << endl;
    cout << "¿Son iguales con tolerancia? " << (diferencia < tolerancia ? "SÍ" : "NO") << endl;
    
    cout << "\n♾️ VALORES ESPECIALES:" << endl;
    cout << defaultfloat;
    
    double positivo_infinito = 1.0 / 0.0;
    double negativo_infinito = -1.0 / 0.0;
    double no_numero = 0.0 / 0.0;
    double cero_positivo = 0.0;
    double cero_negativo = -0.0;
    
    cout << "Infinito positivo: " << positivo_infinito << endl;
    cout << "Infinito negativo: " << negativo_infinito << endl;
    cout << "NaN: " << no_numero << endl;
    cout << "Cero positivo: " << cero_positivo << endl;
    cout << "Cero negativo: " << cero_negativo << endl;
    cout << "¿+0.0 == -0.0? " << (cero_positivo == cero_negativo ? "SÍ" : "NO") << endl;
    
    cout << "\n🔍 ANÁLISIS DE BITS (float):" << endl;
    float numero = 3.14159f;
    uint32_t bits = *(uint32_t*)&numero;  // Reinterpretar bits
    
    cout << "Número: " << numero << endl;
    cout << "Bits: " << bitset<32>(bits) << endl;
    cout << "Signo: " << ((bits >> 31) & 1) << endl;
    cout << "Exponente: " << ((bits >> 23) & 0xFF) << " (sesgado: " << (((bits >> 23) & 0xFF) - 127) << ")" << endl;
    cout << "Mantisa: " << (bits & 0x7FFFFF) << endl;
    
    cout << "\n📈 DISTRIBUCIÓN DE PRECISIÓN:" << endl;
    cout << "Entre 1.0 y 2.0 hay " << (1 << 23) << " números float representables" << endl;
    cout << "Entre 1000.0 y 2000.0 hay " << (1 << 13) << " números float representables" << endl;
    cout << "¡La precisión disminuye con números más grandes!" << endl;
    
    cout << "\n💰 PROBLEMA CON DINERO:" << endl;
    float precio1 = 0.10f;
    float precio2 = 0.20f;
    float total_float = precio1 + precio2;
    
    int centavos1 = 10;  // 10 centavos
    int centavos2 = 20;  // 20 centavos
    int total_centavos = centavos1 + centavos2;
    
    cout << fixed << setprecision(10);
    cout << "Suma con float: $" << total_float << endl;
    cout << "Suma con centavos: " << total_centavos << " centavos = $" << (total_centavos / 100.0) << endl;
    
    cout << "\n🎯 CASOS DE USO APROPIADOS:" << endl;
    cout << "FLOAT:" << endl;
    cout << "- Gráficos 3D (coordenadas, colores)" << endl;
    cout << "- Juegos (posiciones, velocidades)" << endl;
    cout << "- Sensores (temperatura, presión)" << endl;
    cout << "- Audio (muestras de sonido)" << endl;
    
    cout << "\nDOUBLE:" << endl;
    cout << "- Cálculos científicos" << endl;
    cout << "- Estadísticas y análisis de datos" << endl;
    cout << "- Simulaciones físicas" << endl;
    cout << "- Matemáticas de alta precisión" << endl;
    
    cout << "\nLONG DOUBLE:" << endl;
    cout << "- Astronomía (distancias cósmicas)" << endl;
    cout << "- Criptografía (números muy grandes)" << endl;
    cout << "- Física de partículas" << endl;
    cout << "- Cálculos financieros críticos" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: CARACTERES, ASCII Y UNICODE
================================================================================

🔤 EVOLUCIÓN DE LA CODIFICACIÓN DE CARACTERES:

1. 📜 ASCII (American Standard Code for Information Interchange):
   - Desarrollado en 1963
   - 7 bits = 128 caracteres posibles
   - Cubre alfabeto inglés, dígitos y símbolos básicos
   - Valores 0-31: Caracteres de control
   - Valores 32-126: Caracteres imprimibles
   - Valor 127: DEL (delete)

2. 🌍 EXTENDED ASCII:
   - 8 bits = 256 caracteres
   - Valores 128-255: Caracteres extendidos (acentos, símbolos)
   - Diferentes "páginas de código" para diferentes idiomas
   - Problema: Incompatibilidad entre sistemas

3. 🌐 UNICODE:
   - Estándar universal para todos los idiomas
   - UTF-8, UTF-16, UTF-32 como codificaciones
   - Más de 1 millón de caracteres posibles
   - Incluye emojis, símbolos matemáticos, idiomas antiguos

📋 TABLA ASCII COMPLETA (CARACTERES IMPORTANTES):

CARACTERES DE CONTROL (0-31):
0   NUL (Null)           8   BS  (Backspace)      16  DLE (Data Link Escape)
1   SOH (Start of Head)  9   TAB (Horizontal Tab) 17  DC1 (Device Control 1)
2   STX (Start of Text)  10  LF  (Line Feed)      18  DC2 (Device Control 2)
3   ETX (End of Text)    11  VT  (Vertical Tab)   19  DC3 (Device Control 3)
4   EOT (End of Trans)   12  FF  (Form Feed)      20  DC4 (Device Control 4)
5   ENQ (Enquiry)        13  CR  (Carriage Ret)   21  NAK (Negative Ack)
6   ACK (Acknowledge)    14  SO  (Shift Out)      22  SYN (Synchronous Idle)
7   BEL (Bell)           15  SI  (Shift In)       23  ETB (End Trans Block)

CARACTERES IMPRIMIBLES (32-126):
32  ' ' (Espacio)       48-57  '0'-'9' (Dígitos)    65-90   'A'-'Z' (Mayúsculas)
33  '!' (Exclamación)   58     ':' (Dos puntos)     91-96   Símbolos
34  '"' (Comillas)      59     ';' (Punto y coma)   97-122  'a'-'z' (Minúsculas)
35  '#' (Numeral)       60     '<' (Menor que)      123-126 Símbolos
...

🔍 OPERACIONES AVANZADAS CON CARACTERES:

1. 🔄 CONVERSIONES MAYÚSCULA/MINÚSCULA:
   - Diferencia constante: 'a' - 'A' = 32
   - Mayúscula a minúscula: char + 32
   - Minúscula a mayúscula: char - 32
   - Solo funciona para letras inglesas

2. 🔢 VALIDACIONES:
   - ¿Es dígito? char >= '0' && char <= '9'
   - ¿Es letra? (char >= 'A' && char <= 'Z') || (char >= 'a' && char <= 'z')
   - ¿Es mayúscula? char >= 'A' && char <= 'Z'

3. 🧮 ARITMÉTICA DE CARACTERES:
   - Convertir dígito a número: '5' - '0' = 5
   - Convertir número a dígito: 5 + '0' = '5'
   - Siguiente letra: 'A' + 1 = 'B'

⚠️ PROBLEMAS CON CARACTERES:

1. 🌍 INTERNACIONALIZACIÓN:
   - ASCII solo cubre inglés
   - Caracteres acentuados requieren codificaciones extendidas
   - Diferentes sistemas usan diferentes páginas de código

2. 🔒 SEGURIDAD:
   - Inyección de caracteres de control
   - Desbordamiento de buffer con strings
   - Validación insuficiente de entrada

3. 🔄 CONVERSIONES ERRÓNEAS:
   - Asumir que char es siempre ASCII
   - No validar rangos antes de convertir
   - Mezclar signed y unsigned char

================================================================================
*/

void estudio_profundo_caracteres() {
    cout << "\n=== ESTUDIO PROFUNDO: CARACTERES Y CODIFICACIÓN ===" << endl;
    
    cout << "\n📊 INFORMACIÓN DEL TIPO CHAR EN ESTE SISTEMA:" << endl;
    cout << "Tamaño de char: " << sizeof(char) << " byte" << endl;
    cout << "¿char es signed? " << (CHAR_MIN < 0 ? "SÍ" : "NO") << endl;
    cout << "Rango de char: " << (int)CHAR_MIN << " a " << (int)CHAR_MAX << endl;
    cout << "Rango de unsigned char: 0 a " << (int)UCHAR_MAX << endl;
    
    cout << "\n📋 TABLA ASCII - CARACTERES DE CONTROL:" << endl;
    cout << "Código | Nombre    | Símbolo | Descripción" << endl;
    cout << "-------|-----------|---------|------------------" << endl;
    cout << "   0   | NUL       | \\0      | Fin de cadena" << endl;
    cout << "   7   | BEL       | \\a      | Campana/Beep" << endl;
    cout << "   8   | BS        | \\b      | Retroceso" << endl;
    cout << "   9   | TAB       | \\t      | Tabulación" << endl;
    cout << "  10   | LF        | \\n      | Nueva línea" << endl;
    cout << "  11   | VT        | \\v      | Tab vertical" << endl;
    cout << "  12   | FF        | \\f      | Nueva página" << endl;
    cout << "  13   | CR        | \\r      | Retorno de carro" << endl;
    
    cout << "\n📋 TABLA ASCII - CARACTERES IMPRIMIBLES:" << endl;
    cout << "Rango  | Descripción           | Ejemplos" << endl;
    cout << "-------|----------------------|------------------" << endl;
    cout << "32-47  | Símbolos y espacio   | ' !'\"#$%&'()*+,-./" << endl;
    cout << "48-57  | Dígitos              | 0123456789" << endl;
    cout << "58-64  | Símbolos             | :;<=>?@" << endl;
    cout << "65-90  | Letras mayúsculas    | ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    cout << "91-96  | Símbolos             | [\\]^_`" << endl;
    cout << "97-122 | Letras minúsculas    | abcdefghijklmnopqrstuvwxyz" << endl;
    cout << "123-126| Símbolos             | {|}~" << endl;
    
    cout << "\n🔍 DEMOSTRACIÓN DE CÓDIGOS ASCII:" << endl;
    cout << "Carácter | Código | Binario    | Hexadecimal" << endl;
    cout << "---------|--------|------------|------------" << endl;
    
    char caracteres[] = {'A', 'a', '0', ' ', '!', '\n', '\t'};
    string nombres[] = {"'A'", "'a'", "'0'", "' '", "'!'", "'\\n'", "'\\t'"};
    
    for (int i = 0; i < 7; i++) {
        if (caracteres[i] == '\n' || caracteres[i] == '\t') {
            cout << setw(8) << nombres[i] << " | " 
                 << setw(6) << (int)caracteres[i] << " | "
                 << bitset<8>(caracteres[i]) << " | "
                 << hex << uppercase << (int)caracteres[i] << dec << endl;
        } else {
            cout << setw(8) << nombres[i] << " | " 
                 << setw(6) << (int)caracteres[i] << " | "
                 << bitset<8>(caracteres[i]) << " | "
                 << hex << uppercase << (int)caracteres[i] << dec << endl;
        }
    }
    
    cout << "\n🔄 CONVERSIONES ENTRE MAYÚSCULAS Y MINÚSCULAS:" << endl;
    cout << "Diferencia 'a' - 'A' = " << ('a' - 'A') << endl;
    cout << "Conversiones:" << endl;
    
    for (char c = 'A'; c <= 'E'; c++) {
        char minuscula = c + 32;
        char mayuscula = minuscula - 32;
        cout << "'" << c << "' + 32 = '" << minuscula << "', '" 
             << minuscula << "' - 32 = '" << mayuscula << "'" << endl;
    }
    
    cout << "\n🔢 CONVERSIONES ENTRE DÍGITOS Y NÚMEROS:" << endl;
    cout << "Dígito | Código ASCII | Como número" << endl;
    cout << "-------|--------------|------------" << endl;
    
    for (char digito = '0'; digito <= '9'; digito++) {
        int numero = digito - '0';
        cout << "  '" << digito << "'   |      " << (int)digito 
             << "      |      " << numero << endl;
    }
    
    cout << "\n🧮 VALIDACIONES DE CARACTERES:" << endl;
    char test_chars[] = {'A', 'z', '5', '@', ' ', '\n'};
    
    for (char c : test_chars) {
        cout << "Carácter '" << (c == '\n' ? 'n' : c) << "' (" << (int)c << "): ";
        
        if (c >= '0' && c <= '9') cout << "DÍGITO ";
        if (c >= 'A' && c <= 'Z') cout << "MAYÚSCULA ";
        if (c >= 'a' && c <= 'z') cout << "MINÚSCULA ";
        if (c == ' ' || c == '\t' || c == '\n') cout << "ESPACIO ";
        if (c >= 33 && c <= 126) cout << "IMPRIMIBLE ";
        if (c >= 0 && c <= 31) cout << "CONTROL ";
        
        cout << endl;
    }
    
    cout << "\n🌍 LIMITACIONES DE ASCII:" << endl;
    cout << "ASCII solo cubre 128 caracteres básicos del inglés." << endl;
    cout << "Para caracteres internacionales se necesita:" << endl;
    cout << "- Extended ASCII (256 caracteres)" << endl;
    cout << "- Unicode/UTF-8 (millones de caracteres)" << endl;
    cout << "- Bibliotecas especializadas para texto internacional" << endl;
    
    cout << "\n💡 BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Usar funciones de <cctype>: isdigit(), isalpha(), toupper()" << endl;
    cout << "✅ Validar entrada antes de procesar" << endl;
    cout << "✅ Considerar Unicode para aplicaciones internacionales" << endl;
    cout << "✅ Usar char para caracteres, int para códigos ASCII" << endl;
    cout << "❌ No asumir que char es siempre signed" << endl;
    cout << "❌ No hacer aritmética directa sin validar rangos" << endl;
}

/*
================================================================================
📖 ESTUDIO PROFUNDO: TIPO BOOLEANO - LÓGICA Y OPTIMIZACIONES
================================================================================

🧠 FUNDAMENTOS DE LÓGICA BOOLEANA:

El tipo bool está basado en el álgebra booleana desarrollada por George Boole en 1854.
Esta álgebra define operaciones sobre valores de verdad (verdadero/falso).

🔍 REPRESENTACIÓN INTERNA:
- bool ocupa 1 byte (8 bits) aunque solo necesita 1 bit
- true se almacena como 1, false como 0
- Cualquier valor ≠ 0 se considera true en conversiones
- Solo 0 se considera false

📊 TABLA DE VERDAD COMPLETA:

AND (&&):
A | B | A && B
--|---|-------
F | F |   F
F | T |   F
T | F |   F
T | T |   T

OR (||):
A | B | A || B
--|---|-------
F | F |   F
F | T |   T
T | F |   T
T | T |   T

NOT (!):
A | !A
--|---
F | T
T | F

XOR (^) - Exclusivo:
A | B | A ^ B
--|---|------
F | F |   F
F | T |   T
T | F |   T
T | T |   F

🚀 OPTIMIZACIONES DEL COMPILADOR:

1. 🔄 EVALUACIÓN PEREZOSA (SHORT-CIRCUIT):
   - En A && B: si A es false, B no se evalúa
   - En A || B: si A es true, B no se evalúa
   - Importante para eficiencia y seguridad

2. 🎯 OPTIMIZACIÓN DE RAMAS:
   - El compilador puede eliminar código inalcanzable
   - if (true) se optimiza completamente
   - if (false) elimina el bloque completo

3. 📊 PREDICCIÓN DE RAMAS:
   - El procesador predice qué rama se tomará
   - Patrones predecibles mejoran el rendimiento
   - Ramas aleatorias causan penalizaciones

⚡ OPERADORES BITWISE VS LÓGICOS:

LÓGICOS (&&, ||, !):
- Operan sobre valores de verdad
- Resultado siempre true o false
- Evaluación perezosa
- Para control de flujo

BITWISE (&, |, ^, ~):
- Operan bit por bit
- Resultado puede ser cualquier número
- Siempre evalúan ambos operandos
- Para manipulación de bits

🎯 CASOS DE USO AVANZADOS:

1. 🏁 FLAGS Y ESTADOS:
   bool sistema_iniciado = false;
   bool usuario_autenticado = false;
   bool datos_cargados = false;

2. 🔍 VALIDACIONES COMPLEJAS:
   bool es_valido = (edad >= 18) && (edad <= 65) && tiene_licencia;

3. 🎮 CONTROL DE BUCLES:
   bool continuar = true;
   while (continuar && intentos < max_intentos) { ... }

4. 🛡️ GUARDS Y PRECONDICIONES:
   if (!archivo_abierto || datos_corruptos) return false;

================================================================================
*/

void estudio_profundo_booleanos() {
    cout << "\n=== ESTUDIO PROFUNDO: TIPO BOOLEANO Y LÓGICA ===" << endl;
    
    cout << "\n📊 CARACTERÍSTICAS DEL TIPO BOOL:" << endl;
    cout << "Tamaño de bool: " << sizeof(bool) << " byte(s)" << endl;
    cout << "Valores posibles: true (1) y false (0)" << endl;
    
    bool verdadero = true;
    bool falso = false;
    
    cout << "\n🔢 REPRESENTACIÓN NUMÉRICA:" << endl;
    cout << "true como int: " << (int)verdadero << endl;
    cout << "false como int: " << (int)falso << endl;
    cout << "true en binario: " << bitset<8>(verdadero) << endl;
    cout << "false en binario: " << bitset<8>(falso) << endl;
    
    cout << "\n🔄 CONVERSIONES DESDE NÚMEROS:" << endl;
    int numeros[] = {-5, -1, 0, 1, 42, 100};
    
    for (int num : numeros) {
        bool como_bool = (bool)num;
        cout << "int " << setw(3) << num << " -> bool " << boolalpha << como_bool << noboolalpha << endl;
    }
    
    cout << "\n📊 TABLA DE VERDAD - OPERADORES LÓGICOS:" << endl;
    cout << "A     | B     | A&&B  | A||B  | !A    | A^B" << endl;
    cout << "------|-------|-------|-------|-------|------" << endl;
    
    bool valores[] = {false, true};
    for (bool a : valores) {
        for (bool b : valores) {
            cout << boolalpha << setw(5) << a << " | " << setw(5) << b << " | "
                 << setw(5) << (a && b) << " | " << setw(5) << (a || b) << " | "
                 << setw(5) << (!a) << " | " << setw(5) << (a ^ b) << noboolalpha << endl;
        }
    }
    
    cout << "\n⚡ DEMOSTRACIÓN DE EVALUACIÓN PEREZOSA:" << endl;
    
    // Función que tiene efecto secundario
    auto funcion_con_efecto = [](const string& mensaje) -> bool {
        cout << "  [Ejecutando: " << mensaje << "]" << endl;
        return true;
    };
    
    cout << "Evaluando: false && funcion_con_efecto(\"nunca se ejecuta\")" << endl;
    bool resultado1 = false && funcion_con_efecto("nunca se ejecuta");
    cout << "Resultado: " << boolalpha << resultado1 << noboolalpha << endl;
    
    cout << "\nEvaluando: true || funcion_con_efecto(\"nunca se ejecuta\")" << endl;
    bool resultado2 = true || funcion_con_efecto("nunca se ejecuta");
    cout << "Resultado: " << boolalpha << resultado2 << noboolalpha << endl;
    
    cout << "\nEvaluando: true && funcion_con_efecto(\"sí se ejecuta\")" << endl;
    bool resultado3 = true && funcion_con_efecto("sí se ejecuta");
    cout << "Resultado: " << boolalpha << resultado3 << noboolalpha << endl;
    
    cout << "\n🔍 COMPARACIÓN: LÓGICOS VS BITWISE:" << endl;
    int a = 3, b = 5;  // 3 = 011, 5 = 101 en binario
    
    cout << "a = " << a << " (" << bitset<8>(a) << ")" << endl;
    cout << "b = " << b << " (" << bitset<8>(b) << ")" << endl;
    cout << "\nOperadores lógicos (resultado bool):" << endl;
    cout << "a && b = " << boolalpha << (bool)(a && b) << " (" << (a && b) << ")" << noboolalpha << endl;
    cout << "a || b = " << boolalpha << (bool)(a || b) << " (" << (a || b) << ")" << noboolalpha << endl;
    
    cout << "\nOperadores bitwise (resultado int):" << endl;
    cout << "a & b = " << (a & b) << " (" << bitset<8>(a & b) << ")" << endl;
    cout << "a | b = " << (a | b) << " (" << bitset<8>(a | b) << ")" << endl;
    cout << "a ^ b = " << (a ^ b) << " (" << bitset<8>(a ^ b) << ")" << endl;
    
    cout << "\n🎯 CASOS DE USO PRÁCTICOS:" << endl;
    
    // Sistema de permisos
    cout << "\n1. SISTEMA DE PERMISOS:" << endl;
    bool es_admin = true;
    bool esta_autenticado = true;
    bool tiene_permisos_especiales = false;
    
    bool puede_eliminar = es_admin && esta_autenticado;
    bool puede_modificar = esta_autenticado && (es_admin || tiene_permisos_especiales);
    bool puede_leer = esta_autenticado;
    
    cout << boolalpha;
    cout << "Puede eliminar: " << puede_eliminar << endl;
    cout << "Puede modificar: " << puede_modificar << endl;
    cout << "Puede leer: " << puede_leer << endl;
    cout << noboolalpha;
    
    // Validación de datos
    cout << "\n2. VALIDACIÓN DE ENTRADA:" << endl;
    int edad = 25;
    string email = "usuario@ejemplo.com";
    bool acepta_terminos = true;
    
    bool edad_valida = (edad >= 18) && (edad <= 120);
    bool email_valido = !email.empty() && (email.find('@') != string::npos);
    bool registro_valido = edad_valida && email_valido && acepta_terminos;
    
    cout << boolalpha;
    cout << "Edad válida: " << edad_valida << endl;
    cout << "Email válido: " << email_valido << endl;
    cout << "Registro válido: " << registro_valido << endl;
    cout << noboolalpha;
    
    // Control de flujo
    cout << "\n3. CONTROL DE BUCLE CON MÚLTIPLES CONDICIONES:" << endl;
    int intentos = 0;
    int max_intentos = 3;
    bool exito = false;
    bool usuario_cancelo = false;
    
    cout << "Simulando bucle de autenticación:" << endl;
    while (!exito && intentos < max_intentos && !usuario_cancelo) {
        intentos++;
        cout << "Intento " << intentos << "..." << endl;
        
        // Simular resultado aleatorio
        exito = (intentos == 2);  // Éxito en el segundo intento
        usuario_cancelo = false;  // Usuario no cancela
        
        if (!exito && intentos < max_intentos) {
            cout << "Falló, intentando de nuevo..." << endl;
        }
    }
    
    cout << boolalpha;
    cout << "Resultado final - Éxito: " << exito << ", Intentos: " << intentos << endl;
    cout << noboolalpha;
    
    cout << "\n💡 OPTIMIZACIONES Y BUENAS PRÁCTICAS:" << endl;
    cout << "✅ Usar evaluación perezosa para eficiencia" << endl;
    cout << "✅ Nombrar variables bool con prefijos: es_, tiene_, puede_" << endl;
    cout << "✅ Evitar comparaciones redundantes: if (flag == true)" << endl;
    cout << "✅ Usar bool para flags de estado y control" << endl;
    cout << "✅ Combinar condiciones complejas con paréntesis claros" << endl;
    cout << "❌ No confundir operadores lógicos con bitwise" << endl;
    cout << "❌ No asumir que bool siempre es 1 byte en todos los sistemas" << endl;
}

/*
================================================================================
🎯 FUNCIÓN PRINCIPAL MEJORADA - SISTEMA DE APRENDIZAJE INTERACTIVO
================================================================================
*/

int main() {
    cout << "📚 TEORÍA AVANZADA: TIPOS DE DATOS Y VARIABLES EN C++" << endl;
    cout << "==========================================================" << endl;
    cout << "🎓 Sistema de Aprendizaje Profundo e Interactivo" << endl;
    cout << "📖 Desde conceptos básicos hasta detalles de implementación" << endl;
    
    int opcion;
    
    do {
        cout << "\n--- MENÚ DE ESTUDIOS PROFUNDOS ---" << endl;
        cout << "1. 🔢 Tipos enteros - Arquitectura y representación" << endl;
        cout << "2. 🔢 Punto flotante - IEEE 754 y precisión" << endl;
        cout << "3. 🔤 Caracteres - ASCII, Unicode y codificación" << endl;
        cout << "4. ✅ Booleanos - Lógica y optimizaciones" << endl;
        cout << "5. 📝 Cadenas - Gestión de memoria y operaciones" << endl;
        cout << "6. 🔒 Constantes - Optimización y buenas prácticas" << endl;
        cout << "7. 🔄 Conversiones - Casting y compatibilidad" << endl;
        cout << "8. 🎯 Ejemplo integrador avanzado" << endl;
        cout << "9. 📊 Resumen completo con tablas" << endl;
        cout << "10. 🧪 Laboratorio de experimentación" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                estudio_profundo_enteros();
                break;
            case 2:
                estudio_profundo_flotantes();
                break;
            case 3:
                estudio_profundo_caracteres();
                break;
            case 4:
                estudio_profundo_booleanos();
                break;
            case 5:
                // TODO: Implementar estudio profundo de strings
                cout << "\n🚧 Estudio profundo de strings - En desarrollo" << endl;
                break;
            case 6:
                // TODO: Implementar estudio profundo de constantes
                cout << "\n🚧 Estudio profundo de constantes - En desarrollo" << endl;
                break;
            case 7:
                // TODO: Implementar estudio profundo de conversiones
                cout << "\n🚧 Estudio profundo de conversiones - En desarrollo" << endl;
                break;
            case 8:
                // TODO: Implementar ejemplo integrador avanzado
                cout << "\n🚧 Ejemplo integrador avanzado - En desarrollo" << endl;
                break;
            case 9:
                // TODO: Implementar resumen completo
                cout << "\n🚧 Resumen completo - En desarrollo" << endl;
                break;
            case 10:
                // TODO: Implementar laboratorio de experimentación
                cout << "\n🚧 Laboratorio de experimentación - En desarrollo" << endl;
                break;
            case 0:
                cout << "\n🎉 ¡Excelente! Has completado el estudio profundo de tipos de datos." << endl;
                cout << "🚀 Ahora tienes un conocimiento sólido de los fundamentos." << endl;
                cout << "📈 Continúa con operadores para el siguiente nivel." << endl;
                break;
            default:
                cout << "❌ Opción inválida. Seleccione entre 0 y 10." << endl;
        }
        
        if (opcion != 0) {
            cout << "\n📚 Presiona Enter para continuar con tu aprendizaje...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcion != 0);
    
    return 0;
}

/*
================================================================================
📝 PLANTILLA AVANZADA PARA PRÁCTICA PROFUNDA
================================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <bitset>
using namespace std;

int main() {
    cout << "=== LABORATORIO DE EXPERIMENTACIÓN CON TIPOS ===" << endl;
    
    // 🎯 EXPERIMENTO 1: Límites y desbordamientos
    cout << "\n1. EXPERIMENTANDO CON LÍMITES:" << endl;
    // TODO: Crear variables en los límites de cada tipo
    // TODO: Probar qué pasa al superar los límites
    // TODO: Documentar los resultados
    
    // 🎯 EXPERIMENTO 2: Precisión de flotantes
    cout << "\n2. EXPERIMENTANDO CON PRECISIÓN:" << endl;
    // TODO: Crear números con muchos decimales
    // TODO: Comparar float vs double vs long double
    // TODO: Probar operaciones que causan pérdida de precisión
    
    // 🎯 EXPERIMENTO 3: Conversiones peligrosas
    cout << "\n3. EXPERIMENTANDO CON CONVERSIONES:" << endl;
    // TODO: Probar conversiones que pierden información
    // TODO: Documentar cuándo es seguro convertir
    // TODO: Crear funciones de conversión segura
    
    // 🎯 EXPERIMENTO 4: Optimizaciones del compilador
    cout << "\n4. EXPERIMENTANDO CON OPTIMIZACIONES:" << endl;
    // TODO: Crear código que el compilador puede optimizar
    // TODO: Usar constantes vs variables
    // TODO: Medir diferencias de rendimiento
    
    // 🎯 EXPERIMENTO 5: Representación en memoria
    cout << "\n5. EXPERIMENTANDO CON MEMORIA:" << endl;
    // TODO: Mostrar direcciones de memoria de variables
    // TODO: Analizar cómo se alinean los datos
    // TODO: Comparar tamaños de estructuras
    
    return 0;
}

================================================================================
🎯 EJERCICIOS DE INVESTIGACIÓN AVANZADA
================================================================================

1. 🔬 INVESTIGACIÓN DE ARQUITECTURA:
   - Investiga cómo tu procesador maneja diferentes tipos
   - Compara rendimiento de operaciones con diferentes tipos
   - Analiza el código ensamblador generado

2. 🌐 ESTUDIO DE ESTÁNDARES:
   - Lee la especificación IEEE 754 completa
   - Investiga las diferencias entre C++11, C++14, C++17, C++20
   - Compara C++ con otros lenguajes

3. 🛠️ IMPLEMENTACIÓN PROPIA:
   - Implementa tu propia clase "BigInteger" para números grandes
   - Crea una clase "Decimal" para aritmética exacta
   - Implementa conversiones entre diferentes bases numéricas

4. 🎮 APLICACIONES PRÁCTICAS:
   - Crea un sistema de coordenadas para un juego
   - Implementa un calculador de interés compuesto preciso
   - Desarrolla un analizador de texto con estadísticas completas

5. 🔍 ANÁLISIS DE RENDIMIENTO:
   - Mide el tiempo de diferentes operaciones
   - Compara el uso de memoria de diferentes tipos
   - Analiza el impacto de las conversiones en el rendimiento

================================================================================
*/