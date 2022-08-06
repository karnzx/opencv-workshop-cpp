# ANN MLP Prediction
train model for predict which is 'car identity card' (idcar) or 'personal identity card' (idcard)

**If some warning occurred in run time it may be just a DEBUG warning.**

This script written in batch

1. Generate
	- call 1cmd_generate.bat

		to generate image with posible position when predicting

2. Extract feature
	- call 2cmd_listfile.bat
		
		to generate idcar.txt and idcard.txt

	- call 3cmd_feature.bat
		
		to generate features for input (in.txt) and output (out.txt) and number of sample (sample.txt)

3. Learn feature
	- call 4cmd_learn.bat

		train the model and save to model.xml

4. Predict 
	- call 5cmd_test_predict.bat

		to test predict with trained image
	
	- call 6cmd_prediction.bat

		to use current trained model to predict identity card in resized-image-645

		![result-6cm_prediction](https://github.com/karnzx/opencv-workshop-cpp/blob/main/03-ann-mlp-prediction/terminal-6cmd_predict.png)

# Example of predict

**when predict the image with trained model (image size (width) must be equal to size when trained in this example is 645 pixel width)**

```
LprPredict.exe resized-image-645\idcar3.jpg model.xml 645
```

# Image resource

- id car

	- [idcar.jpg](https://commons.wikimedia.org/wiki/File:Thailand_probationary_dl_sample_obverse.svg)

	- [idcar2.jpg](https://www.thebangkokinsight.com/news/business/economics/245250/)

	- [idcar3.jpg](https://grabdriverth.com/document)

- id card

	- [idcard.jpg](https://aiforthai.in.th/files/iappIDcr-front-ex.jpg)

	- [idcard2.jpg](https://matemnews.com/News/24796)

	- [idcard3.jpg](https://twitter.com/iam_double_p/status/1121107011708411905?lang=zh-Hant)

