package condominio.entities;

import java.util.List;

public class Empresa extends Dados{
	
	private List<Telefone> telefones;

	public Empresa () {
		super();
		
	}

	public Empresa(String nome, Endereco endereco, String cnpj) {
		super(nome, endereco, cnpj);
	}

	public List<Telefone> getTelefones() {
		return telefones;
	}

	public void addNumber(Telefone telefone) {
		telefones.add(telefone);
	}
	
	public void removeNumber(Telefone telefone) {
		telefones.remove(telefone);
	}
	
}
