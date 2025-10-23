#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   // For _kbhit() and _getch()
#include <time.h>    // For rand()

#define WIDTH 20
#define HEIGHT 10

char map[HEIGHT][WIDTH + 1] = {
    "###################",
    "#........#........#",
    "#.###.#..#..#.###.#",
    "#.................#",
    "#.###.#.###.#.###.#",
    "#.....#..G..#.....#",
    "#.###.#.###.#.###.#",
    "#........C........#",
    "#........#........#",
    "###################"
};

int pacmanX = 8, pacmanY = 7;
int ghostX = 10, ghostY = 5;
int score = 0;

void drawMap() {
    system("cls"); // Clear screen (Windows)
    for (int i = 0; i < HEIGHT; i++)
        printf("%s\n", map[i]);
    printf("\nScore: %d\n", score);
}

void movePacman(char direction) {
    int newX = pacmanX, newY = pacmanY;

    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
    }

    if (map[newY][newX] != '#') {
        if (map[newY][newX] == '.')
            score++;
        map[pacmanY][pacmanX] = ' ';
        pacmanX = newX;
        pacmanY = newY;
        map[pacmanY][pacmanX] = 'C';
    }
}

void moveGhost() {
    int dir = rand() % 4;
    int newX = ghostX, newY = ghostY;

    switch (dir) {
        case 0: newY--; break;
        case 1: newY++; break;
        case 2: newX--; break;
        case 3: newX++; break;
    }

    if (map[newY][newX] != '#' && map[newY][newX] != 'C') {
        map[ghostY][ghostX] = ' ';
        ghostX = newX;
        ghostY = newY;
        map[ghostY][ghostX] = 'G';
    }
}

int main() {
    srand(time(NULL));

    while (1) {
        drawMap();

        if (_kbhit()) {
            char ch = _getch();
            movePacman(ch);
        }

        moveGhost();

        if (pacmanX == ghostX && pacmanY == ghostY) {
            system("cls");
            printf("Game Over! Final Score: %d\n", score);
            break;
        }

        _sleep(200);
    }

    return 0;
}
