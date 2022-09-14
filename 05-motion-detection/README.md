# Motion Dection

detect movement by using background subtraction method to sperate movable thing in the picture and background

### movable in this video are people
## there are 2 different code here
1. `detect.cpp` only detect the movement in background and create bounding box on it
    - please use with `vtest.avi`
2. `detect-count.cpp` detect the movement and count when the object pass the counting line  
    - please use with `video.avi`
    - (**counting not very accurated** because current program cant track the object || program dont know that detected object in each frame is the same or not)

the noise of these video arent the same so i have to create diffrent code for each video.

## results
### detect.cpp (vtest.avi)
<div>
  <img alt="detect1" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/05-motion-detection/results/detect1.png">

  <img alt="detect2" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/05-motion-detection/results/detect2.png">
  
  <img alt="detect3" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/05-motion-detection/results/detect3.png">
</div>

### detect-count.cpp (video.avi)
<div>
  <img alt="detect-count1" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/05-motion-detection/results/detect-count1.png">

  <img alt="detect-count2" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/05-motion-detection/results/detect-count2.png">
  
</div>


