# 📚 PLAN DE ESTUDIO COMPLETO - PROGRAMACIÓN EN C++
## Unidad 1: Fundamentos de Programación

---

## 🎯 OBJETIVOS DEL PLAN DE ESTUDIO

### Objetivo General
Dominar los fundamentos de programación en C++ a través de un enfoque práctico y estructurado, desarrollando habilidades sólidas en:
- Sintaxis básica de C++
- Declaración y manejo de variables
- Tipos de datos fundamentales
- Operadores y expresiones
- Estructuras de control
- Gestión de memoria

### Objetivos Específicos
1. **Comprender** la sintaxis básica de C++
2. **Aplicar** correctamente variables y tipos de datos
3. **Utilizar** operadores de manera eficiente
4. **Implementar** estructuras de control
5. **Gestionar** memoria de forma adecuada

---

## 📅 CRONOGRAMA DE ESTUDIO (4 SEMANAS)

### **SEMANA 1: FUNDAMENTOS BÁSICOS**
**Días 1-7: Introducción y Variables**

#### **DÍA 1: Introducción a C++**
- **Material:** `01_Introducción (1).pdf`
- **Tiempo:** 2-3 horas
- **Actividades:**
  - Leer introducción completa
  - Configurar entorno de desarrollo
  - Primer programa "Hola Mundo"

**Ejercicio Práctico Día 1:**
```cpp
// Ejercicio 1: Mi primer programa
#include <iostream>
using namespace std;

int main() {
    cout << "¡Hola! Soy [Tu Nombre]" << endl;
    cout << "Este es mi primer programa en C++" << endl;
    return 0;
}
```

#### **DÍA 2-3: Variables y Tipos de Datos**
- **Material:** `inforII-u1-declaracion-de-variables-y-tipos-de-datos-fundamentales-en-c (1).pdf`
- **Tiempo:** 3-4 horas por día
- **Actividades:**
  - Estudiar tipos de datos fundamentales
  - Practicar declaración de variables
  - Ejercicios de conversión de tipos

**Ejercicios Prácticos Días 2-3:**
```cpp
// Ejercicio 2: Tipos de datos básicos
#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    int edad = 20;
    float altura = 1.75;
    double peso = 70.5;
    char inicial = 'A';
    bool esEstudiante = true;
    string nombre = "Juan";
    
    // Mostrar información
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Altura: " << altura << " metros" << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Inicial: " << inicial << endl;
    cout << "Es estudiante: " << (esEstudiante ? "Sí" : "No") << endl;
    
    return 0;
}
```

#### **DÍA 4-5: Operadores**
- **Material:** `inforII-u1-operadores-de-c++ (1).pdf`
- **Tiempo:** 3-4 horas por día
- **Actividades:**
  - Operadores aritméticos
  - Operadores de comparación
  - Operadores lógicos
  - Operadores de asignación

**Ejercicios Prácticos Días 4-5:**
```cpp
// Ejercicio 3: Calculadora básica
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operador;
    
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el operador (+, -, *, /): ";
    cin >> operador;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    
    double resultado;
    bool operacionValida = true;
    
    switch(operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                resultado = num1 / num2;
            } else {
                cout << "Error: División por cero" << endl;
                operacionValida = false;
            }
            break;
        default:
            cout << "Operador no válido" << endl;
            operacionValida = false;
    }
    
    if(operacionValida) {
        cout << num1 << " " << operador << " " << num2 << " = " << resultado << endl;
    }
    
    return 0;
}
```

#### **DÍA 6-7: Práctica y Repaso**
- **Material:** `inforII-u1-practica-0.pdf` y `inforII-u1-practica-0 (1).pdf`
- **Tiempo:** 4-5 horas por día
- **Actividades:**
  - Resolver ejercicios de práctica
  - Crear programas combinando conceptos
  - Autoevaluación

---

### **SEMANA 2: ESTRUCTURAS DE CONTROL**
**Días 8-14: Condicionales y Bucles**

