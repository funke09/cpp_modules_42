/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:34 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/21 03:04:47 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if (str.empty()) {
        std::cerr << "Error: empty string to replace" << std::endl;
        return;
    }

    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.erase(startPos, from.length());
        str.insert(startPos, to);
        startPos += to.length();
    }
}


int main(int argc, char* argv[]) {
    // Ensure correct number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    // Open input file
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: could not open input file: " << filename << std::endl;
        return 1;
    }
    if(inputFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error: empty file" << std::endl;
        return 1;
    }
    // Open output file
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile) {
        std::cerr << "Error: could not open output file: " << filename << ".replace" << std::endl;
        return 1;
    }

    // Copy input file to output file, replacing s1 with s2
    std::string line;
    while (std::getline(inputFile, line)) {
        // if file is empty
        if (line.empty()) {
            std::cerr << "Error: empty file" << std::endl;
            return 1;
        }
        replaceAll(line, s1, s2);
        outputFile << line << std::endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    std::cout << "Replacement complete! Check " << filename << ".replace for the modified content.\n";

    return 0;
}
