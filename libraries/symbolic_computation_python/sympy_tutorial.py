'''
Tutorial on symforce and its usage
along with some basics on sympy

'''
import symforce
symforce.set_symbolic_api("sympy")
symforce.set_log_level("warning")
import symforce.symbolic as sf
from symforce.notebook_util import display, print_expression_tree


x = sf.Symbol("x")
y = sf.Symbol("y")

expr = x**2 + sf.sin(y) / x**2
display(expr)

print_expression_tree(expr)
