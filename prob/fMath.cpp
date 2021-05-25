#include "fMath.h"
#include "Processor.h"

void fMath::set_flags(Processor& proc) noexcept
{
	(proc.stackGet_top().ft == 0) ? proc.PSW.zf = 1 : proc.PSW.zf = 0;
	(proc.stackGet_top().ft < 0) ? proc.PSW.sf = 1 : proc.PSW.sf = 0;
}

void fMath::operator()(Processor& proc) noexcept
{
	datatype tmp;
	tmp.ft = calculate(proc.stackPop().ft, proc.stackPop().ft);
	proc.stackPush(tmp);
	set_flags(proc);
}