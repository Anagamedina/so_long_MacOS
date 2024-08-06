# SoLOng
Tu proyecto debe cumplir con las siguientes normas:

• Debes usar la miniLibX. Ya sea la versión disponible en el sistema operativo, o
su fuente. Si eliges trabajar con la fuente, deberás compilar siguiendo las mismas
normas que con tu libft, descritas en la parte de Instrucciones generales.

• Debes entregar un Makefile que compile con tus archivos fuente.

• Tu programa debe aceptar como primer argumento un archivo con la descripción
del mapa de extensión .ber.

IV.1. Juego
• El objetivo del jugador es recolectar todos los objetos presentes en el mapa 
y salir eligiendo la ruta más corta posible.
• Las teclas W, A, S y D se utilizarán para mover al personaje principal.
• El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o
ir a la derecha.
• El jugador no puede entrar dentro de las paredes.
• Tras cada movimiento, el número real de movimientosdebe mostrarse en un ter-
minal.
• Utilizarás una perspectiva 2D (vista de pájaro o lateral).
• El juego no necesita ser en tiempo real.
• Aunque los ejemplos dados se refieren a una temática de delfín, puedes crear el
mundo que quieras.
IV.2. Gestión de gráficos

• El programa mostrará la imagen en una ventana.
• La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc)
• Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
• Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa
limpiamente.
• El uso de images de la miniLibX es obligatorio
SoLong And thanks for all the fish!

IV.3. Mapa
• El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.
• El mapa estará compuesto de solo 5 caracteres: 0 para un espacio vacío, 1 para un
muro, C para un coleccionable, E para salir del mapa y P para la posición inicial
del jugador.

Este es un ejemplo simple de un mapa válido:
 El mapa debe tener una salida, al menos un objeto y una posición inicial.
 • El mapa debe ser rectangular.
• El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa
deberá devolver un error.

• Tienes que comprobar si hay un camino válido en el mapa.
• Debes poder procesar cualquier tipo de mapa, siempre y cuando respete las anteri-
ores normas.

• Otro ejemplo minimalista de un mapa .ber:
• En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el
programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje
explícito de tu elección.
