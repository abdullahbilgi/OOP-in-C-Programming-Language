#include "Btaktik.h"

Btaktik BtaktikOlustur() {
	Btaktik this;
	this = (Btaktik)malloc(sizeof(struct BTAKTIK));
	
	this->super = TaktikOlustur();
	this->super->savas = &savas;
	return this;
}
int savas(const Btaktik this,int b) {
	time_t t;
	srand((unsigned)time(&t));
	int r = rand() % 600;
	return (r + b*b - b*2);
}