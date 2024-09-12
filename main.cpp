#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <climits> // Inclui o cabeçalho <climits> para usar INT_MAX

// Função para gerar um vetor com 'size' elementos inteiros aleatórios
std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = dis(gen);
    }
    return vec;
}

// Função para gerar um vetor ordenado com 'size' elementos
std::vector<int> generateSortedVector(size_t size) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = i;
    }
    return vec;
}

// Função para medir e imprimir o tempo de ordenação
void measureSortTime(const std::vector<int>& vec, const std::string& description) {
    std::vector<int> copy = vec;  // Cria uma cópia do vetor para não alterar o original
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(copy.begin(), copy.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time to sort " << description << ": " << duration.count() << " seconds" << std::endl;
}

int main() {
    // Tamanhos dos vetores
    std::vector<size_t> sizes = {1000, 10000, 100000, 1000000};

    // Gerar e ordenar vetores de tamanhos diferentes
    for (size_t size : sizes) {
        std::vector<int> randomVec = generateRandomVector(size);
        measureSortTime(randomVec, std::to_string(size) + " random elements");

        std::vector<int> sortedVec = generateSortedVector(size);
        measureSortTime(sortedVec, std::to_string(size) + " sorted elements");
    }

    return 0;
}
