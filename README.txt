# Dungeon_Files

Estoy haciendo el trabajo solo porque el Alberto habló con el Pau y le dijo que si queria hacer cosas mas avanzadas podia pero que no lo haga con otra gente.
Como el lo esta haciendo con SDL3 y yo ya tuve suficiente con SDL en navidades, haré el trabajo solo y por consola, como lo pides pot el moodle.

Algo me dice que el codigo no es el codigo mas limpio del mundo, pero estoy bastante contento con el resultado.

!IMPORTANTE¡ Si vas a cargar una partida con archivos binarios el programa lee la información del jugador de una manera muy específica:

- Struct Position (2 ints)
- Money (int)
- WinChance (int)
- PlayerHealth (int)
- bomb (bool)
- Gambling Coin (bool)

También tendras que escribir antes de cada fila de carácteres la cantidad de carácteres que tiene esa fila (ejemplo: 13, ..., 15, ...).

Si se carga un binario sin cumplir con estas especificaciones el programa va a crashear.


!SEMI IMPORTAMTE! Si creas un mapa custom con txt es MUY IPORTANTE que el mapa tenga SOLO una S (mayúscula) y una O ('mayúscula'). Si el mapa
carece de esos elementos, no se podra ganar el juego.

En esta versión del trabajo que se nos pide, el jugador empieza con una cantidad aleatoria de vidas. Puede empezar con 0 vidas y perder directamente (es una feature!), o con 1 o 2 vidas... o con 7. 
Los items se consiguen en la tienda (S) y la salida (O) es la única manera de ganar la partida. 