#### **DÍA 8-9: Estructuras Condicionales**
- **Material:** `02_EstructurasDeControl (1).pdf`
- **Tiempo:** 3-4 horas por día
- **Actividades:**
  - if, else if, else
  - switch-case
  - Operador ternario

**Ejercicios Prácticos Días 8-9:**
```cpp
// Ejercicio 4: Sistema de calificaciones
#include <iostream>
using namespace std;

int main() {
    float nota;
    cout << "Ingrese su calificación (0-100): ";
    cin >> nota;
    
    if(nota >= 90) {
        cout << "Excelente (A)" << endl;
    } else if(nota >= 80) {
        cout << "Muy Bueno (B)" << endl;
    } else if(nota >= 70) {
        cout << "Bueno (C)" << endl;
    } else if(nota >= 60) {
        cout << "Regular (D)" << endl;
    } else {
        cout << "Insuficiente (F)" << endl;
    }
    
    // Usando operador ternario
    string estado = (nota >= 60) ? "APROBADO" : "REPROBADO";
    cout << "Estado: " << estado << endl;
    
    return 0;
}
```

#### **DÍA 10-11: Bucles (for, while, do-while)**
- **Material:** Continuar con `02_EstructurasDeControl (1).pdf`
- **Tiempo:** 3-4 horas por día

**Ejercicios Prácticos Días 10-11:**
```cpp
// Ejercicio 5: Tabla de multiplicar
#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Ingrese un número para ver su tabla de multiplicar: ";
    cin >> numero;
    
    cout << "\nTabla del " << numero << ":" << endl;
    for(int i = 1; i <= 10; i++) {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }
    
    // Ejercicio con while: Suma de números
    int suma = 0, num;
    cout << "\nIngrese números (0 para terminar): ";
    while(cin >> num && num != 0) {
        suma += num;
        cout << "Suma actual: " << suma << endl;
        cout << "Siguiente número (0 para terminar): ";
    }
    cout << "Suma total: " << suma << endl;
    
    return 0;
}
```

#### **DÍA 12-13: Bucles Anidados y Patrones**
**Ejercicios Prácticos Días 12-13:**
```cpp
// Ejercicio 6: Patrones con asteriscos
#include <iostream>
using namespace std;

int main() {
    int filas;
    cout << "Ingrese el número de filas: ";
    cin >> filas;
    
    // Triángulo
    cout << "\nTriángulo:" << endl;
    for(int i = 1; i <= filas; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    // Pirámide
    cout << "\nPirámide:" << endl;
    for(int i = 1; i <= filas; i++) {
        // Espacios
        for(int j = 1; j <= filas - i; j++) {
            cout << " ";
        }
        // Asteriscos
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
```

#### **DÍA 14: Proyecto Integrador Semana 2**
```cpp
// Ejercicio 7: Juego de Adivinanza
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Semilla para números aleatorios
    int numeroSecreto = rand() % 100 + 1;
    int intento, intentos = 0;
    bool adivinado = false;
    
    cout << "¡Juego de Adivinanza!" << endl;
    cout << "He pensado un número entre 1 y 100" << endl;
    
    do {
        cout << "Ingrese su intento: ";
        cin >> intento;
        intentos++;
        
        if(intento == numeroSecreto) {
            adivinado = true;
            cout << "¡Felicidades! Adivinaste en " << intentos << " intentos" << endl;
        } else if(intento < numeroSecreto) {
            cout << "El número es mayor" << endl;
        } else {
            cout << "El número es menor" << endl;
        }
    } while(!adivinado && intentos < 10);
    
    if(!adivinado) {
        cout << "Se acabaron los intentos. El número era: " << numeroSecreto << endl;
    }
    
    return 0;
}
```

---

### **SEMANA 3: GESTIÓN DE MEMORIA Y CONCEPTOS AVANZADOS**
**Días 15-21: Memoria y Optimización**

#### **DÍA 15-16: Conceptos de Memoria**
- **Material:** `Taller Memoria (1).pdf`
- **Tiempo:** 4-5 horas por día
- **Actividades:**
  - Entender stack vs heap
  - Punteros básicos
  - Referencias

