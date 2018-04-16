#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "builder.h"
#include <fstream>
#include <vector>
#include <string>
#include <fstream>

class FileParser{
protected:
    Builder* m_Builder;
public:
    void setBuilder(Builder* builder){
        m_Builder = builder;
    }

    void tokenize(std::ifstream* infile){
        // array?
        std::vector<std::vector<std::string> > matrix;
        std::string token = "";
        if (infile->is_open()){
            std::string line = "";
            while (std::getline(*infile, line)){
                std::istringstream ss(line);
                std::vector<std::string> segments;
                while(std::getline(ss, token, ',')){
                    segments.push_back(token);
                }
                matrix.push_back(segments);
            }

        }
        m_Builder->add(matrix);
    }

};

#endif // FILEPARSER_H
