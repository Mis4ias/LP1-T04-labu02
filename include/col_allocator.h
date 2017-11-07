#ifndef __COL_ALLOCATOR_H__
#define __COL_ALLOCATOR_H__

#include <iostream>
#include <memory>
#include <string>
#include <vector>


void print_vector(const std::vector<std::string>& temp){
	for(size_t it = 0; it < temp.size(); it++)
		std::cout<<temp[it]<<" ";	
	std::cout<<std::endl;
}

std::unique_ptr<Coluna> create_coluna(const std::vector<std::string>& temp){
		std::unique_ptr<Coluna> new_coluna(new Coluna(temp));
		return new_coluna;
}

#endif // __COL_ALLOCATOR_H__
