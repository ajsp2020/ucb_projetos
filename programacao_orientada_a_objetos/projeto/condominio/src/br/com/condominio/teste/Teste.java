package br.com.condominio.teste;

import br.com.condominio.manutencao.*;

public class Teste {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Manutencao manutencao = new Manutencao();
		
		for(int i = 0; i < manutencao.getServicos().length; i++) {
			System.out.println(manutencao.getServicos()[i]);
		}
		
		
		manutencao.setDataAtual();	
		System.out.println(manutencao.getDataAtual());
		
		manutencao.setDataProxima();
		System.out.println(manutencao.getDataProxima());
		
	}

}
