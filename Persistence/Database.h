
#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "../Model/Operation.h"

class Database {
public:
    void addOperation(const std::string &type, double a, double b, double result);
    void saveToFile(const std::string &filename);

private:
    std::vector<Operation> operations;
};

#endif // DATABASE_H
