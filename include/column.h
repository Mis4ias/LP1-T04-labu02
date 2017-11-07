#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <fstream>
#include <string>
#include <memory>
#include <vector>
class Coluna {
	protected:
		std::vector<std::string> _col;
		std::string _colname;
	public:
		Coluna(const std::vector<std::string>& temp){
			this->_col.resize(temp.size());
			for(size_t it = 0;it < this->_col.size(); it++){
				_col[it] = temp [it];
			}	
		}  
		std::unique_ptr<Coluna> create_coluna(const std::vector<std::string>& temp){
			std::unique_ptr<Coluna> new_coluna(new Coluna(temp));
			return new_coluna;
		}			
			
};


#endif //__COLUMN_H__
