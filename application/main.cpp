#include "dataframe.h"
#include "agregator.h"

#include <string>
#include <iostream>
#include <vector>


int main(int argc, char **argv){
	Dataframe<std::string> data(0);
	std::vector<std::string> col(0);
	std::vector<std::string> col2(0);
	std::vector<std::string> col3(0);
	std::cin >> data;

	data.const_get_line(2);	
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout << data; 
	
	data.break_col(col, 1);
	Agregator<std::string> coluna(col, data.get_name(1), 1);
	coluna.load_aux();
	coluna.min_value();
	coluna.max_value();
	coluna.med_value();
	coluna.export_to_file("coluna1.csv");
	
	
	data.find_col(col2, "1996");	
	Agregator<std::string> coluna2(col2, "1996", data.get_index("1996"));
	coluna2.load_aux();
	coluna2.min_value();
	coluna2.max_value();
	coluna2.med_value();
	coluna2.export_to_file("coluna2.csv");

	data.break_col(col3, 6);
	Agregator<std::string> coluna3(col3, data.get_name(6), 6);
	coluna3.load_aux();
	coluna3.values();
	coluna3.export_to_file("coluna3.csv");	
	
	
	return EXIT_SUCCESS;
}
