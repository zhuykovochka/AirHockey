#pragma once
#include <SFML/Graphics.hpp>
#include "players.h"
#include "puck.h"
#include "score.h"

using namespace sf;
using namespace std;

enum class GameState
{
	Menu,
	Game,
	Blue_Wins,
	Red_Wins
};

class Game_Workspace {
private:
    Texture Table, Menu, Goal1, Goal2;
public:
    RectangleShape gamingBackground, background, left_goal, right_goal;
    Font font;
    Text Title, Prompt, Red_wins, Blue_wins, play_again;
    Music gameMusic, goal, click, button_click, gameover, again;

    Game_Workspace() {

        // Load Table texture and set up gaming background
        Table.loadFromFile("Image/table.png");
        gamingBackground.setSize(Vector2f(1280, 580));
        gamingBackground.setTexture(&Table);
        gamingBackground.setPosition(Vector2f(0, 0));
        // Load Menu texture and set up menu background
        Menu.loadFromFile("Image/menu.jpg");
        background.setSize(Vector2f(1280, 580));
        background.setTexture(&Menu);
        background.setPosition(Vector2f(0, 0));

        // Load the font
        font.loadFromFile("font/font.TTF");

        // Setup Title
        Title.setFont(font);
        Title.setString("Air Hockey Game!");
        Title.setCharacterSize(84);
        Title.setFillColor(Color::Green);
        Title.setStyle(Text::Bold);
        Title.setPosition(Vector2f(100, 100));

        // Setup Prompt
        Prompt.setFont(font);
        Prompt.setString("Press ENTER to begin playing!");
        Prompt.setCharacterSize(50);
        Prompt.setFillColor(Color::Yellow);
        Prompt.setStyle(Text::Bold);
        Prompt.setPosition(Vector2f(45, 300));

        // Setup Red Wins Text
        Red_wins.setFont(font);
        Red_wins.setString("Red Wins!");
        Red_wins.setCharacterSize(84);
        Red_wins.setFillColor(Color::Red);
        Red_wins.setStyle(Text::Bold);
        Red_wins.setPosition(Vector2f(330, 100));
        // Setup Blue Wins Text
        Blue_wins.setFont(font);
        Blue_wins.setString("Blue Wins!");
        Blue_wins.setCharacterSize(84);
        Blue_wins.setFillColor(Color::Blue);
        Blue_wins.setStyle(Text::Bold);
        Blue_wins.setPosition(Vector2f(330, 100));

        // Setup Play Again Text
        play_again.setFont(font);
        play_again.setString("Press SPACE to play again!");
        play_again.setCharacterSize(50);
        play_again.setFillColor(Color::Black);
        play_again.setStyle(Text::Bold);
        play_again.setPosition(Vector2f(100, 300));

        // Setup Goals
        Goal1.loadFromFile("Image/blue_goal.png");
        left_goal.setSize(Vector2f(30, 240));
        left_goal.setTexture(&Goal1);
        left_goal.setPosition(0, 170);
        Goal2.loadFromFile("Image/red_goal.png");
        right_goal.setSize(Vector2f(30, 240));
        right_goal.setTexture(&Goal2);
        right_goal.setPosition(1250, 170);

        //Load music
        gameMusic.openFromFile("sound/menu.mp3");  //menu opening
        gameMusic.setVolume(40);
        goal.openFromFile("sound/goal.wav");
        goal.setVolume(20);
        click.openFromFile("sound/pop.wav"); //pop
        click.setVolume(20);
        button_click.openFromFile("sound/button_click.mp3"); //from menu to game
        button_click.setVolume(20);
        gameover.openFromFile("sound/gameover.wav");
        gameover.setVolume(20);
        again.openFromFile("sound/again.mp3"); //returning to game
        again.setVolume(30);
    }
    void startGame(GameState& state, RenderWindow& win, Text& Title, Text& Prompt, Text& score, int& score1, int& score2, RectangleShape& left_goal, RectangleShape& right_goal, float& y_puck, float& x_puck,
        RectangleShape& puck, Vector2f& moveRec2, Vector2f& moveRec, RectangleShape& player1, RectangleShape& player2, RectangleShape& background, Text& Red_wins, Text& Blue_wins,
        Text& play_again, RectangleShape& gamingBackground, bool& puck_been_hit, Music& goal, Music& button_click, Music& gameove, Music& again, Music& click);
};
