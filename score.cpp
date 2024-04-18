#include "score.h"

void Score::update_score(Text& score, int& score1, int& score2)
{
	score.setString(to_string(score1) + ":" + to_string(score2));
}
