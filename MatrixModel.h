//
// Created by Mateusz on 10.10.2024.
//

#ifndef PEA_PROJEKT_1_MATRIXMODEL_H
#define PEA_PROJEKT_1_MATRIXMODEL_H
#include <string>

class MatrixModel {
private:
    void initMatrix();  //Utworzenie macierzy o rozmiarze n wypełnionej zerami
public:
    int **matrix;
    int n; //Rozmiar macierzy
    void freeMatrix();
    void displayMatrix();
    void loadMatrixFromFile(std::string path);

};


#endif //PEA_PROJEKT_1_MATRIXMODEL_H