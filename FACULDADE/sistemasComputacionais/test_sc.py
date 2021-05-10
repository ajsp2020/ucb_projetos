from hexadecimal import Hexadecimal
from decimal import Decimal
from binario import Binario

from unittest import TestCase

class TestHexadecimal(TestCase):

    def setUp(self):
        self.hexadecimal_int = Hexadecimal('B')
        self.hexadecimal_fracao = Hexadecimal('A,A')


    def test_deve_retornar_o_valor_equivalente_em_decimal(self):

        valor_esperadp_decimal_inteiro = '11'
        valor_esperado_decimal_fracao = '10','625'

        self.assertEqual(valor_esperadp_decimal_inteiro, self.hexadecimal_int.decimal())
        self.assertEqual(valor_esperado_decimal_fracao, self.hexadecimal_fracao.decimal())

    def test_deve_retornar_o_valor_equivalente_em_binario(self):

        valor_esperado_binario_inteiro= '1011'
        valor_esperado_binario_fracao = '1010','1010'

        self.assertEqual(valor_esperado_binario_inteiro, self.hexadecimal_int.binario())
        self.assertEqual(valor_esperado_binario_fracao, self.hexadecimal_fracao.binario())


class testDecimal(TestCase):

    def setUp(self):
        self.decimal_int = Decimal('122')
        self.decimal_fracao = Decimal('10,625')

    def test_deve_retornar_o_valor_equivalente_em_binario(self):

        valor_esperado_banario_inteiro = '1111010'
        valor_esperado_binario_fracao = '1010','101'

        self.assertEqual(valor_esperado_banario_inteiro, self.decimal_int.binario())
        self.assertEqual(valor_esperado_binario_fracao, self.decimal_fracao.binario())


    def test_deve_retornar_o_valor_equivalente_em_hexadecimal(self):


        valor_esperado_hexadecimal_inteiro = '7A'
        valor_esperado_hexadecimal_fracao = 'A','A'

        self.assertEqual(valor_esperado_hexadecimal_inteiro, self.decimal_int.hexadecimal())
        self.assertEqual(valor_esperado_hexadecimal_fracao, self.decimal_fracao.hexadecimal())


class testBinario(TestCase):

    def setUp(self):

        self.binario_inteiro = Binario('1111010')
        self.binario_fracao = Binario('1010,101')

    def test_deve_retornar_o_valor_equivalente_em_decimal(self):

        valor_esperado_decimal_inteiro = '122'
        valor_esperado_decimal_fracao = '10','625'

        self.assertEqual(valor_esperado_decimal_inteiro, self.binario_inteiro.decimal())
        self.assertEqual(valor_esperado_decimal_fracao, self.binario_fracao.decimal())

    def test_deve_retornar_o_valor_equivalente_em_hexadecimal(self):

        valor_esperado_hexadecimal_inteiro = '7A'
        valor_esperado_hexadecimal_fracao = 'A','A'

        self.assertEqual(valor_esperado_hexadecimal_inteiro, self.binario_inteiro.hexadecimal())
        self.assertEqual(valor_esperado_hexadecimal_fracao, self.binario_fracao.hexadecimal())