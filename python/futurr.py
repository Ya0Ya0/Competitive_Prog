from __future__ import division, unicode_literals

from typing import Union

from .taxed_money import Money

Addable = Union[Money, 'MoneyRange']


class MoneyRange:
    """A taxed money range."""

    __slots__ = ('start', 'stop')

    def __init__(self, start: Money, stop: Money) -> None:
        if start.currency != stop.currency:
            raise ValueError(
                'Cannot create a range as %r and %r use different currencies' % (
                    start, stop))
        if start > stop:
            raise ValueError(
                'Cannot create a range from %r to %r' % (
                    start, stop))
        self.start = start
        self.stop = stop

    def __repr__(self) -> str:
        return 'MoneyRange(%r, %r)' % (self.start, self.stop)

    def __add__(self, other: Addable) -> 'MoneyRange':
        if isinstance(other, Money):
            if other.currency != self.currency:
                raise ValueError(
                    "Cannot add range in %r to argument in %r" % (
                        self.currency, other.currency))
            start = self.start + other
            stop = self.stop + other
            return MoneyRange(start, stop)
        elif isinstance(other, MoneyRange):
            if other.start.currency != self.currency:
                raise ValueError(
                    'Cannot add ranges in %r and %r' % (
                        self.currency, other.currency))
            start = self.start + other.start
            stop = self.stop + other.stop
            return MoneyRange(start, stop)
        return NotImplemented

    def __sub__(self, other: Addable) -> 'MoneyRange':
        if isinstance(other, Money):
            if other.currency != self.start.currency:
                raise ValueError(
                    'Cannot subtract Money in %r from a range in %r' % (
                        other.currency, self.start.currency))
            start = self.start - other
            stop = self.stop - other
            return MoneyRange(start, stop)
        elif isinstance(other, MoneyRange):
            if other.start.currency != self.start.currency:
                raise ValueError(
                    'Cannot subtract range in %r from %r' % (
                        other.start.currency, self.start.currency))
            start = self.start - other.start
            stop = self.stop - other.stop
            return MoneyRange(start, stop)
        return NotImplemented

    def __eq__(self, other: object) -> bool:
        if isinstance(other, MoneyRange):
            return (
                self.start == other.start and
                self.stop == other.stop)
        return False

    def __contains__(self, item: Money) -> bool:
        if not isinstance(item, Money):
            raise TypeError(
                '`in money_range` requires Money as left operand, not %s' % (
                    type(item),))
        return self.start <= item <= self.stop

    @property
    def currency(self) -> str:
        """Return the currency of the range."""
        return self.start.currency

    def quantize(self, exp=None, rounding=None) -> 'MoneyRange':
        """Return a copy of the range with start and stop quantized.

        All arguments are passed to `Money.quantize`.
        """
        return MoneyRange(
            self.start.quantize(exp, rounding=rounding),
            self.stop.quantize(exp, rounding=rounding))

    def replace(self, start: Money = None, stop: Money = None) -> 'MoneyRange':
        """Return a range with start or stop replaced with given values."""
        if start is None:
            start = self.start
        if stop is None:
            stop = self.stop
        return MoneyRange(start=start, stop=stop)

[EOD]
path: prices/money.py

from __future__ import division, unicode_literals

import warnings
from decimal import ROUND_HALF_UP, Decimal
from typing import Union, overload

from babel.numbers import get_currency_precision

Numeric = Union[int, Decimal]


