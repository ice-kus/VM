#pragma once
#include "Command.h"
#include <iostream>

//Ввод целого числа
class in_i : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Ввод дробного числа
class in_f : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Вывод целого числа
class out_i : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Вывод дробного числа
class out_f : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

