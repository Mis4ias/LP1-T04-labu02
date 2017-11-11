#include "dataframe.h"

#include <string>
#include <iostream>

int main(int argc, char **argv){
	Dataframe<std::string> data(0);
	
	std::cin >> data;
	//data.break_col(2);
	//data.break_col(3);
	
	std::cout << data; 
	std::cout<<std::endl;
	data.find_col("1996");	
	std::cout<<std::endl;
	data.find_col("Municipio");	
	
	return EXIT_SUCCESS;
}