class Money:
    """An amount of a particular currency."""

    __slots__ = ('amount', 'currency')

    def __init__(self, amount: Numeric, currency: str) -> None:
        if isinstance(amount, float):
            warnings.warn(  # pragma: no cover
                RuntimeWarning(
                    'float passed as value to Money, consider using Decimal'),
                stacklevel=2)
        self.amount = Decimal(amount)
        self.currency = currency

    def __repr__(self) -> str:
        return 'Money(%r, %r)' % (str(self.amount), self.currency)

    def __lt__(self, other: 'Money') -> bool:
        if isinstance(other, Money):
            if self.currency != other.currency:
                raise ValueError(
                    'Cannot compare amounts in %r and %r' % (
                        self.currency, other.currency))
            return self.amount < other.amount
        return NotImplemented

    def __le__(self, other: 'Money') -> bool:
        if self == other:
            return True
        return self < other

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Money):
            return (
                self.amount == other.amount and
                self.currency == other.currency)
        return False

    def __mul__(self, other: Numeric) ->'Money':
        try:
            amount = self.amount * other
        except TypeError:
            return NotImplemented
        return Money(amount, self.currency)

    def __rmul__(self, other: Numeric) -> 'Money':
        return self * other

    @overload
    def __truediv__(self, other: 'Money') -> Decimal:
        ...  # pragma: no cover

    @overload
    def __truediv__(self, other: Numeric) -> 'Money':
        ...  # pragma: no cover

    def __truediv__(self, other):
        if isinstance(other, Money):
            if self.currency != other.currency:
                raise ValueError(
                    'Cannot divide amounts in %r and %r' % (
                        self.currency, other.currency))
            return self.amount / other.amount
        try:
            amount = self.amount / other
        except TypeError:
            return NotImplemented
        return Money(amount, self.currency)

    def __add__(self, other: 'Money') -> 'Money':
        if isinstance(other, Money):
            if other.currency != self.currency:
                raise ValueError(
                    'Cannot add amount in %r to %r' % (
                        self.currency, other.currency))
            amount = self.amount + other.amount
            return Money(amount, self.currency)
        return NotImplemented

    def __sub__(self, other: 'Money') -> 'Money':
        if isinstance(other, Money):
            if other.currency != self.currency:
                raise ValueError(
                    'Cannot subtract amount in %r from %r' % (
                        other.currency, self.currency))
            amount = self.amount - other.amount
            return Money(amount, self.currency)
        return NotImplemented

    def __bool__(self) -> bool:
        return bool(self.amount)

    def quantize(self, exp=None, rounding=None) -> 'Money':
        """Return a copy of the object with its amount quantized.

        If `exp` is given the resulting exponent will match that of `exp`.

        Otherwise the resulting exponent will be set to the correct exponent
        of the currency if it's known and to default (two decimal places)
        otherwise.
        """
        if rounding is None:
            rounding = ROUND_HALF_UP
        if exp is None:
            digits = get_currency_precision(self.currency)
            exp = Decimal('0.1') ** digits
        else:
            exp = Decimal(exp)
        return Money(
            self.amount.quantize(exp, rounding=rounding), self.currency)

[EOD]
path: prices/taxed_money.py

from __future__ import division, unicode_literals

import warnings
from decimal import Decimal
from typing import Union

from .money import Money

Numeric = Union[int, Decimal]


