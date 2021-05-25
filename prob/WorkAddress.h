#pragma once
#include "Command.h"

//��������� �������� �������
class l_address : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//��������� �������� ������� �� ������
class l_mmr_address : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//��������� �������� �������
class s_address : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//C������� � �������� ��������
class add_addr : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//��������� � �������� ��������
class sub_addr : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};
