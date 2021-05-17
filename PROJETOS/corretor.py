import nltk
import time
#nltk.download('punkt') # Precisa fazer o download para funcionar

class TrataTexto:
    def __init__(self):
        with open("dados/texto.txt", "r", encoding="utf-8") as f:
            self.__texto = f.read()
        f.close()

    def trata_texto(self):
        ini = time.time()
        self._lista_tokens = nltk.tokenize.word_tokenize(self.__texto)
        self._lista_palavras = self.separa_palavras(self._lista_tokens)
        self._lista_normalizada = self.normalizacao(self._lista_palavras)
        fim = time.time()
        
        print(f"O TRATAMENTO DO TEXO LEVOU: {fim - ini} SEGUNDOS ")
        with open("dados/lista_normalizada.txt", "w", encoding="utf-8") as f:
            for palavra in self._lista_palavras:
                f.write(palavra)
                f.write(' ')
        f.close()
        
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
        palavras_geradas += self.deletando_caracteres(fatias)
        palavras_geradas += self.troca_letra(fatias)
        palavras_geradas += self.insere_letras(fatias)

        return palavras_geradas

    def gerador_turbinado(self, palavras_geradas):
        novas_palavras = []
        for palavra in palavras_geradas:
            novas_palavras += self.gerador_palavras(palavra)

        return novas_palavras

    def insere_letras(self, fatias):
        novas_palavras = []
        letras = 'abcdefghijklmnopqrstuvwxyzáâàãéêèẽíîìĩóôõòúûùũç'

        for E, D in fatias:
            for letra in letras:
                novas_palavras.append(E + letra + D)

        return novas_palavras

    def deletando_caracteres(self, fatias):
        novas_palavras = []
        for E, D in fatias:
            novas_palavras.append(E + D[1:])

        return novas_palavras

    def troca_letra(self, fatia):
        novas_palavra = []
        letras = 'abcdefghijklmnopqrstuvwxyzáâàãéêèẽíîìĩóôõòúûùũç'
        for E, D in fatia:
            for letra in letras:
                novas_palavra.append(E + letra + D[1:])

        return novas_palavra

    def inverte_letras(self, fatias):
        novas_palavra = []
        for E, D in fatias:
            if len(D) > 1:
                novas_palavra.append(E + D[1] + D[0] + D[2:])

        return novas_palavra


class Corretor:

    def __init__(self, palavra, lista_normalizada, palavra_gerada, palavras_turbinado):
        self.__palavra = palavra
        self._lista_normalizada = lista_normalizada
        self._palavra_gerada = palavra_gerada
        self._palavras_turbinado = palavras_turbinado


    def corretor(self):


        todas_palavras = set(self._palavra_gerada)
        vocabulario = set(self._lista_normalizada)
        candidato = [self.__palavra]
        for palavra in todas_palavras:
            if palavra in vocabulario:
                candidato.append(palavra)
        palavra_correta = max(candidato, key=self.probabilidade)

        if palavra_correta == self.__palavra:
            todas_palavras = set(self._palavras_turbinado)
            vocabulario = set(self._lista_normalizada)
            candidato = [self.__palavra]
            for palavra in todas_palavras:
                if palavra in vocabulario:
                    candidato.append(palavra)
            palavra_correta = max(candidato, key=self.probabilidade)

        fim = time.time()

        print(f"PALAVRA INCORRETA = {self.__palavra}")
        print(f"PALAVRA CORRIGIDA = {palavra_correta}")
        return palavra_correta

    def probabilidade(self, palavra_gerada):

        frequencia = nltk.FreqDist(self._lista_normalizada)
        total_palavras = len(self._lista_normalizada)

        return frequencia[palavra_gerada]/total_palavras

if __name__ == '__main__':

    TrataTexto().trata_texto()

