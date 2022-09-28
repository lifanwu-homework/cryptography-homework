#pragma once

class bits_array {
public:
	bits_array()
	{
		Bits = nullptr;
	}
	bits_array(int size)
	{
		Bits = (char*)malloc(size / 8 + 1);
	}




private:
	char* Bits;
};
