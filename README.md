# 2D Car Racing Game Using C++ and SFML

## Project Overview

The **2D Car Racing Game** is a desktop-based racing game developed using C++ and the Simple and Fast Multimedia Library (SFML). The project focuses on implementing fundamental game development concepts through object-oriented programming, real-time input processing, sprite rendering, vehicle movement, collision detection, and game state management.

The game provides a top-down racing experience in which the player controls a car on a continuously scrolling road while avoiding incoming enemy vehicles. The player can control the vehicle's speed, navigate between lanes, and attempt to achieve the highest possible score without colliding with other vehicles.

The project demonstrates how C++ programming concepts and multimedia libraries can be combined to develop an interactive graphical application.

## Game Objective

The primary objective is to drive the player's vehicle while avoiding collisions with incoming enemy cars.

The player must:
- Navigate the vehicle using directional controls.
- Accelerate and decelerate according to gameplay requirements.
- Avoid incoming enemy vehicles.
- Survive for as long as possible.
- Achieve a higher score by successfully passing enemy vehicles.

A collision with an enemy vehicle ends the current game session. The player can restart the game and attempt to achieve a better score.

## Key Features

### 1. Player Vehicle Control
The player controls a racing car using keyboard inputs. Horizontal movement allows the vehicle to move left and right, while vertical speed control allows acceleration and deceleration.

### 2. Dynamic Speed Management
The player's vehicle supports variable speed within predefined minimum and maximum limits. Acceleration and braking are handled continuously based on keyboard input.

### 3. Enemy Vehicle System
Multiple enemy vehicles are generated and managed throughout the game. These vehicles move vertically towards the player's vehicle, creating an obstacle-avoidance challenge.

When an enemy vehicle moves beyond the visible game window, it is repositioned to another location to continue the gameplay.

### 4. Scrolling Road Animation
The road background continuously moves vertically to simulate vehicle motion and create the appearance of driving along a racing track.

### 5. Collision Detection
The game uses sprite bounding rectangles to identify intersections between the player's vehicle and enemy vehicles. A detected collision changes the game state to Game Over.

### 6. Score Tracking
The player's score increases whenever an enemy vehicle successfully passes beyond the visible screen.

### 7. Time and Speed Monitoring
The game displays real-time information, including:
- Current score
- Elapsed game time
- Current vehicle speed

### 8. Game State Management
The application manages active gameplay and game-over states. When a collision occurs, the game displays the final score and time. The player can restart the game using the designated keyboard control.

## Technologies and Tools

| Technology | Purpose |
|---|---|
| C++ | Core programming language and game logic |
| SFML | Graphics rendering, window management, sprites, textures, keyboard input and multimedia functionality |
| SFML Graphics | Rendering vehicles, road backgrounds and text |
| SFML Window | Game window creation and event handling |
| SFML System | Time management and frame-independent movement |

## Programming Concepts Implemented

The project applies several important C++ and game development concepts.

### Object-Oriented Programming

The game is structured around separate classes that represent different game components.

**Car Class**

The base `Car` class provides common functionality for vehicles, including:
- Sprite management
- Vehicle speed
- Position and movement-related properties
- Access to sprite boundaries

It also declares a virtual movement function, allowing derived vehicle classes to implement their own movement behaviour.

**Player Class**

The `Player` class inherits from `Car` and implements:
- Keyboard-controlled movement
- Acceleration and deceleration
- Minimum and maximum speed restrictions
- Screen boundary restrictions
- Player position and speed reset functionality

**Enemy Class**

The `Enemy` class also inherits from `Car` and implements:
- Automatic downward movement
- Enemy repositioning after leaving the visible screen
- Individual enemy vehicle speed management

**Game Class**

The `Game` class manages the overall application and coordinates:
- Game window initialization
- Texture and font loading
- Player and enemy vehicle creation
- Event handling
- Game updates
- Collision detection
- Score and time management
- Rendering and game state transitions

### Inheritance and Polymorphism

Inheritance is used to derive the `Player` and `Enemy` classes from the common `Car` class.

Polymorphism is implemented through the virtual `move()` function, which allows player and enemy vehicles to perform different movement operations using a shared interface.

### STL Vector

The C++ `vector` container is used to maintain multiple enemy vehicle objects, allowing the game to manage and update several obstacles.

### Time-Based Movement

SFML's clock functionality is used to calculate delta time between frames. This allows vehicle movement and road scrolling to be updated based on elapsed time rather than relying solely on the number of rendered frames.

### Collision Detection

The game uses SFML's global sprite bounds and rectangle intersection functionality to determine whether the player and enemy vehicles overlap.

### Event and Input Handling

SFML keyboard input and window events are used to process player controls and application events.

## Game Controls

| Keyboard Input | Function |
|---|---|
| Up Arrow | Accelerate |
| Down Arrow | Decelerate |
| Left Arrow | Move the player's car left |
| Right Arrow | Move the player's car right |
| R | Restart the game after Game Over |

## Game Assets

The game uses external graphical and font resources to create its visual interface.

| Asset | Purpose |
|---|---|
| `player_car.png` | Player vehicle |
| `enemy_car.png` | Enemy vehicles |
| `road.png` | Racing road background |
| `arial.ttf` | Font used for displaying game information |

These resources are loaded at runtime through SFML's texture and font-loading functionality.

## Game Execution and Working Mechanism

The application follows a continuous game loop consisting of three primary operations:

**1. Event Handling**

The application processes window events and keyboard inputs. It also checks for restart input when the game is in the Game Over state.

**2. Game Updates**

During active gameplay, the application:
- Updates player movement and speed.
- Restricts the player vehicle to the game window.
- Updates enemy vehicle positions.
- Repositions vehicles that leave the screen.
- Updates the score when vehicles are successfully passed.
- Checks for collisions.
- Updates the road scrolling position.
- Calculates elapsed time and current speed.

**3. Rendering**

The application draws the road background, player vehicle, enemy vehicles, and gameplay information. When the game ends, it displays the Game Over screen with the final score and time.

These operations continue until the user closes the game window.

## Application Structure

The implementation is organized into four main classes:

| Class | Responsibility |
|---|---|
| `Car` | Common vehicle properties and virtual movement interface |
| `Player` | Player-controlled vehicle behaviour |
| `Enemy` | Automated enemy vehicle behaviour |
| `Game` | Main game logic, updates, rendering and state management |

The `main()` function initializes the `Game` object and starts the game loop.

## Learning Outcomes

This project provides practical experience in:

- Applying object-oriented programming principles in C++.
- Designing class hierarchies using inheritance.
- Implementing runtime polymorphism using virtual functions.
- Developing graphical applications using SFML.
- Managing textures, sprites, fonts and graphical rendering.
- Processing real-time keyboard input.
- Implementing collision detection.
- Managing multiple game objects using STL containers.
- Developing time-dependent animations and movement.
- Structuring an interactive application using a game loop.

## Conclusion

The 2D Car Racing Game demonstrates the practical application of C++ and SFML in developing an interactive desktop game. By combining object-oriented programming, graphical rendering, real-time input handling, collision detection, and game state management, the project provides a foundation for understanding the architecture and implementation of 2D games.

It also serves as an opportunity to explore how fundamental programming concepts can be transformed into an interactive gaming experience.

---

**Developed by:** Safroon Nisha M

**Project Domain:** Game Development

**Programming Language:** C++

**Graphics Library:** SFML
