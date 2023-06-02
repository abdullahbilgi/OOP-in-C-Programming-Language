#ifndef KOLONI_H
#define KOLONI_H

#include "Ataktik.h"
#include "Btaktik.h"
#include "Math.h"

struct KOLONI {
	char sembol;
	int populasyon;
	int yemekStogu;
	int kazanma;
	int kaybetme;
	int puan;

	void (*toString)(struct KOLONI*);

	int (*getPopulasyon)(struct KOLONI*);
	void (*setPopulasyon)(struct KOLONI*,int);

	int (*getYemekStogu)(struct KOLONI*);
	void (*setYemekStogu)(struct KOLONI*, int);

	int (*getKazanma)(struct KOLONI*);
	void (*setKazanma)(struct KOLONI*, int);

	int (*getKaybetme)(struct KOLONI*);
	void (*setKaybetme)(struct KOLONI*, int);

	int (*getPuan)(struct KOLONI*);
	void (*setPuan)(struct KOLONI*, int);

	void (*yoket)(struct KOLONI*);
};
typedef struct KOLONI* Koloni;

Koloni KoloniOlustur(int,char);
void toString(const Koloni);

int getPopulasyon(const Koloni);
void setPopulasyon(const Koloni,int);

int getYemekStogu(const Koloni);
void setYemekStogu(const Koloni,int);

int getKazanma(const Koloni);
void setKazanma(const Koloni, int);

int getKaybetme(const Koloni);
void setKaybetme(const Koloni, int);

int getPuan(const Koloni);
void setPuan(const Koloni, int);

void KoloniYoket(const Koloni);

#endif