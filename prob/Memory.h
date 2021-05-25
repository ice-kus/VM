#pragma once

#include "Structures.h"

class Memory
{
	uint8_t *memory;
public:
	Memory() { memory = new ui8[65536]; }
	~Memory() { delete[] memory; }
	void push_memory(const com_24bit& cmd, const ui16& address) noexcept;
	void push_memory(const datatype& num, const ui16& address) noexcept;
	void push_memory(const registerAddress& regAddress, const ui16& address) noexcept;

	datatype get_num(const ui16& address) const noexcept;
	com_24bit get_cmd(const ui16& address) const noexcept;
};

