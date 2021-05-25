#pragma once
#include "Command.h"

//«агрузка в стек по адресу из команды
class s_push_cmd : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//«агрузка в стек по адресу из адресного регистра
class s_push : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

//»звлечение из стека по адресу из адресного регистра
class s_pop : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};

// опирование вершины стека по адресу из адресного регистра
class s_get_top : public Command
{
public:
	virtual void operator() (Processor& proc) noexcept override;
};