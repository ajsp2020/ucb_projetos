from base import Base
"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""


class Binario(Base): # Transforma um valor binário ou hexadecimal em decimal
    """
     - Formula geral:
        Nb = S(n ->1) an * b ** (n -1)
        * n = Posição do algoritmo
        * b = base
        * an = Algoritmo na posição n
    """
    def __init__(self, binario):
        super().__init__(binario)
        print(f"O VALOR EM BINÁRIO É DE: {binario}")

# CALCULA VALORES DE BINÁRIO -> DECIMAL:

    def decimal(self):
        inteiro = self.calcula_decimal_int()
        try:
            fracao = self.calcula_decimal_fracao()
            print(f"->> O VALOR EM DECIMAL É DE: {inteiro},{fracao} <<-")
            return inteiro, fracao
        except:
            print(f"->> O VALOR EM DECIMAL É DE: {inteiro} <<-")
            return inteiro

    def calcula_decimal_int(self): # Recebendo o valor em binário ou hexadecimal
        print("PARTE INTEIRO:")

        numeros = [int(self._inteiro) for self._inteiro in self._inteiro] # Separando os valores e colocando numa listao

        n = len(numeros) - 1
        soma = 0
        for numero in numeros: # Para cada numero o resultado será mutiplicado de acordo com a formula e impresso
            _ = numero * (2 ** n)
            print(f"({numero} * ({2} ** {n})): ", _) # Impressão parcial
            soma += numero * (2 ** n) # formula genérica, valida para base qualquer base
            n -= 1
        return str(soma)

    def calcula_decimal_fracao(self): # Calculando a parte fracionária
        print("PARTE FRAÇÃO")

        numeros = [int(self._fracao) for self._fracao in self._fracao]

        n = 1
        soma = 0
        while (self._fracao != 0 and n < len(numeros)):
            for numero in numeros:
                _ = numero * (2 ** -n)
                print(f"({numero} * ({2} ** -{n})): ", _ )  # Impressão parcial
                soma += numero * (2 ** -n)  # formula genérica, valida para base qualquer base
                n += 1

        soma = str(soma)
        zero, soma = soma.split('.')

        return str(soma)

# CALCULA VALORES DE BINÁRIO -> HEXADECIMAL

    def hexadecimal(self):

        inteiro = self.calcula_inteiro()
        inteiro = "".join(inteiro)

        try:
            fracao = self.calcula_fracao()
            fracao = "".join(fracao)
            print(f"->> O VALOR EM HEXADECIMAL É DE: {inteiro},{fracao} <<-")
            return inteiro, fracao

        except:
            print(f"->> O VALOR EM HEXADECIMAL É DE: {inteiro} <<-")
            return inteiro


    def calcula_inteiro(self): # Calcula a parte inteira
        self.adiciona_zero_int(self._inteiro) # Adiciona zero a parte esquerda caso nescessário
        self._inteiro = self.divide(self._inteiro) # Divide em partes de 4 em 4
        self._inteiro = self.transforma_binario(self._inteiro, "binario") # Calcula o valor equivalente em hexadecimal
        return self._inteiro

    def calcula_fracao(self):
        self.adiciona_zero_fracao(self._fracao)
        self._fracao = self.divide(self._fracao)
        self._fracao = self.transforma_binario(self._fracao, "binario")
        return self._fracao


    def adiciona_zero_int(self, valor): # Adiciona zero a parte inteira
        valor = len(valor)
        if valor % 4 == 0:
            return self._inteiro

        else:
            self._inteiro = '0' + self._inteiro
            return self.adiciona_zero_int(self._inteiro)

    def adiciona_zero_fracao(self, valor): # Adiciona zero a parte fracionária
        valor = len(valor)
        if valor % 4 == 0:
            return self._fracao

        else:
            self._fracao = self._fracao + '0'
            return self.adiciona_zero_fracao(self._fracao)

    def divide(self, valor): # dividi as partes em intervalo de 4
        n = 4
        return [valor[i:i+n] for i in range(0, len(valor), n)]


if __name__ == '__main__':

    #Binario('1111000110001,10111').decimal()
    print("\n\n")
    #Binario('101111111011111100011111110101010111,0').hexadecimal()
    #Binario('01,01').hexadecimal()

    Binario('1111010').hexadecimal()