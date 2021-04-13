import re

class Questao1:
    def __init__(self, placa, velocidade):
        if self.valida_placa(placa):
            self.__placa = placa
        if self.valida_velocidade(velocidade):
            self.__velocidade = velocidade
        else:
            raise ValueError("Velocidade não pode ser inferior a zero:")


    def valida_velocidade(self, velocidade):
        if velocidade > 0:
            return True
        else:
            return False
    
    def valida_placa(self, placa):
        padrao = "[a-zA-Z]{3}[0-9][A-Za-z0-9][0-9]{2}"
        resposta = re.findall(padrao, placa)
        if resposta:
            return True
        else:
            return False
    
    def seramutado(self):
        if self.__velocidade > 80:
            return True
        return False

    def imprimeresultado(self):

        if self.seramutado():
            print(f"O veículo placa {self.__placa} sera multado")
        else:
            print(f"O veículo placa {self.__placa} não sera multado")

            

    def __str__(self):
        return ("Questao 1: \n\nConstrua um algoritmo que a partir da leitura da velocidade e placa do carro, avise ao\n"
            "motorista somente se ele será multado, quando estiver trafegando no Eixo Rodoviário \n(limite" 
            "de 80 km/h).\n")

    


if __name__ == '__main__':


    q = Questao1('aaa1111', 70)
    q.imprimeresultado()