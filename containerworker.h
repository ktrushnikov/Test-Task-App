#ifndef CONTAINERWORKER_H
#define CONTAINERWORKER_H

#include <vector>
#include <map>
#include <random>
#include <time.h>

class ContainerWorker
{
public:
    ContainerWorker();                                                                               

    void sync_data();

    void fillVectorData();
    void fillMapData();

    void removeFewValues(int count);

    const std::vector<int> &getVectorData() const;
    const std::map<int, int> &getMapData() const;

private:
    std::vector<int> vec_data;
    std::map<int, int> map_data;

    int common_count;

    bool mapContainsValue(int value);
};
                    
#endif // CONTAINERWORKER_H
