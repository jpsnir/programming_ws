from functools import cache, partial, wraps


def with_greeting(func):
    def wrapper(*args, **kwargs):
        print("Hello world")
        return func(*args, **kwargs)
    return wrapper


def add(x, y):
    """
    Adds two numbers
    """
    print(x + y)
