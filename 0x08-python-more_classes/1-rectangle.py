#!/usr/bin/python3
"""
module to define an empty class
"""


class Rectangle:
    """
    empty class Rectangle that represents  a rectangle
    """
    def __init__(self, width=0, height=0):
        """
        initializing a class Rectangle

        Args:
            width (int): the width of the rectangle
            height (int): the height of the rectangle

        Raises:
            TypeError: if the value is not an integer
            ValueError: if the value is less than 0
        """
        self.__width = width
        self.__height = height

    @property
    def width(self):
        """to retrive the width"""
        return self.__width

    @width.setter
    def width(self, value):
        """to set the width attribute"""
        if not isinstance(value, int):
            raise TypeError('width must be an integer')
        if value < 0:
            raise ValueError('width must be >= 0')
        self.__width = value

    @property
    def height(self):
        """to retive the attribute"""
        return self.__height

    @height.setter
    def height(self, value):
        """to set the height attribute"""
        if not isinstance(value, int):
            raise TypeError('height must be an integer')
        if value < 0:
            raise ValueError('height must be >= 0')
        self.__height = value
