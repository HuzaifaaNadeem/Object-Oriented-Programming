#include <iostream>
using namespace std;

class GraphicsEngine {
public:
    GraphicsEngine() { cout << "Graphics Engine initialized.\n"; }
    ~GraphicsEngine() { cout << "Graphics Engine destroyed.\n"; }
};

class InputHandler {
public:
    InputHandler() { cout << "Input Handler initialized.\n"; }
    ~InputHandler() { cout << "Input Handler destroyed.\n"; }
};

class PhysicsEngine {
public:
    PhysicsEngine() { cout << "Physics Engine initialized.\n"; }
    ~PhysicsEngine() { cout << "Physics Engine destroyed.\n"; }
};

class GameEngine {
private:
    GraphicsEngine graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    GameEngine() { cout << "Game Engine initialized.\n"; }
    ~GameEngine() { cout << "Game Engine destroyed.\n"; }
};

int main() {
    GameEngine game;
    return 0;
}
