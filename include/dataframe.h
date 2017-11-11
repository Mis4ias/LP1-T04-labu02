#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__


#include <sstream>
#include <vector>
#include <iostream>
#include <string>

template <typename T>
class Dataframe {
	public:
	
		Dataframe(unsigned tam): _data(tam), _header(tam), _col_temp(tam), _nline(1) { }
	
	/******************************************************************************/	
	/******************************************************************************/	
	/** Non-constant Members **/
		
		void size_line(std::string line){
			if(this->_nline == 1){
				for(std::string::iterator it = line.begin(); it != line.end(); it++){
					if((*it) == ';')
							this->_nline++;
				}
			}
		}	
		void break_col(std::vector<T>& maincol, size_t ncol){
			for(size_t it = 0; it < this->_data.size(); it++){
				if(it % this->_nline == ncol)
					maincol.push_back(this->_data[it]);	
			}
		
		}	
		/*void break_col(size_t ncol){
			if(this->_col_temp.size() != 0)
					this->_col_temp.resize(0);
			
			for(size_t it = 0; it < this->_data.size(); it++){
				if(it % this->_nline == ncol)
					this->_col_temp.push_back(this->_data[it]);	
			}		
			print_col(ncol);
		}*/
		
		void find_col(std::vector<T>& maincol, std::string name) {
			for(size_t it = 0; it < this->_header.size(); it++){
				std::string buffer = this->_header[it];
				if(name.compare(buffer) == 0)
					break_col(maincol, it);	
			}
		}	
	
	/******************************************************************************/	
	/******************************************************************************/	
	/** Constant Members **/
		
		void print_header() const {
			for(size_t it = 0; it < this->_header.size(); it++){
				std::cout<<this->_header[it]<<" ";
			}
		}	
		
		void print_col(size_t ncol) const {
			for(size_t it = 0; it < this->_col_temp.size(); it++){
					std::cout<<this->_col_temp[it]<<" ";	
			}		
			std::cout<<std::endl;
		}
		
		void const_get_line(size_t line) const {
			size_t offset = line * this->_nline;
			for(size_t it = offset; it < offset + this->_nline; it++){
				std::cout<<this->_data[it]<<" ";
			}
			std::cout<<std::endl;
		}
		
		void const_find_col(std::string name) const {
			for(size_t it = 0; it < this->_header.size(); it++){
				std::string buffer = this->_header[it];
				if(name.compare(buffer) == 0)
					print_col(it);	
			}
		}	
	
	/******************************************************************************/	
	/******************************************************************************/	
	/** Friends Members **/
		
		friend std::istream& operator >>(std::istream& in, Dataframe<T>& obj){
			bool first_line = true;
			while(in){
				std::string buffer;
				std::getline(in, buffer, '\n');
				obj.size_line(buffer);
				buffer+=";";
				
				std::string token;
				std::istringstream iss(buffer);
				while(std::getline(iss, token, ';')){
					if(first_line)
						obj._header.push_back(token);	
					if(!first_line)
						obj._data.push_back(token);	
				}
			first_line = false;
			}
			return in;
		}
		
		friend std::ostream& operator <<(std::ostream& out, const Dataframe<T>& obj){
			obj.print_header();
			for(size_t it = 0; it < obj._data.size(); it++){
				if(it % obj._nline == 0)
					out<<std::endl;	
				out<<obj._data[it]<<" ";
			}
		return out;
		}
	
	/******************************************************************************/	
	/******************************************************************************/	
	
	
	private:
		
		std::vector<T> _data, _header, _col_temp;	
		size_t _nline;
};

#endif // __DATAFRAME_H__
