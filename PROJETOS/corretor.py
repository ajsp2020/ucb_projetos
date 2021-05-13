import nltk
# nltk.download('punkt') # Precisa fazer o download para funcionar

class Corretor:

    def __init__(self, palavra):
        self.__palavra = palavra

        with open("texto.txt", "r", encoding="utf-8") as f:
            self.__texto = f.read()

    def trata_texto(self):

        lista_tokens = nltk.tokenize.word_tokenize(self.__texto)
        lista_palavras = self.separa_palavras(lista_tokens)
        lista_normalizada = self.normalizacao(lista_palavras)

        print(f"Número de palavras é {len(lista_palavras)}")
        print(lista_palavras[:10])
        print(lista_normalizada[:10])

    def separa_palavras(self, lista_tokens): # Separa as palavras em uma lista contendo todas
        lista_palavras = []
        for token in lista_tokens:
            if token.isalpha():
                lista_palavras.append(token)

        return lista_palavras

    def normalizacao(self, lista_palavras): # Deixa todas as palavras com letra minúscula
        lista_normalizada = []
        for palavra in lista_palavras:
            lista_normalizada.append(palavra.lower())
        return lista_normalizada

if __name__ == '__main__':

    Corretor('a').trata_texto()