#pragma once
#include "Command.h"

//Загрузить адресный регистр
class l_address : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Загрузить адресный регистр из памяти
class l_mmr_address : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Сохранить адресный регистр
class s_address : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Cложение в адресном регистре
class add_addr : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//Вычитание в адресном регистре
class sub_addr : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};
