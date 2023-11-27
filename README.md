# calculadora-nomina

**Objetivo del proyecto escolar:** Crear una calculadora de nóminas y graficar cualquier dato. 

Simula una calculadora de nómina mensual y dibuja una gráfica de barras del promedio del pago de nómina mensual de 3 grupos de empleados.

## Prerrequisitos: 📋

Para compilar el programa correctamente en VS Code se requiere configurar el compilador para que funcione la librería _graphics.h_

Me basé en estos 2 videos para configurarlo correctamente:
- [How to setup graphics.h in VS Code | CodeWar](https://www.youtube.com/watch?v=J0_vt-7Ok6U&t=1226s) por CodeWar.
- [How to Fix Fatal error: graphics.h: No such file or directory in CodeBlocks | graphics.h not working](https://www.youtube.com/watch?v=b4Xk1ut8fO0&t=239s) por MD TARIF HASAN TECH

Y usé la extensión _Code Runner_ de Jun Han para compilar. 

----
## Funcionamiento del programa 🧮

El programa le pide al usuario que ingrese el sueldo base, los días trabajados y las horas extras de un trabajador; se guarda esa información y se calcula la nómina que se le debe pagar al empleado en el mes, con base en las fórmulas: 
- pago al mes = (sueldo base / 30) * días trabajados. 
- pago de horas extras = (sueldo base / 30) / 8 horas * 1.5 * cantidad de horas extras. 

Cada empleado tiene un número de identificador donde el primer dígito (5, 6 o 7) corresponde al grupo de empleado al que pertenece.

Para este ejercicio se consideró que hay 6 empleados:
- 2 técnicos del grupo A: 5101 y 5102
- 2 técnicos del grupo B: 6101 y 6102
- 2 técnicos del grupo C: 7101 y 7101

Si se ingresa el número de estos empleados, se actualizará su sueldo base. Se pueden modificar los sueldos de cada empleado cuantas veces desee. 

Cuando el usuario decida no seguir actualizando la información, se calculará el promedio de pago de nómina que gana en un mes cada grupo de técnicos. 

Al final, se dibuja una gráfica de barras donde se muestra qué grupo de técnicos cobrará más en ese mes. 

