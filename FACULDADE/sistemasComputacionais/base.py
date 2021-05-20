

class Base:

    def __init__(self, valor):
        self._valor = valor
        if ',' in self._valor:
            self._inteiro, self._fracao = self._valor.split(',')

        else:
            self._inteiro = self._valor


    @property
    def inteiro(self):
        return self._inteiro

    @property
    def fracao(self):
        return self._fracao


    def transforma_hexadecimal(self, valor):

        numeros = [valor for valor in valor]

        for valor in numeros:
            if type(valor) is int:
                hexadecimais = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

            else:
                hexadecimais = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}


        for key in hexadecimais.keys():
            for i in range(len(numeros)):
                if key == numeros[i]:
                    numeros[i] = str(hexadecimais[key])

                else:
                    numeros[i] = str(numeros[i])

        return numeros

    def transforma_binario(self, valores, classe):

        lista = []
        if classe == "hexadecimal":
            hexadecimais = {'1': '0001', '2': '0010', '3': '0011', '4': '0100', '5': '0101', '6': '0110', '7': '0111',
                            '8': '1000', '9': '1001', 'A': '1010', 'B': '1011', 'C': '1100', 'D': '1101', 'E': '1110',
                            'F': '1111'}

        elif classe == "binario":
            hexadecimais = {'0001': '1', '0010': '2', '0011': '3', '0100': '4', '0101': '5', '0110': '6', '0111': '7',
                            '1000': '8', '1001': '9', '1010': 'A', '1011': 'B', '1100': 'C', '1101': 'D', '1110': 'E',
                            '1111': 'F'}

        for valor in valores:
            for key in hexadecimais.keys():
                if valor == key:
                    valor = hexadecimais[key]

            lista.append(valor)

        return lista