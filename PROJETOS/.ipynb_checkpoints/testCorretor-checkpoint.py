from palavra import Palavra

class Teste:

    def cria_dados_teste(self, nome_arquivo):
        lista_palavras_teste = []
        f = open(nome_arquivo, "r", encoding="utf-8")

        for linha in f:
            correta, errada = linha.split()
            lista_palavras_teste.append((correta, errada))

        f.close()

        return lista_palavras_teste

    def avaliador(self, testes):
        numero_palavras = len(testes)
        acertou = 0

        for correta, errada in testes:
            palavra_corrigida = Palavra().corrige_palavra(errada)
            print(palavra_corrigida)

            if palavra_corrigida == correta:
                acertou += 1

        taxa_acerto = round(acertou/numero_palavras * 100, 2)
        print(f"Acertou: {acertou} de {numero_palavras} palavras a taxa de acerto é"
              f" de {taxa_acerto}%")


if __name__ == '__main__':

   lista_teste = Teste().cria_dados_teste("dados/palavras.txt")
   Teste().avaliador(lista_teste)