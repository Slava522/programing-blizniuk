#include "entity.h"

class Node {
    private:
	size_t size;
	Package *package_node;

    public:
	void printNode();
	
	void addPackage(size_t pos, Package *element);

	Package &findElementPackage(size_t pos);

	void delElementPackage(const size_t pos);

	void findOldestPackage();
};