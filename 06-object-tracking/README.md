# Object Tracking

- Detect movement by using background subtraction method

- Object tracking by compare distance of object in previous with new frame to tell programe they are same object but in different frame(time) so its can mark ID on it

- Counting when cross the line, counting is more accurated than "05-motion-detection" because using benefit of object tracking and also using average of previous object y axis to know the direction of object so its can tell which go up or down 

## tracking moving object in video and count when cross the line
- `simple-tracking.cpp` only detect the movement in background and create bounding box on it
    - please use with video.avi

`run with "video.avi"`
<div>
  <img alt="detect1" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/06-object-tracking/result/1.png">
</div>

---

- `highway.cpp` detect car and count when cross the line with direction where car go
    - please use with highway.mp4

`run with "highway.mp4"`
<div>
  <img alt="detect2" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/06-object-tracking/result/highway.png">
</div>
