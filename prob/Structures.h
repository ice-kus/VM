#pragma once

#include <cinttypes>

#pragma pack(push,1)

using ui16 = uint16_t;
using ui8 = uint8_t;

struct ProgramStateWord
{
	ui16 IP : 16;
	ui16 SP : 4;
	ui16 sf : 1;
	ui16 zf : 1;
};

struct command_struct
{
	ui16 address : 16;
	ui16 cop : 7;
	ui16 b : 1;
};

union datatype
{
	ui16 addr;
	int32_t i32t;
	float ft;
	ui8 ui8t[4];
};

union registerAddress
{
	ui16 address;
	ui8 ui8t[2];
};

union com_24bit
{
	command_struct cmd;
	ui8 ui8t[3];
};

#pragma pack(pop)