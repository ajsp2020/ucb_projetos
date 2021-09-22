package condominio.entities;

import java.util.Date;

import condominio.entities.enums.Status;

public class Servico {
	
	private String tipo;
	private Empresa empresa;
	private Date data;
	private String preco;
	private Status status;
	
	
	public Servico() {
	}


	public Servico(String tipo, Empresa empresa, Date data, String preco, Status status) {
		this.tipo = tipo;
		this.empresa = empresa;
		this.data = data;
		this.preco = preco;
		this.status = status;
	}


	public String getTipo() {	
		return tipo;
	}

	
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}


	public Empresa getEmpresa() {
		return empresa;
	}


	public void setEmpresa(Empresa empresa) {
		this.empresa = empresa;
	}


	public Date getData() {
		return data;
	}


	public void setData(Date data) {
		this.data = data;
	}


	public String getPreco() {
		return preco;
	}


	public void setPreco(String preco) {
		this.preco = preco;
	}


	public Status getStatus() {
		return status;
	}


	public void setStatus(Status status) {
		this.status = status;
	}

	
}
