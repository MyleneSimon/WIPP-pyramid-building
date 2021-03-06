//
// Created by Gerardin, Antoine D. (Assoc) on 1/16/19.
//



#include <string>
#include <iostream>
#include <FastImage/api/FastImage.h>
#include <glog/logging.h>


#include "experimental/filesystem"
#include "SimpleReadAndWriteGraph.h"


int main()
{
    std::string directory = "/home/gerardin/Documents/images/dataset7/tiled-images/";

    auto begin = std::chrono::high_resolution_clock::now();

    auto outputPath =filesystem::current_path() / "testPerfOutput";

    if(!filesystem::exists(outputPath)) {
        filesystem::create_directory(outputPath);
    }

    auto graph = new htgs::TaskGraphConf<InputFile, ImageData<uint16_t >>();
    auto readTask = new TestReadTask<uint16_t>(20);
    auto writeTask = new TestWriteTask<uint16_t>( outputPath ,10);
    graph->setGraphConsumerTask(readTask);
    graph->addGraphProducerTask(writeTask);
    auto *runtime = new htgs::TaskGraphRuntime(graph);
    graph->addEdge(readTask,writeTask);
    runtime->executeRuntime();


    for (const auto & entry : filesystem::directory_iterator(directory)) {
        VLOG(2) << "input path: " << entry.path().string() << std::endl;
        graph->produceData(new InputFile(entry.path()));
    }


    graph->finishedProducingData();


    while(!graph->isOutputTerminated()){
        auto r = graph->consumeData();
        if(r == nullptr){
            break;
        }
        delete[] r->getData();
    }

    runtime->waitForRuntime();
    delete runtime;



    auto end = std::chrono::high_resolution_clock::now();
    VLOG(2) << "Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " mS" << std::endl;


    return 0;
}