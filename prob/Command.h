#pragma once

#include <iostream>

class Processor;
class Command
{
public:
	virtual void operator() (Processor& proc) noexcept = 0;
};