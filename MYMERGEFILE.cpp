#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
	if (argc != 3) 
		return 0;

	char buffer[1025];
	string src = argv[1];		
	int found = src.find_last_of(".");
	string name = src.substr(src.find_last_of("\\") + 1);
	string realname = argv[2] + name.substr(0, name.find_last_of("."));
	string srcparts = src.substr(0, found);

	ifstream fin;
	fin.open(src, ios::binary);

	if (!fin.is_open())
		return 0;

	string parts = ".part0";
	int i = 1;
	ofstream fout;
	fout.open(realname, ios::binary);
	while (fin.is_open()) {
		while (fin.read(buffer, sizeof(buffer)))
		    fout.write(buffer, fin.gcount());

		fin.close();
		if (i >= 9)
			parts = ".part";
		i++;
		fin.open(srcparts + parts + to_string(i), ios::binary);
	}
	
	cout << realname;
	fout.close();
	
	return 0;
}