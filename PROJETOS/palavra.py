from corretor import TrataTexto, Corretor
import nltk

class Palavra:
    def __init__(self):
        with open("dados/lista_normalizada.txt", "r", encoding="utf-8") as f:
            self.__palavras = f.read()
        f.close()

        self._lista_normalizada = nltk.tokenize.word_tokenize(self.__palavras)


    def corrige_palavra(self, palavra):
        self.__palavra = palavra
        self._palavra_gerada = TrataTexto().gerador_palavras(self.__palavra)
        self._palavrra_turbinada = TrataTexto().gerador_turbinado(self._palavra_gerada)
        self._palavra_correta = Corretor(self.__palavra, self._lista_normalizada, self._palavra_gerada,self._palavrra_turbinada).corretor()

        return self._palavra_correta

if __name__ == '__main__':

    Palavra().corrige_palavra('lógca')
