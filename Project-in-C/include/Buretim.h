#ifndef BURETIM_H
#define BURETIM_H

#include "Uretim.h"

struct BURETIM {
	Uretim super;
};
typedef struct BURETIM* Buretim;
Buretim BuretimOlustur();
int Uret(const Buretim);

#endif