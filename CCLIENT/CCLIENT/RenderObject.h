#pragma once

class RenderObject
{
private:
	int leftUp;
	int rightUp;
	int leftDown;
	int rightDown;
	int color;
	char table[4][4] = { {' ', '\'', ',', '/'},
						{'.', '(', '_', 'd'},
						{'`', '^', 'l', 'r'},
						{'\\', 'q', 'b', 'B'} };

public:
	void Print(int x,int y);
	RenderObject();
	RenderObject(int leftUp, int rightUp, int leftDown, int rightDown, int color = 0);
	~RenderObject();
	void SetColor(int color);
	void SetState(int leftUp, int rightUp, int leftDown, int rightDown);
};