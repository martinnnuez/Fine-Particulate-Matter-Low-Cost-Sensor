# Sistema de monitoreo basado en sensores de bajo costo

<p align="center">
    <img width="500" src="https://github.com/martinnnuez/Tesis-Doctorado/blob/master/images/imagescap2/SensorDentroRecorte.png" alt="Sensor de bajo costo desarrollado">
</p>


## Introducción

  Solo países desarrollados económicamente tienen la capacidad de generar redes de vigilancia de la calidad del aire basadas en equipos certificados de referencia. Un país que marca tendencia en cuanto al seguimiento y control del PM es Estados Unidos, donde se lleva a cabo una vigilancia exhaustiva de este contaminante a nivel del suelo por medio de del Método Federal de Referencia (FRM) y los Métodos Federales Equivalentes (FEM). Se cuenta con aproximadamente 600 estaciones de referencia en todo el país, que además se complementan con mediciones satelitales y otros métodos alternativos de seguimiento para lograr extrapolar los resultados a todo el territorio nacional. A pesar de ser un país que marca tendencia en lo que es el control y gestión de la calidad del aire, establece protocolos y normativas que responden a la realidad de un país desarrollado, y desarrolla tecnologías cuya accesibilidad requiere elevados presupuestos. Estos estándares entonces, representan metas inalcanzables para países en vías de desarrollo, motivo por el cual se hace necesario migrar hacia alternativas de bajo costo para la gestión y control de la calidad del aire.

  En países en vías de desarrollo, frente a la necesidad de control de la calidad del aire y los elevados costos de adquisición y manutención de los FRM y FEM, se recurre a sensores portátiles y de bajo costo. A efectos de esta tesis, se entiende por bajo costo a sensores que cuestan menos de 100 dólares. En esta tesis se armaron instrumentos de bajo costo  empleando un sensor láser de medición de partículas que sigue el principio de funcionamiento del fotómetro de dispersión, lo cual proporciona una solución económica para el monitoreo y control de la concentración de (PM<sub>2.5</sub>). Sus principales ventajas frente a los FRM y los FEM incluyen mediciones en tiempo real de los valores de concentración, además de su portabilidad y rentabilidad. Estas ventajas son a expensas de la exactitud en la medición e información acerca de la composición e individualidad de la partícula. 
  
  El monitoreo de la calidad del aire es una herramienta fundamental a la hora de identificar y evaluar problemas de contaminación, y junto con modelos predictivos e inventarios de emisión, forman parte integral de los sistemas de gestión y control de la calidad del aire. Su propósito primordial recae en la provisión de información a los científicos, legisladores y planificadores, que fomenten la toma de decisiones para la gestión, mejora del ambiente y preservación de la salud pública. El objetivo del presente capítulo es evaluar la utilidad de sensores de bajo costo para el monitoreo de la concentración de (PM<sub>2.5</sub>) en el área metropolitana de la provincia de Córdoba, Argentina. Para abarcar este objetivo fue necesario el diseño y desarrollo de dispositivos de monitoreo basado en sensores de bajo costo que permitiesen recopilar datos de concentración de (PM<sub>2.5</sub>). Además, resultó indispensable determinar la integridad de las mediciones realizadas, no solo la estabilidad entre sensores, si no que también su validación respecto a una estación de referencia.

