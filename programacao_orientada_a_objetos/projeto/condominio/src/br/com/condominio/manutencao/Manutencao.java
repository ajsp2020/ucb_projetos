package br.com.condominio.manutencao;

public class Manutencao {
	
	private String dataAtual;
	private String dataProxima;
	private String[] servicos = {"Pintura", "Limpeza", "Troca"};
	private String nomeDaEmpresa;
	private String observacao;
	private double precoMaterial;
	private double precoMaoDeObra;
	
	
	public String[] getServicos() {
		return servicos;
	}
	
	
	
}