**Ejercicios Prácticos Días 15-16:**
```cpp
// Ejercicio 8: Introducción a punteros
#include <iostream>
using namespace std;

int main() {
    int numero = 42;
    int* puntero = &numero;
    
    cout << "Valor de numero: " << numero << endl;
    cout << "Dirección de numero: " << &numero << endl;
    cout << "Valor del puntero: " << puntero << endl;
    cout << "Valor apuntado por puntero: " << *puntero << endl;
    
    // Modificar a través del puntero
    *puntero = 100;
    cout << "Nuevo valor de numero: " << numero << endl;
    
    // Referencias
    int& referencia = numero;
    referencia = 200;
    cout << "Valor después de modificar referencia: " << numero << endl;
    
    return 0;
}
```

#### **DÍA 17-18: Arrays y Punteros**
**Ejercicios Prácticos Días 17-18:**
```cpp
// Ejercicio 9: Arrays y manipulación
#include <iostream>
using namespace std;

int main() {
    const int TAMAÑO = 5;
    int numeros[TAMAÑO];
    
    // Llenar array
    cout << "Ingrese " << TAMAÑO << " números:" << endl;
    for(int i = 0; i < TAMAÑO; i++) {
        cout << "Número " << (i+1) << ": ";
        cin >> numeros[i];
    }
    
    // Mostrar array
    cout << "\nNúmeros ingresados: ";
    for(int i = 0; i < TAMAÑO; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    // Encontrar mayor y menor
    int mayor = numeros[0], menor = numeros[0];
    for(int i = 1; i < TAMAÑO; i++) {
        if(numeros[i] > mayor) mayor = numeros[i];
        if(numeros[i] < menor) menor = numeros[i];
    }
    
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    
    // Calcular promedio
    double suma = 0;
    for(int i = 0; i < TAMAÑO; i++) {
        suma += numeros[i];
    }
    cout << "Promedio: " << (suma / TAMAÑO) << endl;
    
    return 0;
}
```

#### **DÍA 19-20: Funciones Básicas**
**Ejercicios Prácticos Días 19-20:**
```cpp
// Ejercicio 10: Funciones útiles
#include <iostream>
using namespace std;

// Función para calcular factorial
long long factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

// Función para verificar si es primo
bool esPrimo(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Función para intercambiar valores
void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int opcion;
    
    do {
        cout << "\n=== MENÚ DE FUNCIONES ===" << endl;
        cout << "1. Calcular factorial" << endl;
        cout << "2. Verificar si es primo" << endl;
        cout << "3. Intercambiar dos números" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                int n;
                cout << "Ingrese un número: ";
                cin >> n;
                cout << "Factorial de " << n << " = " << factorial(n) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "Ingrese un número: ";
                cin >> n;
                cout << n << (esPrimo(n) ? " es primo" : " no es primo") << endl;
                break;
            }
            case 3: {
                int a, b;
                cout << "Ingrese dos números: ";
                cin >> a >> b;
                cout << "Antes: a=" << a << ", b=" << b << endl;
                intercambiar(a, b);
                cout << "Después: a=" << a << ", b=" << b << endl;
                break;
            }
        }
    } while(opcion != 0);
    
    return 0;
}
```

#### **DÍA 21: Repaso y Consolidación**
- Revisar todos los conceptos
- Resolver dudas
- Práctica adicional

---

### **SEMANA 4: PROYECTOS INTEGRADORES**
**Días 22-28: Aplicación Práctica**

