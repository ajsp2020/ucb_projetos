
class Teoria:

    def le_arquivo(self):
        with open("../mudancadebase.txt", "r", encoding='utf-8') as f:
            self._texto = f.read()

        print(self._texto)


