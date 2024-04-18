#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Players {
private:
    Texture Player1, Player2;
public:

    RectangleShape player1, player2;
    Vector2f moveRec, moveRec2;

    Players() : player1(Vector2f(150, 150)), player2(Vector2f(150, 150)) {
        Player1.loadFromFile("Image/player1.png");
        player1.setTexture(&Player1);
        player1.setPosition(Vector2f(0, 220));

        Player2.loadFromFile("Image/player2.png");
        player2.setTexture(&Player2);
        player2.setPosition(Vector2f(1130, 220));
    }

    void players_keys(Vector2f& moveRec, Vector2f& moveRec2, Event& event);
    void player1move(RectangleShape& player1, Vector2f& moveRec);
    void player2move(RectangleShape& player2, Vector2f& moveRec2);
};
