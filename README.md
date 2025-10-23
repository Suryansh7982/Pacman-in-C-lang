Overview

This program tries to recreate a basic, text-based Pac-Man experience that runs entirely in the terminal. The player controls Pac-Man (C) using the W, A, S, and D keys to move around a maze, collecting pellets (.) for points while avoiding a moving ghost (G). The maze layout is represented using a 2D character array, where walls are marked by #.

The game continues until the ghost catches Pac-Man, after which the final score is displayed.

Key Features
1.Simple ASCII-based maze layout
2.Real-time player movement using keyboard input
3.Random ghost movement for unpredictability
4.Score system for tracking collected pellets
5.Game-over condition when Pac-Man collides with the ghost

Concepts Used:
1.2D arrays for map representation
2.Keyboard input handling with _kbhit() and _getch()
3.Random number generation (rand()) for ghost movement
4.Loops and conditional statements for game logic
5.Modular functions for cleaner and reusable code
