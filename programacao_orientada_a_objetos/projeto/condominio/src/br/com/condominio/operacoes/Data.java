package br.com.condominio.operacoes;

import java.util.Scanner;

public class Data {
	
	Scanner scan = new Scanner(System.in);
	
	private int dia;
	private int mes;
	private int ano;
	
	/*
	 * public Data() { System.out.print("Digite o dia: "); this.dia =
	 * scan.nextInt(); System.out.print("Digite o mes: "); this.mes =
	 * scan.nextInt(); System.out.print("Digite o ano: "); this.ano =
	 * scan.nextInt();
	 * 
	 * }
	 */
	

	public int getDia() {
		return dia;
	}

	public void setDia(int dia) {
		this.dia = dia;
	}

	public int getMes() {
		return mes;
	}

	public void setMes(int mes) {
		this.mes = mes;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}
	
	
	@Override
	public String toString() {
		return "Data: ["+ dia + "/" + mes + "/" + ano + "]";
	}

	
}
