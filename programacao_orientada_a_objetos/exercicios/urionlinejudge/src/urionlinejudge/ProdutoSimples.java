package urionlinejudge;

import java.util.Scanner;

public class ProdutoSimples {

	public static void main(String[] args) {
		
		// Leia dois valores inteiros. A seguir, calcule o produto entre estes dois valores e atribua esta operação à variável PROD. A seguir mostre a variável PROD com mensagem correspondente.
		
		Scanner ler = new Scanner(System.in);
		
		double valor1, valor2, prod;
		
		System.out.printf("Digite o primeiro valor: ");
		valor1 = ler.nextDouble();
		
		System.out.printf("Digite o segundo valor: ");
		valor2 = ler.nextDouble();
		
		prod = valor1 * valor2;
		
		System.out.printf("O produto da operação: %.2f * %.2f = %.2f", valor1, valor2, prod);
		
		
		/*
		  	%d – for signed decimal integer

			%f – for the floating point

			%o – octal number

			%c – for a character

			%s – a string

			%i – use for integer base 10

			%u – for unsigned decimal number

			%x – hexadecimal number

			%% – for writing % (percentage)

			%n – for new line = \n
		 */
	}

}
