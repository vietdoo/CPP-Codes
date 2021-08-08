#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
	if (argc != 3) 
		return 0;

	char buffer[1025];
	string src = argv[1];	
	int found = src.find_last_of("\\");
	string dst = argv[2] + src.substr(found + 1);

	cout << src << '\n' << dst;

	ifstream fin;
	fin.open(src, ios::binary);
	if (fin.is_open()) {
		ofstream fout;
		fout.open(dst, ios::binary);
		
		while (fin.read(buffer, sizeof(buffer))) {
		    fout.write(buffer, fin.gcount());
		   
		}
		fout.close();
	}
	fin.close();

	return 0;
}