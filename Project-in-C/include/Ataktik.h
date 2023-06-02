#ifndef ATAKTIK_H
#define ATAKTIK_H

#include "Taktik.h"
#include "unistd.h"

struct ATAKTIK {
	Taktik super;
};
typedef struct ATAKTIK* Ataktik;
Ataktik AtaktikOlustur();
int Savas(const Ataktik,int);


#endif