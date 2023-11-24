import java.io.*;

public class MeilleurScore {

	public void saveBestScore(int score) {
		try {
			FileOutputStream fos = new FileOutputStream("Record.bin");
			DataOutputStream dos = new DataOutputStream(fos);
			dos.writeInt(score);
			dos.close();
		} catch (IOException e) {
			System.out.println("Erreur lors de la fermeture du fichier");
		}
	}

	public int readBestScore() {
		File file = new File("Record.bin");
		if (file.exists()) {
			try {
				FileInputStream fis = new FileInputStream("Record.bin");
				DataInputStream dis = new DataInputStream(fis);
				int score = dis.readInt();
				dis.close();
				return score;
			} catch (IOException e) {
				System.out.println("Erreur lors de l'ouverture du fichier");
			}
		}
		return 0;
	}
}
