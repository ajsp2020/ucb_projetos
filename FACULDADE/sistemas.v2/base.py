
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


