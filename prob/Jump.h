#pragma once
#include "Command.h"

class Jump : public Command
{
	virtual void go_to(Processor& proc) noexcept = 0;
public:
	virtual void operator () (Processor& proc) noexcept override;
};

//����������� �������
class unconditional : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� ������� � ��������� ����� �������� ���������� (�� ����� ����)
class conditional_zf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� ������� � ��������� ���������������� ����� �������� ���������� (����� ����)
class conditional_nzf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� ������� � ��������� ����� �������������� ���������� (������ ���� ��� ����� ����)
class conditional_sf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� ������� � ��������� ���������������� ����� �������� ���������� (������ ����)
class conditional_nsf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� ������� � ��������� ����� �������������� ���������� (������ ����)
class conditional_sf_zf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� ������� � ��������� ���������������� ����� �������� ���������� (������ ���� ��� ����� ����)
class conditional_nsf_nzf : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//������� � ������������
class to_program : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//�������� �� ������������
class from_program : public Jump
{
	virtual void go_to(Processor& proc) noexcept override;
};

//����� �� ���������
class p_stop : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};