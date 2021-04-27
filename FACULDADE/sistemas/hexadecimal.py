

class Hexadecimal: # Transforma classe de hexadecimal em Binario ou Decimal

    def __init__(self, hexadecimal):
        self.__hexadecimal = hexadecimal

        if ',' in self.__hexadecimal:
            self.__inteiro, self.__fracao = self.__hexadecimal.split(',')
            self.__inteiro = self.transforma_hexadecimal(self.__inteiro)
            self.__fracao = self.transforma_hexadecimal(self.__fracao)
        else:
            self.__inteiro = self.__hexadecimal
            self.__inteiro = self.transforma_hexadecimal(self.__inteiro)

# CALCULA VALORES DE HEXADECIMAL -> DECIMAL:

    def decimal(self): # Recebendo o valor em hexadecimal
        self.__base = 16
        self.__soma = 0

        inteiro = self.calcula_decimal_int()
        try:
            fracao = self.calcula_decimal_fracao()
            print(f"{inteiro},{fracao}")
            return inteiro, fracao
        except:
            print(inteiro)
            return inteiro


    def transforma_hexadecimal(self, valor): # Pega os valores em hexadecial e associa com o seu valor
        hexa = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
        numeros = [valor for valor in valor] # Separando os valores e colocando numa lista

        for valor in hexa.keys(): # Substituindo os valores caso seja em A, B... F para de 10 a 15
            for i in range(len(numeros)):
                if valor == numeros[i]:
                    numeros[i] = hexa[valor]

        return numeros

    def calcula_decimal_int(self): # Calcula os valores de hexadecimal em decimal
        print("PARTE INTEIRA:")
        numeros = [int(self.__inteiro) for self.__inteiro in self.__inteiro] # Transformando os valores em inteiro
        n = len(numeros) - 1
        soma = 0
        for numero in numeros: # Para cada numero o resultado será mutiplicado de acordo com a formula e impresso

            _ = numero * (self.__base ** n)
            print(f"({numero} * ({self.__base} ** {n})): ", _) # Impressão parcial
            soma += numero * (self.__base ** n) # formula genérica, valida para base qualquer base
            n -= 1
        #print("")
        #print(f"O valor em decimal é: {self.__soma}") # impressão total
        return soma

    def calcula_decimal_fracao(self):
        print("PARTE FRAÇÃO:")
        numeros = [int(self.__fracao) for self.__fracao in self.__fracao]
        n = 1
        soma = 0
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

        inteiro, fracao = self.decimal()
        print(inteiro)
        print(fracao)


    def calcula_binario(self, numeros):
        pass


if __name__ == '__main__':

    Hexadecimal('A,A').decimal()
    #Hexadecimal('A,A').binario()