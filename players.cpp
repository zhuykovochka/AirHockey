#include "players.h"

void Players::players_keys(Vector2f& moveRec, Vector2f& moveRec2, Event& event)
{
    //Player1 Control (keys)
    switch (event.type)
    {
    case Event::KeyPressed:
        if (event.key.code == Keyboard::S) moveRec.y = 0.7;
        if (event.key.code == Keyboard::W) moveRec.y = -0.7;
        if (event.key.code == Keyboard::A) moveRec.x = -0.7;
        if (event.key.code == Keyboard::D) moveRec.x = 0.7;
        break;
    case Event::KeyReleased:
        if (event.key.code == Keyboard::S) moveRec.y = 0;
        if (event.key.code == Keyboard::W) moveRec.y = 0;
        if (event.key.code == Keyboard::A) moveRec.x = 0;
        if (event.key.code == Keyboard::D) moveRec.x = 0;
        break;
    }
    //Player2 Control (keys)
    switch (event.type)
    {
    case Event::KeyPressed:
        if (event.key.code == Keyboard::Down) moveRec2.y = 0.7;
        if (event.key.code == Keyboard::Up) moveRec2.y = -0.7;
        if (event.key.code == Keyboard::Left) moveRec2.x = -0.7;
        if (event.key.code == Keyboard::Right) moveRec2.x = 0.7;
        break;
    case Event::KeyReleased:
        if (event.key.code == Keyboard::Down) moveRec2.y = 0;
        if (event.key.code == Keyboard::Up) moveRec2.y = 0;
        if (event.key.code == Keyboard::Left) moveRec2.x = 0;
        if (event.key.code == Keyboard::Right) moveRec2.x = 0;
        break;
    default:
        break;
    }
}

void Players::player1move(RectangleShape& player1, Vector2f& moveRec)
{
    //Player1 Control (frames)
    player1.move(moveRec);
    Vector2f pos = player1.getPosition();
    if (pos.x > 487) player1.setPosition(487, pos.y);
    if (pos.x < 0) player1.setPosition(0, pos.y);
    if (pos.y > 430) player1.setPosition(pos.x, 430);
    if (pos.y < 0) player1.setPosition(pos.x, 0);

    if ((pos.x > 487) && (pos.y < 0)) player1.setPosition(487, 0);
    if ((pos.x > 487) && (pos.y > 430)) player1.setPosition(487, 430);
    if ((pos.x < 0) && (pos.y < 0)) player1.setPosition(0, 0);
    if ((pos.x < 0) && (pos.y > 430)) player1.setPosition(0, 430);
}

void Players::player2move(RectangleShape& player2, Vector2f& moveRec2)
{
    //Player2 Control (frames)
    player2.move(moveRec2);
    Vector2f pos2 = player2.getPosition();
    if (pos2.x > 1130) player2.setPosition(1130, pos2.y);
    if (pos2.x < 660) player2.setPosition(660, pos2.y);
    if (pos2.y > 430) player2.setPosition(pos2.x, 430);
    if (pos2.y < 0) player2.setPosition(pos2.x, 0);

    if ((pos2.x > 1130) && (pos2.y < 0)) player2.setPosition(1130, 0);
    if ((pos2.x > 1130) && (pos2.y > 430)) player2.setPosition(1130, 430);
    if ((pos2.x < 660) && (pos2.y < 0)) player2.setPosition(660, 0);
    if ((pos2.x < 660) && (pos2.y > 430)) player2.setPosition(660, 430);
}
