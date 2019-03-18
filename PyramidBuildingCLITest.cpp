//
// Created by Gerardin, Antoine D. (Assoc) on 2/25/19.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <tclap/CmdLine.h>
#include "src/api/CommandLineCli.h"
#include <experimental/filesystem>

using namespace std::experimental;

int main(int argc, const char** argv)
{

//        std::string vector = "/Users/gerardin/Documents/projects/wipp++/pyramid-building/resources/dataset1/stitching_vector/img-global-positions-1.txt";
//        std::string directory = "/Users/gerardin/Documents/projects/wipp++/pyramid-building/resources/dataset1/tiled-images/";
//        uint32_t tilesize = 256;

//    std::string vector = "/home/gerardin/Documents/pyramidBuilding/resources/dataset1/stitching_vector/img-global-positions-1.txt";
//    std::string directory = "/home/gerardin/Documents/pyramidBuilding/resources/dataset1/tiled-images/";
//    uint32_t tilesize = 256;

//    std::string vector = "/home/gerardin/Documents/images/dataset2/img-global-positions-1.txt";
//    std::string directory = "/home/gerardin/Documents/images/dataset2/images/";
//    uint32_t tilesize = 1024;

//    std::string vector = "/home/gerardin/Documents/pyramidBuilding/resources/dataset03/stitching_vector/img-global-positions-1.txt";
//    std::string directory = "/home/gerardin/Documents/pyramidBuilding/resources/dataset03/images/";
//    uint32_t tilesize = 256;

    std::string vector = "/Users/gerardin/Documents/projects/pyramidio/pyramidio/src/test/resources/dataset2/stitching_vector/tiled-pc/img-global-positions-1.txt";
    std::string directory = "/Users/gerardin/Documents/projects/pyramidio/pyramidio/src/test/resources/dataset2/images/tiled-pc/";
    uint32_t tilesize = 1024;

//    std::string vector = "/Users/gerardin/Documents/projects/wipp++/pyramid-building/resources/dataset03/stitching_vector/img-global-positions-1.txt";
//        std::string directory = "/Users/gerardin/Documents/projects/wipp++/pyramid-building/resources/dataset03/images/";
//        uint32_t tilesize = 512;

//    std::string vector = "/home/gerardin/Documents/images/dataset4/img-global-positions-1.txt";
//    std::string directory = "/home/gerardin/Documents/images/dataset4/images/";
//    uint32_t tilesize = 16;

//    std::string vector = "/home/gerardin/Documents/images/dataset5/img-global-positions-1.txt";
//    std::string directory = "/home/gerardin/Documents/images/dataset5/images/";
//    uint32_t tilesize = 1024;

//    std::string vector = "/home/gerardin/Documents/images/dataset6/img-global-positions-0.txt";
//    std::string directory = "/home/gerardin/Documents/images/dataset6/images/";
//    uint32_t tilesize = 1024;

    std::string output = filesystem::current_path().string();

    std::string vector_option = "-v " + vector;
    std::string tilesize_option = "-t " + std::to_string(tilesize);

    std::vector<const char*> new_argv(argv, argv + argc);

    new_argv.push_back(directory.c_str());
    new_argv.push_back(output.c_str());
    new_argv.push_back(vector_option.c_str());
    new_argv.push_back(tilesize_option.c_str());
    new_argv.push_back(nullptr); //no more arguments
    argv = new_argv.data();
    argc = argc + 4;

    pyramidBuilding(argc, argv);
}