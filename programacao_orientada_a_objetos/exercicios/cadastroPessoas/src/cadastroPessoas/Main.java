package cadastroPessoas;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in); 
		//classe objeto =  método
		Pessoa pessoa1 = new Pessoa(); // Instanciando o objeto.
		Pets pet1 = new Pets();
		
		pessoa1.setNome(scan.nextLine());	
		System.out.println("Nome: "+ pessoa1.getNome());
	}
	
	// Definir uma classe que faz o cadastro e a impressao dos dados do professor

}
