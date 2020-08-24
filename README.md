About the project
--------------------------------------------------------------------------------------------------------------------------
This project is about dealing with image files in format BMP, using matrices.

**About the matrix class design**  
The matrix class uses the behavior and the functionality of the struct matrix from the libmatrix.so library.
The class actually saves a pointer to a struct matrix, and uses *delegation* to get the behavior of this struct, using the global functions of the struct, appears in the library libmatrix.so. Most of the mathods in the Matrix class delegates the functionality of the struct matrix: methods like the getters, setters, the copy ctor, and the operators.
The Matrix class also performs *the rule of 5*.

**About the dealing with BMP files**  
There are classes which represent every part of the BMP file: Header, DIB Header, Color pallete, and Bitmap array.
The class Bitmap is the main class, which represents the whole BMP file by containing objects of the BMP file parts.
In the implementation, we used the *design pattern component* to make all the parts work together.
All of those classes are inheriting from the abstract class BitAdjuster, and implementing at least the following methods:
turn() - changes the current part of the BMP file, according to turning the image right by 90 degrees.
gray() - changes the current part of the BMP file, according to changing the color of the image to gray.
write() - writes the content of the object into a string (binary).
So according to the *design pattern component*, calling each one of those methods in the class Bitmap actually calling
those methods for the objects of the parts of the BMP file (the parts of the file are the "leaves"). 
**In case that the format of the file will be different**, the change in the implementation will be as the following:
Implementing a class for each part of the file (each part cannot be splitted to other parts), and each class should inherit from the abstract class and implement the abstract methods, which will be according to the file format.       Also need to implement a main class which will represent the whole file, and will contain objects of the parts of the file. The implementation of the abstract methods in the main class must call those methods for the objects of the parts of the file, according to the *design pattern component*. 