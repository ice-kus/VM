#include "WorkAddress.h"
#include "Processor.h"

void l_address::operator()(Processor& proc) noexcept
{
	switch (proc.get_cmd_b())
	{
	case 0:
		proc.regAddress = proc.get_cmd_address();
		break;
	case 1:
		proc.regAddress += proc.get_cmd_address();
		break;
	}
}

void l_mmr_address::operator()(Processor& proc) noexcept
{
	switch (proc.get_cmd_b())
	{
	case 0:
		proc.regAddress = proc.mmr.get_num(proc.get_cmd_address()).addr;
		break;
	case 1:
		proc.regAddress += proc.mmr.get_num(proc.get_cmd_address()).addr;
		break;
	}
}

void s_address::operator()(Processor& proc) noexcept
{
	registerAddress tmp;
	tmp.address = proc.regAddress;
	proc.mmr.push_memory(tmp, proc.get_cmd_address());
}

void add_addr::operator()(Processor& proc) noexcept
{
	proc.regAddress += proc.get_cmd_address();
}

void sub_addr::operator()(Processor& proc) noexcept
{
	proc.regAddress -= proc.get_cmd_address();
}
