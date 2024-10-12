#include "Render.h"
#include "TColor.h"
Render::Render()
{
	for (int i = 0; i < MAP_SIZE_Y / TILE_SIZE_Y; i++)
	{
		vector<RenderObject> temp;
		for (int j = 0; j < MAP_SIZE_X / TILE_SIZE_X; j++)
		{
			RenderObject obj;
			temp.push_back(obj);
		}
		board.push_back(temp);
	}
}
Render::~Render()
{
}
void Render::PrintBoard(vector<vector<int>> v)
{
	for (int i = 0; i < v.size() / TILE_SIZE_Y; i++)
	{
		for (int j = 0; j < v[i].size() / TILE_SIZE_X; j++)
		{
			int lu = 0;
			int ru = 0;
			int ld = 0;
			int rd = 0;
			int color[COLOR_COUNT] = { 0, };
			for (int k = 0; k < TILE_SIZE_Y; k++)
			{
				for (int l = 0; l < TILE_SIZE_X; l++)
				{
					if (v[i * TILE_SIZE_Y + k][j * TILE_SIZE_X + l] >= 1)
					{
						if (k < TILE_SIZE_Y / 2)
						{
							if (l < TILE_SIZE_X / 2)
							{
								lu += 1;
							}
							else
							{
								ru += 1;
							}
						}
						else
						{
							if (l < TILE_SIZE_X / 2)
							{
								ld += 1;
							}
							else
							{
								rd += 1;
							}
						}
						color [v[i * TILE_SIZE_Y + k][j * TILE_SIZE_X + l] - 1] += 1;
					}
				}
			}
			int max = 0;
			int maxIndex = 0;
			for (int k = 0; k < COLOR_COUNT; k++)
			{
				if (color[k] > max)
				{
					max = color[k];
					maxIndex = k;
				}
			}
			board[i][j].SetState(lu,ru,ld,rd);
			board[i][j].SetColor(maxIndex);
			board[i][j].Print(j,i);
		}
		cout << "\n";
	}

}
