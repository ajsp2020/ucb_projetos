from base import Base

class A1():

    def __init__(self, valor1, valor2):
        self._valor_maior = int(valor1)
        self._valor_menor = int(valor2)

    def subtracao_inteiro(self):

        if abs(self._valor_maior) < abs(self._valor_menor):
            valor = self._valor_maior
            self._valor_maior = self._valor_menor
            self._valor_menor = valor

        complemento = self.calcula_complemento_decimal()
        comprimento, soma = self.soma_complementos_subtração(complemento)
        self.abandona_signaficativo(comprimento, soma)

    def calcula_complemento_decimal(self):

        casas_decimais = len(str(self._valor_maior))

        noves = ''
        for item in range(casas_decimais):
            noves += '9'

        noves = int(noves)
        complemento = noves - self._valor_menor + 1

        print("O COMPLEMENTO E:")
        print(f'C({-self._valor_menor}) = {noves} - {self._valor_menor} + 1 = {complemento}\n')


        return  complemento

    def soma_complementos_subtração(self, complemento):

        soma = self._valor_maior + complemento

        comprimento = len(str(soma)) - 1
        print("A SOMA É: ")
        print(f'{self._valor_maior} + C({self._valor_menor}) = {self._valor_maior} + {complemento} = {soma}\n')

        return comprimento, soma

    def abandona_signaficativo(self, comprimento, soma):


        subtracao = soma - 10 ** comprimento

        print("ABANDONANDO O ALGORISMO MAIS SIGNIFICATIVO: ")
        print(f'1 -> {subtracao} = {subtracao}')


    def divisao_inteiro(self):
        if abs(self._valor_maior) < abs(self._valor_menor):
            valor = self._valor_maior
            self._valor_maior = self._valor_menor
            self._valor_menor = valor

        complemento = self.calcula_complemento_decimal()
        comprimento, soma = self.soma_complementos_subtração(complemento)
        valor = self.abandona_signaficativo(comprimento, soma)
        self.divide_valor(valor)

    def divide_valor(self, valor, complemento): # Continuar a imaginar como fazer a divisão.
        contador = 0
        divisao = 1
        while(divisao > 0):
            valor + complemento



if __name__ == '__main__':

    teste = A1(728, 456)
    teste.subtracao_inteiro()