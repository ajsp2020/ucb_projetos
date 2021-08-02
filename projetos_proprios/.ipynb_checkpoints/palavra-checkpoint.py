from corretor import TrataTexto, Corretor

class Palavra:
    def __init__(self):
        self._lista_normalizada = TrataTexto().trata_texto()

    def corrige_palavra(self, palavra):
        self.__palavra = palavra
        self._palavra_gerada = TrataTexto().gerador_palavras(self.__palavra)
        self._palavra_correta = Corretor(self.__palavra, self._lista_normalizada, self._palavra_gerada).corretor()

        return self._palavra_correta

if __name__ == '__main__':
    print(Palavra().corrige_palavra('lgica'))
