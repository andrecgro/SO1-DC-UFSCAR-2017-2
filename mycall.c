#define _GNU_SOURCE
#include <linux/unistd.h> 
#include <linux/linkage.h>
#include <linux/syscalls.h>

#include <linux/fcntl.h>
#include <linux/types.h>
#include <linux/stat.h>

asmlinkage long createFile(const char fileName[], const char dirPath[], const char toWrite[]){
	
	if(chdir(dirPath) == 0){
		int f = open(fileName,O_WRONLY|O_CREAT,0640);
		if (write(f, toWrite, sizeof(toWrite)) != sizeof(toWrite)) {
			write(2, "Houve um erro ao tentar escrever!\n", 35);
			return -1;
		}
	}
	else{
		int d = mkdir(dirPath, S_IFDIR);
		if(chdir(dirPath) == 0){
			int f = open(fileName,O_WRONLY|O_CREAT,0640);
			if (write(f, toWrite, sizeof(toWrite)) != sizeof(toWrite)) {
				write(2, "Houve um erro ao tentar escrever!\n", 35);
				return -1;
			}
		}
	}
	return 0;
}
