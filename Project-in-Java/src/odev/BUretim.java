package odev;

import java.util.Random;

public class BUretim extends Uretim {
	
	public BUretim() {
		
	}
	

	@Override
	public int Uret() {
		
		Random rastgele = new Random();
        int sayi = rastgele.nextInt(10) + 1;
       
		return sayi;
	}

}
