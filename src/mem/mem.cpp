#include "mem.h"
#include <iostream>

void mem::getPage(uintptr_t &addr, size_t &len)
{
    uintptr_t ret = (addr / mem::pageSize) * mem::pageSize;

	size_t n (addr - ret + len);
	if (n % mem::pageSize)
		n /= mem::pageSize, ++n;
	else
		n /= mem::pageSize;

    addr = ret;
    len = n*mem::pageSize;
}


void mem::makeWritable(uintptr_t addr, size_t len)
{
    getPage(addr, len);
	if ( mprotect(reinterpret_cast<void*>(addr), len, PROT_EXEC | PROT_READ | PROT_WRITE) == -1)
		throw "makeWritable() : `mprotect` failed";
}

std::uintptr_t mem::getSymbol(const std::string& file, const std::string& symbol)
{
	void* handle = dlopen(file.c_str(), 2);
	void* addr = dlsym(handle, symbol.c_str());
	dlclose(handle);
		
	return reinterpret_cast<std::uintptr_t>(addr);
}