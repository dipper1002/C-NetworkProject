#include "IntByte.h"

void IntByte::IntToByte(unsigned int n, unsigned char* bytes)
{
	bytes[0] = (n >> 24) & 0xFF;
	bytes[1] = (n >> 16) & 0xFF;
	bytes[2] = (n >> 8) & 0xFF;
	bytes[3] = n & 0xFF;
	bytes[4] = '\0';
}
void IntByte::ByteToInt(unsigned char* bytes, unsigned int& n)
{
	n = (bytes[0] & 0xFF) << 24 | (bytes[1] & 0xFF) << 16 | (bytes[2] & 0xFF) << 8 | (bytes[3] & 0xFF);
}