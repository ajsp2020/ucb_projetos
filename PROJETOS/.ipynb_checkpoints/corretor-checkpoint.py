import nltk
import time
#nltk.download('punkt') # Precisa fazer o download para funcionar

class TrataTexto:
    def __init__(self):
        with open("dados/texto.txt", "r", encoding="utf-8") as f:
            self.__texto = f.read()

    def trata_texto(self):
        ini = time.time()
        self._lista_tokens = nltk.tokenize.word_tokenize(self.__texto)
        self._lista_palavras = self.separa_palavras(self._lista_tokens)
        self._lista_normalizada = self.normalizacao(self._lista_palavras)
        fim = time.time()

        print(f"O TRATAMENTO DO TEXO LEVOU: {fim - ini} SEGUNDOS ")


        return self._lista_normalizada

    def separa_palavras(self, lista_tokens):  # Separa as palavras em uma lista contendo todas
        lista_palavras = []
        for token in lista_tokens:
            if token.isalpha():
                lista_palavras.append(token)

        return lista_palavras

    def normalizacao(self, lista_palavras):  # Deixa todas as palavras com letra minúscula
        lista_normalizada = []

        for palavra in lista_palavras:
            lista_normalizada.append(palavra.lower())

        return lista_normalizada


    def gerador_palavras(self, palavra):
        fatias = []

        for i in range(len(palavra) + 1):
            fatias.append((palavra[:i], palavra[i:]))

        palavras_geradas = self.insere_letras(fatias)

        return palavras_geradas

    def insere_letras(self, fatias):
        novas_palavras = []
        letras = 'abcdefghijklmnopqrstuvwxyzáâàãéêèẽíîìĩóôõòúûùũç'

        for E, D in fatias:
            for letra in letras:
                novas_palavras.append(E + letra + D)

        return novas_palavras


class Corretor:

    def __init__(self, palavra, lista_normalizada, palavra_gerada):
        self.__palavra = palavra
        self._lista_normalizada = lista_normalizada
        self._palavra_gerada = palavra_gerada


    def corretor(self):

        ini = time.time()

        palavra_correta = max(self._palavra_gerada, key=self.probabilidade)
        fim = time.time()

        print(f"PARA ENCONTRAR A PALAVRA CORRETA LEVOU: {fim - ini} SEGUNDOS")

        return palavra_correta

    def probabilidade(self, palavra_gerada):

        ini = time.time()
        frequencia = nltk.FreqDist(self._lista_normalizada)
        total_palavras = len(self._lista_normalizada)
        fim = time.time()

        print(f"PARA ENCONTRAR A FREQUENCIA LEVOU: {fim - ini} SEGUNDOS")

        return frequencia[palavra_gerada]/total_palavras

if __name__ == '__main__':

    #Corretor('lgica').trata_texto()
    print(Corretor('lgica').corretor())
    #print(Corretor('lógica').probabilidade('lógica'))

