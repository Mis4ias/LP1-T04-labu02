#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__
#include "column.h"

#include <fstream>
#include <string>
#include <vector>
#include <memory>

/** @brief Por agora a classe não está tendo grandes propósitos a não ser os 
 * métodos no public */
class Frame {
	public:
	Frame(const std::string&);
	void line_size(char);
	void col_size();
	void read_col(size_t, char);	

	private:
		std::vector<std::string> _filecont;
		std::vector<Coluna> _frame;	
		std::string _filepath;
		std::fstream _stream;
		size_t _xsize, _ysize;
};

#endif // __DATAFRAME_H__
