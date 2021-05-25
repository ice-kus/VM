#pragma once

#include <vector>
#include "Command.h"
#include "Memory.h"

class Processor
{
	friend class Jump;
	friend class p_stop;

	enum op_code
	{
		//---------------������� ���������---------------
		stop = 0,
		//------------������� ����� ����������-----------
		intAdd = 1, //��������
		intSub = 2, //���������
		intMul = 3, //���������
		intDiv = 4, //�������
		//-----------������� ������� ����������----------
		floatAdd = 5, //��������
		floatSub = 6, //���������
		floatMul = 7, //���������
		floatDiv = 8, //�������
		//-------------������� ����� � ������------------
		in_int = 9, //���� ������ �����
		out_int = 10, //����� ������ �����
		in_float = 11, //���� �������� �����
		out_float = 12, //����� �������� �����
		//---------������ � �������� ���������-----------
		load_address = 13, //��������� �������� �������
		load_mmr_address = 14, //��������� �������� ������� �� ������
		save_address = 15, //��������� �������� �������
		add_address = 16, //C������� � �������� ��������
		sub_address = 17, //��������� � �������� ��������
		//--------------������ �� ������-----------------
		stack_push_cmd = 18, //�������� � ���� �� ������ �� �������
		stack_push = 19, //�������� � ���� �� ������ �� ��������� ��������
		stack_pop = 20, //���������� �� ����� �� ������ �� ��������� ��������
		stack_get_top = 21, //����������� �������� ����� �� ������ �� ��������� ��������
		//--------------������� ��������-----------------
		jump_unconditional = 22, //����������� �������
		jump_conditional_zf = 23, //�������� ������� � ��������� ����� �������� ���������� (�� ����� ����)
		jump_conditional_nzf = 24, //�������� ������� � ��������� ���������������� ����� �������� ���������� (����� ����)
		jump_conditional_sf = 25, //�������� ������� � ��������� ����� �������������� ���������� (������ ���� ��� ����� ����)
		jump_conditional_nsf = 26, //�������� ������� � ��������� ���������������� ����� �������������� ���������� (������ ����)
		jump_conditional_sf_zf = 27, //�������� ������� � ��������� ������ �������� � �������������� ���������� (������ ����)
		jump_conditional_nsf_nzf = 28, //�������� ������� � ��������� ��������������� ������ �������� � �������������� ���������� (������ ���� ��� ����� ����)
		jump_toProgram = 29, //������� � ������������
		jump_fromProgram = 30, //�������� �� ������������
	};
	com_24bit cmd;
	class Command* com[128];
	int stack_size;
	std::vector <datatype> stack; //�������� � ������
	ui16 IF; // ���������� ���������� ���������
	ui16 jf; // �������
public:

	Memory mmr;
	ProgramStateWord PSW;
	ui16 regAddress;

	Processor();
	Processor(Processor&) = delete;
	Processor operator = (Processor&) = delete;
	Processor operator = (Processor&&) = delete;

	ui8 get_cmd_cop() const noexcept { return cmd.cmd.cop; }
	ui8 get_cmd_b() const noexcept { return cmd.cmd.b; }
	ui8 get_cmd_address() const noexcept { return cmd.cmd.address; }

	void stackPush(const datatype& num) noexcept;
	datatype stackPop() noexcept;
	datatype stackGet_top() const noexcept;

	void set_jf(const ui16& change) noexcept { jf = change; };

	void loadCommand() noexcept { cmd = mmr.get_cmd(PSW.IP); }
	void reset() noexcept 
	{ 
		PSW.IP = PSW.sf = PSW.zf = IF = jf = 0; 
		regAddress = 0;
		cmd.cmd.address = cmd.cmd.b = cmd.cmd.cop = 0;
	}
	void run() noexcept;
};
