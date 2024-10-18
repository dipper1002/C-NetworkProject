#pragma once

class IntByte
{
public:
	static void IntToByte(unsigned int n, unsigned char* bytes);
	static void ByteToInt(unsigned char* bytes, unsigned int& n);
};