from questao3 import Questao3

class Questao11(Questao3):

    def contaladosiguais(self):
        self.soma = 0

        for i in range(len(self.lados) - 1):
            for j in range(1, len(self.lados)):
                if i != j:
                    if self.lados[i] == self.lados[j]:
                        self.soma += 1


    def definetriangulos(self):
        self.contaladosiguais()

        if self.soma == 0:
            return "Escaleno"
        elif self.soma == 1:
            return "Isóceles"

        elif self.soma == 3:
            return "Equilátero"

    def __str__(self):
        if self.ehtriangulo():
            triangulo = self.definetriangulos()
            return f"{triangulo}"




if __name__ == '__main__':
    print(Questao11())
