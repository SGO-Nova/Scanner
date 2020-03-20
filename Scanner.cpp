#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	ofstream pfile("output.txt");
	
	
	pfile << "Test";
	pfile.close();
	
	return 0;
}