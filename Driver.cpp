#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Processor.h"
using namespace std;

int main(int argc, char* argv[]) {
const string stopFile = "stop.txt";
string fileName;
if (argc >= 2) {
if (argc > 2) std::cerr << "Invalid use.\nUsage: ./wikiParse input_file_name" << endl;
fileName = argv[1];
}
else {
cout << "Please input the title of the file to processes" << endl;
string fileName;
cin >> fileName;
}

Processor* myProcessor = new Processor(fileName);

delete myProcessor;
return 0;
}
