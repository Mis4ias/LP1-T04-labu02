#include "dataframe.h"
#include <string>
#include <fstream>
#include <iostream>

/* Comente as funcoes que não quer usar.
 Ou usa-se as funcoes read_file em conjunto com load_coluna(size_t)
 ou  Apenas read_col(size_t)
 */

int main(int argc, char **argv){
	Frame data("../data/data.csv");
	data.read_col(1);
//	data.read_file();
//	data.load_coluna(1);	
//	data.load_coluna(2);	
//	data.load_coluna(3);	

return EXIT_SUCCESS;
}
