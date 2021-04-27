from binario import Binario

"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""

class Decimal:
    """
    - Decimal -> Base
    - Sucessivas divisões dentro do conjunto dos naturais

        Dividendo / Divisor = Quociente + Resto
        Ex:
            * 15 / 2 = 7 + 1
            * 18 / 2 = 9 + 0

        Onde:

        - Dividendo: O decimal a ser convertido
        - Divisor: Base
        - Quociente: O resutado da divisão a cada etapa
        - Resto: Resto
        - Interromper as sucessivas divisões quando o quociente for menor que dois
        - O Binário correspondente ao decimal, é formada pelo último quociente sequido dos restos das etapas das
            divisões anteriores, em sentido contrário.
    """
    def __init__(self, decimal):
        self.__decimal = decimal

        # Divide a parte fracionária da parte inteira
        if ',' in self.__decimal:
            self.__inteiro, self.__fracao = self.__decimal.split(',')

        else:
            self.__inteiro = self.__decimal

    def __hexadecimal(self, valor):
        lista = []
        hexadecimais = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        for item in valor:
            for hexa in hexadecimais.keys():
                if item == hexa:
                    item = hexadecimais[hexa]

            lista.append(str(item))

        return lista
# CALCULA VALORES DE DECIMAL -> BINÁRIO:

    def binario(self):
        inteiro = self.calcula_binario_int()
        inteiro = "".join(inteiro)

        try:
            fracao = self.calcula_binario_fracionario()
            fracao = "".join(fracao)
            print(f"{inteiro},{fracao}")
            return inteiro , fracao
        except:
            print(inteiro)
            return inteiro


    def calcula_binario_int(self):

        self.__inteiro = int(self.__inteiro)
        print("PARTE INTEIRA:\n")
        self.__algoritmo = []


        while self.__inteiro > 0:
            resto = self.__inteiro % 2
            quociente = self.__inteiro // 2
            print(f"Valor: {self.__inteiro} / Divisor: {2} = Quociente: {quociente} +  Resto: {resto}")
            self.__inteiro = self.__inteiro // 2
            self.__algoritmo.append(str(resto))

        self.__algoritmo.reverse()

        return (self.__algoritmo)


    def calcula_binario_fracionario(self):
        print("PARTE FRACIONÁRIA:\n")
        self.__fracao = float("0." + self.__fracao)

        n = 0
        self.__parte_fracionaria = []
        while (self.__fracao != 0 and n < 8):

            self.__intermediario = self.__fracao * 2

            if self.__intermediario > 0:
                self.__parte_inteira = int(self.__intermediario)
                self.__parte_fracionaria.append(str(self.__parte_inteira))
                print("{:.5f}".format(self.__fracao, 4), f" * {2} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {self.__parte_inteira}")

                self.__fracao = self.__intermediario - self.__parte_inteira
            else:
                self.__parte_fracionaria.append("0")
                print("{:.5f}".format(self.__fracao, 4), f" * {2} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {0}")
            n += 1

        return self.__parte_fracionaria

# CALCULA VALORES DE DECIMAL -> HEXADECIMAL

    def hexadecimal(self):
        inteiro = self.calcula_hexadecimal_int()
        inteiro = "".join(inteiro)

        try:
            fracao = self.calcula_hexadecimal_fracionario()
            fracao = "".join(fracao)
            print(f"{inteiro},{fracao}")
            return inteiro , fracao
        except:
            print(inteiro)
            return inteiro

    def calcula_hexadecimal_int(self):

        self.__inteiro = int(self.__inteiro)
        print("PARTE INTEIRA:\n")
        self.__algoritmo = []


        while self.__inteiro > 0:
            resto = self.__inteiro % 16
            quociente = self.__inteiro // 16
            print(f"Valor: {self.__inteiro} / Divisor: {16} = Quociente: {quociente} +  Resto: {resto}")
            self.__inteiro = self.__inteiro // 16
            self.__algoritmo.append((resto))

        self.__algoritmo.reverse()
        self.__algoritmo = self.__hexadecimal(self.__algoritmo)
        return (self.__algoritmo)


    def calcula_hexadecimal_fracionario(self):
        print("PARTE FRACIONÁRIA:\n")
        self.__fracao = float("0." + self.__fracao)

        n = 0
        self.__parte_fracionaria = []
        while (self.__fracao != 0 and n < 8):

            self.__intermediario = self.__fracao * 16

            if self.__intermediario > 0:
                self.__parte_inteira = int(self.__intermediario)
                self.__parte_fracionaria.append((self.__parte_inteira))
                print("{:.5f}".format(self.__fracao, 4), f" * {16} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {self.__parte_inteira}")

                self.__fracao = self.__intermediario - self.__parte_inteira
            else:
                self.__parte_fracionaria.append("0")
                print("{:.5f}".format(self.__fracao, 4), f" * {16} =",
                      "{:.5f}".format(self.__intermediario),
                      f"-> {0}")
            n += 1
        self.__parte_fracionaria = self.__hexadecimal(self.__parte_fracionaria)
        return self.__parte_fracionaria


if __name__ == '__main__':

    #Decimal('123,238').binario()
    Decimal('54897,00003662109375').hexadecimal()
    #Decimal('54897').hexadecimal()