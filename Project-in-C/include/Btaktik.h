#ifndef BTAKTIK_H
#define BTAKTIK_H

#include "Taktik.h"

struct BTAKTIK {
	Taktik super;

};
typedef struct BTAKTIK* Btaktik;
Btaktik BtaktikOlustur();
int savas(const Btaktik,int);


#endif