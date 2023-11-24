import java.util.Random;

abstract class CaseBonus extends Case {

	public int getValeur() {
		return this.valeur;
	}

	public void setValeur(int v) {
		this.valeur = v;
	}

	public String getLabelValeur() {
		return String.valueOf(this.valeur);
	}

	public String getLabelPv() {
		return null;
	}

	public static CaseBonus newCase() {
		double r = Math.random();
		CaseBonus res;
		Random rand = new Random();
		if(r < 0.4){
			res = new Or(5 + rand.nextInt(21));
		} else if(r < 0.75) {
			res = new Arme(5 + rand.nextInt(9));
		} else{
			res = new Potion(4 + rand.nextInt(5));
		}
		return res;
	}

}
