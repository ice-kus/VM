#include "iMath.h"
#include "Processor.h"

void iMath::set_flags(Processor& proc) noexcept
{
	(proc.stackGet_top().i32t == 0) ? proc.PSW.zf = 1 : proc.PSW.zf = 0;
	(proc.stackGet_top().i32t < 0) ? proc.PSW.sf = 1 : proc.PSW.sf = 0;
}

void iMath::operator()(Processor& proc) noexcept
{
	datatype tmp;
	tmp.i32t = calculate(proc.stackPop().i32t, proc.stackPop().i32t);
	proc.stackPush(tmp);
	set_flags(proc);
}