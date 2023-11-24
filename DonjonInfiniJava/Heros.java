import java.util.Random;

public class Heros extends Case {

	protected int pv;
	protected Arme wp;
	public String nom; 

	protected String type[] = {"Feu", "Vent", "Foudre", "Terre", "Eau", "Lumière", "Ténèbres"};

	public Heros() {
		this.pv = 10;
		this.wp = null;

		Random r = new Random();
		int typeval = r.nextInt(7);
		this.nom = type[typeval];
	}

	public String getNomArme() {
		return this.wp.getLabel();
	}

	public int getValeur() {
		return 0;
	}

	public void setPv(int v) throws IllegalStateException {
		pv += v;
		if (pv <= 0) {
			throw new IllegalStateException("Mort");
		}
	}

	public void setWp(Arme a) {
		if(a.getValeur() > wp.getValeur()) {
			wp = a;
		}
	}

	public boolean rencontrer(Case c) {
		if (c instanceof Monstre) {
			Monstre m = (Monstre) c;

			if(this.wp == null) {
				int mpv = m.getPv();
				String typH = this.nom;
				String typM = m.getType();
				switch (typH){
					case "Feu":
						if (typM == "Vent") {
							m.setPv((mpv-2) - this.pv);
						try {
							if (mpv > 1) {
								this.setPv(-mpv+2);
							}
						} catch (IllegalStateException e){
							throw e;
						}
						} else if (typM == "Eau") {
							m.setPv((mpv+2) - this.pv);
							try {
								this.setPv(-mpv-2);
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
						try {
							this.setPv(-mpv);
						} catch (IllegalStateException e) {
							throw e;
						}
						}
						break;
					case "Vent":
						if (typM == "Foudre") {
							m.setPv((mpv-2) - this.pv);
							try {
								if (mpv > 1) {
									this.setPv(-mpv+2);
								}
							} catch (IllegalStateException e) {
								throw e;
							}
						} else if (typM == "Feu") {
							m.setPv((mpv + 2) - this.pv);
							try {
								this.setPv(-mpv-2);
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
							try {
								this.setPv(-mpv);
							} catch (IllegalStateException e) {
								throw e;
							}
						}
						break;
					case "Foudre":
						if (typM == "Terre") {
							m.setPv((mpv - 2) - this.pv);
							try {
								if (mpv > 1) {
									this.setPv(-mpv+2);
								}
							} catch (IllegalStateException e) {
								throw e;
							}
						} else if (typM == "Vent") {
							m.setPv((mpv + 2) - this.pv);
							try {
								this.setPv(-mpv-2);
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
							try{
								this.setPv(-mpv);
							} catch (IllegalStateException e) {
								throw e;
							}
						}
						break;
					case "Terre":
						if (typM == "Eau") {
							m.setPv((mpv-2) - this.pv);
							try{
								if (mpv > 1) {
									this.setPv(-mpv+2);
								}
							} catch (IllegalStateException e) {
								throw e;
							}
						} else if (typM == "Foudre") {
							m.setPv((mpv+2)-this.pv);
							try{
								this.setPv(-mpv-2);
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
							try{
								this.setPv(-mpv);
							} catch (IllegalStateException e) {
								throw e;
							}
						}
						break;
					case "Eau":
						if (typM == "Feu") {
							m.setPv((mpv-2) - this.pv);
							try {
								if (mpv > 1) {
									this.setPv(-mpv+2);
								}
							} catch (IllegalStateException e) {
								throw e;
							}
						} else if (typM == "Terre") {
							m.setPv((mpv+2) - this.pv);
							try {
								this.setPv(-mpv-2);
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
							try{
								this.setPv(-mpv);
							} catch (IllegalStateException e) {
								throw e;
							}
						}
						break;
					case "Lumière":
						if (typM == "Ténèbres") {
							m.setPv((mpv-1) - this.pv);
							try {
								if (mpv > 0) {
									this.setPv(-mpv+1);
								}
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
							try {
								this.setPv(-mpv-1);
							} catch (IllegalStateException e) {
								throw e;
							}
						}
						break;
					case "Ténèbres":
						if (typM == "Lumière") {
							m.setPv((mpv-1) - this.pv);
							try {
								if (mpv > 0) {
									this.setPv(-mpv);
								}
							} catch (IllegalStateException e) {
								throw e;
							}
						} else {
							m.setPv(mpv - this.pv);
							try {
								this.setPv(-mpv);
							} catch (IllegalStateException e) {
								throw e;
							}
						}
						break;
				}
				return true;
			} else {
				int mpv = m.getPv();
				String typH = this.nom;
				String typM = m.getType();
				switch (typH) {
					case "Feu":
						if (typM == "Vent") {
							m.setPv(mpv - (this.wp.getValeur()+2));
						}
						else if (typM == "Eau") {
							m.setPv(mpv - (this.wp.getValeur()-2));
						} 
						else {
							m.setPv(mpv-this.wp.getValeur());
						}
						break;
					case "Vent":
						if (typM == "Foudre") {
							m.setPv(mpv - (this.wp.getValeur()+2));
						}
						else if (typM == "Feu") {
							m.setPv(mpv - (this.wp.getValeur()-2));
						}
						else {
							m.setPv(mpv - this.wp.getValeur());
						}
						break;
					case "Foudre":
						if (typM == "Terre") {
							m.setPv(mpv - (this.wp.getValeur()+2));
						}
						else if (typM == "Vent") {
							m.setPv(mpv - (this.wp.getValeur()-2));
						}
						else {
							m.setPv(mpv - this.wp.getValeur());
						}
						break;
					case "Terre":
						if (typM == "Eau") {
							m.setPv(mpv - (this.wp.getValeur()+2));
						}
						else if (typM == "Foudre") {
							m.setPv(mpv - (this.wp.getValeur()-2));
						}
						else {
							m.setPv(mpv - this.wp.getValeur());
						}
						break;
					case "Eau":
						if (typM == "Feu") {
							m.setPv(mpv - (this.wp.getValeur()+2));
						}
						else if (typM == "Terre") {
							m.setPv(mpv - (this.wp.getValeur()-2));
						}
						else {
							m.setPv(mpv - this.wp.getValeur());
						}
						break;
					case "Lumière":
						if (typM == "Ténèbres") {
							m.setPv(mpv - (this.wp.getValeur()+1));
						}
						else {
							m.setPv(mpv - this.wp.getValeur());
						}
						break;
					case "Ténèbres":
						if (typM == "Lumière") {
							m.setPv(mpv - (this.wp.getValeur()+1));
						}
						else {
							m.setPv(mpv - this.wp.getValeur());
						}
						break;
				}
				int mpvt = m.getValeur();
				if (this.wp.getLabel() == "Carotte") {
					if ((mpvt > this.wp.getValeur()) && (m.getPv() <= 0)) {
						this.wp.dura--;
					} else if (mpvt <= this.wp.getValeur()) {
						this.wp.dura = this.wp.dura - 3;
					}
				} else if (this.wp.getLabel() == "Hache") {
					this.wp.dura--;
					if (m.getPv() <= 0) {
						this.setPv(2);
					}
				} else if (this.wp.getLabel() == "Arme") {
					this.wp.dura--;
				}
				if(this.wp.dura <= 0) {
					this.wp = null;
				}
				return false;
			}
		}
		if (c instanceof Arme) {
			Arme a = (Arme) c;
			if(this.wp == null) {
				this.wp = a;
			} else if ((a.getLabel() == "Carotte") && ((this.wp.getLabel() == "Arme") || (this.wp.getLabel() == "Hache"))) {
				this.wp = a;
			} else if ((this.wp.valeur <= a.valeur) && (this.wp.dura <= a.dura) && (this.wp.getLabel() == "Carotte")) {
				this.wp = a;
			} else if ((a.getLabel() == "Hache") && (this.wp.getLabel() == "Arme")) {
				this.wp = a;
			} else if ((this.wp.valeur <= a.valeur) && (this.wp.dura <= a.dura) && (this.wp.getLabel() == "Hache")) {
				this.wp = a;
			} else if ((this.wp.valeur <= a.valeur) && (this.wp.dura <= a.dura) && (this.wp.getLabel() == "Arme") && (a.getLabel() == "Arme")) {
				this.wp = a;
			} else {
				this.setWp(a);
			}
			return true;
		}
		if (c instanceof Potion) {
			Potion p = (Potion) c;
			this.pv += p.getValeur();
			return true;
		}
		return true;
	}

	public String getLabelValeur() {
		if (wp == null) {
			return null;
		}
		return wp.getLabelValeur();
	}

	public String getLabelPv() {
		return String.valueOf(this.pv);
	}

	public String getLabel() {
		return this.nom;
	}

}
