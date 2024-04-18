#pragma once
#include <SFML/Graphics.hpp>
#include "game_workspace.h"

using namespace sf;

class Score {
public:
    int score1;
    int score2;
    Text score;
    Score(Font& font) : score1(0), score2(0) {
        score.setFont(font);
        score.setCharacterSize(100);
        score.setFillColor(Color::Magenta);
        score.setStyle(Text::Bold);
        score.setPosition(Vector2f(536, 20));
    }
    void update_score(Text& score, int& score1, int& score2);
};