class TaxedMoney:
    """Stores Money for net, gross (incl. tax) and tax."""

    __slots__ = ('net', 'gross')

    def __init__(self, net: Money, gross: Money) -> None:
        if not isinstance(net, Money) or not isinstance(gross, Money):
            raise TypeError('Price requires two amounts, got %r, %r' % (
                net, gross))
        if net.currency != gross.currency:
            raise ValueError(
                'Amounts given in different currencies: %r and %r' % (
                    net.currency, gross.currency))
        self.net = net
        self.gross = gross

    def __repr__(self) -> str:
        return 'TaxedMoney(net=%r, gross=%r)' % (self.net, self.gross)

    def __lt__(self, other: 'TaxedMoney') -> bool:
        if isinstance(other, TaxedMoney):
            return self.gross < other.gross
        elif isinstance(other, Money):
            raise TypeError(
                'Cannot compare taxed and untaxed Money,'
                ' use taxed_money.net or taxed_money.gross explicitly')
        return NotImplemented

    def __eq__(self, other: object) -> bool:
        if isinstance(other, TaxedMoney):
            return (
                self.gross == other.gross and
                self.net == other.net)
        return False

    def __le__(self, other: 'TaxedMoney') -> bool:
        if self == other:
            return True
        return self < other

    def __mul__(self, other: Numeric) -> 'TaxedMoney':
        try:
            net = self.net * other
            gross = self.gross * other
        except TypeError:
            return NotImplemented
        return TaxedMoney(net=net, gross=gross)

    def __rmul__(self, other: Numeric) -> 'TaxedMoney':
        return self * other

    def __truediv__(self, other: Numeric) -> 'TaxedMoney':
        try:
            net = self.net / other
            gross = self.gross / other
        except TypeError:
            return NotImplemented
        return TaxedMoney(net=net, gross=gross)

    def __add__(self, other: Union[Money, 'TaxedMoney']) -> 'TaxedMoney':
        if isinstance(other, TaxedMoney):
            net = self.net + other.net
            gross = self.gross + other.gross
            return TaxedMoney(net=net, gross=gross)
        if isinstance(other, Money):
            net = self.net + other
            gross = self.gross + other
            return TaxedMoney(net=net, gross=gross)
        return NotImplemented

    def __sub__(self, other: Union[Money, 'TaxedMoney']) -> 'TaxedMoney':
        if isinstance(other, TaxedMoney):
            net = self.net - other.net
            gross = self.gross - other.gross
            return TaxedMoney(net=net, gross=gross)
        if isinstance(other, Money):
            net = self.net - other
            gross = self.gross - other
            return TaxedMoney(net=net, gross=gross)
        return NotImplemented

    def __bool__(self) -> bool:  # pragma: no cover
        warnings.warn(
            RuntimeWarning(
                '`bool(taxed_money)` will always evaluate to True, consider'
                ' replacing the test with explicit `if taxed_money is None`'
                ' or `if taxed_money.gross`.'),
            stacklevel=2)
        return True

    @property
    def currency(self) -> str:
        """Return the currency of the money."""
        return self.net.currency

    @property
    def tax(self) -> Money:
        """Return the tax amount."""
        return self.gross - self.net

    def quantize(self, exp=None, rounding=None) -> 'TaxedMoney':
        """Return a new instance with both net and gross quantized.

        All arguments are passed to `Money.quantize`.
        """
        return TaxedMoney(
            net=self.net.quantize(exp, rounding=rounding),
            gross=self.gross.quantize(exp, rounding=rounding))

[EOD]
path: tests/test_money_range.py

import pytest

from prices import Money, MoneyRange


def test_construction():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    assert price_range.start == price1
    assert price_range.stop == price2
    with pytest.raises(ValueError):
        MoneyRange(price1, Money(20, 'PLN'))
    with pytest.raises(ValueError):
        MoneyRange(price2, price1)


def test_addition_with_money():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    price3 = Money(40, 'EUR')
    result = price_range + price3
    assert result.start == price1 + price3
    assert result.stop == price2 + price3
    with pytest.raises(ValueError):
        price_range + Money(1, 'BTC')


def test_addition_with_money_range():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range1 = MoneyRange(price1, price2)
    price3 = Money(40, 'EUR')
    price4 = Money(80, 'EUR')
    price_range2 = MoneyRange(price3, price4)
    result = price_range1 + price_range2
    assert result.start == price1 + price3
    assert result.stop == price2 + price4
    with pytest.raises(ValueError):
        price_range1 + MoneyRange(Money(1, 'BTC'), Money(2, 'BTC'))


def test_addition_with_other_types():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    with pytest.raises(TypeError):
        price_range + 1


def test_subtraction_with_money():
    price1 = Money(40, 'EUR')
    price2 = Money(80, 'EUR')
    price_range = MoneyRange(price1, price2)
    price3 = Money(10, 'EUR')
    result = price_range - price3
    assert result.start == price1 - price3
    assert result.stop == price2 - price3
    with pytest.raises(ValueError):
        price_range - Money(1, 'BTC')


def test_subtraction_with_money_range():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range1 = MoneyRange(price1, price2)
    price3 = Money(40, 'EUR')
    price4 = Money(80, 'EUR')
    price_range2 = MoneyRange(price3, price4)
    result = price_range2 - price_range1
    assert result.start == price3 - price1
    assert result.stop == price4 - price2
    with pytest.raises(ValueError):
        price_range2 - MoneyRange(Money(1, 'BTC'), Money(2, 'BTC'))


def test_subtraction_with_other_types():
    price1 = Money(40, 'EUR')
    price2 = Money(80, 'EUR')
    price_range = MoneyRange(price1, price2)
    with pytest.raises(TypeError):
        price_range - 1


