#pragma once

class RenderObject
{
private:
	int leftUp;
	int rightUp;
	int leftDown;
	int rightDown;
	int color;
public:
	void Print();
	RenderObject();
	RenderObject(int leftUp, int rightUp, int leftDown, int rightDown, int color = 0);
	~RenderObject();
	void SetColor(int color);
	void SetState(int leftUp, int rightUp, int leftDown, int rightDown);
};