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
		//---------------Команда остановки---------------
		stop = 0,
		//------------Команды целой арифметики-----------
		intAdd = 1, //Сложение
		intSub = 2, //Вычитание
		intMul = 3, //Умножение
		intDiv = 4, //Деление
		//-----------Команды дробной арифметики----------
		floatAdd = 5, //Сложение
		floatSub = 6, //Вычитание
		floatMul = 7, //Умножение
		floatDiv = 8, //Деление
		//-------------Команды ввода и вывода------------
		in_int = 9, //Ввод целого числа
		out_int = 10, //Вывод целого числа
		in_float = 11, //Ввод дробного числа
		out_float = 12, //Вывод дробного числа
		//---------Работа с адресным регистром-----------
		load_address = 13, //Загрузить адресный регистр
		load_mmr_address = 14, //Загрузить адресный регистр из памяти
		save_address = 15, //Сохранить адресный регистр
		add_address = 16, //Cложение в адресном регистре
		sub_address = 17, //Вычитание в адресном регистре
		//--------------Работа со стеком-----------------
		stack_push_cmd = 18, //Загрузка в стек по адресу из команды
		stack_push = 19, //Загрузка в стек по адресу из адресного регистра
		stack_pop = 20, //Извлечение из стека по адресу из адресного регистра
		stack_get_top = 21, //Копирование вершиины стека по адресу из адресного регистра
		//--------------Команды перехода-----------------
		jump_unconditional = 22, //Безусловный переход
		jump_conditional_zf = 23, //Условный переход с проверкой флага нулевого результата (не равно нулю)
		jump_conditional_nzf = 24, //Условный переход с проверкой инвертированного флага нулевого результата (равно нулю)
		jump_conditional_sf = 25, //Условный переход с проверкой флага отрицательного результата (больше нуля или равно нулю)
		jump_conditional_nsf = 26, //Условный переход с проверкой инвертированного флага отрицательного результата (меньше нуля)
		jump_conditional_sf_zf = 27, //Условный переход с проверкой флагов нулевого и отрицательного результата (больше нуля)
		jump_conditional_nsf_nzf = 28, //Условный переход с проверкой инвертированных флагов нулевого и отрицательного результата (меньше нуля или равно нулю)
		jump_toProgram = 29, //Переход к подпрограмме
		jump_fromProgram = 30, //Вовзврат из подпрограммы
	};
	com_24bit cmd;
	class Command* com[128];
	int stack_size;
	std::vector <datatype> stack; //закручен в кольцо
	ui16 IF; // завершение выполнения программы
	ui16 jf; // переход
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
