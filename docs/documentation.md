## DOCUMENTATION 

-- Functions -- 

We have created 4 separate functions: 

# int GatherReadings(float[]);

This function takes input from the user and modifies the float array in main, hence why it takes it as a parameter. It also returns the size of the array back to main as well in order to be used in future functions.

# void isInRange(float[], int[], int);

This function takes the readings that were defined in GatherReadings() and fills out int ranges[] that functions as a boolean array.

Since the index of both ranges[] and readings[] are the same, ranges[] serves as a check for readings[] to make sure that value is within range. 

The range being between 68F - 76F

# void DisplayStatus(float[], int[], int);

This function serves the role of printing the readings and articulating if the temperatures are in range or not. It takes int ranges[] to know whether or not if a temperature is out of range. It also takes size, provided by GatherReadings, to know the size of both readings[] and ranges[].

# float calculatAverages(float[], int);

This function takes readings and adds them to a local variable, float total, and returns itself divided by size which is provided by the second parameter. 