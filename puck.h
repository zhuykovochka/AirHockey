#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Puck {
private:
    Texture gamePuck;
    unsigned int width = 1280;
    unsigned int height = 580;
public:
    RectangleShape puck;
    bool puck_been_hit;
    float y_puck, x_puck;

    Puck() : puck(Vector2f(100, 100)) {
        gamePuck.loadFromFile("Image/puck.png");
        puck.setTexture(&gamePuck);
        puck.setPosition(Vector2f(600, 240));
        puck_been_hit = false;
        srand(time(NULL));
        x_puck = rand() % 2 == 1 ? 1.f : -1.f;
        y_puck = rand() % 2 == 1 ? 1.f : -1.f;
    }
    void puck_moves(RectangleShape& puck, bool& puck_been_hit, float& x_puck, float& y_puck);
    void puck_frames(RectangleShape& puck, RectangleShape& player1, RectangleShape& player2, bool& puck_been_hit,
        float& x_puck, float& y_puck, Music& click);
};
