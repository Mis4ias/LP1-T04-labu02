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
 *  Como não se sabe ainda se o mesmo será definitivo, um prototipo de contagem 
 *  de colunas e linhas é feito acima.
 **/

/** @brief Na primeira versao do código, como não se consegue ler apenas uma 
 * coluna por vez, a leitura é feita normalmente. o this->_stream refere-se ao
 * fstream armazenado no atributo da classe, é aberto com o caminho também armaze
 * nado.
*/

/** @brief O arquivo é completamente lido e jogado unicamente em um único vetor
* sendo assim não se considera linha ou coluna por agora.
*/
void Frame::read_file(){
	std::string buffer;
	this->_stream.open(this->_filepath, std::fstream::in);
	while(std::getline(this->_stream, buffer, '\n')){
		std::istringstream ss(buffer);
		std::string token;
		while(std::getline(ss, token, ';'))
		this->_filecont.push_back(token);
	}
	this->_stream.close();
}


/** @biref Esse é o prototipo para quebrar o vetor, que armazenou todo o conteudo 
 do arquivo. Um novo vetor é criado que será como se fosse a coluna simulada
 temp é criada tendo como parâmetro o _ysize que é o tamanho da coluna. 
 o valor passado na assitaura da funcao, index será a posicao da coluna buscada 
 no metodo. A grande lógica dessa parte está em localizar os indíces corretos no 
 vetor que detem as informaçoes do arquivo.*/

/** @biref No funcao é criado um outro indice ik que será igual ao index - 1, ou
seja passada a coluna 1 na main é referenciada ao indice 0. Note que o indice 
buscado no vetor _filecont sera modificado de maneira independente do indice do
vetor temp. 

Os indices buscados no vetor vao sempre ser modificados pelo tamanho da linha, x
_xsize. Por exemplo se quero buscar a coluna de indice 0 no vetor _filecont, a 
conta feita para achar os indices corretos é 0 + tamanho da linha. a coluna 0 
por exemplo terá os indices todos multiplos da linha, ou seja 0, 3, 6, 9...

*/

void Frame::load_coluna(size_t index){
	
	this->col_size();
	this->line_size();
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
/** @brief Por agora essa funcao está sendo desenvolvida para ser a leitura inde
pendente das colunas, sem a necessidade de passar o conteudo do arquivo inteiro
para um vetor auxiliar */

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

