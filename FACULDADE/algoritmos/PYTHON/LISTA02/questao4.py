

class Questao4:

    def __init__(self, nome, sexo):
        sexo = sexo.capitalize()
        self._nome = nome.capitalize()
        if self.valida_sexo(sexo):
            self._sexo = sexo
        else:
            raise ValueError("Valor do sexo incorreto")


    @property
    def nome(self):
        return nome

    @nome.setter
    def nome(self, nome):
        self._nome = nome.capitalize()

    @property
    def sexo(self):
        return sexo

    @sexo.setter
    def sexo(self, sexo):
        sexo = sexo.capitalize()
        if self.valida_sexo(sexo):
            self._sexo = sexo

    def valida_sexo(self, sexo):
        sexo_valido = ('M', 'F')
        for valido in sexo_valido:
            if valido == sexo:
                return True
        return False

    def __str__(self):
        if self._sexo == 'M':
            return f"Ilmo Sr. {self.__nome}"
        else:
            return f"Ilmo Sra. {self.__nome}"

if __name__ == '__main__':

    nome = input("Digite o nome: ")
    sexo = input("Digite o sexo (M / F): ")
    print(Questao4(nome, sexo))