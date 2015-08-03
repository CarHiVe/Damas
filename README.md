Juego de las damas chilenas

El juego sólo está disponible por ahora para jugar blancas (jugador humano) contra negras (CPU)

Para comenzar, abrir una terminal y dirigirse a la carpeta contenedora, la cual debería llamarse Damas esta se encontraría en descargas o en la carpeta en donde lo guardó. 

Para compilar, digite el siguiente comando

	g++ Arbol.cpp Jugador.cpp JugadorHumano.cpp main.cpp Tablero.cpp -o main

Se creará un ejecutable llamado main, el cual debe llamarse de la siguiente manera desde la terminal.

	./main

Para jugar debe digitar primero donde está posicionada la ficha de su respectivo color, que en este caso sólo está disponible para el color blanco.

Por ejemplo, si su pieza está posicionada en la casilla h4 y desea moverla a g3, debe digitar

	h4g3

Si desea comer una ficha; por ejemplo, si su ficha está situada en e3 y la ficha para comer está en d4, usted debe digitar 

	e3c5

esto quiere decir que saltará a la casilla inmediatamente siguiente a la ficha rival.

Cabe destacar que si su usted no come la ficha rival, el oponente tiene el derecho de comerse dicha ficha o sacarla del juego.

Para ganar debe dejar sin piezas al oponente o dejarlo sin movimientos.