## Desarrollo del sistema de monitoreo basado en sensores de bajo costo

  En el marco del estudio de sensores de bajo costo para la medición de PM, se llevó a cabo una investigación de las distintas tecnologías disponibles en el mercado. Luego de analizar diferentes aspectos, como precisión de medición, costo, funcionamiento, tamaño, sensibilidad e interfaz de programación, se seleccionó el sensor PMS 1003 de la marca Plantower como la opción más viable. Este sensor utiliza un haz láser para medir las partículas en tres rangos de tamaño diferentes: (PM<sub>1.0</sub>), (PM<sub>2.5</sub>) y (PM<sub>10</sub>). Es importante mencionar que el sensor mide solo (PM<sub>2.5</sub>), pero mediante el uso de un algoritmo de estimación, genera datos de concentración para las demás fracciones.

  Para garantizar el correcto funcionamiento del sensor, se procedió a desarrollar y programar el código que permitiría la conexión y comunicación entre los diferentes componentes. Luego de analizar diferentes opciones, se decidió utilizar la plataforma de desarrollo Arduino, junto con una placa Arduino UNO R3 SMD (CH340G) y una de ampliación para facilitar la conexión de los numerosos pines. Además se incorporó una memoria micro SD para almacenar la información recopilada . Como resultado, el producto final quedó conformado por los siguientes componentes:

  1.	Sensor PMS 1003 Plantower.
  2.	Sensor RTC-DS3231 - con EEPROM I2C.
  3.	Sensor DHT22 - Módulo Sensor Digital de Temperatura y Humedad.
  4.	Arduino UNO R3 SMD (CH340G) comp / ATmega328 16MHz.
  5.	Micro SD Card - Conexión SPI y Reg de Tensión.
  6.	Protoshield para Arduino uno shield y proto 170p unoelectro.
  7.	Fuente Arduino 12V 1,25 A.

  El sensor PMS 1003 es un sensor de calidad del aire basado en el principio de dispersión láser, desarrollado por la compañía Plantower, una empresa de china con sede en Shenzhen y oficinas en Pekín. Este sensor es el encargado de medir los datos de PM, y después convertirlo en sus fracciones de (PM<sub>1.0</sub>), (PM<sub>2.5</sub>) y (PM<sub>10</sub>). Este sensor emplea la tecnología de dispersión láser, implementando uno de 660 nm para la medición. El fabricante reporta una precisión de ±10 $\frac{\mu g}{m^3}$ para el (PM<sub>2.5</sub>) en el rango de 0 a 500 ±10 $\frac{\mu g}{m^3}$, mientras que para el rango de 500 a 1000 $\frac{\mu g}{m^3}$ el error se estima como ±10 %m.v., lo que significa que el error puede ser de hasta el 10% del valor medido en ese rango de concentración. Es importante tener en cuenta estas especificaciones a la hora de utilizar el sensor, con el objetivo de lograr una correcta interpretación de los datos.
  
  El chip RTC DS3231 en combinación con la EEPROM I2C proporcionan un reloj en tiempo real (RTC) que permite registrar la fecha y hora en que se realizan las  mediciones. Además, cuenta con una interfaz I2C, un oscilador integrado con compensación de temperatura de cristal (TCXO) y un cristal, que mejoran su precisión y la estabilidad del reloj.
  
  El sensor DHT22 es un sensor digital de temperatura y humedad relativa de bajo costo, que permite detectar cualquier anomalía en las condiciones ambientales durante el funcionamiento del sensor. A partir de los datos registrados por este sensor podemos cerciorarnos de las condiciones de funcionamiento, con el objetivo de determinar la calidad de los datos recopilados. Este módulo utiliza un sensor capacitivo de humedad y un termistor que permite medir el aire circundante. Es importante asegurarse de que las condiciones en las que se realiza la medición sean estables y adecuadas para obtener datos confiables.

  Arduino es una plataforma de electrónica abierta para la creación de prototipos basada en software y hardware flexibles, diseñada con el objetivo de facilitar la creación de entornos y objetos interactivos. La tarjeta de Arduino que se empleo fue la UNO R3 SMD, esta es una tarjeta que reduce su costo dado que contiene el chip adaptador USB – SERIAL CH340, a diferencia de otras tarjetas más costosas que contienen el FT232. Otra característica que abarata su costo es que emplea ATmega328 en su versión SMD o de montaje superficial. En resumen, se trata de una placa electrónica basada en el microcontrolador ATmega328 que cuenta con 14 pines de entrada y salida digitales (de los cuales 6 pueden ser utilizados como salidas PWM) y 6 entradas analógicas, un conector USB, uno de alimentación y un botón de reinicio.
  
  El módulo micro SD permite incorporar una memoria micro SD, dada su gran capacidad de almacenamiento en comparación con su reducido tamaño físico. De esta forma, son una alternativa sumamente compatible con la plataforma Arduino, sobre todo cuando se requiere almacenar grandes cantidades de información en productos de reducido tamaño.
  
  La protoshield para Arduino uno junto con el proto unoelectro, permiten duplicar el número de conexiones que podemos realizar en la placa, otorgando mayor espacio para realizar las conexiones. La protoshield, es una placa de expansión analógica y digital que permite la interconexión de múltiples periféricos al estandarizar la disposición de los pines. Esta se acopla al Arduino ampliando las capacidades de la placa de base.
  
  Finalmente, la fuente de alimentación de 12 V es necesaria para garantizar el funcionamiento continuo del sistema de medición. Esta se conecta a una toma eléctrico de pared permitiendo la provisión de energía  de manera continua al instrumento.

<p align="center">
    <img width="500" src="https://github.com/martinnnuez/Tesis-Doctorado/blob/master/images/imagescap2/SensorDentro.jpg" alt="Sensor de bajo costo desarrollado">
</p>

* **Codigo arduino:**
    * Sensor PMS1003: [PMS1003](https://github.com/martinnnuez/Fine-Particulate-Matter-Low-Cost-Sensor/blob/main/CodigoSensorPMS1003.ino)
    * Sensor SDS011: [SDS011](https://github.com/martinnnuez/Fine-Particulate-Matter-Low-Cost-Sensor/blob/main/CogidoSensorSDS011.ino)
