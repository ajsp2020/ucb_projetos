from palavra import Palavra
import time

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
        print("INÍCIO:")

        numero_palavras = len(testes)
        acertou , desconhecida, tempo_total, contador = 0, 0, 0, 1
        vocabulario = Palavra()._lista_normalizada

        for correta, errada in testes:
            ini = time.time()
            palavra_corrigida = Palavra().corrige_palavra(errada)
            fim = time.time()
            print(f"{contador}/{numero_palavras} - TEMPO PARA CORRIGIR A PALAVRA ({errada}): {round(fim - ini)} SEGUNDOS ")
            print(f"TEMPO TOTAL: {round(tempo_total + (fim - ini))} SEGUNDOS")

            if palavra_corrigida == correta:
                acertou += 1
            else:
                self.palavras_desconhecidas = []
                self.palavras_desconhecidas.append(palavra_corrigida)
                desconhecida += (correta not in vocabulario)

            tempo_total += fim - ini
            contador += 1

        print(f"PALAVRAS DESCONHECIDAS: {self.palavras_desconhecidas}")
        taxa_acerto = round(acertou/numero_palavras * 100, 2)
        taxa_desconhecida = round(desconhecida / numero_palavras * 100, 2)
        print(f"Acertou: {acertou} de {numero_palavras} palavras a taxa de acerto é"
              f" de {taxa_acerto}%, deconhecida é {taxa_desconhecida}%")


        print(f"FIM:")

if __name__ == '__main__':

   lista_teste = Teste().cria_dados_teste("dados/palavras.txt")
   Teste().avaliador(lista_teste)