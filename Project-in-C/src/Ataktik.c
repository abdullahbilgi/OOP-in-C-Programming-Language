#include "Ataktik.h"

Ataktik AtaktikOlustur() {
	Ataktik this;
	this = (Ataktik)malloc(sizeof(struct ATAKTIK));
	
	this->super = TaktikOlustur();
	this->super->savas = &Savas;
	return this;
}
int Savas(const Ataktik this,int a) {
    srand(time(NULL));
	int b = rand() % 500;
    return (b + a*a);
}
