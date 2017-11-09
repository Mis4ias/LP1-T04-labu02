#ifndef __COL_ALLOCATOR_H__
#define __COL_ALLOCATOR_H__
#include "dataframe.h"
#include "column.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>


void print_vector(const std::vector<std::string>& temp){
	for(size_t it = 0; it < temp.size(); it++)
		std::cout<<temp[it]<<" ";	
	std::cout<<std::endl;
}
template <typename T>
std::unique_ptr<Coluna<T>> create_coluna(const std::vector<T>& temp){
		std::unique_ptr<Coluna<T>> new_coluna(new Coluna<T>(temp));
		return new_coluna;
}

#endif // __COL_ALLOCATOR_H__
