#pragma once
#include "Command.h"

class fMath : public Command
{
	void set_flags(Processor& proc) noexcept;
	virtual float calculate(const float& left, const float& right) noexcept = 0;
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Сложение
class fAdd : public fMath
{
	virtual float calculate(const float& left, const float& right) noexcept override { return left + right; }
};

//Вычитание
class fSub : public fMath
{
	virtual float calculate(const float& left, const float& right) noexcept override { return left - right; }
};

//Умножение
class fMul : public fMath
{
	virtual float calculate(const float& left, const float& right) noexcept override { return left * right; }
};

//Деление
class fDiv : public fMath
{
	virtual float calculate(const float& left, const float& right) noexcept override { return left / right; }
};