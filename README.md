# Snake Game

## Overview

This project is a classic **Snake Game** implemented using OpenGL and GLUT libraries. The game involves controlling a snake to consume food, causing the snake to grow and increase the player's score. The game ends when the snake collides with the wall or itself. The implementation provides basic graphical rendering and user interaction capabilities within a windowed environment.

## Key Components

### Definitions and Global Variables

- **Grid Dimensions:** The game grid is defined by `COLUMNS` and `ROWS`, setting the width and height of the playing field to 50x50 units.
- **FPS (Frames Per Second):** The game runs at 10 FPS, controlling the speed of the snake’s movement.
- **Movement Constants:** Directions for the snake are defined by constants `UP`, `DOWN`, `RIGHT`, and `LEFT`.
- **Maximum Length (`MAX`):** The snake's maximum length is capped at 60 units.
- **Snake Attributes:** Arrays `posx` and `posy` store the x and y coordinates of the snake's body segments. The `sdirection` variable keeps track of the snake’s current movement direction, and `snakelength` represents the current length of the snake.
- **Food Attributes:** Variables `foodx` and `foody` represent the coordinates of the food. The `food` flag indicates whether food is present on the grid.
- **Scores:** `score` tracks the player’s current score, and `highscore` keeps the highest score achieved.

### Main Function

- Initializes GLUT with `glutInit()` and sets up the display mode to RGB with double buffering.
- Configures the window size and title, and sets up the display, reshape, timer, and keyboard callback functions.
- Enters the GLUT main loop with `glutMainLoop()` to start the game.

### Rendering Functions

- **`display()` Function:** Clears the screen and determines which content to render based on the `window` variable. It draws either the game screen or the title screen.
- **`drawGrid()` Function:** Renders the game grid with borders and cell lines. The border cells are drawn in blue, while the grid lines are gray.
- **`drawSnake()` Function:** Updates the snake's position based on the direction of movement. The snake is rendered with a black head and red body segments. Collision detection is performed to check if the snake hits the borders or itself, ending the game if a collision is detected.
- **`drawFood()` Function:** Randomly places food on the grid if it is not currently present. The food is drawn in green.
- **`drawLetters()` Function:** Displays the title "SNAKE GAME" on the screen using a series of line drawings.

### Utility Functions

- **`init()` Function:** Sets the background color of the window to a light yellow.
- **`reshape()` Function:** Adjusts the viewport and projection matrix to ensure the game scales correctly with the window size.
- **`timer()` Function:** Manages the game’s frame rate by repeatedly calling `glutPostRedisplay()` to refresh the display at the specified FPS.
- **`keyboard()` Function:** Handles keyboard input to change the snake’s direction or toggle between the game and title screens.

## Game Mechanics

- **Movement:** The snake moves continuously in the current direction, which can be changed using the arrow keys. Movement is restricted to prevent the snake from reversing direction.
- **Collision Detection:** The game detects collisions with the grid borders and the snake’s own body. If a collision occurs, the game ends, and the current score and highscore are displayed in the console.
- **Food Consumption:** When the snake's head intersects with the food, the snake grows in length, the score increases, and new food is placed on the grid.
- **Game Over:** Upon game termination, the console displays the player’s final score and the highscore. The program then exits.

## Improvements

1. **Food Placement:** Ensure that food does not spawn on the snake’s body to avoid immediate overlap.
2. **Difficulty Adjustment:** Introduce increasing difficulty levels or faster speeds as the game progresses.
3. **Enhanced Graphics:** Improve graphical elements and incorporate a user interface to display the score and highscore within the game window.
4. **State Management:** Develop a more sophisticated system for managing game states, including game over, restarting, and navigating menus.

