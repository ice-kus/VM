#include "InOut.h"
#include "Processor.h"

using namespace std;

void in_i::operator()(Processor& proc) noexcept
{
	datatype tmp;
	cout << "> " << endl;
	cin >> tmp.i32t;
	proc.mmr.push_memory(tmp, proc.regAddress);
}

void in_f::operator()(Processor& proc) noexcept
{
	datatype tmp;
	cout << "> " << endl;
	cin >> tmp.ft;
	proc.mmr.push_memory(tmp, proc.regAddress);
}

void out_i::operator()(Processor& proc) noexcept
{
	cout << "------------------------------" << endl << "Вывод из памяти по адресу из регистра: " << proc.mmr.get_num(proc.regAddress).i32t << endl << "------------------------------" << endl;
}

void out_f::operator()(Processor& proc) noexcept
{
	if (proc.mmr.get_num(proc.regAddress).ft==-0)
		cout << "------------------------------" << endl << "Вывод из памяти по адресу из регистра: " << 0 << endl << "------------------------------" << endl;
	else
		cout << "------------------------------" << endl << "Вывод из памяти по адресу из регистра: " << proc.mmr.get_num(proc.regAddress).ft << endl << "------------------------------" << endl;
}