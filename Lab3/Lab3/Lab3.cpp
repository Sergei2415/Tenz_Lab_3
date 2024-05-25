#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> value_data, rows_data, columnIndexes_data ,testvalue, testvalue2;
std::string line;
int b = 2;
// Импорт данных
void ImportData() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return ;
    }



    for (int i = 0; i < 3 && std::getline(file, line); ++i) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            if (i == 0) {
                value_data.push_back(num);
            }
            else if (i == 1) {
                rows_data.push_back(num);
            }
            else {
                columnIndexes_data.push_back(num);
            }
        }
    }

    file.close();

    // Print the vectors to check if the numbers are imported correctly
    std::cout << "Vector 1: ";
    for (const auto& n : value_data) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    for (const auto& n : rows_data) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::cout << "Vector 3: ";
    for (const auto& n : columnIndexes_data) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    std::cout << sqrt(value_data.size()) << ' ';
    std::cout << std::endl;
}

// Выполнить задание для маленького массива
void solving_the_task() {


    int** arr = new int* [columnIndexes_data.size() + 1];
    int* value_array = new int[value_data.size()];

    // Выделяем память для каждого массива и инициализируем указатели
    for (int i = 0; i < columnIndexes_data.size() + 1; ++i) {
        arr[i] = new int[columnIndexes_data.size() + 1];
        for (int j = 0; j < columnIndexes_data.size() + 1; ++j) {
            arr[i][j] = 0;
        }
    }
    // Заполняем массив данными
    int current_index = 0;
    for (int i = 0; i < columnIndexes_data.size() - 1; i++) {
        for (int j = current_index; j < columnIndexes_data[i + 1]; j++) {

            arr[rows_data[current_index]][i] = value_data[j];
            current_index += 1;
        }
    }
    cout << endl << endl;

    // Выводим массив параллельно заполняя testvalue
    for (int i = 0; i < columnIndexes_data.size() - 1; i++) {
        for (int j = 0; j < columnIndexes_data.size() - 1; j++) {
            std::cout << arr[i][j] << " ";
            if (arr[i][j] != 0) {
                testvalue.push_back(arr[i][j]);
            }
        }
        std::cout << std::endl;
    }
    cout << "b = " << b << endl;

    //Вывод значений вектора testvalue
    cout << "До " << endl;
    for (int i = 0; i < value_data.size(); ++i) {
        cout << testvalue[i] << " ";

    }

    // Сортировка testvalue
    int buf = 0;
    for (int i = 0; i < testvalue.size(); ++i) {
        //std::cout << "Index: " << i << ", Value: " << value_data[i] << std::endl;
        if (testvalue[i] < b) {
            /*
            cout <<endl<< "В цикле при итерации i = " << i << " до преобразования" << endl;
            for (int i = 0; i < value_data.size(); ++i) {
                cout << testvalue[i] << " ";
            }*/
            //cout << endl;
            for (int j = i + 1; j < testvalue.size(); j++) {

                if (testvalue[j] > b) {
                    //cout << "До в i - " << testvalue[i] << endl;
                    //cout << "До в j - " << testvalue[j] << endl;
                    buf = testvalue[j];
                    for (int k = j; k > i; k--) {

                        iter_swap(testvalue.begin() + k, testvalue.begin() + k - 1);
                        /*
                        cout << endl << "В цикле ВНУТРИ при итерации k = " << k << " до преобразования" << endl;
                        for (int i = 0; i < value_data.size(); ++i) {
                            cout << testvalue[i] << " ";
                        }
                        cout << endl;*/
                    }

                    //cout << "После в i - " << testvalue[i] << endl;
                    //cout << "После в j - " << testvalue[j] << endl;
                    //cout << endl;
                    break;
                }
            }
            /*
            cout << "В цикле при итерации i = " << i << " после преобразования" << endl;
            for (int i = 0; i < value_data.size(); ++i) {
                cout << testvalue[i] << " ";
            }*/
            cout << endl;

        }
        //cout << "После в testvalue i - " << testvalue[i] << endl;

    }


    //Вывод значений вектора testvalue
    cout << "После " << endl;
    for (int i = 0; i < value_data.size(); ++i) {
        cout << testvalue[i] << " ";

    }
    cout << endl << endl;

    // Заполнение массива отсортированными значениями из testvalue

    int index = 0;
    for (int i = 0; i < columnIndexes_data.size() - 1; i++) {
        for (int j = 0; j < columnIndexes_data.size() - 1; j++) {
            if (arr[i][j] != 0) {
                arr[i][j] = testvalue[index];
                index += 1;
            }
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;

}

// Выполнить задание для большого массива
void array_output() {

    int** arr = new int* [columnIndexes_data.size() + 1];
    int* value_array = new int[value_data.size()];

    // Выделяем память для каждого массива и инициализируем указатели
    for (int i = 0; i < columnIndexes_data.size() + 1; ++i) {
        arr[i] = new int[columnIndexes_data.size() + 1];
        for (int j = 0; j < columnIndexes_data.size() + 1; ++j) {
            arr[i][j] = 0;
        }
    }
    // Заполняем массив данными
    int current_index = 0;
    for (int i = 0; i < columnIndexes_data.size() - 1; i++) {
        for (int j = current_index; j < columnIndexes_data[i + 1]; j++) {
            
            arr[rows_data[current_index]][i] = value_data[j];
            current_index += 1;
        }
    }
    cout << endl << endl;

    // Выводим массив параллельно заполняя testvalue
    for (int i = 0; i < columnIndexes_data.size() - 1; i++) {
        for (int j = 0; j < columnIndexes_data.size() - 1; j++) {
            std::cout << arr[i][j] << " ";
            if (arr[i][j] != 0) {
                testvalue.push_back(arr[i][j]);
            }
        }
        std::cout << std::endl;
    }
    cout << "b = " << b  << endl;

    //Вывод значений вектора testvalue
    cout << "До "  << endl;
    for (int i = 0; i < value_data.size(); ++i) {
        cout << testvalue[i] << " ";

    }
    
    // Сортировка testvalue
    int buf = 0;
    for (int i = 0; i < testvalue.size(); ++i) {
        //std::cout << "Index: " << i << ", Value: " << value_data[i] << std::endl;
        if (testvalue[i] < b) {
            /*
            cout <<endl<< "В цикле при итерации i = " << i << " до преобразования" << endl;
            for (int i = 0; i < value_data.size(); ++i) {
                cout << testvalue[i] << " ";
            }*/
            //cout << endl;
            for (int j = i + 1; j < testvalue.size(); j++) {

                if (testvalue[j] > b) {
                    //cout << "До в i - " << testvalue[i] << endl;
                    //cout << "До в j - " << testvalue[j] << endl;
                    buf = testvalue[j];
                    for (int k = j; k > i; k--) {

                        iter_swap(testvalue.begin() + k, testvalue.begin() + k-1);
                        /*
                        cout << endl << "В цикле ВНУТРИ при итерации k = " << k << " до преобразования" << endl;
                        for (int i = 0; i < value_data.size(); ++i) {
                            cout << testvalue[i] << " ";
                        }
                        cout << endl;*/
                    }

                    //cout << "После в i - " << testvalue[i] << endl;
                    //cout << "После в j - " << testvalue[j] << endl;
                    //cout << endl;
                    break;
                }
            }
            /*
            cout << "В цикле при итерации i = " << i << " после преобразования" << endl;
            for (int i = 0; i < value_data.size(); ++i) {
                cout << testvalue[i] << " ";
            }*/
            cout << endl;

        }
        //cout << "После в testvalue i - " << testvalue[i] << endl;

    }


    //Вывод значений вектора testvalue
    cout << "После "  << endl;
    for (int i = 0; i < value_data.size(); ++i) {
        cout << testvalue[i] << " ";

    }
    cout << endl << endl;

    // Заполнение массива отсортированными значениями из testvalue
    
    int index = 0;
    for (int i = 0; i < columnIndexes_data.size() - 1; i++) {
        for (int j = 0; j < columnIndexes_data.size() - 1; j++) {
            if (arr[i][j] != 0) {
                arr[i][j] = testvalue[index];
                index += 1;
            }
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << endl << endl;

    // Вывод больших данный
    for (int j = 0; j < 2; j++) {
        std::cout << arr[0][j] << " ";
    }
    cout << " . . . ";
    for (int j = columnIndexes_data.size()-3; j < columnIndexes_data.size()-1; j++) {
        std::cout << arr[0][j] << " ";
    }
    cout << endl;
    for (int j = 0; j < 2; j++) {
        std::cout << arr[1][j] << " ";
    }
    cout << " . . . ";
    for (int j = columnIndexes_data.size() - 3; j < columnIndexes_data.size() - 1; j++) {
        std::cout << arr[1][j] << " ";
    }
    cout << endl;
    cout << "...............";
    cout << endl;
    for (int j = 0; j < 2; j++) {
        std::cout << arr[columnIndexes_data.size() - 3][j] << " ";
    }
    cout << " . . . ";
    for (int j = columnIndexes_data.size() - 3; j < columnIndexes_data.size() - 1; j++) {
        std::cout << arr[columnIndexes_data.size() - 3][j] << " ";
    }
    cout << endl;
    for (int j = 0; j < 2; j++) {
        std::cout << arr[columnIndexes_data.size() - 2][j] << " ";
    }
    cout << " . . . ";
    for (int j = columnIndexes_data.size() - 3; j < columnIndexes_data.size() - 1; j++) {
        std::cout << arr[columnIndexes_data.size() - 2][j] << " ";
    }

}


int main() {


    setlocale(LC_ALL, "Russian");

    int choice;
    while (true) {
        cout << "\nДоступные опции:\n";
        cout << "1. Импорт данных из файла\n";
        cout << "2. На места ненулевых элементов матрицы вначале поместить все её ненулевые элементы большие b, а затем ненулевые элементы меньшие b. Элементы не сортировать. Большой вывод\n";
        cout << "3. На места ненулевых элементов матрицы вначале поместить все её ненулевые элементы большие b, а затем ненулевые элементы меньшие b. Элементы не сортировать. Обычный вывод\n";
        cout << "4. Выход\n";
        cout << "Введите число(номер опции): ";
        cin >> choice;

        switch (choice) {
        case 1:
            ImportData();
            break;
        case 2:
            array_output();
            break;
        case 3:
            solving_the_task();
            break;
        case 4:
            cout << "Выход...\n";
            return 0;
        default:
            cout << "Некорректный ввод опции! Повторите попытку.\n";
            break;
        }
    }
    return 0;




    return 0;
}
