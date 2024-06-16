#include <stdio.h>
#include <stdlib.h>
#include "./include/function.h"	
#include "./include/print.h"
#include "./include/structure.h"

int main(int argc, char const *argv[])
{
	if (argc!=3){
		printError("preconditioning", "The preprocessed file name is not entered", "There was a system call error, which may be caused by your input error or a system error. If you did not operate it yourself, please update to the latest version, which may have fixed this bug. If you are already using the latest version, please report the issue at http://xn--m7rp6drx8ckejqgcze.nndx.eu.org.");
		return -1;
	}
	//预处理
	char *filedata;
	FILE *file = openfile(argv[1], "r");
	if (file==NULL || fileSize(file)==0){
		printError("preconditioning", "The file does not exist", "There was a system call error, which may be caused by your input error or a system error. If you did not operate it yourself, please update to the latest version, which may have fixed this bug. If you are already using the latest version, please report the issue at http://xn--m7rp6drx8ckejqgcze.nndx.eu.org.");
		return -1;
	}
	filedata = readfile(file, fileSize(file));
	//删除多余的空格
	bool string = false ; 
	bool ch = false ;
	int fileSize = strlen(filedata);
	for (int i = 0; i < fileSize; i++){
		if (filedata[i]=='"'){
			string = !string ;
		}else if (filedata[i]==39){
			ch = !ch ;
		}else{
			if ((filedata[i]==' ' || filedata[i]=='\t') && filedata[i-1]==' ' && !string && !ch){
				filedata[i] = '0';
				filedata = erase(filedata, i, 1);
				fileSize--;
			}
		}
	}
	filedata[fileSize] = '\0';
	erase(filedata, 0, 1);
	closefile(file);
	printf("%s", filedata);
	FILE *end = openfile(argv[2], "w");
	writetofile(end, filedata);
	closefile(end);
	return 0;
}
