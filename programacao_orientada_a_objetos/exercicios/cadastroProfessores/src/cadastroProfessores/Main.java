package cadastroProfessores;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		Dados dados = new Dados();
		System.out.printf("Nome: "); dados.setNome(scan.nextLine());
		System.out.printf("CPF: "); dados.setCpf(scan.nextLine());
		System.out.printf("Endereço: "); dados.setEndereco(scan.nextLine());
		System.out.printf("Telefone: "); dados.setTelefone(scan.nextLine());
		System.out.printf("Email: "); dados.setEmail(scan.nextLine());
		System.out.printf("Idade: "); dados.setIdade(scan.nextInt());
		
		
		Professor professor = new Professor();
		professor.setDado(dados);
		System.out.printf("Departamento: "); professor.setDepartamento(scan.nextLine());
		
		int resposta = 1;
		do {
			System.out.println("Deseja adicionar uma aula?");
			System.out.println("0 - Não:");
			System.out.println("1 - Sim");
			System.out.printf("Resposta: "); resposta = scan.nextInt();
			
			if (resposta == 1) {
				System.out.print("Aula: "); String classe = scan.nextLine(); // Ver pq não está funcionando
				System.out.print("Dia da semana: "); String dia = scan.nextLine();
				professor.adiciona(new Aula(classe, dia));
			}
			
			
		}while(resposta != 0);
		
		
		System.out.println(professor.getDado().getNome());
		System.out.println(professor.getDado().getCpf());
		System.out.println(professor.getAulas());

	}
	
	
	// CONTINUAR E DESCOBRIR UMA FORMA DE INSTANCIAR OS DADOS

}
