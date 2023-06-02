package odev;

import java.util.Random;

public class ATaktik extends Taktik {
	
	public ATaktik() {
		
	}

	@Override
	public int Savas() {
		
		Random rastgele = new Random();
        int sayi = rastgele.nextInt(1000);
		
		return sayi;
	}

}
