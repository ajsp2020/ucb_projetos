
public class Questao2 {
	
	private double valor;
	
	public Questao2(double valor) {
		this.valor = valor;
		
		this.valorabsoluto();
		this.imprimevalor();
	}
	
	public double valorabsoluto() {
		if (this.valor < 0) {
			this.valor = -this.valor;
		}
		return this.valor;
	}
	 public void imprimevalor() {
		 System.out.println(this.valor);
	 }
}
