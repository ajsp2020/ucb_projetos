package br.com.condominio.manutencao;

import br.com.condominio.operacoes.Data;

public class Manutencao {
	
	private Data dataAtual;
	private Data dataProxima;
	private String[] servicos = {"Pintura", "Limpeza", "Troca"};
	private String nomeDaEmpresa;
	private String observacao;
	private double precoMaterial;
	private double precoMaoDeObra;
	
	
	public String[] getServicos() {
		return servicos;
	}


	public Data getDataAtual() {
		return dataAtual;
	}


	public Data getDataProxima() {
		return dataProxima;
	}


	public void setDataProxima() {
		this.dataProxima = new Data();
		
	}


	public void setDataAtual() {
		this.dataAtual = new Data();
	}

	
	
}
