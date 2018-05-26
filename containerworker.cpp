#include "containerworker.h"

#include <algorithm>
#include <iostream>
#include <iterator>

ContainerWorker::ContainerWorker()
{
    common_count = 10 + rand() % 21;
}

void ContainerWorker::sync_data()
{
    for (int item : vec_data) {
        if (!mapContainsValue(item))
            vec_data.erase(std::remove(vec_data.begin(), vec_data.end(), item), vec_data.end());
    }

    for (auto it = map_data.begin(); it != map_data.end();) {
        if (std::find(vec_data.begin(), vec_data.end(), it->second) == vec_data.end())
            it = map_data.erase(it);
        else
            it++;
    }
}

void ContainerWorker::fillVectorData()
{
    vec_data.clear();
    for (int i = 0; i < common_count; i++)
        vec_data.push_back(1 + rand() % 10);
}

void ContainerWorker::fillMapData()
{
    map_data.clear();
    for (int i = 0; i < common_count; i++)
        map_data[i] = 1 + rand() % 10;
}

void ContainerWorker::removeFewValues(int count)
{
    if (count > common_count)
        return;
    vec_data.erase(vec_data.begin(), vec_data.begin() + count);
    map_data.erase(map_data.begin(), std::next(map_data.begin(), count));
}

const std::vector<int> &ContainerWorker::getVectorData() const
{
    return vec_data;
}

const std::map<int, int> &ContainerWorker::getMapData() const
{
    return map_data;
}

bool ContainerWorker::mapContainsValue(int value)
{
    for (auto it = map_data.begin(); it != map_data.end(); it++) {
        if (it->second == value)
            return true;
    }
    return false;
}
