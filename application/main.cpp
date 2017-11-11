#include "dataframe.h"
#include "agregator.h"

#include <string>
#include <iostream>
#include <vector>

int main(int argc, char **argv){
	Dataframe<std::string> data(0);
	std::vector<std::string> col(0);
	
	std::cin >> data;
	
	//std::cout << data; 
	std::cout<<std::endl;
	//data.find_col("1996");	
	data.break_col(col, 1);
	Agregator<std::string> coluna(col);
	coluna.min_value();
	std::cout<<coluna;
	std::cout<<std::endl;
	//data.find_col("Municipio");	
	
	return EXIT_SUCCESS;
}
