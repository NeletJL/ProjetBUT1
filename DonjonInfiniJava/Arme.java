import java.util.Random;

public class Arme extends CaseBonus {

	public String nom; 
	public int dura;

	public Arme(int v) {
		Random rand = new Random();
		double r = Math.random();
		if (r < 0.08) {
			this.valeur = 18;
			this.dura = 8;
			nom = "Carotte";
		} else if (r < 0.30) {
			this.valeur = v;
			this.dura = v - (rand.nextInt(v-2));
			nom = "Hache";
		} else {
			this.valeur = v;
			this.dura = v - (rand.nextInt(v-2));
			nom = "Arme";
		}
	}

	public String getLabel() {
		return nom;
	}

	public int getValeur() {
		return valeur;
	}

	public String getLabelDurabilite() {
		return String.valueOf(this.dura);
	}

}
