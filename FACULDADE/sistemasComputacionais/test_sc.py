from hexadecimal import Hexadecimal
from unittest import TestCase

class TestHexadecimal(TestCase):

    def setUp(self):
        self.hexadecimal = Hexadecimal('A')


    def test_deve_retornar_o_valor_equivalente_em_decimal(self):


        valor_esperado_decimal_int = '10'

        #valor_esperado_binario = '1010,1010'

        self.assertEqual(valor_esperado_decimal_int, self.hexadecimal.decimal())
        #self.assertEqual(valor_esperado_binario, self.hexadecimal.binario())