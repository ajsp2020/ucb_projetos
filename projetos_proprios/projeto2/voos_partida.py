import pandas as pd

def dados():
    dataset = pd.read_csv("registros_2020-12-01.csv", sep=";")

    dataset = dataset.drop(columns=['Equip ', 'Seg', 'Ter', 'Qua', 'Qui', 'Sex', 'Sáb', 'Dom',
                                    'Nº SIROS', 'Situação SIROS', 'Data Registro', 'Início Operação', 'Fim Operação',
                                    'Natureza Operação', 'Nº Etapa', 'Tipo Serviço', 'Codeshare'])

    a_renomear = {
        'Cód  Empresa': 'codigo_empresa',
        'Empresa': 'empresa',
        'Empresa numero': 'empresa_numero',
        'Nº Voo': 'numero_voo',
        'Quant  Assentos': 'quantidade_assentos',
        'Cód  Origem': 'codigo_origem',
         'Arpt Origem': 'aeroporto_origem',
        'Cód Destino': 'codigo_destino',
        'Arpt Destino': 'aeroporto_destino',
        'Horário Partida': 'horario_partida',
        'Horário Chegada': 'horario_chegada',
        'Objeto Transporte': 'objeto_transporte'
    }

    dataset = dataset.rename(columns=a_renomear)
    dataset = dataset[['codigo_destino', 'aeroporto_destino']]

    dataset.to_csv("dados_voo.csv", index=False)
    print('dado criado')
    return dataset

if __name__=='__main__':
    dados()