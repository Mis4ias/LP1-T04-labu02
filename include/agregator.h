#ifndef __AGREGATOR_H__
#define __AGREGATOR_H__

#include <iostream>
#include <vector>
#include <algorithm>
//#include <cctype>
#include <cstdlib>
#include <locale>

using namespace std;

template <class T>
class Agregator {
	public:
		Agregator(vector<T>& main_vector): _colun(main_vector), _min(0) { };
		
		void min_value(){
			vector<int> aux;
			int value;
			std::string token;
			std::locale loc;
			for(size_t it = 0; it < this->_colun.size(); it++){
				token = this->_colun[it];
				char *p;
				value = strtol(token.c_str(),&p,10);
				aux.push_back(value);
			}
			this->_min = *min_element(aux.begin(), aux.end());
			std::cout<<"Menor elemento da coluna: "<<this->_min<<std::endl;
		}
		/*
		int min_value(vector<T>& colun){
			vector<int> aux;
			int value;

			for(typename vector<T>::iterator i = colun.begin();i!=colun.end();i++){
				if(isdigit(*i)){
					value=atoi(*i);
					aux.push_back(value);
				}
			}

			return min_element(aux.begin(),aux.end());

		}

		//template <typename T>
		int max_value(vector<T>& colun){	
			vector<int> aux;
			int value;

			for(typename vector<T>::iterator i = colun.begin();i!=colun.end();i++){
				if(isdigit(*i)){
					value=atoi(*i);
					aux.push_back(value);
				}
			}

			return max_element(aux.begin(),aux.end());

		}

		//template <typename T>
		int med_value(vector<T>& colun){
			int value=0;

			for(typename vector<T>::iterator i = colun.begin();i!=colun.end();i++){
				if(isdigit(*i)){
					value+=atoi(*i);

				}
			}
			return value/colun.size();
		}

		//template <typename T>
		int moda(vector <T>& colun){
			vector<int> aux;
			int value,cont1=0,cont2=0,offset=0;

			for(typename vector<T>::iterator i = colun.begin();i!=colun.end();i++){
				if(isdigit(*i)){
					value=atoi(*i);
					aux.push_back(value);
				}
			}
			for (int j = 0; j < aux.size(); ++j){
				for(int k=j+1;k<aux.size();k++){
					if(aux[j]==aux[k]){
						cont1++;
					}		
				}
				if(cont1>cont2){
					cont2=cont1;
					cont1=0;
					offset=j;
				}
			}
			return aux[offset];
		}*/
		
		friend std::ostream& operator <<(std::ostream& out, const  Agregator<T>& obj){
			for(size_t it = 0; it < obj._colun.size(); it++){
				out<<obj._colun[it]<<" ";
			}
			out<<std::endl;
		return out;
		}
	
	private:
		vector<T> _colun;
		int _min;
	
};

#endif //__AGREGATOR_H__
