package odev;

import java.util.Iterator;
import java.util.Random;
import java.util.Scanner;

public class Oyun {
	
	Scanner scanner = new Scanner(System.in);
		
	
	public void basla() { 
		
		
		
		
		
		String str = scanner.nextLine();
        String[] strArray = str.split(" ");
        int[] intArray = new int[strArray.length];

        for (int i = 0; i < strArray.length; i++) {
            intArray[i] = Integer.parseInt(strArray[i]);
        }
        
        Koloni [] k = new Koloni[intArray.length];
        
        char [] s = new char [intArray.length] ;
        
        for(int i =65 , j =0; i< 65+intArray.length;i++,j++) {
        	s[j]=(char)i;
        }

        for (int i = 0; i < intArray.length; i++) {
        	
        	k[i]=new Koloni(intArray[i],s[i]);
            //System.out.print(intArray[i] + " \n");
        }
        
        //simge çevirme
       /*int a =65;
       char b = (char)a;
       
       System.out.println(b);*/
        
        
       
       //koloni yazdýrma
       // for(int i=0;i<intArray.length;i++ ) {
    	//   System.out.println(k[i]);
       //}
       
       
       
       /*
       //4 populasyon varsa
       for(int i =0 ; i<3 ;i++) { //  i =lengt-1 sýnýr
    	   for(int j=i+1 ; j<4;j++) { // j=lengt sýnýr
    		   
    		   System.out.println(i + " "+j);
    	   }
       }*/
        
        
        ATaktik a = new ATaktik();
        BTaktik b = new BTaktik();
        
        AUretim a1 = new AUretim();
        BUretim b1 = new BUretim();

        
        int [] puan = new int[15];
        
        int [] uret = new int[15];
       
        
        Random random = new Random();
        //int r = random.nextInt(2);
        
        //System.out.println(puan[r]);
       
       
       int tur =0;
       
       while(true) {
    	   
    	   System.out.println("-------------------------------------------------------");
           System.out.println("Tur Sayisi:"+tur);
           System.out.println("Koloni   Populasyon   Yemek Stogu   Kazanma  Kaybetme");
           for(int i=0;i<intArray.length;i++ ) {
           	System.out.println(k[i]);
           }
           System.out.println("\n-------------------------------------------------------");
    	   
    	   
    	   for(int i =0 ; i<intArray.length-1 ; i++) { //  i =lengt-1 sýnýr
        	   for(int j=i+1 ; j<intArray.length ; j++) { // j=lengt sýnýr
        		   
        		   if(k[i].getPopulasyon() == 0 || k[j].getPopulasyon() == 0) {// elenen koloni olunca savasý olmayacak
        			   continue;
        		   }
        		   
        		   
        		   
        		   for(int q =0,z=1;q<15 && z<15  ;q+=2,z+=2) { 
        			   puan[q]=a.Savas();   
        			   puan[z]=b.Savas(); 
        		   }
        		   
        		   int r = random.nextInt(15);
        		   int t = random.nextInt(15);
        		   
        		   k[i].setPuan(puan[r]);
        		   k[j].setPuan(puan[t]);
        		   
        		   int kazanmaI = k[i].getKazanma()+1;
        		   int kazanmaJ = k[j].getKazanma()+1;
        		   int kaybetmeI = k[i].getKaybetme()+1;
        		   int kaybetmeJ = k[j].getKaybetme()+1;
        		   
        		   
        		   
        		   
        		   System.out.println(k[i].getPuan()+","+k[j].getPuan());

        		   
        		   if(k[i].getPuan()>k[j].getPuan()) {//k[i] kazanýr
        			   
        			   int fark = k[i].getPuan() - k[j].getPuan();
        			   int oran = fark*100/1000;
        			   k[j].setPopulasyon(k[j].getPopulasyon() - (k[j].getPopulasyon()*oran/100));
        			   k[j].setYemekStogu(k[j].getYemekStogu() - (k[j].getPopulasyon()*oran/100));
        			   k[i].setYemekStogu(k[i].getYemekStogu() + (k[j].getPopulasyon()*oran/100));
        			   
        			  
        			   
        			   k[i].setKazanma(kazanmaI);
        			   k[j].setKaybetme(kaybetmeJ);
        			   
        		   }
        		   else if(k[i].getPuan()<k[j].getPuan()) {//k[i] kaybeder
        			   
        			   
        			   int fark = k[j].getPuan() - k[i].getPuan();
        			   int oran = 1000/fark;
        			   k[i].setPopulasyon(k[i].getPopulasyon() - (k[i].getPopulasyon()*oran/100));
        			   k[i].setYemekStogu(k[i].getYemekStogu() - (k[i].getPopulasyon()*oran/100));
        			   k[j].setYemekStogu(k[j].getYemekStogu() + (k[i].getPopulasyon()*oran/100));
        			   
        			   
        			   
        			   k[j].setKazanma(kazanmaJ);
        			   k[i].setKaybetme(kaybetmeI);
        			   
        		   }
        		   else {//berabere
        			   
        			   int berabere = random.nextInt(2);
        			   
        			   
        			   if(berabere == 0) {//k[i] kazansýn
        				   
        				   int fark = k[i].getPuan() - k[j].getPuan() + 100;
            			   int oran = fark*100/1000;
            			   k[j].setPopulasyon(k[j].getPopulasyon() - (k[j].getPopulasyon()*oran/100));
            			   k[j].setYemekStogu(k[j].getYemekStogu() - (k[j].getPopulasyon()*oran/100));
            			   k[i].setYemekStogu(k[i].getYemekStogu() + (k[j].getPopulasyon()*oran/100));
            			   
        				   
            			   
            			   k[i].setKazanma(kazanmaI);
            			   k[j].setKaybetme(kaybetmeJ);
        				   
        			   }
        			   else if(berabere == 1) {//k[j] kazansýn
        				   
        				   int fark = k[j].getPuan() - k[i].getPuan() +100;
            			   int oran = fark*100/1000;
            			   k[i].setPopulasyon(k[i].getPopulasyon() - (k[i].getPopulasyon()*oran/100));
            			   k[i].setYemekStogu(k[i].getYemekStogu() - (k[i].getPopulasyon()*oran/100));
            			   k[j].setYemekStogu(k[j].getYemekStogu() + (k[i].getPopulasyon()*oran/100));
        				   
            			   
            			   k[j].setKazanma(kazanmaJ);
            			   k[i].setKaybetme(kaybetmeI);
        				   
        			   }
        			   else {
        				   ;
        			   }
        			   
        		   }
        			   
        		   
        		   
        		   
        		   
        		   
        		   
        		   
        		   
        		   
        		   
        		   System.out.println(i + " "+j);
        	   }
        	
        	   
    	   }
    	   
    	   
    	   for(int q =0,z=0;q<15 && z<15;q+=2,z+=2) { 
			   uret[q]=a1.Uret();   
			   uret[z]=b1.Uret(); 
		   }
    	   
    	   
    	 //tur sonu olanlar
    	   for(int w =0;w<intArray.length;w++) {
    		   
    		   int uSecim = random.nextInt(15);
    		   int uOnceki= k[w].getYemekStogu();
    		   k[w].setYemekStogu(uOnceki+uret[uSecim]);// her tur 1-10 yemek ekle stoða
    		   
    		   if(k[w].getPopulasyon() <= 0 || k[w].getYemekStogu() <=0 ) {// koloni elenirse
    			   k[w].setPopulasyon(0);
    			   k[w].setYemekStogu(0);
    			   k[w].setKazanma(0);
    			   k[w].setKaybetme(0);
    		   }
    		   
    		   if(k[w].getPopulasyon() != 0 || k[w].getYemekStogu() != 0){// pop ve stok iþlemleri
    			 //pop
    			   int pop = k[w].getPopulasyon();
    			   k[w].setPopulasyon(pop + (pop*20/100));
    			 //stok  
        		   int stok = k[w].getYemekStogu() -pop*2;
        		   k[w].setYemekStogu(stok);
    		   }
    		   else {
    			   ;
    		   }
    		   
    		 
    	   }
        	   
        tur++;
        
        int sayi =0;
        for (int w =0;w<intArray.length;w++) {
        	if(k[w].getPopulasyon() == 0){
        		sayi++;
        	}
        	
        }
        
        if(sayi==(intArray.length-1)) break;  
        
       }
       
       
       
       
       System.out.println("-------------------------------------------------------");
       System.out.println("Tur Sayisi:"+tur);
       System.out.println("Koloni   Populasyon   Yemek Stogu   Kazanma  Kaybetme");
       for(int i=0;i<intArray.length;i++ ) {
       	System.out.println(k[i]);
       }
       System.out.println("\n-------------------------------------------------------");
       
       
       
       
       	
		
	}

}
