package cadastroProfessores;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Professor {

	
	// Atributos (encapsuladas)
	private String departamento;
	private List<Aula> aulas = new ArrayList<>();
	private Dados dadoPessoais;
	
	
	
	public Dados getDado() {
		return dadoPessoais;
	}


	public void setDado(Dados dado) {
		this.dadoPessoais = dado;
	}


	public String getDepartamento() {
		return departamento;
	}
	
	
	public void setDepartamento(String departamento) {
		this.departamento = departamento;
	}
	
	public List<Aula> getAulas() {
		return Collections.unmodifiableList(aulas);
	}
	
	public void adiciona(Aula aula) {
		this.aulas.add(aula);
	}
	
			
}
