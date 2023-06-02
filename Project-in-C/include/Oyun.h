#ifndef OYUN_H
#define OYUN_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Ataktik.h"
#include "Btaktik.h"
#include "Auretim.h"
#include "Buretim.h"


struct OYUN
{
	void (*basla)(struct OYUN*);
};

typedef struct OYUN* Oyun;

Oyun OyunOlustur();
void basla(const Oyun);
void OyunYoket(const Oyun);
#endif
