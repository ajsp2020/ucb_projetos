

class Base:

    def __init__(self):

        self._valor = 0
        self._base = 0

    @property
    def valor(self):
        return self._valor

    @property
    def base(self):
        return self._base

    @valor.setter
    def valor(self, valor):
        self._valor = valor

    @base.setter
    def base(self, base):
        self._base = base

    def hexadecimal(self, algoritmo):

        hexa = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

        i = 0
        for resto in algoritmo:
            for valores in hexa.keys():
                if resto == valores:
                    algoritmo[i] = hexa[valores]
            i += 1

    def calcula_binario(self):
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




if __name__ == '__main__':
    alg = Base()
    alg.valor = int(input("Digite o valor do número decimal: "))
    alg.base = int(input("Digite o valor da base que deseja converter: "))
    alg.calcula_binario()