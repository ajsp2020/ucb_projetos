package cadastroProfessores;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Professor prof1 = new Professor();
		Dados joao = new Dados();
		joao.setNome("Antonio joão");	
		joao.setCpf("12345678-9");
		joao.setEndereco("Aguas claras");
		joao.setTelefone("619999-9999");
		joao.setEmail("algumacoisa@algumacoisa.com");
		prof1.setDado(joao);
		
		System.out.println(prof1.getDado().getNome());
		System.out.println(prof1.getDado().getCpf());
		
		prof1.adiciona(new Aula("Programação orientada a objeto", "Terça-feira"));
		prof1.adiciona(new Aula("Programação estruturada", "Segunda-feira"));
		prof1.adiciona(new Aula("Programação estruturada", "Segunda-feira"));
		
		System.out.println(prof1.getAulas());

	}
	
	
	// CONTINUAR E DESCOBRIR UMA FORMA DE INSTANCIAR OS DADOS

}
