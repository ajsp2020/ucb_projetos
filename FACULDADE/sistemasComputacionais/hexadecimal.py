from base import Base

class Hexadecimal(Base): # Transforma classe de hexadecimal em Binario ou Decimal
    def __init__(self, hexadecimal):
        super().__init__(hexadecimal)
        print(f"O VALOR EM HEXADECIMAL É DE: {hexadecimal}")

# CALCULA VALORES DE HEXADECIMAL -> DECIMAL:

    def decimal(self): # Recebendo o valor em hexadecimal
        self.__base = 16
        self.__soma = 0

        inteiro = self.calcula_decimal_int()

        try:

            fracao = self.calcula_decimal_fracao()
            print(f"->> O VALOR EM DECIMAL É DE: {inteiro},{fracao} <<-")
            return inteiro, fracao
        except:
            print(f"->> O VALOR EM DECIMAL É DE: {inteiro} <<-")
            return inteiro

    def calcula_decimal_int(self): # Calcula os valores de hexadecimal em decimal
        print("PARTE INTEIRA:")

        self._inteiro = self.transforma_hexadecimal(self._inteiro)
        numeros = [int(self._inteiro) for self._inteiro in self._inteiro] # Transformando os valores em inteiro
        n = len(numeros) - 1
        soma = 0
        for numero in numeros: # Para cada numero o resultado será mutiplicado de acordo com a formula e impresso

            _ = numero * (self.__base ** n)
            print(f"({numero} * ({self.__base} ** {n})): ", _) # Impressão parcial
            soma += numero * (self.__base ** n) # formula genérica, valida para base qualquer base
            n -= 1

        return soma

    def calcula_decimal_fracao(self):
        print("PARTE FRAÇÃO:")

        self._fracao = self.transforma_hexadecimal(self._fracao)
        numeros = [int(self._fracao) for self._fracao in self._fracao]
        n = 1
        soma = 0
        while (self._fracao != 0 and n < len(numeros)):
            for numero in numeros:
                _ = numero * (2 ** -n)
                print(f"({numero} * ({16} ** -{n})): ", _)  # Impressão parcial
                soma += numero * (16 ** -n)  # formula genérica, valida para base qualquer base
                n += 1

        soma = str(soma)
        zero, soma = soma.split('.')

        return soma
# CALCULA VALORES DE HEXADECIMAL -> BINÁRIO:
    def binario(self):

        inteiro = self.calcula_binario_int()
        inteiro = ''.join(inteiro)
        try:
            fracao = self.calcula_binario_fracao()
            fracao = ''.join(fracao)
            print(f"->> O VALOR EM BINÁRIO É DE: {inteiro},{fracao} <<-")
            return fracao
        except:
            print(f"->> O VALOR EM BINÁRIO É DE: {inteiro} <<-")
            return inteiro

    def calcula_binario_int(self):
        self._inteiro = [self._inteiro for self._inteiro in self._inteiro]
        self._inteiro = self.transforma_binario(self._inteiro, "hexadecimal")
        return self._inteiro

    def calcula_binario_fracao(self):
        self._fracao = [self._fracao for self._fracao in self._fracao]
        self._fracao = self.transforma_binario(self._fracao, "hexadecimal")
        return  self._fracao



if __name__ == '__main__':

    #Hexadecimal('AB45CD,ABC').decimal()
    #Hexadecimal('A').binario()
    Hexadecimal('A').decimal()

