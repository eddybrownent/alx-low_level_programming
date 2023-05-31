#!/usr/bin/python3


class Square:
    """
    Represents a square

    Attributes:
        size (float or int): the size of the square
    """

    def __init__(self, size=0):
        """
        initializes a square instance

        Args:
            size (float or int): the size of the square
        """
        self.size = size

    @property
    def size(self):
        """
        Gets the size of the square

        Returns:
            float or int; the size of the square
        """
        return self.size

    @size.setter
    def size(self, value):
        """
        Set the size of the square.

        Args:
            value (float or int): The size of the square.

        Raises:
            TypeError: If size is not a number.
            ValueError: If size is less than 0.
        """
        if not isinstance(value, (float, int)):
            raise TypeError("size must be a number")
        if value < 0:
            raise ValueError('size must be >= 0')
        self.__size = value

    def area(self):
        """
        Calculate the area of the square.

        Returns:
            float or int: The area of the square.
        """
        return self.__size * self.__size

    def __eq__(self, other):
        """
        compare if two square have equal areas

        Args:
            other (Square): the other square we are to compare with

        Returns:
            bool: true if areas are equal else false
        """
        return self.area == other.area()

    def __ne__(self, other):
        """
        compare if the two squares have different areas

        Args:
            other (square): the other area to compare with

        Returns:
            bool: true if the areas are different else false
        """
        return self.area() != other.area()

    def __gt__(self, other):
        """
        compare if the area of this square is graeter than the other area

        Args:
            other (Square): the other square to compare with
        Returns:
            bool: true if area is greater else false
        """
        return self.area() > other.area()

    def __ge__(self, other):
        """
        compare if the area is greater than or equqal to the other

        Args:
            other (Square): The other square to compare with.
        Return:
            bool: True if area is greater than or equal else False
        """
        return self.area() >= other.area()

    def __lt__(self, other):
        """
        compare if this area is ess than the area of the other square

        Args:
            other (Square): The other square to compare with
        Returns:
            bool: True if area is less, False otherwise
        """
        return self.area() < other.area()

    def __le__(self, other):
        """
        compare if this area is less than or equal to the other

        Args:
            other(square): the other area to compare with
        Returns:
            bool: true if are is less than or equal else false
        """
        return self.area() <= other.area()
