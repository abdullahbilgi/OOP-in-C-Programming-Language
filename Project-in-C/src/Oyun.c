#include "Oyun.h"
#include "Koloni.h"


Oyun OyunOlustur() {
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->basla = &basla;
	return this;
}
void basla(const Oyun this) {

	char str[50];
	int koloniSayisi = 0;
	int pops[30];

	printf("Populasyonlari girin: ");
	fgets(str, sizeof(str), stdin);
	char* token = strtok(str, " ");

	while (token != NULL) {
		
		pops[koloniSayisi] = atoi(token);
		koloniSayisi++;
		token = strtok(NULL, " ");
	}

	Koloni k[koloniSayisi];

	for (int i = 0; i < koloniSayisi; i++) {
		k[i] = KoloniOlustur(pops[i], 65+i);
	}
	int tur = 0;

	Ataktik a = AtaktikOlustur();
	Btaktik b = BtaktikOlustur();

	Auretim a1 = AuretimOlustur();
	Buretim b1 = BuretimOlustur();


	int puan[30];

	int uret[14];
	

	while (1) {
		printf("\n");
		printf("------------------------------------------------------------------");
		printf("\n");

		printf("Tur Sayisi: %d\n ",tur);
		
		printf("% s\n", "Koloni   Populasyon   YemekStogu   Kazanma   Kaybetme");

		for (int i = 0; i < koloniSayisi; i++) {
			
			k[i]->toString(k[i]);
			printf("\n");

		}

		for (int i = 0; i < koloniSayisi - 1; i++) {
			for (int j = i + 1; j < koloniSayisi; j++) {
				if (k[i]->getPopulasyon(k[i]) == 0 || k[j]->getPopulasyon(k[i]) == 0) {
					continue;
				}

				for (int q = 0, z = 1; q < 31 && z < 30; q += 2, z += 2) {
					puan[q] = a->super->savas(a,q+1);//hep ayni sayi
					puan[z] = b->super->savas(b,z+2);
					
				}

				//for (int i = 0; i < 14; i++) {
				//	printf("\n%d",puan[i]);
				//}

				int random1;
				int random2;

				// Seed değerini zamanla güncelleme
				srand(time(0));

				// 0 ile 15 arasında rastgele bir değer üretme
				//hep ayni sayi

				random1 = (rand() % 4) + j + i;
				random2 = (rand() % 9) + j + 2;


				k[i]->setPuan(k[i],puan[random1]);
				k[j]->setPuan(k[j], puan[random2]);

				int kazanmaI = (k[i]->getKazanma(k[i])) + 1;
				int kazanmaJ = (k[j]->getKazanma(k[j])) + 1;
				int kaybetmeI = (k[i]->getKaybetme(k[i])) + 1;
				int kaybetmeJ = (k[j]->getKaybetme(k[j])) + 1;

				
				printf("\n%d %d", k[i]->getPuan(k[i]), k[j]->getPuan(k[j]));

				if (k[i]->getPuan(k[i]) > k[j]->getPuan(k[j])) {//k[i] kazanýr

					int fark = k[i]->getPuan(k[i]) - k[j]->getPuan(k[j]);
					int oran = fark * 100 / 1000;
					k[j]->setPopulasyon(k[j],(k[j]->getPopulasyon(k[j]) - (k[j]->getPopulasyon(k[j])) * oran / 100));
					k[j]->setYemekStogu(k[j], (k[j]->getYemekStogu(k[j]) - (k[j]->getPopulasyon(k[j])) * oran / 100));
					k[i]->setYemekStogu(k[i],(k[i]->getYemekStogu(k[i]) + (k[j]->getPopulasyon(k[j])) * oran / 100));



					k[i]->setKazanma(k[i],kazanmaI);
					k[j]->setKaybetme(k[j],kaybetmeJ);

				}
				else if (k[i]->getPuan(k[i]) < k[j]->getPuan(k[j])) {//k[i] kaybeder


					int fark = k[j]->getPuan(k[j]) - k[i]->getPuan(k[i]);
					int oran = fark * 100 / 1000;
					k[i]->setPopulasyon(k[i],(k[i]->getPopulasyon(k[i]) - (k[i]->getPopulasyon(k[i])) * oran / 100));
					k[i]->setYemekStogu(k[i], (k[i]->getYemekStogu(k[i]) - (k[i]->getPopulasyon(k[i])) * oran / 100));
					k[j]->setYemekStogu(k[j],(k[j]->getYemekStogu(k[j]) + (k[i]->getPopulasyon(k[i])) * oran / 100));



					k[j]->setKazanma(k[j],kazanmaJ);
					k[i]->setKaybetme(k[i],kaybetmeI);

				}
				else {//berabere

					int berabere = rand() % 2;


					if (berabere == 0) {//k[i] kazansýn

						int fark = k[i]->getPuan(k[i]) - k[j]->getPuan(k[j]) + 100;
						int oran = fark * 100 / 1000;
						k[j]->setPopulasyon(k[j], (k[j]->getPopulasyon(k[j]) - (k[j]->getPopulasyon(k[j])) * oran / 100));
						k[j]->setYemekStogu(k[j], (k[j]->getYemekStogu(k[j]) - (k[j]->getPopulasyon(k[j])) * oran / 100));
						k[i]->setYemekStogu(k[i], (k[i]->getYemekStogu(k[i]) + (k[j]->getPopulasyon(k[j])) * oran / 100));



						k[i]->setKazanma(k[i], kazanmaI);
						k[j]->setKaybetme(k[j], kaybetmeJ);

					}
					else if (berabere == 1) {//k[j] kazansýn

						int fark = k[j]->getPuan(k[j]) - k[i]->getPuan(k[i]) + 100;
						int oran = fark * 100 / 1000;
						k[i]->setPopulasyon(k[i], (k[i]->getPopulasyon(k[i]) - (k[i]->getPopulasyon(k[i])) * oran / 100));
						k[i]->setYemekStogu(k[i], (k[i]->getYemekStogu(k[i]) - (k[i]->getPopulasyon(k[i])) * oran / 100));
						k[j]->setYemekStogu(k[j], (k[j]->getYemekStogu(k[j]) + (k[i]->getPopulasyon(k[i])) * oran / 100));



						k[j]->setKazanma(k[j], kazanmaJ);
						k[i]->setKaybetme(k[i], kaybetmeI);
					}
					else {
						
					}

				}


			}

		}

		for (int q = 0, z = 0; q < 15 && z < 14; q += 2, z += 2) {
			uret[q] = a1->super->uret(a1);
			uret[z] = b1->super->uret(b1);
		}

		//tur sonu 
		for (int w = 0; w < koloniSayisi; w++) {

			int uSecim = rand() % 14;
			int uOnceki = k[w]->getYemekStogu(k[w]);
			k[w]->setYemekStogu(k[w], (uOnceki + uret[uSecim]));


			if (k[w]->getPopulasyon(k[w]) != 0 && k[w]->getYemekStogu(k[w]) != 0) {
				//pop
				int pop = k[w]->getPopulasyon(k[w]);
				k[w]->setPopulasyon(k[w], pop + (pop * 20 / 100));
				//stok  
				int stok = k[w]->getYemekStogu(k[w]) - pop * 2;
				k[w]->setYemekStogu(k[w], stok);
			}

			if (k[w]->getPopulasyon(k[w]) <= 0 || k[w]->getYemekStogu(k[w]) <= 0) {
				k[w]->setPopulasyon(k[w],0);
				k[w]->setYemekStogu(k[w],0);
				k[w]->setKazanma(k[w],0);
				k[w]->setKaybetme(k[w],0);
			}
		}
		printf("------------------------------------------------------------------");
		printf("\n");

		tur++;

		int sayi = 0;
		for (int w = 0; w < koloniSayisi; w++) {
			if (k[w]->getPopulasyon(k[w]) == 0) {
				sayi++;
			}

		}

		if (sayi == (koloniSayisi - 1)) break;
	}
	printf("\n");
	printf("------------------------------------------------------------------");
	printf("\n");

	printf("Tur Sayisi: %d\n ", tur);

	printf("% s\n", "Koloni   Populasyon   YemekStogu   Kazanma   Kaybetme");

	for (int i = 0; i < koloniSayisi; i++) {

		k[i]->toString(k[i]);
		printf("\n");

	}
	printf("------------------------------------------------------------------");
	printf("\n");



}
void OyunYoket(const Oyun this) {

	free(this);
}
