package odev;

public class Koloni {
	
	private char simge;
	private int populasyon;
	private int yemekStogu;
	private int kazanma;
	private int kaybetme;
	private int puan;
	
	
	
	public Koloni(int populasyon,char simge) {
		this.simge = simge;
		this.populasyon=populasyon;
		this.yemekStogu = (int) Math.pow(populasyon, 2);
		this.kazanma = 0;
		this.kaybetme=0;
	}

	@Override
	public String toString() {
		
		String str = " "+simge + "\t   " + populasyon + " \t\t  " + yemekStogu + "\t  \t" +kazanma + "  \t" + kaybetme ;

		return str;
	}

	public int getPopulasyon() {
		return populasyon;
	}

	public void setPopulasyon(int populasyon) {
		this.populasyon = populasyon;
	}

	public int getYemekStogu() {
		return yemekStogu;
	}

	public void setYemekStogu(int yemekStogu) {
		this.yemekStogu = yemekStogu;
	}

	

	public int getKazanma() {
		return kazanma;
	}

	

	public void setKazanma(int kazanma) {
		this.kazanma = kazanma;
	}
	
	public int getKaybetme() {
		return kaybetme;
	}

	public void setKaybetme(int kaybetme) {
		this.kaybetme = kaybetme;
	}

	public int getPuan() {
		return puan;
	}

	public void setPuan(int puan) {
		this.puan = puan;
	}
	
	
	
	
	
	
	
	
	
	

	

}