#### **PROYECTO 1: Sistema de Gestión de Estudiantes**
```cpp
// Proyecto 1: Sistema de Gestión de Estudiantes
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    string carrera;
};

const int MAX_ESTUDIANTES = 100;
Estudiante estudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;

void agregarEstudiante() {
    if(totalEstudiantes >= MAX_ESTUDIANTES) {
        cout << "No se pueden agregar más estudiantes" << endl;
        return;
    }
    
    cout << "=== AGREGAR ESTUDIANTE ===" << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, estudiantes[totalEstudiantes].nombre);
    cout << "Edad: ";
    cin >> estudiantes[totalEstudiantes].edad;
    cout << "Promedio: ";
    cin >> estudiantes[totalEstudiantes].promedio;
    cout << "Carrera: ";
    cin.ignore();
    getline(cin, estudiantes[totalEstudiantes].carrera);
    
    totalEstudiantes++;
    cout << "Estudiante agregado exitosamente!" << endl;
}

void mostrarEstudiantes() {
    if(totalEstudiantes == 0) {
        cout << "No hay estudiantes registrados" << endl;
        return;
    }
    
    cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
    for(int i = 0; i < totalEstudiantes; i++) {
        cout << "\nEstudiante " << (i+1) << ":" << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Carrera: " << estudiantes[i].carrera << endl;
    }
}

void buscarEstudiante() {
    if(totalEstudiantes == 0) {
        cout << "No hay estudiantes registrados" << endl;
        return;
    }
    
    string nombreBuscar;
    cout << "Ingrese el nombre a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscar);
    
    bool encontrado = false;
    for(int i = 0; i < totalEstudiantes; i++) {
        if(estudiantes[i].nombre == nombreBuscar) {
            cout << "\nEstudiante encontrado:" << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Promedio: " << estudiantes[i].promedio << endl;
            cout << "Carrera: " << estudiantes[i].carrera << endl;
            encontrado = true;
            break;
        }
    }
    
    if(!encontrado) {
        cout << "Estudiante no encontrado" << endl;
    }
}

int main() {
    int opcion;
    
    do {
        cout << "\n=== SISTEMA DE GESTIÓN DE ESTUDIANTES ===" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar todos los estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Mostrar estadísticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                if(totalEstudiantes > 0) {
                    float sumaPromedios = 0;
                    for(int i = 0; i < totalEstudiantes; i++) {
                        sumaPromedios += estudiantes[i].promedio;
                    }
                    cout << "Total de estudiantes: " << totalEstudiantes << endl;
                    cout << "Promedio general: " << (sumaPromedios / totalEstudiantes) << endl;
                } else {
                    cout << "No hay estudiantes registrados" << endl;
                }
                break;
        }
    } while(opcion != 0);
    
    return 0;
}
```

#### **PROYECTO 2: Juego de Tres en Raya (Tic-Tac-Toe)**
```cpp
// Proyecto 2: Tres en Raya
#include <iostream>
using namespace std;

char tablero[3][3];
char jugadorActual = 'X';

void inicializarTablero() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero() {
    cout << "\n   0   1   2" << endl;
    for(int i = 0; i < 3; i++) {
        cout << i << "  " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << endl;
        if(i < 2) cout << "  ---|---|---" << endl;
    }
    cout << endl;
}

bool esMovimientoValido(int fila, int col) {
    return (fila >= 0 && fila < 3 && col >= 0 && col < 3 && tablero[fila][col] == ' ');
}

bool verificarGanador() {
    // Verificar filas
    for(int i = 0; i < 3; i++) {
        if(tablero[i][0] == jugadorActual && tablero[i][1] == jugadorActual && tablero[i][2] == jugadorActual) {
            return true;
        }
    }
    
    // Verificar columnas
    for(int j = 0; j < 3; j++) {
        if(tablero[0][j] == jugadorActual && tablero[1][j] == jugadorActual && tablero[2][j] == jugadorActual) {
            return true;
        }
    }
    
    // Verificar diagonales
    if(tablero[0][0] == jugadorActual && tablero[1][1] == jugadorActual && tablero[2][2] == jugadorActual) {
        return true;
    }
    if(tablero[0][2] == jugadorActual && tablero[1][1] == jugadorActual && tablero[2][0] == jugadorActual) {
        return true;
    }
    
    return false;
}

bool tableroLleno() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    inicializarTablero();
    
    cout << "¡Bienvenido al Tres en Raya!" << endl;
    cout << "Jugador X vs Jugador O" << endl;
    
    while(true) {
        mostrarTablero();
        
        int fila, col;
        cout << "Turno del jugador " << jugadorActual << endl;
        cout << "Ingrese fila (0-2): ";
        cin >> fila;
        cout << "Ingrese columna (0-2): ";
        cin >> col;
        
        if(esMovimientoValido(fila, col)) {
            tablero[fila][col] = jugadorActual;
            
            if(verificarGanador()) {
                mostrarTablero();
                cout << "¡Jugador " << jugadorActual << " gana!" << endl;
                break;
            }
            
            if(tableroLleno()) {
                mostrarTablero();
                cout << "¡Empate!" << endl;
                break;
            }
            
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        } else {
            cout << "Movimiento inválido. Intente de nuevo." << endl;
        }
    }
    
    return 0;
}
```