def test_comparison():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range1 = MoneyRange(price1, price2)
    price3 = Money(40, 'EUR')
    price4 = Money(80, 'EUR')
    price_range2 = MoneyRange(price3, price4)
    assert price_range1 == MoneyRange(price1, price2)
    assert price_range1 != price_range2
    assert price_range1 != MoneyRange(price1, price1)
    assert price_range1 != MoneyRange(
        Money(10, 'USD'), Money(30, 'USD'))
    assert price_range1 != price1


def test_membership():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    assert price1 in price_range
    assert price2 in price_range
    assert (price1 + price2) / 2 in price_range
    assert price1 + price2 not in price_range
    with pytest.raises(TypeError):
        15 in price_range


def test_quantize():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    result = price_range.quantize()
    assert str(result.start.amount) == '10.00'
    assert str(result.stop.amount) == '30.00'


def test_replace():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price3 = Money(20, 'EUR')
    price_range = MoneyRange(price1, price2)
    result = price_range.replace(stop=price3)
    assert result.start == price1
    assert result.stop == price3
    result = price_range.replace(start=price3)
    assert result.start == price3
    assert result.stop == price2


def test_currency():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    assert price_range.currency == 'EUR'


def test_repr():
    price1 = Money(10, 'EUR')
    price2 = Money(30, 'EUR')
    price_range = MoneyRange(price1, price2)
    assert repr(price_range) == (
        "MoneyRange(Money('10', 'EUR'), Money('30', 'EUR'))")

[EOD]
path: prices/taxed_money_range.py

from __future__ import division, unicode_literals

from typing import Union

from .money import Money
from .money_range import MoneyRange
from .taxed_money import TaxedMoney

Addable = Union[Money, MoneyRange, TaxedMoney, 'TaxedMoneyRange']


class TaxedMoneyRange:
    """A taxed money range."""

    __slots__ = ('start', 'stop')

    def __init__(self, start: TaxedMoney, stop: TaxedMoney) -> None:
        if start.currency != stop.currency:
            raise ValueError(
                'Cannot create a range as %r and %r use different currencies' % (
                    start, stop))
        if start > stop:
            raise ValueError(
                'Cannot create a range from %r to %r' % (start, stop))
        self.start = start
        self.stop = stop

    def __repr__(self) -> str:
        return 'TaxedMoneyRange(%r, %r)' % (self.start, self.stop)

    def __add__(self, other: Addable) -> 'TaxedMoneyRange':
        if isinstance(other, (Money, TaxedMoney)):
            if other.currency != self.currency:
                raise ValueError(
                    "Cannot add a range in %r to argument in %r" % (
                        self.currency, other.currency))
            start = self.start + other
            stop = self.stop + other
            return TaxedMoneyRange(start, stop)
        elif isinstance(other, (MoneyRange, TaxedMoneyRange)):
            if other.start.currency != self.currency:
                raise ValueError(
                    'Cannot add ranges in %r and %r' % (
                        self.currency, other.currency))
            start = self.start + other.start
            stop = self.stop + other.stop
            return TaxedMoneyRange(start, stop)
        return NotImplemented

    def __sub__(self, other: Addable) -> 'TaxedMoneyRange':
        if isinstance(other, (Money, TaxedMoney)):
            if other.currency != self.start.currency:
                raise ValueError(
                    'Cannot subtract argument in %r from range in %r' % (
                        other.currency, self.start.currency))
            start = self.start - other
            stop = self.stop - other
            return TaxedMoneyRange(start, stop)
        elif isinstance(other, (MoneyRange, TaxedMoneyRange)):
            if other.start.currency != self.start.currency:
                raise ValueError(
                    'Cannot subtract range in %r from %r' % (
                        other.start.currency, self.start.currency))
            start = self.start - other.start
            stop = self.stop - other.stop
            return TaxedMoneyRange(start, stop)
        return NotImplemented

    def __eq__(self, other: object) -> bool:
        if isinstance(other, TaxedMoneyRange):
            return (
                self.start == other.start and
                self.stop == other.stop)
        return False

    def __contains__(self, item: TaxedMoney) -> bool:
        if not isinstance(item, TaxedMoney):
            raise TypeError(
                '`in taxed_money_range` requires TaxedMoney as left operand, not %s' % (
                    type(item),))
        return self.start <= item <= self.stop

    @property
    def currency(self) -> str:
        """Return the currency of the range."""
        return self.start.currency

    def quantize(self, exp=None, rounding=None) -> 'TaxedMoneyRange':
        """Return a copy of the range with start and stop quantized.

        All arguments are passed to `TaxedMoney.quantize` which in turn calls
        `Money.quantize`.
        """
        return TaxedMoneyRange(
            self.start.quantize(exp, rounding=rounding),
            self.stop.quantize(exp, rounding=rounding))

    def replace(self, start: TaxedMoney = None, stop: TaxedMoney = None) -> 'TaxedMoneyRange':
        """Return a range with start or stop replaced with given values."""
        if start is None:
            start = self.start
        if stop is None:
            stop = self.stop
        return TaxedMoneyRange(start=start, stop=stop)

