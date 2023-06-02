#include "Auretim.h"


Auretim AuretimOlustur() {
	Auretim this;
	this = (Auretim)malloc(sizeof(struct AURETIM));

	this->super = UretimOlustur();
	this->super->uret = &uret;
	return this;
}
int uret(const Auretim this) {
	time_t t;
	srand((unsigned)time(&t));
	return (rand() % 5 +1 );
}