---

## 📋 RUTINA DIARIA DE ESTUDIO

### **Estructura Diaria Recomendada (2-4 horas)**

#### **Fase 1: Calentamiento (15-20 min)**
- Revisar conceptos del día anterior
- Resolver 1-2 ejercicios rápidos
- Repasar sintaxis básica

#### **Fase 2: Teoría Nueva (45-60 min)**
- Leer material del día
- Tomar notas importantes
- Identificar conceptos clave

#### **Fase 3: Práctica Guiada (60-90 min)**
- Seguir ejemplos del material
- Modificar ejemplos existentes
- Experimentar con variaciones

#### **Fase 4: Práctica Independiente (30-45 min)**
- Resolver ejercicios propuestos
- Crear programas propios
- Debuggear errores

#### **Fase 5: Reflexión (10-15 min)**
- Documentar lo aprendido
- Identificar dificultades
- Planificar el siguiente día

---

## 🎯 EJERCICIOS ADICIONALES POR TEMA

### **Variables y Tipos de Datos**
```cpp
// Ejercicio Extra 1: Conversor de unidades
#include <iostream>
using namespace std;

int main() {
    double metros, centimetros, pulgadas, pies;
    
    cout << "Ingrese una distancia en metros: ";
    cin >> metros;
    
    centimetros = metros * 100;
    pulgadas = metros * 39.3701;
    pies = metros * 3.28084;
    
    cout << fixed;
    cout.precision(2);
    
    cout << "\nConversiones:" << endl;
    cout << metros << " metros = " << centimetros << " centímetros" << endl;
    cout << metros << " metros = " << pulgadas << " pulgadas" << endl;
    cout << metros << " metros = " << pies << " pies" << endl;
    
    return 0;
}
```

### **Operadores**
```cpp
// Ejercicio Extra 2: Calculadora de IMC
#include <iostream>
using namespace std;

int main() {
    double peso, altura, imc;
    
    cout << "=== CALCULADORA DE IMC ===" << endl;
    cout << "Ingrese su peso (kg): ";
    cin >> peso;
    cout << "Ingrese su altura (m): ";
    cin >> altura;
    
    imc = peso / (altura * altura);
    
    cout << fixed;
    cout.precision(1);
    cout << "\nSu IMC es: " << imc << endl;
    
    if(imc < 18.5) {
        cout << "Clasificación: Bajo peso" << endl;
    } else if(imc < 25) {
        cout << "Clasificación: Peso normal" << endl;
    } else if(imc < 30) {
        cout << "Clasificación: Sobrepeso" << endl;
    } else {
        cout << "Clasificación: Obesidad" << endl;
    }
    
    return 0;
}
```

### **Estructuras de Control**
```cpp
// Ejercicio Extra 3: Generador de números primos
#include <iostream>
using namespace std;

int main() {
    int limite;
    cout << "Ingrese el límite para generar números primos: ";
    cin >> limite;
    
    cout << "Números primos hasta " << limite << ":" << endl;
    
    for(int num = 2; num <= limite; num++) {
        bool esPrimo = true;
        
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                esPrimo = false;
                break;
            }
        }
        
        if(esPrimo) {
            cout << num << " ";
        }
    }
    cout << endl;
    
    return 0;
}
```

---

## 🔧 HERRAMIENTAS Y RECURSOS RECOMENDADOS

