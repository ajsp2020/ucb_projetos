package br.com.agenciaViagens.cliente;

import br.com.agenciaViagens.passagem.Passagem;

public class Cliente {
	
	private String nome;
	private String sobrenome;
	private String cpf;
	private String email;
	private String telefone;
	private Passagem passagem = new Passagem();
}
