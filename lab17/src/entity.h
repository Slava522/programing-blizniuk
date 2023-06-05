#ifndef ENTITY_H
#define ENTITY_H
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#define N 10


class Package {

    private:
	    struct Size {
        int size_weight;
        char size_cost[N];
    };
	char size[N];
	char sender[N];
	int date;
	Size size_data;
    char format[N];

	class bow {

	    private:
		int bow_weight;
		char bow_cost[N];

	    public:
		char* getBow_cost();
		void setBow_cost(char *bow_cost);
		int getBow_weight();
		void setBow_weight(int bow_weight);
		friend class Package;
		friend class Information;
	} bow;

    public:
 Package(const char size[N], const char sender[N], const int data, const int bow_weight, const char bow_cost[N],
		const char format[N]);
	Package();


char *getSize();
void setSize(char *size);

char *getSender();
void setSender(char *sender);

void setformat(char *format);

int getDate();
void setDate(int Date);

char* getFormat();
void setFormat(char* Format);

    friend class Node;
};
#endif