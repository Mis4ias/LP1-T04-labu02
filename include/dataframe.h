#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__

#include <sstream>
#include <vector>
#include <iostream>
#include <string>

template <typename T>
class Dataframe {
	public:
		Dataframe(unsigned tam): _data(tam), _header(tam), _nline(1) { }
		
		
		void size_line(std::string line){
			if(this->_nline == 1){
				for(std::string::iterator it = line.begin(); it != line.end(); it++){
					if((*it) == ';')
							this->_nline++;
				}
			}
		}	
		
	
		void print_header() const {
			for(size_t it = 0; it < this->_header.size(); it++){
				std::cout<<this->_header[it]<<" ";
			}
		}	
		
		void get_line(size_t line) const {
			size_t offset = line * this->_nline;
			for(size_t it = offset; it < offset + this->_nline; it++){
				std::cout<<this->_data[it]<<" ";
			}
			std::cout<<std::endl;
		}
		
		void break_col(size_t ncol) const {
			for(size_t it = 0; it < this->_data.size(); it++){
				if(it % this->_nline == ncol)
					std::cout<<this->_data[it]<<" ";	
			}		
			std::cout<<std::endl;
		}
		void find_col(std::string name) const {
			for(size_t it = 0; it < this->_header.size(); it++){
				std::string buffer = this->_header[it];
				if(name.compare(buffer) == 0)
					break_col(it);	
			}
		}	
	/******************************************************************************/	
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
	
	
	private:
		std::vector<T> _data, _header;	
		size_t _nline;
};

#endif // __DATAFRAME_H__
