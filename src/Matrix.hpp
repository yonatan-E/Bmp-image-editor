#pragma once

#include "Matrix.h"

namespace matrix {
    
    /**
     * @brief This class defines a matrix and its general behavior.
     */
    class Matrix {
        // a pointer to struct matrix
        PMatrix _decorated;

        public:   
            /**
             * @brief The first constructor, that creates matrix by height and width
             * 
             * @param height the height of the new matrix
             * @param width the width of the new matrix
             */
            Matrix(uint32_t height, uint32_t width);    
            
            /**
             * @brief The copy constructor
             * 
             * @param other the matrix which is copied to create the new matrix from it
             */
            Matrix(const Matrix& other);  

            /**
             * @brief The copy assignment operator
             * 
             * @param other the matrix which is copied to the current matrix
             * @return Matrix& a reference to the current matrix object
             */
            Matrix& operator=(const Matrix& other);      

            /**
             * @brief The move constructor
             * 
             * @param other the matrix which is data moved to create the new matrix from it
             */
            Matrix(Matrix&& other) noexcept;       

            /**
             * @brief The move assignment operator
             * 
             * @param other the matrix which is data moved to the current matrix 
             * @return Matrix& a reference to the current matrix object
             */
            Matrix& operator=(Matrix&& other) noexcept;   

            /**
             * @brief The destructor
             */
            ~Matrix();  
    };
}
