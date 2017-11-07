#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <string>
#include <memory>
#include <vector>
#include <iostream>

class Coluna {
	protected:
		std::vector<std::string> _col;
	public:
		Coluna(const std::vector<std::string>& temp){
		//	this->_col.resize(temp.size());
			for(size_t it = 0;it < temp.size(); it++){
				_col.push_back(temp[it]);
			}	
			
		}  
			
};

#endif //__COLUMN_H__
