#include "column.h"
#include "dataframe.h"

#include <iostream> // for late nitght debugging (please don't judge me)

#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>

/** @brief Construtor Paramétrizado, recebe uma string que é tratada como 
 caminho do arquivo 
 Toda vez que é chamado this-> é o mesmo que chamar o atributo privado da classe
 ou seja this->_filepath é o mesmo que o objeto data, criado na main, no campo 
 _filepath recebe a string file_path 
 o atributo _xsize é referente ao tamanho da linha. 
 e o _ysize refere-se ao tamanho da coluna, ambos começam com 0 */
 
Frame::Frame(const std::string& file_path){
	this->_filepath = file_path;		
	this->_xsize = 0; 
	this->_ysize = 0;
}


/** @brief Os dois metodos a baixo só servem para calcular os valores referentes
 * ao tamanho da linha e tamanho da coluna, os valores achados são guardados nos
 * atributos _xsize e _ysize , respectivamentes.
*/
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
/** @brief no futuro essa funcão de tamanho da coluna deverá ser adptada para
calcular o tamanho da coluna a ser alocada, para que não tenham bugs referentes
a colunas com tamanhos diferentes. Talvez em vez de ter essa funcao o processo
de calculo da coluna seja passada para o proprio metodo de alocar. */

void Frame::col_size(){
	if(this->_ysize == 0){
		this->_stream.open(this->_filepath, std::fstream::in);
		std::string dummy;
		while(std::getline(this->_stream, dummy, '\n'))
			this->_ysize++;	
		this->_stream.close();
	}
}

/** @brief Por agora essa funcao está sendo desenvolvida para ser a leitura inde
pendente das colunas, sem a necessidade de passar o conteudo do arquivo inteiro
para um vetor auxiliar */
void Frame::read_col(size_t index, char delim){
	index = index-1;		
	
	this->col_size();	
	this->line_size();
	
	std::vector<std::string> col_temp(this->_ysize);
	std::string buffer;
	this->_stream.open(this->_filepath, std::fstream::in);
		while(std::getline(this->_stream, buffer)){
			buffer += delim;
			std::istringstream ss(buffer);
			std::string token;
			
			size_t offset = this->_xsize + 1;
			
			for(size_t it = 0; it < offset; it++){
				std::getline(ss, token, delim);	
				if(it == index - it / offset){
					col_temp.push_back(token);
				}
			}	
		}
	this->_stream.close();
	std::cout<<"col: "<<index<<std::endl;
	for(std::vector<std::string>::iterator it = col_temp.begin(); it != col_temp.end(); it ++){
		std::cout<<(*it);
	}
	std::cout<<std::endl;
}

