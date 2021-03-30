

"""
- Sistemas de numeração:

    Sistemas não posicionais: Os algarismos têm um valor fixo independente da posição que ocupem.
    (exemplo: Algarismos romanos)

    Sistemas posicionais: Os algarismos possuem um valor relativo à posição que ocupam no número.
"""

class Binario:
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
    def __init__(self):

        self._valor = 0
        self._base = 0

    def hexadecimal(self, algoritmo):

        hexa = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        i = 0
        for resto in algoritmo:
            for valores in hexa.keys():
                if resto == valores:
                    algoritmo[i] = hexa[valores]
            i += 1

    def calcula_binario(self, valor, base):
        self._valor = valor
        self._base = base
        algoritmo = []
        while self._valor > 0:
            resto = self._valor % self._base
            print(f"Valor: {self._valor}, Resto: {resto}")
            self._valor = self._valor // self._base
            algoritmo.append(resto)

        algoritmo.reverse()

        if self._base == 16:
            self.hexadecimal(algoritmo)

        print(algoritmo)


class Decimal:
    """
     - Formula geral:
        Nb = S(n ->1) an * b ** (n -1)
    """

    def __init__(self):
        self._valor = 0

    def calcula_decimal(self, valor):
        self._valor = valor
        numeros = [int(self._valor) for self._valor in str(self._valor)]
        n = len(numeros) - 1
        soma = 0
        for numero in numeros:
            soma += numero * (2 ** n)
            n -= 1
        print(soma)


if __name__ == '__main__':

    escolha = int(input("Deseja calcular o valor binário(1) ou valor decimal(2): "))
    if escolha == 1:
        valor = int(input("Digite o valor do número decimal: "))
        base = int(input("Digite o valor da base que deseja converter: "))
        print("Valor em binário:")
        Binario().calcula_binario(valor, base)

    if escolha == 2:
        valor = int(input("Digite o valor do número em binário: "))
        print("Valor em decimal:")
        Decimal().calcula_decimal(valor)