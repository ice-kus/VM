#include "Jump.h"
#include "Processor.h"

void Jump::operator()(Processor& proc) noexcept
{
	proc.jf = 1;
	ui16 sIP = proc.PSW.IP;
	go_to(proc);
	if (proc.PSW.IP == sIP)
		proc.jf = 0;
}

void body_go_to(Processor& proc) noexcept
{
	if (proc.get_cmd_address() == 0) { proc.PSW.IP = proc.regAddress; }
	else
		switch (proc.get_cmd_b())
		{
		case 0:
			proc.PSW.IP = proc.get_cmd_address();
			break;
		case 1:
			proc.PSW.IP = proc.regAddress + proc.get_cmd_address();
			break;
		}
}

void unconditional::go_to(Processor& proc) noexcept { body_go_to(proc); }

void conditional_sf::go_to(Processor& proc) noexcept { if (proc.PSW.sf == 0) body_go_to(proc);}

void conditional_nsf::go_to(Processor& proc) noexcept { if (proc.PSW.sf == 1) body_go_to(proc); }

void conditional_zf::go_to(Processor& proc) noexcept { if (proc.PSW.zf == 0) body_go_to(proc); }

void conditional_nzf::go_to(Processor& proc) noexcept { if (proc.PSW.zf == 1) body_go_to(proc); }

void conditional_sf_zf::go_to(Processor& proc) noexcept { if (proc.PSW.zf == 0 || proc.PSW.sf == 0) body_go_to(proc); }

void conditional_nsf_nzf::go_to(Processor& proc) noexcept { if (proc.PSW.zf == 1 || proc.PSW.sf == 1) body_go_to(proc); }

void to_program::go_to(Processor& proc) noexcept
{
	proc.regAddress = proc.PSW.IP + 3;
	body_go_to(proc);
}

void from_program::go_to(Processor& proc) noexcept { proc.PSW.IP = proc.regAddress; }

void p_stop::operator()(Processor& proc) noexcept { proc.IF = 1; }