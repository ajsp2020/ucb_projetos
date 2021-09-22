package condominio.program;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.TimeZone;

import condominio.entities.Cliente;
import condominio.entities.Dados;
import condominio.entities.Empresa;
import condominio.entities.Endereco;
import condominio.entities.Servico;


public class Program {
	

	public static void main(String[] args) {
		
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		int menu;
		Dados condominio = new Cliente();
		
		do {
			
			System.out.println("Menu:");
			System.out.println("0 - Sair.");
			System.out.println("1 - Adicionar Condomínnio.");
			System.out.println("2 - Adicionar Empresa.");
			System.out.println("3 - Adicionar Serviço");
			System.out.println("4 - Mostrar Dados");
			menu = sc.nextInt();

		
			switch (menu) {
			case 0: {
				
				break;
			}
			case 1: {
				
				System.out.print("Nome do Condomínio: ");
				String nome = sc.nextLine(); // estou com problema em pegar o nome.
				sc.nextLine();
				System.out.println("Endereço do Condomínio");
				
				System.out.print("Rua: ");
				String rua = sc.nextLine();
				
				System.out.print("Numero: ");
				String numero = sc.nextLine();
				
				System.out.print("CEP: ");
				String cep = sc.nextLine();
				
				System.out.print("Cidade: ");
				String cidade = sc.nextLine();
				
				System.out.print("Estado: ");
				String estado = sc.nextLine();
				
				System.out.print("Pais: ");
				String pais = sc.nextLine();
				
				System.out.print("CNPJ: ");
				String cnpj = sc.nextLine();
				
				System.out.print("Sindico: ");
				String sindico = sc.nextLine();
				
				condominio = new Cliente(nome, 
						new Endereco(rua, numero, cep, cidade, estado, pais), 
						cnpj, 
						sindico);
					
				break;
			}
			
			case 2: {
				
				break;
			}
			case 3: {
				
				break;
			}
			case 4: {
				
				System.out.println(condominio);
				
				break;
			}
				
			default:
				break;
			}
			
		}while(menu != 0);
		
		
		sc.close();
		
	}

}
