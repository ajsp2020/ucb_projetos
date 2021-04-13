
class Questao3:

    def __init__(self):
       self.lados = []

       for i in range(3):
            lado = float(input(f"Digite o lador do lado {i + 1}: "))
            if self.ehvalido(lado):
               self.lados.append(lado)
            else:
                self.lados.clear()
                self.__init__()
                break

    def ehvalido(self, lado):
        if lado > 0:
            return True
        else:
            return False

    def ehtriangulo(self):
        soma = 0
        for i in range(len(self.lados)):
            for j in range(len(self.lados)):
                if i != j:
                    soma += self.lados[j]
            if self.lados[i] > soma:
                return False
            soma = 0
        return True

    def __str__(self):
        if self.ehtriangulo():
            return (f"Os valores constituem um triângulo")
        else:
            return "Os Valores não constituem um triângulo"

if __name__ == '__main__':


    print(Questao3())