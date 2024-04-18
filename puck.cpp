#include "puck.h"

void Puck::puck_moves(RectangleShape& puck, bool& puck_been_hit, float& x_puck, float& y_puck)
{
    //Puck moves
    if (!puck_been_hit) puck.move(x_puck * 0.125f, y_puck * 0.125f);
    else puck.move(x_puck, y_puck);
    if (puck.getPosition().y <= 20) y_puck = 1.0f;
    else if (puck.getPosition().y >= height - 20 - puck.getSize().y) y_puck = -1.0f;
    else if (puck.getPosition().x <= 20) x_puck = 1.0f;
    else if (puck.getPosition().x >= width - 20 - puck.getSize().x) x_puck = -1.0f;
}

void Puck::puck_frames(RectangleShape& puck, RectangleShape& player1, RectangleShape& player2, bool& puck_been_hit, float& x_puck, float& y_puck, Music& click)
{
    // Puck hits blue right side
    if (puck.getPosition().x - (player1.getPosition().x + player1.getSize().x) <= 0
        && puck.getPosition().x - (player1.getPosition().x + player1.getSize().x) >= -8
        && puck.getPosition().y <= player1.getPosition().y + player1.getSize().y
        && puck.getPosition().y >= player1.getPosition().y - puck.getSize().y)
    {
        click.play();
        x_puck = 1.0f;
        puck_been_hit = true;
    }
    // Puck hits blue left side
    if (puck.getPosition().x + puck.getSize().x - player1.getPosition().x >= 0
        && puck.getPosition().x + puck.getSize().x - player1.getPosition().x <= 8
        && puck.getPosition().y <= player1.getPosition().y + player1.getSize().y
        && puck.getPosition().y >= player1.getPosition().y - puck.getSize().y)
    {
        click.play();
        x_puck = -1.0f;
        puck_been_hit = true;
    }
    // Puck hits blue top side
    // formula: puck.getPosition().y + puck.getSize().y == player1.getPosition().y
    if (puck.getPosition().y + puck.getSize().y - player1.getPosition().y >= 0
        && puck.getPosition().y + puck.getSize().y - player1.getPosition().y <= 8
        && puck.getPosition().x <= player1.getPosition().x + player1.getSize().x
        && puck.getPosition().x >= player1.getPosition().x - puck.getSize().x)
    {
        click.play();
        y_puck = -1.0f;
        puck_been_hit = true;
    }
    // Puck hits blue bottom side  
    // formula: puck.getPosition().y == player1.getPosition().y + player1.getSize().y
    if (puck.getPosition().y - (player1.getPosition().y + player1.getSize().y) >= 0
        && puck.getPosition().y - (player1.getPosition().y + player1.getSize().y) <= 8
        && puck.getPosition().x <= player1.getPosition().x + player1.getSize().x
        && puck.getPosition().x >= player1.getPosition().x - puck.getSize().x)
    {
        click.play();
        y_puck = 1.0f;
        puck_been_hit = true;
    }
    // Puck hits red right side  
    if (puck.getPosition().x - (player2.getPosition().x + player2.getSize().x) <= 0
        && puck.getPosition().x - (player2.getPosition().x + player2.getSize().x) >= -8
        && puck.getPosition().y <= player2.getPosition().y + player2.getSize().y
        && puck.getPosition().y >= player2.getPosition().y - puck.getSize().y)
    {
        click.play();
        x_puck = 1.0f;
        puck_been_hit = true;
    }
    // Puck hits red left side  
    if (puck.getPosition().x + puck.getSize().x - player2.getPosition().x >= 0
        && puck.getPosition().x + puck.getSize().x - player2.getPosition().x <= 8
        && puck.getPosition().y <= player2.getPosition().y + player2.getSize().y
        && puck.getPosition().y >= player2.getPosition().y - puck.getSize().y)
    {
        click.play();
        x_puck = -1.0f;
        puck_been_hit = true;
    }
    // Puck hits red top side  
    if (puck.getPosition().y + puck.getSize().y - player2.getPosition().y >= 0
        && puck.getPosition().y + puck.getSize().y - player2.getPosition().y <= 8
        && puck.getPosition().x <= player2.getPosition().x + player2.getSize().x
        && puck.getPosition().x >= player2.getPosition().x - puck.getSize().x)
    {
        click.play();
        y_puck = -1.0f;
        puck_been_hit = true;
    }
    // Puck hits red bottom side  
    if (puck.getPosition().y - (player2.getPosition().y + player2.getSize().y) >= 0
        && puck.getPosition().y - (player2.getPosition().y + player2.getSize().y) <= 8
        && puck.getPosition().x <= player2.getPosition().x + player2.getSize().x
        && puck.getPosition().x >= player2.getPosition().x - puck.getSize().x)
    {
        click.play();
        y_puck = 1.0f;
        puck_been_hit = true;
    }
}