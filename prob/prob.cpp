#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Processor.h"

using namespace std;

bool Uploader(Processor& proc, const string& name)
{
	ifstream file(name);

	if (!file.is_open())
		return false;
	ui16 startAddress = 0;

	char pref = ' ';

	while (pref != 'e') //конец работы загрузчика
	{
		string line;
		getline(file, line);
		if (line.empty())
			continue;
		istringstream pars(line);
		pars >> pref;
		switch (pref)
		{
		case 's': //установить адрес загрузки
		{
			pars >> startAddress;
			break;
		}
		case 'i': //загрузить целое знаковое число
		{
			datatype num;
			pars >> num.i32t;
			proc.mmr.push_memory(num, startAddress);
			startAddress += 4;
			break;
		}
		case 'r': //загрузить дробное число
		{
			datatype num;
			pars >> num.ft;
			proc.mmr.push_memory(num, startAddress);
			startAddress += 4;
			break;
		}
		case 'c': //загрузить команду
		{
			com_24bit command;
			ui16 tmp;
			pars >> tmp;
			command.cmd.cop = tmp;
			pars >> tmp;
			command.cmd.b = tmp;
			pars >> tmp;
			command.cmd.address = tmp;
			proc.mmr.push_memory(command, startAddress);
			startAddress += 3;
			break;
		}
		case 'e': //установить IP, остановить работу загрузчика
		{
			com_24bit command;
			command.cmd.cop = 0;
			proc.mmr.push_memory(command, startAddress);
			ui16 tmp_IP;
			pars >> tmp_IP;
			proc.PSW.IP = tmp_IP;
			break;
		}
		}
	}
	return true;
	file.close();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	Processor proc;
	cout << "File " << argv[1] << endl;
	if (Uploader(proc, argv[1]))
	{
		cout << "uploaded successfully" << endl;
		proc.run();
	}
	else
		cout << "not uploaded" << endl;
	return 0;
}