#pragma once
#include "Command.h"
#include <iostream>

//���� ������ �����
class in_i : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//���� �������� �����
class in_f : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//����� ������ �����
class out_i : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//����� �������� �����
class out_f : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

