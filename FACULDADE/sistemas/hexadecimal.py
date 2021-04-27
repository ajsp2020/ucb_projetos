
class Hexadecimal: # Transforma classe de hexadecimal em Binario ou Decimal

    def __init__(self, valor):
        self.__valor = valor

        if ',' in self.__valor:
            self.__inteiro, self.__fracao = self.__valor.split(',')
            self.__inteiro = self.transforma_hexadecimal(self.__inteiro)
            self.__fracao = self.transforma_hexadecimal(self.__fracao)
        else:
            self.__inteiro = self.__valor
            self.__inteiro = self.transforma_hexadecimal(self.__inteiro)


    def decimal(self): # Recebendo o valor em hexadecimal
        self.__base = 16
        self.__soma = 0

        inteiro = self.calcula_decimal_int(self.__inteiro)
        try:
            fracao = self.calcula_decimal(self.__fracao)
            print(f"{inteiro},{fracao}")
        except:
            print(inteiro)


    def transforma_hexadecimal(self, valor): # Pega os valores em hexadecial e associa com o seu valor
        hexa = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
        numeros = [valor for valor in valor] # Separando os valores e colocando numa lista

        for valor in hexa.keys(): # Substituindo os valores caso seja em A, B... F para de 10 a 15
            for i in range(len(numeros)):
                if valor == numeros[i]:
                    numeros[i] = hexa[valor]

        return numeros

    def calcula_decimal_int(self, numeros): # Calcula os valores de hexadecimal em decimal

        numeros = [int(numero) for numero in numeros] # Transformando os valores em inteiro
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

    def binario(self):

        numeros = self.transforma_hexadecimal()
        self.calcula_binario(numeros)

    def calcula_binario(self, numeros):
        pass