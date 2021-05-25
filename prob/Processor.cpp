#include "Processor.h"
#include "iMath.h"
#include "fMath.h"
#include "InOut.h"
#include "WorkAddress.h"
#include "WorkStack.h"
#include "Jump.h"

Processor::Processor()
{
	stack_size = 16;
	stack.resize(stack_size);
	PSW.IP = PSW.sf = PSW.zf = IF = jf = 0;
	regAddress = 0;
	cmd.cmd.address = cmd.cmd.b = cmd.cmd.cop = 0;

	com[stop] = new p_stop();

	com[intAdd] = new iAdd();
	com[intSub] = new iSub();
	com[intMul] = new iMul();
	com[intDiv] = new iDiv();

	com[floatAdd] = new fAdd();
	com[floatSub] = new fSub();
	com[floatMul] = new fMul();
	com[floatDiv] = new fDiv();

	com[in_int] = new in_i();
	com[out_int] = new out_i();
	com[in_float] = new in_f();
	com[out_float] = new out_f();

	com[load_address] = new l_address();
	com[load_mmr_address] = new l_mmr_address();
	com[save_address] = new s_address();
	com[add_address] = new add_addr();
	com[sub_address] = new sub_addr();

	com[stack_push_cmd] = new s_push_cmd();
	com[stack_push] = new s_push();
	com[stack_pop] = new s_pop();
	com[stack_get_top] = new s_get_top();

	com[jump_unconditional] = new unconditional();
	com[jump_conditional_zf] = new conditional_zf();
	com[jump_conditional_nzf] = new conditional_nzf();
	com[jump_conditional_sf] = new conditional_sf();
	com[jump_conditional_nsf] = new conditional_nsf();
	com[jump_conditional_sf_zf] = new conditional_sf_zf();
	com[jump_conditional_nsf_nzf] = new conditional_nsf_nzf();
	com[jump_toProgram] = new to_program();
	com[jump_fromProgram] = new from_program();
 }


void Processor::stackPush(const datatype& num) noexcept
{
	if (PSW.SP == stack_size-1)
		PSW.SP =- 1;
	PSW.SP++;
	stack[PSW.SP] = num;
}

datatype Processor::stackPop() noexcept
{
	datatype tmp;
	tmp = stack[PSW.SP];
	if (PSW.SP == 0)
		PSW.SP = 16;
	stack[PSW.SP].i32t = 0;
	PSW.SP--;
	return tmp;
}

datatype Processor::stackGet_top() const noexcept
{
	return stack[PSW.SP];
}

void Processor::run() noexcept
{
	loadCommand();
	while (IF != 1)
	{
		com[cmd.cmd.cop] -> operator()(*this);
		if (jf != 1) PSW.IP += 3;
		else jf = 0;
		loadCommand();
	}
	system("pause");
}