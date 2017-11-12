#ifndef __AGREGATOR_H__
#define __AGREGATOR_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

template <class T>
class Agregator {
	public:
		/**Constructor ***/
		Agregator(vector<T>& main_vector, std::string name, size_t i): _colun(main_vector), 
		_aux(main_vector.size()), _min(0), _max(0), _med(0), _total(0), 
		_name(name), _index(i) { };
		
		/** Non Constant Members ***/
		void load_aux(){
			std::string token;
			int value;
			this->_aux.resize(this->_colun.size());
			this->_total = 0;
			for(size_t it = 0; it < this->_colun.size(); it++){
				token = this->_colun[it];
				char *p;
				value = strtol(token.c_str(),&p,10);
				this->_aux[it] = value;
				this->_total += value;
			}
		}	
		void min_value(){
				if(this->_min == 0){
				this->_min = *min_element(this->_aux.begin(), this->_aux.end());
				std::cout<<"Menor elemento da coluna: "<<this->_min<<std::endl;
			}
		}
		void max_value(){
			if(this->_max == 0){
				this->_max = *max_element(this->_aux.begin(), this->_aux.end());
				std::cout<<"Maior elemento da coluna: "<<this->_max<<std::endl;
			}
		}
		void med_value(){
			if(this->_med == 0){
				this->_med = this->_total/this->_aux.size();
				std::cout<<"Valor médio da coluna: "<<this->_med<<std::endl;
			}
		}
		void values(){
			if(this->_med == 0 and this->_min == 0 and this->_max == 0){
				this->_min = *min_element(this->_aux.begin(), this->_aux.end());
				this->_max = *max_element(this->_aux.begin(), this->_aux.end());
				this->_med = this->_total/this->_aux.size();
			}
		}	
		/** Constant Members ***/
		void export_to_file(std::string name)const {

			std::fstream stream;
			stream.open("../data/"+name, std::fstream::out);
			stream<<"Valores, mínimo("<<this->_min<<"), máximo("<<this->_max<<") e médio(";
			stream<<this->_med<<")"<<std::endl;
			stream<<"Coluna: ";
			for(size_t it = 0; it< this->_colun.size(); it++){
				stream<<this->_colun[it]<<" ";
			}
			stream<<std::endl;
			stream.close();
			std::cout<<"Arquivo salvo em: ../data"<<name<<std::endl;
		}	
		
		/** Friend Members ***/
		friend std::ostream& operator <<(std::ostream& out, const  Agregator<T>& obj){
			for(size_t it = 0; it < obj._colun.size(); it++){
				out<<obj._colun[it]<<" ";
			}
			out<<std::endl;
		return out;
		}
	
	private:
		std::vector<T> _colun;
		std::vector<int> _aux;
		int _min, _max, _med, _total;
		std::string _name;
		size_t _index;
		
};

#endif //__AGREGATOR_H__
