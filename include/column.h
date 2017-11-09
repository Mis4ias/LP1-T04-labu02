#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <string>
#include <memory>
#include <vector>
#include <iostream>
template <class T>
class Coluna {
	private:
		size_t _sizeof;
	public:
		std::vector<T> _col;
		Coluna(const std::vector<T>& temp){
			for(size_t it = 0;it < temp.size(); it++){
				_col.push_back(temp[it]);
			}	
			_sizeof = temp.size();
		}  
		std::vector<T>* get_col(){
			return &_col;
		}
		size_t get_size(){
			return this->_sizeof;
		}		
};

#endif //__COLUMN_H__
