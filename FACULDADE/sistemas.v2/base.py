
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


    def transforma_hexadecimal(self, valor): # Pega os valores em hexadecial e associa com o seu valor
        hexa = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
        numeros = [valor for valor in valor] # Separando os valores e colocando numa lista

        for valor in hexa.keys(): # Substituindo os valores caso seja em A, B... F para de 10 a 15
            for i in range(len(numeros)):
                if valor == numeros[i]:
                    numeros[i] = hexa[valor]

        return numeros