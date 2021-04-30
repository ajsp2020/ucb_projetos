from base import Base

class Hexadecimal(): # Transforma classe de hexadecimal em Binario ou Decimal
    def __init__(self, valor):
        self.__valor = valor

# CALCULA VALORES DE HEXADECIMAL -> DECIMAL:

    def decimal(self): # Recebendo o valor em hexadecimal
        self.__base = 16
        self.__soma = 0

        self.__inteiro = Base(self.__valor).inteiro
        inteiro = self.calcula_decimal_int()
        try:
            self.__fracao = Base(self.__valor).fracao
            fracao = self.calcula_decimal_fracao()
            print(f"->> O VALOR EM DECIMAL É DE: {inteiro},{fracao} <<-")
            return inteiro, fracao
        except:
            print(f"->> O VALOR EM DECIMAL É DE: {inteiro} <<-")
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


        self.__inteiro = self.transforma_hexadecimal(self.__inteiro)
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
        self.__fracao = self.transforma_hexadecimal(self.__fracao)
        numeros = [int(self.__fracao) for self.__fracao in self.__fracao]
        n = 1
        soma = 0
        while (self.__fracao != 0 and n < len(numeros)):
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
        self.__inteiro = [self.__inteiro for self.__inteiro in self.__inteiro]
        self.__inteiro = self.hexadecimal(self.__inteiro)
        return  self.__inteiro

    def calcula_binario_fracao(self):
        self.__fracao = [self.__fracao for self.__fracao in self.__fracao]
        self.__fracao = self.hexadecimal(self.__fracao)
        return  self.__fracao

    def hexadecimal(self, valor):

        lista = []
        hexadecimais = {'1': '0001', '2': '0010', '3': '0011', '4': '0100', '5': '0101', '6': '0110', '7': '0111',
                        '8': '1000', '9': '1001', 'A': '1010', 'B': '1011', 'C': '1100', 'D': '1101', 'E': '1110',
                        'F': '1111'}
        for item in valor:
            for hexa in hexadecimais.keys():
                if item == hexa:
                    item = hexadecimais[hexa]

            lista.append(item)

        return lista

if __name__ == '__main__':

    Hexadecimal('AB45CD,ABC').decimal()
    #Hexadecimal('1111111,00011111').binario()

