#include "OtherPlayer.h"

OtherPlayer::OtherPlayer()
{
	otherPlayer.push_back(make_pair(-300, 0));
	otherPlayer.push_back(make_pair(-300, 0));
	otherPlayer.push_back(make_pair(-300, 0));
	otherPlayer.push_back(make_pair(-300, 0));
	otherPlayer.push_back(make_pair(-300, 0));
}
OtherPlayer::~OtherPlayer()
{
}
void OtherPlayer::AddPlayer(int x, int y)
{
	otherPlayer.push_back(make_pair(x, y));
}
void OtherPlayer::UpdatePlayer(int id, int x, int y)
{
	otherPlayer[id].first = x;
	otherPlayer[id].second = y;
}
void OtherPlayer::PrintPlayer(Board& board)
{
	for (int i = 0; i < otherPlayer.size(); i++)
	{
		board.PaintCircle(otherPlayer[i].first, otherPlayer[i].second, 30, 2);
	}
}