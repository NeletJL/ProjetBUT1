abstract class Case {

	protected int valeur = 0;
	abstract String getLabel();
	abstract String getLabelPv();
	abstract String getLabelValeur();
	abstract int getValeur();

	public static Case newCase() {
		double r = Math.random();
		Case res;
		if(r < 0.5) {
			res = new Monstre();
		} else {
			res = CaseBonus.newCase();
		}	
		return res;
	} 

}
