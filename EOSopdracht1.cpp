#include <iostream>
#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

void new_file() {
	int fd;
	string bestandsnaam;
	string tekst;
	cout << "Wat is de bestandsnaam?" << endl;
	cin >> bestandsnaam;
	cout << endl << "Wat moet het bestand bevatten" << endl;
	getline(cin, tekst, '<');
	cout << tekst.c_str();
	fd=open(bestandsnaam.c_str(), O_WRONLY |  O_CREAT, 777);
	write(fd, tekst.c_str(), tekst.length());
	close(fd);
}


void ls(){
	int lsFork = syscall(SYS_fork);
	cout << lsFork;
	if (lsFork ==-1){
		cout << "Error while forking" << endl;
	} else if (lsFork==0) {
		//"|" "/bin/cat"
		char *args[] = {"/bin/ls", "-l", "-a", NULL};
		syscall(execv("/bin/ls",args));
	} else {
		int exit_status;
		syscall(wait(&exit_status));
	}
}

/*
void find() {
	int fd1[2];
	string findString;
	cout << "Wat is de find string?" << endl;
	cin >> findString;
	int p = pipe(fd1);
	int findFork = syscall(SYS_fork);
	int grepFork = syscall(SYS_fork);
	if (findFork == -1) {
		cout << "Error while forking" << endl;
	} else if (findFork==0) {
		close(fd1[0]);
		int execString = syscall(execv("/bin/find", NULL));
		write(fd1[1], execString, 100);
		close(fd1[1]);
	}

	if (grepFork == -1) { cout << "Error while forking" << endl; }
	else if (grepFork==0) {
		close(fd1[1]);
		char findResult[100];
		read(fd1[0], findResult, 100);
		char *args[] = {findResult, NULL};
		syscall(execv("/bin/grep", args));
		close(fd1[0]);
	}

}
*/



void python() {
	//cout << "Python time";
	int pythonFork = syscall(SYS_fork);

	if (pythonFork==-1){
		cout << "Error while forkin";
	} else if (pythonFork==0) {
		//char *args[] = {"/bin/python", NULL};
		syscall(execl("/usr/bin/python", NULL));
	} else {
		int exit_status;
		syscall(wait(&exit_status));
	}

}


int main()
{
	string input;
	int inputFile = open("input", O_RDONLY);
	int ret;
	char buf[1024];
	while ((ret = read(inputFile, buf, sizeof(buf)-1)) > 0) {
		buf[ret] = 0x00;
	}
	close(inputFile);

	string promt = "Todo";
	// int fd;
	// fd=open(input, O_RONLY);
	// rd=read(fd, prompt

	while (true)
	{
		cout << buf;
		getline(cin, input);

		if (input == "new_file") new_file();
		else if (input == "ls") ls();
		// else if (input == "find") find();
		else if (input=="python") python();
	}
}
