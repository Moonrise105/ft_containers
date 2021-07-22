#include "vector.hpp"
#include <vector>

int main() {

	ft::vector<int> my(5);
	my.resize(5, 1);
	std::cout << "Capacity: " << my.capacity() << std::endl;
	std::cout << "Size: " << my.size() << std::endl;
	for (int i = 0; i < my.size(); ++i) {
		std::cout << my._data[i] << std::endl;
	}

	// std::vector<int> vec(10, 1);
	// vec.resize(5);
	// std::cout << "Capacity: " << vec.capacity() << std::endl;
	// std::cout << "Size: " << vec.size() << std::endl;

	
	return 0;
}