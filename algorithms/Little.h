//
// Created by Mateusz on 25.10.2024.
//

#ifndef PEA_PROJEKT_1_LITTLENEW_H
#define PEA_PROJEKT_1_LITTLENEW_H


#include <vector>
#include <limits>
#include <queue>
#include "../Helpers.h"
const int INF = std::numeric_limits<int>::max();

class Little {
public:
    // Algorytm Little'a do rozwiązania problemu komiwojażera
    int* algorithm(int** costMatrix, int size);

private:
    struct Node {
        int** reducedMatrix;
        int cost;
        int vertex;
        int level;
        std::vector<int> path;
        //Operator porównania węzłów na podstawie wartości cost. Służy do porównywania węzłów wstawianych do kolejki priorytetowej
        bool operator>(const Node& other) const {
            return cost > other.cost;
        }
    };
    Helpers helpers;
    // Metody pomocnicze
    int** createMatrix(int size);
    void deleteMatrix(int** matrix, int size);
    int** copyMatrix(int** matrix, int size);
    void replaceZeroesWithINF(int** matrix, int size);
    int reduceMatrix(int** matrix, int size);
    Node createNode(int** parentMatrix, int level, int i, int j, int parentCost, std::vector<int> path, int size);
    double calculateSymmetry(int** matrix, int size);
};

#endif //PEA_PROJEKT_1_LITTLENEW_H