[EOD]
path: setup.py

#! /usr/bin/env python
from setuptools import setup

CLASSIFIERS = [
    'Intended Audience :: Developers',
    'License :: OSI Approved :: BSD License',
    'Operating System :: OS Independent',
    'Programming Language :: Python',
    'Programming Language :: Python :: 3.5',
    'Programming Language :: Python :: 3.6',
    'Programming Language :: Python :: 3.7',
    'Programming Language :: Python :: 3.8',
    'Topic :: Software Development :: Libraries :: Python Modules']

setup(
    name='prices',
    author='Mirumee Software',
    author_email='hello@mirumee.com',
    description='Python price handling for humans',
    license='BSD',
    version='1.1.0',
    url='https://github.com/mirumee/prices',
    packages=['prices'],
    install_requires=['babel>=2.5.0', 'typing>=3.6.0;python_version<"3.5"'],
    classifiers=CLASSIFIERS,
    platforms=['any'])

[EOD]


path: prices/discount.py

from decimal import Decimal, ROUND_DOWN
from typing import TypeVar, Union

from .money import Money
from .money_range import MoneyRange
from .taxed_money import TaxedMoney
from .taxed_money_range import TaxedMoneyRange

Numeric = Union[int, Decimal]

T = TypeVar('T', Money, MoneyRange, TaxedMoney, TaxedMoneyRange)


def fixed_discount(base: T, discount: Money) -> T:
    """Apply a fixed discount to any price type."""
    if isinstance(base, MoneyRange):
        return MoneyRange(
            fixed_discount(base.start, discount),
            fixed_discount(base.stop, discount))
    if isinstance(base, TaxedMoneyRange):
        return TaxedMoneyRange(
            fixed_discount(base.start, discount),
            fixed_discount(base.stop, discount))
    if isinstance(base, TaxedMoney):
        return TaxedMoney(
            net=fixed_discount(base.net, discount),
            gross=fixed_discount(base.gross, discount))
    if isinstance(base, Money):
        return max(base - discount, Money(0, base.currency))
    raise TypeError('Unknown base for fixed_discount: %r' % (base,))


def fractional_discount(base: T, fraction: Decimal, *, from_gross=True) -> T:
    """Apply a fractional discount based on either gross or net amount."""
    if isinstance(base, MoneyRange):
        return MoneyRange(
            fractional_discount(base.start, fraction, from_gross=from_gross),
            fractional_discount(base.stop, fraction, from_gross=from_gross))
    if isinstance(base, TaxedMoneyRange):
        return TaxedMoneyRange(
            fractional_discount(base.start, fraction, from_gross=from_gross),
            fractional_discount(base.stop, fraction, from_gross=from_gross))
    if isinstance(base, TaxedMoney):
        if from_gross:
            discount = (base.gross * fraction).quantize(rounding=ROUND_DOWN)
        else:
            discount = (base.net * fraction).quantize(rounding=ROUND_DOWN)
        return fixed_discount(base, discount)
    if isinstance(base, Money):
        discount = (base * fraction).quantize(rounding=ROUND_DOWN)
        return fixed_discount(base, discount)
    raise TypeError('Unknown base for fractional_discount: %r' % (base,))


def percentage_discount(base: T, percentage: Numeric, *, from_gross=True) -> T:
    """Apply a percentage discount based on either gross or net amount."""
    factor = Decimal(percentage) / 100
    return fractional_discount(base, factor, from_gross=from_gross)