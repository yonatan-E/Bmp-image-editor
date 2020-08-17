#pragma once

#include "Matrix.h" 
#include <cstdint>

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

            /**
             * @brief The getter operator
             * 
             * @param rowIndex the row of the item we want to get
             * @param colIndex the column of the item we want to get
             * @return double the value of the item placed in (rowIndex, colIndex)
             */
            double operator()(uint32_t rowIndex, uint32_t colIndex);

            /**
             * @brief The setter method
             * 
             * @param val the val we want to set
             * @param rowIndex the row of the item we want to set
             * @param colIndex the column of the item we want to set
             */
            void setAt(double val, uint32_t rowIndex, uint32_t colIndex);

            /**
             * @brief Getter to the matrix height
             * 
             * @return uint32_t the height of the matrix
             */
            uint32_t getHeight();

            /**
             * @brief Getter to the matrix width
             * 
             * @return uint32_t the width of the matrix
             */
            uint32_t getWidth();
    };
}
