package cadastroPessoas; // Em qual pacote a classe está

public class Pessoa {
	
	
	// Atributos:
	private String nome;
	private String cpf;
	private String telefone;
	private String email;
	private String endereco;
	private int idade;
	
	public Pessoa() { // Construtor
			
	}

	public String getNome() { // Getter -> método papra recuperar valores
		return nome;
	}

	public void setNome(String nome) { // Setter -> método para adicionar valores
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	
}
