#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__
#include "column.h"

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Frame {
	public:
	Frame(const std::string&);
	void line_size();
	void col_size();
	void read_file();	
	void load_coluna(size_t);

	private:
		std::vector<std::string> _filecont;
		std::vector<Coluna> _frame;	
		std::string _filepath;
		std::fstream _stream;
		size_t _xsize, _ysize;
};

#endif // __DATAFRAME_H__
