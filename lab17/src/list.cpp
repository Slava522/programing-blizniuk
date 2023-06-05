#include "list.h"
#include "entity.h"

void Node::printNode() {
  std::cout << "Your Packages:" << std::endl;

  for (size_t i = 0; i < size; i++) {
    printf("%s %s %d %d %s %s\n", this->package_node[i].getSize(), this->package_node[i].getSender(), this->package_node[i].date,
       this->package_node[i].bow.getBow_weight(), this->package_node[i].bow.getBow_cost(), this->package_node[i].getFormat());
  }
}

void Node::addPackage(size_t pos, Package* element) {
  Package* new_pack = new Package[size + 1];
  if (pos > size) {
    pos = size;
  }
  memcpy(new_pack, package_node, pos * sizeof(Package));
  memcpy(new_pack + pos, element, sizeof(Package));
  memcpy(new_pack + pos + 1, package_node + pos, (size - pos) * sizeof(Package));
  delete[] package_node;
  package_node = new_pack;
  size++;
  std::cout << "Success, you added a package at position " << pos << std::endl;
}

Package& Node::findElementPackage(size_t pos) {
  if (pos >= size || pos < 0) {
    std::cout << "Mission failed" << std::endl;
    return package_node[0];
  }
  else {
    std::cout << "Yes, you found package at position " << pos << std::endl;
    return package_node[pos];
  }
}

void Node::delElementPackage(const size_t pos) {
  if (pos >= size) {
    std::cout << "Invalid position" << std::endl;
    return;
  }
  Package* new_pack = new Package[size - 1];
  memcpy(new_pack, package_node, sizeof(Package) * pos);
  memcpy(new_pack + pos, package_node + pos + 1, sizeof(Package) * (size - pos - 1));
  delete[] package_node;
  package_node = new_pack;
  size--;
  std::cout << "Yes, you deleted package at position " << pos << std::endl;
}

void Node::findOldestPackage() {
  for (unsigned long int i = 0; i < size - 1; i++) {
    for (unsigned long int j = 0; j < size - i - 1; j++) {
      if (this->package_node[j].getDate() > package_node[j + 1].getDate()) {
        Package temp = package_node[j];
        package_node[j] = package_node[j + 1];
        package_node[j + 1] = temp;
      }
    }
  }
  std::cout << "The oldest package is:" << std::endl;
  printf("%s %s %d %d %s %s\n", package_node[0].getSize(), package_node[0].getSender(), package_node[0].getDate(),
         package_node[0].bow.getBow_weight(), package_node[0].bow.getBow_cost(), package_node[0].getFormat());}