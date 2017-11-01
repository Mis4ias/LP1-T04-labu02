#include "column.h"
#include "dataframe.h"

#include <iostream> // for late nitght debugging (please don't judge me)

#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>


Frame::Frame(const std::string& file_path){
	this->_filepath = file_path;		
	this->_xsize = 0;
	this->_ysize = 1;
}

void Frame::line_size(){
	this->_stream.open(this->_filepath, std::fstream::in);
	std::string dummy;
	std::getline(this->_stream, dummy, '\n');
	for(std::string::iterator it = dummy.begin(); it != dummy.end(); it++)
		if((*it) == ';') this->_xsize++;
	this->_stream.close();
}
/** As dimensoes das colunas e linhas podem facilmente ser calculadas nesse metodo
 *  Como não se sabe ainda se o mesmo será definitivo, um prototipo de contagem de colunas é 
 *  feito acima
 *
 **/
void Frame::read_file(){
	std::string buffer;
	this->_stream.open(this->_filepath, std::fstream::in);
	while(std::getline(this->_stream, buffer, '\n')){
		std::istringstream ss(buffer);
		std::string token;
		while(std::getline(ss, token, ';'))
		this->_filecont.push_back(token);
	this->_ysize++;
	}
	this->_stream.close();
}

void Frame::load_coluna(size_t index){
	
	std::vector<std::string> temp(_ysize);
	
	this->_stream.open(this->_filepath, std::fstream::in);
	size_t ik = (index-1);
	for(size_t it = 0; it < _ysize ;it ++){
		temp[it] = this->_filecont[ik];	
		std::cout<<temp[it]<<" ";
		ik = ik + this->_xsize;
	}
	std::cout<<'\n';
	this->_stream.close();
	temp.clear();
}	
