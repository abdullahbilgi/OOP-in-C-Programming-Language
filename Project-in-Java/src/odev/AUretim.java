package odev;

import java.util.Random;

public class AUretim extends Uretim {
	
	public AUretim() {
		
	}

	@Override
	public int Uret() {

		Random rastgele = new Random();
        int sayi = rastgele.nextInt(10) + 1;
        
       
		
		return sayi;
	}

}
