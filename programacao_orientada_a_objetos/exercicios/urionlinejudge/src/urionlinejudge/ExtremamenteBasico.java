package urionlinejudge;
import java.util.Scanner;

/*
Leia 2 valores inteiros e armazene-os nas variáveis A e B. Efetue a soma de A e B atribuindo o seu resultado na variável X. 
Imprima X conforme exemplo apresentado abaixo. Não apresente mensagem alguma além daquilo que está sendo especificado 
e não esqueça de imprimir o fim de linha após o resultado, caso contrário, você receberá "Presentation Error"
*/
public class ExtremamenteBasico {

	public static void main(String[] args) {
		
		Scanner ler = new Scanner(System.in);
		
		int a, b;
		
		System.out.printf("Digite o valor de A: ");
		a = ler.nextInt();
		
		System.out.printf("Digite o valor de B: ");
		b = ler.nextInt();
			
		int x = a + b;
		
		System.out.printf("Valor de %d + %d = %d ", a, b, x);
		
	}
	

}
