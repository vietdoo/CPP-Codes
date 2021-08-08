#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
	if (argc != 5) 
		return 0;

	char buffer[1025];
	string src = argv[1];	
	string option = argv[3];	
	int x = atoi(argv[4]);
	int found = src.find_last_of("\\");
	string dst = argv[2] + src.substr(found + 1);

	ifstream fin;
	fin.open(src, ios::binary);

	if (option == "-numpart" || option == "-sizeapart") {
		if (fin.is_open()) {
			fin.seekg(0, ios::end);
			int finSize = fin.tellg();	
			fin.seekg(0, ios::beg);
			int i = 0;
			string parts = ".part0";

			while (!fin.eof()) {
				ofstream fout;
				if (i >= 9)
					parts = ".part";
				string partsPath = dst + parts + to_string(++i);
				fout.open(partsPath, ios::binary);
				while (fin.read(buffer, sizeof(buffer))) {
				    fout.write(buffer, fin.gcount());
				    if (option == "-sizeapart" && fin.tellg() > i * x)
				    	break;
				    if (option == "-numpart" && fin.tellg() > i * (finSize / x) * 1.001) 
				    	break;
				}	
				cout << partsPath << '\n';
				fout.close();
			}
			fin.close();
		}
	}
	return 0;
}