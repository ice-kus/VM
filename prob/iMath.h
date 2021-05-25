#pragma once
#include "Command.h"

class iMath : public Command
{
	void set_flags(Processor& proc) noexcept;
	virtual int32_t calculate(const int32_t& left, const int32_t& right) noexcept = 0;
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Сложение
class iAdd : public iMath
{
	virtual int32_t calculate(const int32_t& left, const int32_t& right) noexcept override { return left + right; }
};

//Вычитание
class iSub : public iMath
{
	virtual int32_t calculate(const int32_t& left, const int32_t& right) noexcept override { return left - right; }
};

//Умножение
class iMul : public iMath
{
	virtual int32_t calculate(const int32_t& left, const int32_t& right) noexcept override { return left * right; }
};

//Деление
class iDiv : public iMath
{
	virtual int32_t calculate(const int32_t& left, const int32_t& right) noexcept override { return left / right; }
};
