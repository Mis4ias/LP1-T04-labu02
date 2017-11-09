#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__
#include "col_allocator.h"
#include "column.h"

#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

/** @brief Por agora a classe não está tendo grandes propósitos a não ser os 
 * métodos no public */
template <class T>
class Frame {
	private:
		std::vector<Coluna<T>> _frame;	
		std::string _filepath;
		std::fstream _stream;
		size_t _xsize, _ysize;
		char _delim;
		
	public:
	Frame(const std::string& file_path, char delim){
		this->_filepath = file_path;		
		this->_xsize = 0; 
		this->_ysize = 0;
		this->_delim = delim;
		this->line_size();
		this->_frame.reserve(this->_xsize);
	}

	void line_size(){
		if(this->_xsize == 0){
			this->_stream.open(this->_filepath, std::fstream::in);
			std::string dummy;
			std::getline(this->_stream, dummy, '\n');
			for(std::string::iterator it = dummy.begin(); it != dummy.end(); it++)
				if((*it) == this->_delim) this->_xsize++;
			this->_stream.close();
		}
	}

	void col_size(){
		if(this->_ysize == 0){
			this->_stream.open(this->_filepath, std::fstream::in);
			std::string dummy;
			while(std::getline(this->_stream, dummy, '\n'))
				this->_ysize++;	
			this->_stream.close();
		}
	}

	void read_col(size_t index){
		index = index-1;		
		this->_xsize = 0;
		this->_ysize = 0;		
		this->col_size();	
		this->line_size();
	
		std::vector<std::string> col_temp;
		std::string buffer;
		this->_stream.open(this->_filepath, std::fstream::in);
			while(std::getline(this->_stream, buffer)){
				buffer += this->_delim;
				std::istringstream ss(buffer);
				std::string token;
			
				size_t offset = this->_xsize + 1;
			
				for(size_t it = 0; it < offset; it++){
					std::getline(ss, token, this->_delim);	
					if(it == index - it / offset){
					col_temp.push_back(token);
				}
			}	
		}
		this->_stream.close();
		std::unique_ptr<Coluna<std::string>> individual = move(create_coluna(col_temp));
		this->_frame.push_back(*individual);

	}
	
	friend std::ostream& operator <<(std::ostream& out, const Frame& rig){
		for(size_t it = 0; it < rig._frame.size(); it ++){
			for(size_t ik = 0; ik < rig._frame[it]._col.size(); ik++){
				out<<rig._frame[it]._col[ik];
			}
		std::cout<<std::endl;
		}
		return out;
	}	
};

#endif // __DATAFRAME_H__
