#pragma once

#include <dlfcn.h>
#include <sys/mman.h>
#include <vector>
#include <memory>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>
#include <elf.h>
#include <link.h>

namespace mem
{
    static long pageSize = sysconf(_SC_PAGESIZE);
    void getPage(uintptr_t &addr, size_t &len);
    static Elf32_Word getProtectionFlags(uintptr_t address)
{
	static Elf32_Word flags = 0;
	static std::uintptr_t addr = address;

	dl_iterate_phdr([](struct dl_phdr_info* info, std::size_t, void*)
	{
		std::uintptr_t startingAddr = 0;
		std::uintptr_t endingAddr = 0;

		for (Elf32_Half i = 0; i < info->dlpi_phnum; i++)
		{
			const ElfW(Phdr) *hdr = &info->dlpi_phdr[i];
			if (hdr->p_memsz)
			{
				startingAddr = info->dlpi_addr + hdr->p_vaddr;
				endingAddr = startingAddr + hdr->p_memsz;
				if (startingAddr <= addr && endingAddr >= addr)
					flags |= hdr->p_flags;
			}
		}

		return 0;
	}, nullptr);

	return flags;
}
    void makeWritable(uintptr_t addr, size_t len);
    std::uintptr_t getSymbol(const std::string& file, const std::string& symbol);

}