#include "Utils.h"

/*
 	
 	Getting the process id of a specified process by its name.
 	Further documentation will be added.
 	 
*/

pid_t Utilities::GetProcessByName( std::string process_name )
{
	if( process_name.length() == NULL ){
		std::cout << "No process name specified." << std::endl;
		return 0;
	}
	
	DIR *directory_path = opendir( "/proc/" );
	
	if( directory_path ){
		struct dirent *directory_entry;
		
		while( directory_entry = readdir( directory_path ), directory_entry ){
			if( directory_entry->d_type != DT_DIR )
				continue;
			
			std::string process_id = ( directory_entry->d_name );
			
			std::string comm_path = std::string( "/proc/" ) + process_id + "/comm";
			std::ifstream input_file( comm_path.c_str() );
			
			std::string file;
			
			getline( input_file, file );
			
			if( file == process_name ){
				pid_t proc_id = (pid_t) atoi( process_id.c_str() );
				return proc_id;
			}
		}
	}
	return 0;
}

/*
	
 	ReadProcessMemory is a linux equivalent to the function found in the Windows.h header on a windows machine.
 	Further documentation will be added.
 	For more info check: http://man7.org/linux/man-pages/man2/process_vm_readv.2.html
 	
 	NOTE: This function has not yet been tested.
 	
*/

bool Utilities::ReadProcessMemory( pid_t process_id, void *address, void *buffer, size_t size )
{
	struct iovec local_iovec[1];
	struct iovec remote_iovec[1];

	local_iovec[0].iov_base 	= buffer;
	local_iovec[0].iov_len 		= size;
	
	remote_iovec[0].iov_base 	= address;
	remote_iovec[0].iov_len 	= size;
	
	return( process_vm_readv( process_id, local_iovec, 1, remote_iovec, 1, NULL ) == size );
}

/*

	WriteProcessMemory is a linux equivalent to the function found in the Windows.h header on a windows machine.
 	Further documentation will be added.
 	For more info check: http://man7.org/linux/man-pages/man2/process_vm_writev.2.html
 	
 	NOTE: This function has not yet been tested.
 	
*/

bool Utilities::WriteProcessMemory( pid_t process_id, void *address, void *buffer, size_t size )
{
	struct iovec local_iovec[1];
	struct iovec remote_iovec[1];
	
	local_iovec[0].iov_base 	= buffer;
	local_iovec[0].iov_len 		= size;

	remote_iovec[0].iov_base 	= address;
	remote_iovec[0].iov_len 	= size;

	return( process_vm_writev( process_id, local_iovec, 1, remote_iovec, 1, NULL ) == size );
}