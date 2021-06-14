import pandas as pd
import csv

from voos_partida import dados

class Voo:

    def __init__(self, codigo_destino):

        destinos = dados()

        for codigo in destinos['codigo_destino']:
            try:
                if codigo == codigo_destino:
                    print("DESTINO ENCONTRADO")
                    self.__codigo_destino = codigo_destino
                    break
            except:
                raise ValueError("DESTINO NÃO ENCONTRADO")



if __name__ == '__main__':

    arquivo = open('dados_voo.csv', "r")
    aeroportos = csv.reader(arquivo)
    # next(aeroportos)

    dados_aeroporto
    for i in range(aeroportos):
        dados_aeroporto[] =
    print(aeroportos)


    #print(Voo('KDFW'))

    # aeroportos = dados()
    # print(type(aeroportos))

    # df = pd.read_csv("dados_voo.csv", index_col=0, header=None)
    # print(df)
    # destinos = df.set_index([1])
    #
    # destinos.columns = range(destinos.shape[1])
    # next(destinos)
    # destinos = df.to_dict()
    #
    # print(destinos)
    #
    # # destinos = destinos.to_dict()
    # print(destinos)
    # print(destinos['KMIA'])


