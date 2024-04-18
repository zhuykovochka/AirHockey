#include "game_workspace.h"

int main()
{
    RenderWindow win(VideoMode(1280, 580), "Air Hockey Game.");

    Image icon;
    icon.loadFromFile("Image/icon.png");
    win.setIcon(32, 32, icon.getPixelsPtr());

    Game_Workspace game;

    Score score(game.font);

    GameState state = GameState::Menu;
    game.gameMusic.play();

    Players player;
    Puck puck;

    while (win.isOpen())
    {
        Event event;
        while (win.pollEvent(event))
        {
            if ((event.type == Event::Closed) || Keyboard::isKeyPressed(Keyboard::Escape))
                win.close();
            player.players_keys(player.moveRec, player.moveRec2, event);
        }
        game.startGame(state, win, game.Title, game.Prompt, score.score, score.score1, score.score2, game.left_goal, game.right_goal, puck.y_puck, puck.x_puck,
            puck.puck, player.moveRec2, player.moveRec, player.player1, player.player2, game.background, game.Red_wins, game.Blue_wins,
            game.play_again, game.gamingBackground, puck.puck_been_hit, game.goal, game.button_click, game.gameover, game.again, game.click);
    }
    return 0;
}