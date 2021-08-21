package cadastroProfessores;

public class Aula {
	
	private String nome;
	private String diaDaSemana;
	
	public Aula(String nome, String diaDaSemana) {
		this.nome = nome;
		this.diaDaSemana = diaDaSemana;
		
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Aula: "+ this.nome + ", Dia: " + this.diaDaSemana;
	}
	
	
}
