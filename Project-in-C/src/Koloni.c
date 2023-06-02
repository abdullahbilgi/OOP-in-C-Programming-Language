#include "Koloni.h"


Koloni KoloniOlustur(int populasyon,char sembol) {
	Koloni this;
	this = (Koloni)malloc(sizeof(struct KOLONI));

	this->sembol = sembol;
	this->populasyon = populasyon;

	int yedekStok = populasyon * populasyon;
	this->yemekStogu = yedekStok;
	this->kazanma = 0;
	this->kaybetme = 0;

	this->toString = &toString;
	this->getPopulasyon = &getPopulasyon;
	this->setPopulasyon = &setPopulasyon;

	this->getYemekStogu = &getYemekStogu;
	this->setYemekStogu = &setYemekStogu;

	this->getKazanma = &getKazanma;
	this->setKazanma = &setKazanma;

	this->getKaybetme = &getKaybetme;
	this->setKaybetme = &setKaybetme;

	this->getPuan = &getPuan;
	this->setPuan = &setPuan;

	return this;
}
void toString(const Koloni this) {

	printf(" %c", this->sembol);
	printf("\t   %d",this->populasyon);
	printf(" \t\t  %d", this->yemekStogu);
	printf("\t  \t%d", this->kazanma);
	printf("  \t%d", this->kaybetme);
}

int getPopulasyon(const Koloni this) {
	return this->populasyon;
}
void setPopulasyon(const Koloni this, int populasyon) {
	this->populasyon = populasyon;
}

int getYemekStogu(const Koloni this) {
	return this->yemekStogu;
}
void setYemekStogu(const Koloni this, int stok) {
	this->yemekStogu = stok;
}

int getKazanma(const Koloni this) {
	return this->kazanma;
}
void setKazanma(const Koloni this, int kazanma) {
	this->kazanma = kazanma;
}

int getKaybetme(const Koloni this) {
	return this->kaybetme;
}
void setKaybetme(const Koloni this, int kaybetme) {
	this->kaybetme = kaybetme;
}

int getPuan(const Koloni this) {
	return this->puan;
}
void setPuan(const Koloni this, int puan) {
	this->puan = puan;
}

void KoloniYoket(const Koloni this) {
	free(this);
}