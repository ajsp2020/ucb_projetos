from hexadecimal import Hexadecimal
import pytest

@pytest.fixture
def valor_decimal():
    return Hexadecimal('A').decimal()

def test_deve_retornar_valor_decimal():


    assert valor_decimal == 10