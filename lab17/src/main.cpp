#include "list.h"
#include "entity.h"

int main() {

Package *firstpackage = new Package("Yes", "Nova Poshta", 12, 9, "Clothes", "120");
Package *secondpackage = new Package("Yes", "Justin", 11, 22, "Iphone", "150");
Package *thirdpackage = new Package("Yes", "Ukr Poshta", 11, 28, "Tshirt", "400");
Package *fourthpackage = new Package("No", "Nova Poshta", 12, 01, "Samsung", "400");
	Node *container = new Node();
	container->addPackage(1, firstpackage);
	container->addPackage(2, secondpackage);
	container->addPackage(3, thirdpackage);
	container->addPackage(4, fourthpackage);
	container->printNode();

	container->delElementPackage(1);
	container->printNode();

	container->findElementPackage(1);

	container->findOldestPackage();
	return 0;
}