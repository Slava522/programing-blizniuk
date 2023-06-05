#include <cstring>
#include "entity.h"

char* Package::bow::getBow_cost() {
	return bow_cost;
}

void Package::bow::setBow_cost(char *Bow_cost) {
	strcpy(this->bow_cost, Bow_cost);
}

int Package::bow::getBow_weight() {
	return bow_weight;
}

void Package::bow::setBow_weight(int Bow_weight) {
    this->bow_weight = Bow_weight;
}

Package::Package(const char size[N], const char sender[N], int date, int size_weight, const char size_cost[N], const char format[N]) {
    strcpy(this->size, size);
    strcpy(this->sender, sender);
    this->date = date;
    this->size_data.size_weight = size_weight;
    strcpy(this->size_data.size_cost, size_cost);
    strcpy(this->format, format);
}

Package::Package() {}

//size
char* Package::getSize() {
    return size;
}
void Package::setSize(char* Size) {
    strcpy(this->size, Size);
}

//sender
char* Package::getSender() {
    return sender;
}
void Package::setSender(char* Sender) {
    strcpy(this->sender, Sender);
}

//Date
int Package::getDate() {
    return date;
}
void Package::setDate(int Date) {
    this->date = Date;
}

//Format
char* Package::getFormat() {
    return format;
}
void Package::setFormat(char* Format) {
    strcpy(this->format, Format);
}