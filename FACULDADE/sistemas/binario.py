
"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""


class Binario: # Transforma um valor binário ou hexadecimal em decimal
    """
     - Formula geral:
        Nb = S(n ->1) an * b ** (n -1)
        * n = Posição do algoritmo
        * b = base
        * an = Algoritmo na posição n
    """
    def __init__(self, binario):
        self.__binario = binario

        # Divide a parte fracionária da parte inteira
        if ',' in self.__binario:
            self.__inteiro, self.__fracao = self.__binario.split(',')
            print(self.__inteiro, self.__fracao)

        else:
            self.__inteiro = self.__binario
            print(self.__inteiro)


    def calcula_decimal_int(self): # Recebendo o valor em binário ou hexadecimal

        numeros = [self.__inteiro for self.__inteiro in self.__inteiro] # Separando os valores e colocando numa lista

        numeros = [int(numero) for numero in numeros] # Transformando os valores em inteiro
        n = len(numeros) - 1

        self.__soma = 0
        for numero in numeros: # Para cada numero o resultado será mutiplicado de acordo com a formula e impresso
            _ = numero * (2 ** n)
            print(f"({numero} * ({2} ** {n})): ", _) # Impressão parcial
            self.__soma += numero * (2 ** n) # formula genérica, valida para base qualquer base
            n -= 1
        #print("")
        #print(f"O valor em decimal é: {self.__soma}") # impressão total
        return self.__soma

    def calcula_hexadecimal(self):
        pass

    def calcula_inteiro(self): # Calcula a parte inteira
        self.adiciona_zero_int(self.__inteiro) # Adiciona zero a parte esquerda caso nescessário
        self.__inteiro = self.divide(self.__inteiro) # Divide em partes de 4 em 4
        self.__inteiro = self.nova_lista(self.__inteiro) # Adiciona os valores em uma nova lista
        self.__inteiro = self.__hexadecimal(self.__inteiro) # Calcula o valor equivalente em hexadecimal


    def calcula_fracao(self):
        self.adiciona_zero_fracao(self.__fracao)
        self.__fracao = self.divide(self.__fracao)
        self.__fracao = self.nova_lista(self.__fracao)
        self.__fracao = self.__hexadecimal(self.__fracao)


    def adiciona_zero_int(self, valor): # Adiciona zero a parte inteira
        valor = len(valor)
        if valor % 4 == 0:
            return self.__inteiro

        else:
            self.__inteiro = '0' + self.__inteiro
            return self.adiciona_zero_int(self.__inteiro)

    def adiciona_zero_fracao(self, valor): # Adiciona zero a parte fracionária
        valor = len(valor)
        if valor % 4 == 0:
            return self.__fracao

        else:
            self.__fracao = self.__fracao + '0'
            return self.adiciona_zero_fracao(self.__fracao)

    def divide(self, valor): # dividi as partes em intervalo de 4
        n = 4
        return [valor[i:i+n] for i in range(0, len(valor), n)]

    def nova_lista(self, valor):
        lista = []
        for v in valor:
            lista.append(Binario().calcula_decimal(v))
        return lista

    def __hexadecimal(self, valor):
        lista = []
        hexadecimais = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        for item in valor:
            for hexa in hexadecimais.keys():
                if item == hexa:
                    item = hexadecimais[hexa]

            lista.append(item)

        return lista


if __name__ == '__main__':

    Binario().calcula_hexadecimal('1011101100010100011111101,0101')