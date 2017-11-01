#include "dataframe.h"
#include <string>
#include <fstream>
#include <iostream>


int main(int argc, char **argv){
	Frame data("../data/data.csv");
	data.read_file();
	data.load_coluna(1);	
	data.load_coluna(2);	
	data.load_coluna(3);	

return EXIT_SUCCESS;
}
