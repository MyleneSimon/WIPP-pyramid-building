#!/usr/bin/env bash
#
../tools/run_benchmarks.sh dataset7_1024 1 --benchmark memory  \
-v /home/gerardin/Documents/images/dataset7/img-global-positions-0.txt \
-i /home/gerardin/Documents/images/dataset7/tiled-images \
-o /home/gerardin/Documents/pyramidBuilding/outputs \
-t 1024 -d 8U

#../tools/run_benchmarks.sh dataset5_1024 1 --benchmark memory \
#-v /home/gerardin/Documents/images//dataset5/img-global-positions-1.txt \
#-i /home/gerardin/Documents/images/dataset5/images \
#-o /home/gerardin/Documents/pyramidBuilding/outputs \
#-t 1024 -d 8U

#../tools/run_benchmarks.sh dataset1_256 1 memory \
#-v /home/gerardin/Documents/pyramidBuilding/resources/dataset1/img-global-positions-1.txt \
#-i /home/gerardin/Documents/pyramidBuilding/resources/dataset1/images \
#-o /home/gerardin/Documents/pyramidBuilding/outputs \
#-t 256 -d 8U

#
#../tools/run_benchmarks.sh dataset1_memory_fastImage 1 memory  \
#-v /home/gerardin/Documents/pyramidBuilding/resources/dataset1/stitching_vector/img-global-positions-1.txt \
#-i /home/gerardin/Documents/pyramidBuilding/resources/dataset1/tiled-images \
#-o /home/gerardin/Documents/pyramidBuilding/outputs \
#-t 256 -d 8U

