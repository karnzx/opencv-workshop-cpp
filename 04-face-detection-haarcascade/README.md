# Face Detection haarcascade

(Below result used `haarcascade/400-num-16-stage-cascade.xml`)
<div>
  <img alt="example-test-face-reg1" width="200" height="200" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/04-face-detection-haarcascade/test-face-reg.png">

  <img alt="example-test-face-reg1" width="200" height="200" src="https://github.com/karnzx/opencv-workshop-cpp/blob/main/04-face-detection-haarcascade/test-face-reg2.png">
</div>

## ** First unzip zipfile in negative, positive, test to get image for train and test **

### .dat file extension is text file contain the list of image path 

(positive.dat have additional arguments that is {path number, x1, y1, width, hight})

### positive.vec use for train model

### model with create in haarcascade directory when finish every stages (cascade.xml)

(if accidently broken in process you can run previous command again to continue training at last stage)

# Try this project trained cascade with your webcam
(trained with numPos 400 numStages 16)
```
CascadeOnWebcam.exe haarcascade\400-num-16-stage-cascade.xml
```

## Image Resource

- [positive and test](http://mmlab.ie.cuhk.edu.hk/projects/CelebA.html)

- negative from Lecturer 
