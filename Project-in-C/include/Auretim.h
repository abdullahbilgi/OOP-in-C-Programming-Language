#ifndef AURETIM_H
#define AURETIM_H

#include "Uretim.h"

struct AURETIM {
	Uretim super;
};
typedef struct AURETIM* Auretim;
Auretim AuretimOlustur();
int uret(const Auretim);

#endif