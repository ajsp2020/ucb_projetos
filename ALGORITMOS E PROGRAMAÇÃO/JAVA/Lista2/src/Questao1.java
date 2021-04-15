
public class Questao1 {

	private int velocidade;
	private String placa;
	
	
	public Questao1(int velocidade, String placa) {
		
		this.velocidade = velocidade;
		this.placa = placa;
		
		this.imprimevalor();
	}
	
	public boolean seramultado() {
		if (this.velocidade > 80) {
			return true;
		}
		return false;
	}
	
	public void imprimevalor() {
		if (this.seramultado()) {
			System.out.println("Veículo placa " + this.placa + " Esta trafegado com a velocidade de "+ this.velocidade + "km/k: Sera multado");
		}
	}
}


