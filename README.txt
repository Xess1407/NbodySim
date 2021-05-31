# N-Body simulation

Projet fait dans le cadre de notre TIPE

## Compilation

Windows: gcc src/"*.c" -Wall -lm  -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 

Linux: gcc src/*.c -o bin/prog -lm `sdl2-config --cflags --libs`  -lSDL2_ttf -lSDL2_image

## Démarrage

Pour executer le programme:
- Sous Windows: Ouvrir le terminal (taper dans la bar de recherche "cmd"),
                aller dans le dossier principal du programme(N-body simulation) avec la commande "cd /..."
                taper ".\bin\prog"

- Sous Linux: Ouvrer le terminal,
              aller dans le dossier principal du programme(N-body simulation)avec la commande "cd /...",
              taper "./bin/prog"

