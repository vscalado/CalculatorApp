
#include "Database.h"
#include <yaml-cpp/yaml.h>
#include <fstream>

void Database::addOperation(const std::string &type, double a, double b, double result) {
    operations.push_back(Operation{type, a, b, result});
}

void Database::saveToFile(const std::string &filename) {
    YAML::Emitter out;
    out << YAML::BeginSeq;
    for (const auto &op : operations) {
        out << YAML::BeginMap;
        out << YAML::Key << "tipo" << YAML::Value << op.type;
        out << YAML::Key << "a" << YAML::Value << op.a;
        out << YAML::Key << "b" << YAML::Value << op.b;
        out << YAML::Key << "resultado" << YAML::Value << op.result;
        out << YAML::EndMap;
    }
    out << YAML::EndSeq;

    std::ofstream fout(filename);
    fout << out.c_str();
}
