#include <iostream>

#include "containerworker.h"

int main()
{
    ContainerWorker worker;
    srand(time(NULL));

    worker.fillVectorData();
    worker.fillMapData();

    for (size_t i = 0; i < worker.getVectorData().size(); i++) {
        std::cout << "Vector data[" << i << "] is " << worker.getVectorData().at(i) << std::endl;
        std::cout << "Map data[" << i << "] is " << worker.getMapData().at(i) << std::endl;
        std::cout << "----------" << std::endl;
    }

    std::cout << std::endl << std::endl << "------------------------------------------------------" << std::endl << std::endl;

    worker.removeFewValues(1 + rand()%15);
    worker.sync_data();


    std::cout << "Vector: ";
    for (int i : worker.getVectorData()) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "-------------------------------" << std::endl << "Map: ";
    for (auto it = worker.getMapData().begin(); it != worker.getMapData().end(); it++) {
        std::cout << it->second << " ";
    }
    std::cout << "\n";

    return 0;
}
