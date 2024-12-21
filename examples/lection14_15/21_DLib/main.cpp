#include <dlib/clustering.h>
#include <iostream>
#include <vector>
#include <cstdlib>


int main() {
    // Используем тип данных для кластеризации из Dlib
    typedef dlib::matrix<double, 2, 1> sample_type;
    typedef dlib::radial_basis_kernel<sample_type> kernel_type;

    // Создаем объект для k-means кластеризации
    dlib::kcentroid<kernel_type> kc(kernel_type(0.1), 0.01, 8);

    // Создаем объект для кластеризации
    dlib::kkmeans<kernel_type> kmeans(kc);

    // Вектор для хранения данных
    std::vector<sample_type> samples;

    // Пример данных (2D точки)
    std::srand(std::time(nullptr));
    for(size_t i=0;i<100;++i){
        samples.push_back(sample_type({std::rand() % 10 , std::rand() % 10}));
    }
    // samples.push_back(sample_type({1.0, 2.0}));
    // samples.push_back(sample_type({1.1, 2.1}));
    // samples.push_back(sample_type({5.0, 5.0}));
    // samples.push_back(sample_type({5.1, 5.1}));
    // samples.push_back(sample_type({10.0, 10.0}));
    // samples.push_back(sample_type({10.1, 10.1}));

    // Указываем количество кластеров (k)
    std::vector<sample_type> initial_centers;
    initial_centers.push_back(sample_type({1.0, 2.0}));
    initial_centers.push_back(sample_type({5.0, 5.0}));
    initial_centers.push_back(sample_type({10.0, 10.0}));

    // Инициализируем k-means с начальными центрами
    kmeans.set_number_of_centers(initial_centers.size());
    pick_initial_centers(initial_centers.size(), initial_centers, samples, kmeans.get_kernel());

    // Обучаем модель
    kmeans.train(samples, initial_centers);

    // Кластеризуем данные
    for (const auto& sample : samples) {
        std::cout << "Точка (" << sample(0) << ", " << sample(1) << ") принадлежит кластеру "
                  << kmeans(sample) << std::endl;
    }

    return 0;
}