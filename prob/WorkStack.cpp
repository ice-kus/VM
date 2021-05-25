#include "WorkStack.h"
#include "Processor.h"

void s_push_cmd::operator()(Processor& proc) noexcept
{
	proc.stackPush((proc.mmr.get_num(proc.get_cmd_address())));
}

void s_push::operator()(Processor& proc) noexcept
{
	proc.stackPush(proc.mmr.get_num(proc.regAddress));
}

void s_pop::operator()(Processor& proc) noexcept
{
	proc.mmr.push_memory(proc.stackPop(), proc.regAddress);
}

void s_get_top::operator()(Processor& proc) noexcept
{
	proc.mmr.push_memory(proc.stackGet_top(), proc.regAddress);
}