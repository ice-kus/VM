#pragma once
#include "Command.h"

//�������� � ���� �� ������ �� �������
class s_push_cmd : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//�������� � ���� �� ������ �� ��������� ��������
class s_push : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//���������� �� ����� �� ������ �� ��������� ��������
class s_pop : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//����������� ������� ����� �� ������ �� ��������� ��������
class s_get_top : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};