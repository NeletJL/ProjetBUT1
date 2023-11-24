import java.util.Random;

public class Monstre extends Case {

	protected int pv;
	public String nom; 
	protected String type[] = {"Feu", "Vent", "Foudre", "Terre", "Eau", "Lumière", "Ténèbres"};

	public Monstre() {
		super();
		Random r = new Random();
		pv = 5 + r.nextInt(25);
		valeur=pv;

		int typeval = r.nextInt(7);
		this.nom = type[typeval];
	}

	public int getValeur() {
		return valeur;
	}

	public int getPv() {
		return pv;
	}

	public void setPv(int p) {
		pv = p;
	}

	public String getLabelValeur() {
		return null;
	}

	public String getLabelPv() {
		return String.valueOf(this.pv);
	}

	public String getLabel() {
		return "Monstre " + this.nom;
	}

	public String getType() {
		return this.nom;
	}

}
