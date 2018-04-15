#ifndef PARSER_H
#define PARSER_H

#include "builder.h"
#include <fstream>
#include <vector>
#include <string>

class Parser{
protected:
    Builder* m_dataBuilder;
public:
    void setBuilder(Builder* builder){
        m_dataBuilder = builder;
    }

    void tokenize(std::string line){
        std::vector<std::string> segments;
        std::istringstream ss(line);
        std::string token = "";
        while(std::getline(ss, token, ',')){
            // add everything to database row somehow
            //std::cout << token << std::endl;
            segments.push_back(token);
        }
        m_dataBuilder->addRow(segments);
    }


};

#endif // PARSER_H
