package odev;

import java.util.Random;

public class BTaktik extends Taktik {
	
	public BTaktik() {
		
	}

	@Override
	public int Savas() {
		
		Random rastgele = new Random();
        int sayi = rastgele.nextInt(1000) ;
		
		return sayi;
	}

}
