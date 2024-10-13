//
// Created by Mateusz on 10.10.2024.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include "BruteForce.h"

using namespace std;

bool BruteForce::nextPermutation(int *elements, int n) {
    //Szukamy największego indeksu, dla którego elementy są ustawione rosnąco
    int i = n - 2;
    while (i >= 0 && elements[i] >= elements[i+1]) i--;

    //Jeśli nie ma takiego indeksu, to znaczy, że koniec permutacji
    if (i < 0) return false;
    //Szukamy największego indeksu od prawej strony, który wskaże nam największy element w nieposortowanej częsci tabeli !!!!!!!ZMIENIC!!!!!!
    int j = n -1;
    while (elements[j] <= elements[i]) j--;

    //Zamiana elementów na pozycji i oraz j
    swap(elements[i],elements[j]);

    //Odwracamy elementy od elements[i + 1] do końca
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        swap(elements[left],elements[right]);
        left++;
        right--;
    }
    return true;
}

int* BruteForce::algorithm(int **matrix, int n) {
    int minPath;
    int curCity;
    int nextCity;
    int startCity;
    int *minRoute = new int[n+1];
    int *cities = new int[n];
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }
    //Pierwsza permutacja
    int curPath = 0;
    for (int i = 0; i < n; i ++) {
        if (i < n - 1) {
            curPath += matrix[i][i+1];
        }
        else {
            //Powrót do miejsca startowego
            curPath += matrix[i][0];
        }
    }
    minPath = curPath;
    //Generowanie kolejnych permutacji
    while (nextPermutation(cities, n)) {
        int *curRoute = new int[n + 1]; //Tablica przechowująca bieżącą drogę
        curPath = 0;
        for (int i = 0; i < n - 1; i ++) {
            curCity = cities[i];
            nextCity = cities[i + 1];
            curRoute[i] = curCity;
            curPath += matrix[curCity][nextCity];
        }
        //Dopisanie ostatniego miasta
        curRoute[n-1] = nextCity;

        //Droga z ostatniego miasta do miasta startowego
        startCity = cities[0];
        curCity = cities[n-1];
        curPath += matrix[curCity][startCity];
        curRoute[n] = startCity;
        //Sprawdzanie, czy bieżąca droga może być drogą najkrótszą i ewentualne jej zapamiętanie
        if (curPath < minPath) {
            minPath = curPath;
            memcpy(minRoute, curRoute, (n+1) * sizeof(int));
        }
        delete[] curRoute;
    }
    return minRoute;
}

int BruteForce::countRoute(int **matrix, int *routeArr, int n) {
    int route = 0;
    int routeLen = n + 1;
    int curCity, nextCity,lastCity,firstCity;
    for (int i = 0; i < routeLen - 1; i++) {
        curCity = routeArr[i];
        nextCity = routeArr[i+1];
        route += matrix[curCity][nextCity];
    }
    //Droga z ostatniego do pierwszego miasta
    lastCity = routeArr[routeLen-1];
    firstCity = routeArr[0];
    route += matrix[lastCity][firstCity];
    return route;

}


void BruteForce::displayRoute(int **matrix, int *route, int n) {
    int curCity, nextCity, lastCity;
    int routeLen = n + 1;
    //cout << "routeLen: " << routeLen << endl;
    for (int i = 0; i < routeLen-1; i++) {
        curCity = route[i];
        nextCity = route[i+1];
        //cout << curCity << "   " << nextCity << endl;
        printf("%d -(%d)-> ",curCity,matrix[curCity][nextCity]);
    }
    lastCity = route[routeLen-1];
    printf("%d\n", lastCity);
}

void BruteForce::displayArray(int *arr,int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}