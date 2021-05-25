#include "Memory.h"

void Memory::push_memory(const com_24bit& cmd, const ui16& address) noexcept
{
	memory[address] = cmd.ui8t[0];
	memory[address + 1] = cmd.ui8t[1];
	memory[address + 2] = cmd.ui8t[2];
}

void Memory::push_memory(const datatype& num, const ui16& address) noexcept
{
	memory[address] = num.ui8t[0];
	memory[address + 1] = num.ui8t[1];
	memory[address + 2] = num.ui8t[2];
	memory[address + 3] = num.ui8t[3];
}

void Memory::push_memory(const registerAddress& regAddress, const ui16& address) noexcept
{
	memory[address] = regAddress.ui8t[0];
	memory[address + 1] = regAddress.ui8t[1];
	memory[address + 2] = regAddress.ui8t[2];
	memory[address + 3] = regAddress.ui8t[3];
}

datatype Memory::get_num(const ui16& address) const noexcept
{
	datatype tmp;
	tmp.ui8t[0] = memory[address];
	tmp.ui8t[1] = memory[address + 1];
	tmp.ui8t[2] = memory[address + 2];
	tmp.ui8t[3] = memory[address + 3];
	return tmp;
}

com_24bit Memory::get_cmd(const ui16& address) const noexcept
{
	com_24bit tmp;
	tmp.ui8t[0] = memory[address];
	tmp.ui8t[1] = memory[address + 1];
	tmp.ui8t[2] = memory[address + 2];
	return tmp;
}