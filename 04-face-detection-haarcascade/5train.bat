REM numPos = 0.9 * number_of_positive_samples 
REM minHitRate = 0.99 
opencv_traincascade.exe -data haarcascade -vec positive.vec -bg negative.dat ^
-numPos 1200 -numNeg 900 -numStages 10 -featureType HAAR -w 24 -h 24 ^
-minHitRate 0.9999 -precalcValBufSize 2048 -precalcIdxBufSize 2048
