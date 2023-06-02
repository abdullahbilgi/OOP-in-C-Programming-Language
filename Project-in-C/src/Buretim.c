#include "Buretim.h"

Buretim BuretimOlustur() {
	Buretim this;
	this = (Buretim)malloc(sizeof(struct BURETIM));

	this->super = UretimOlustur();
	this->super->uret = &Uret;
	return this;
}
int Uret(const Buretim this) {
	srand(time(NULL));
	return (rand() % 5 +5);
}