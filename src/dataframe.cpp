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
	this->_ysize = 0;
}

void Frame::line_size(){
	if(this->_xsize == 0){
		this->_stream.open(this->_filepath, std::fstream::in);
		std::string dummy;
		std::getline(this->_stream, dummy, '\n');
		for(std::string::iterator it = dummy.begin(); it != dummy.end(); it++)
			if((*it) == ';') this->_xsize++;
		this->_stream.close();
	}
}
void Frame::col_size(){
	if(this->_ysize == 0){
		this->_stream.open(this->_filepath, std::fstream::in);
		std::string dummy;
		while(std::getline(this->_stream, dummy, '\n'))
			this->_ysize++;	
		this->_stream.close();
	}
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

void Frame::read_col(size_t index){
	size_t now = 0;
	index--;		
	this->col_size();	
	this->line_size();
	std::vector<std::string> temp(this->_ysize);
	std::string buffer;
	this->_stream.open(this->_filepath, std::fstream::in);
		while(std::getline(this->_stream, buffer, '\n')){
			std::istringstream ss(buffer);
			std::string token;
			while(std::getline(ss, token, ';')){
				if((now % this->_xsize) == index){
					std::cout<<token<<std::endl;
					now++;
				}
			now++;
			}
		now++;
		}
	this->_stream.close();
}

