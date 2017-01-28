#ifndef YUNYUNLINUX_UTILS_H
#define YUNYUNLINUX_UTILS_H

//General includes, required for the programs' functionality.
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/uio.h>

//Utilities class containing the functions that will be used in this project.
class Utilities
{
public:
	pid_t GetProcessByName( std::string process_name );
	bool ReadProcessMemory( pid_t process_id, void *address, void *buffer, size_t size );
	bool WriteProcessMemory( pid_t process_id, void *address, void *buffer, size_t size );
};

#endif //YUNYUNLINUX_UTILS_H
