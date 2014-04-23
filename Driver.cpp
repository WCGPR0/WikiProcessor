#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Processor.h"
#include <sys/time.h>
using namespace std;

int main(int argc, char* argv[]) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
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
	cout << "Printing List" << endl;
	cout << *myProcessor << endl;
	cout << "End of list" << endl;
	
	Processor* stopProcessor = new Processor(stopFile);
	
	cout << "Amount of stops" << endl;	
	cout << myProcessor->compareTrees(stopProcessor);

	delete myProcessor;
	delete stopProcessor;
	gettimeofday(&end, NULL);
	float runtime = (end.tv_usec - start.tv_usec);
	cout << "Run time is: " << runtime << endl;

	return 0;
}
