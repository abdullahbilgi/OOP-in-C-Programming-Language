#include "Ataktik.h"
#include "Btaktik.h"
#include "Auretim.h"
#include "Buretim.h"
#include "Math.h"
#include "Koloni.h"
#include "Oyun.h"

int main() {
		
	Oyun oyun = OyunOlustur();
	oyun->basla(oyun);

	return 0;
}
