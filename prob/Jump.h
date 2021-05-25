#pragma once
#include "Command.h"

class Jump : public Command
{
	virtual void go_to(Processor& proc) noexcept = 0;
public:
	virtual void operator () (Processor& proc) noexcept override;
};

//Безусловный переход
class unconditional : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Условный переход с проверкой флага нулевого результата (не равно нулю)
class conditional_zf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Условный переход с проверкой инвертированного флага нулевого результата (равно нуля)
class conditional_nzf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Условный переход с проверкой флага отрицательного результата (больше нуля или равно нулю)
class conditional_sf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Условный переход с проверкой инвертированного флага нулевого результата (меньше нуля)
class conditional_nsf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Условный переход с проверкой флага отрицательного результата (больше нуля)
class conditional_sf_zf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Условный переход с проверкой инвертированного флага нулевого результата (меньше нуля или равно нулю)
class conditional_nsf_nzf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Переход к подпрограмме
class to_program : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Вовзврат из подпрограммы
class from_program : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//Выход из программы
class p_stop : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};