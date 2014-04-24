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
	if (argc != 2) {
		std::cerr << "Invalid use.\nUsage: ./wikiParse input_file_name" << endl;
	return -1;
	}
	fileName = argv[1];

  ofstream myWriter("sorted_words.txt", std::ofstream::out);

	Processor* myProcessor = new Processor(fileName);
	myWriter << *myProcessor << endl;

  myWriter.close();
  myWriter.open("report.txt", std::ofstream::out | std::ofstream::app);

	Processor* stopProcessor = new Processor(stopFile);

	cout << (double)myProcessor->compareTrees(stopProcessor) / (double)myProcessor->getCount() << "% stop words" << endl;

	myProcessor->topReport(myWriter);

	  myWriter.close();

	delete myProcessor;
	delete stopProcessor;
	gettimeofday(&end, NULL);
	float runtime = (end.tv_usec - start.tv_usec);
	std::clog << "Run time is: " << runtime << endl;

	return 0;
}
