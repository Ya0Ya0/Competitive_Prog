from typing import Callable


def remove_empty_line(func: Callable) -> Callable:
    def wrapper(*args, **kwargs):
        lines = func(*args, **kwargs)
        result = []

        result = [_ for _ in lines if len(_.strip()) > 0]

        return result

    return wrapper


def remove_whitespaces(func: Callable) -> Callable:
    def wrapper(*args, **kwargs):
        lines = func(*args, **kwargs)
        result = []

        result = [_.strip() for _ in lines]

        return result

    return wrapper


def remove_comments(func: Callable) -> Callable:
    def wrapper(*args, **kwargs):
        lines = func(*args, **kwargs)
        result = [_ for _ in lines if not _.startswith("#") and not _.startswith("//")]

        return result

    return wrapper


@remove_empty_line
@remove_comments
@remove_whitespaces
def filter_stream(filename):
    with open(filename, "r") as f:
        lines = f.readlines()
    return lines