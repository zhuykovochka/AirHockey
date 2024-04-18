#include "game_workspace.h"

Players player;
Game_Workspace game;
Score gamescore(game.font);
Puck gamePuck;

void Game_Workspace::startGame(GameState& state, RenderWindow& win, Text& Title, Text& Prompt, Text& score, int& score1, int& score2, RectangleShape& left_goal, RectangleShape& right_goal, float& y_puck, float& x_puck,
    RectangleShape& puck, Vector2f& moveRec2, Vector2f& moveRec, RectangleShape& player1, RectangleShape& player2, RectangleShape& background, Text& Red_wins, Text& Blue_wins,
    Text& play_again, RectangleShape& gamingBackground, bool& puck_been_hit, Music& goal, Music& button_click, Music& gameover, Music& again, Music& click)
{

    switch (state)
    {
    case GameState::Menu:
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            button_click.play();
            state = GameState::Game;
            win.setTitle("GO!");
        }
        win.clear();
        win.draw(background);
        win.draw(Title);
        win.draw(Prompt);
        win.display();
        break;

    case GameState::Game:

        win.clear();

        // Puck hits Player2's Goal
        if (puck.getPosition().x + puck.getSize().x >= right_goal.getPosition().x
            && puck.getPosition().y >= right_goal.getPosition().y
            && puck.getPosition().y + puck.getSize().y <= right_goal.getPosition().y + right_goal.getSize().y)
        {
            if (score1 == 4)
            {
                state = GameState::Blue_Wins;
                gameover.play();
                win.setTitle("BLUE WINS");
            }
            goal.play();
            puck.setPosition(Vector2f(600, 240));
            player1.setPosition(Vector2f(0, 220));
            player2.setPosition(Vector2f(1130, 220));
            puck_been_hit = false;
            score1++;
            gamescore.update_score(score, score1, score2);
            win.draw(score);
            win.display();
        }
        // Puck hits Player1's goal
        if (puck.getPosition().x <= left_goal.getPosition().x + left_goal.getSize().x
            && puck.getPosition().y >= left_goal.getPosition().y
            && puck.getPosition().y + puck.getSize().y <= left_goal.getPosition().y + left_goal.getSize().y)
        {
            if (score2 == 4)
            {
                state = GameState::Red_Wins;
                gameover.play();
                win.setTitle("RED WINS");
            }
            goal.play();
            puck.setPosition(Vector2f(600, 240));
            player1.setPosition(Vector2f(0, 220));
            player2.setPosition(Vector2f(1130, 220));
            puck_been_hit = false;
            score2++;
            gamescore.update_score(score, score1, score2);
            win.draw(score);
            win.display();
        }

        gamePuck.puck_moves(puck, puck_been_hit, x_puck, y_puck);
        gamePuck.puck_frames(puck, player1, player2, puck_been_hit, x_puck, y_puck, click);

        player.player1move(player1, moveRec);
        player.player2move(player2, moveRec2);

        win.draw(gamingBackground);
        win.draw(left_goal);
        win.draw(right_goal);
        win.draw(player1);
        win.draw(player2);
        win.draw(puck);
        gamescore.update_score(score, score1, score2);
        win.draw(score);
        win.display();
        break;

    case GameState::Blue_Wins:
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            again.play();
            state = GameState::Game;
            win.setTitle("GO!");
        }
        win.clear();
        puck_been_hit = false;
        score1 = 0;
        score2 = 0;
        puck.setPosition(Vector2f(600, 240));
        player1.setPosition(Vector2f(0, 220));
        player2.setPosition(Vector2f(1130, 220));
        win.draw(background);
        play_again.setFillColor(Color::Yellow);
        win.draw(Blue_wins);
        win.draw(play_again);
        win.display();
        break;
    case GameState::Red_Wins:
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            again.play();
            state = GameState::Game;
            win.setTitle("GO!");
        }
        win.clear();
        puck_been_hit = false;
        score1 = 0;
        score2 = 0;
        puck.setPosition(Vector2f(600, 240));
        player1.setPosition(Vector2f(0, 220));
        player2.setPosition(Vector2f(1130, 220));
        win.draw(background);
        play_again.setFillColor(Color::Yellow);
        win.draw(Red_wins);
        win.draw(play_again);
        win.display();
        break;
    default:
        break;
    }
}