### **Entornos de Desarrollo**
1. **Code::Blocks** (Gratuito, fácil para principiantes)
2. **Dev-C++** (Ligero y simple)
3. **Visual Studio Code** (Con extensión C++)
4. **CLion** (Profesional, con licencia estudiantil)

### **Compiladores**
- **GCC** (GNU Compiler Collection)
- **MinGW** (Para Windows)
- **Clang** (Alternativa moderna)

### **Recursos Online**
- **cppreference.com** - Documentación oficial
- **learncpp.com** - Tutorial completo
- **hackerrank.com** - Ejercicios prácticos
- **leetcode.com** - Problemas de programación

---

## 📊 SISTEMA DE EVALUACIÓN Y SEGUIMIENTO

### **Autoevaluación Semanal**

#### **Semana 1: Fundamentos**
- [ ] Puedo declarar variables de diferentes tipos
- [ ] Entiendo los operadores básicos
- [ ] Puedo crear programas simples con entrada/salida
- [ ] Comprendo la sintaxis básica de C++

#### **Semana 2: Control de Flujo**
- [ ] Uso correctamente if/else
- [ ] Implemento bucles for y while
- [ ] Creo programas con lógica compleja
- [ ] Manejo bucles anidados

#### **Semana 3: Memoria y Arrays**
- [ ] Entiendo conceptos básicos de memoria
- [ ] Trabajo con arrays unidimensionales
- [ ] Uso punteros básicos
- [ ] Creo funciones simples

#### **Semana 4: Proyectos**
- [ ] Integro todos los conceptos aprendidos
- [ ] Creo programas completos y funcionales
- [ ] Debuggeo errores efectivamente
- [ ] Documento mi código adecuadamente

### **Criterios de Evaluación**
- **Sintaxis correcta** (25%)
- **Lógica de programación** (30%)
- **Resolución de problemas** (25%)
- **Buenas prácticas** (20%)

---

## 🚀 CONSEJOS PARA EL ÉXITO

### **Estrategias de Aprendizaje**
1. **Práctica constante**: Programa todos los días, aunque sea 30 minutos
2. **Experimentación**: Modifica los ejemplos para ver qué pasa
3. **Debugging**: Aprende a leer y corregir errores
4. **Documentación**: Comenta tu código y toma notas
5. **Comunidad**: Únete a foros y grupos de programación

### **Manejo de Dificultades**
- **Errores de compilación**: Lee el mensaje de error cuidadosamente
- **Lógica incorrecta**: Usa papel y lápiz para trazar el algoritmo
- **Conceptos difíciles**: Busca múltiples explicaciones y ejemplos
- **Motivación baja**: Recuerda tus objetivos y celebra pequeños logros

### **Recursos de Ayuda**
- **Stack Overflow**: Para preguntas específicas
- **YouTube**: Tutoriales visuales
- **Discord/Reddit**: Comunidades de programadores
- **Profesores/Tutores**: No dudes en preguntar

---

## 📝 PLANTILLA DE SEGUIMIENTO DIARIO

```
FECHA: ___________
TEMA DEL DÍA: ___________
TIEMPO ESTUDIADO: ___________

CONCEPTOS APRENDIDOS:
- 
- 
- 

EJERCICIOS COMPLETADOS:
- 
- 
- 

DIFICULTADES ENCONTRADAS:
- 
- 

DUDAS PARA RESOLVER:
- 
- 

CALIFICACIÓN DEL DÍA (1-10): ___________

PLAN PARA MAÑANA:
- 
- 
```

---

## 🎉 PROYECTO FINAL SUGERIDO

Al completar las 4 semanas, desarrolla un **Sistema de Gestión de Biblioteca** que incluya:

- Registro de libros (título, autor, ISBN, disponibilidad)
- Sistema de préstamos
- Búsqueda de libros
- Reportes estadísticos
- Interfaz de menú completa
- Validación de datos
- Manejo de errores

Este proyecto integrará todos los conceptos aprendidos y te dará una base sólida para continuar con programación orientada a objetos y estructuras de datos más avanzadas.

¡Éxito en tu aprendizaje de C++! 🚀