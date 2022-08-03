# ANN MLP

0. try run LprGenerate.exe with "CMD"
    if Error maybe it not found put opencv41 folder path into env path | your opencv /bin
1. Generate
	- call 1cmd_generate
2. Extract feature
	- call 2cmd_listfile
		to generate p00.txt...p92.txt
	- call 3cmd_feature
		to generate features for input (in.txt) and output (out.txt)
			get n_simples is a sample number
3. Learn feature
	- call 4cmd_learn

4. Predict 
	- call 5cmd_predict
	
