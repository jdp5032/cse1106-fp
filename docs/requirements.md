## REQUIREMENTS

-- OBJECTIVE --

The objective of this project is to take input from the user and turn on an LED if the following data provided from the user exceeds the range we have outlined. 

## TEST CASES

--- TEST CASE 1 --- 
# Question: Does the warning activate if given all out of range temperatures? 
Input: 20 40 80 100 q

Result: 
--Enter Q to quit when finished--
Please enter temperature #1: 20
Please enter temperature #2: 40
Please enter temperature #3: 80
Please enter temperature #4: 100
Please enter temperature #5: q

All temperatures have been receieved!

20.0F   WARNING ON
40.0F   WARNING ON
80.0F   WARNING ON
100.0F  WARNING ON

# PASS

-- TEST CASE 2 -- 
# Question: Does the program successfully save data to status.txt?
Input: 40 50 60 70 80 90 100 q

Result: 
--Enter Q to quit when finished--
Please enter temperature #1: 40
Please enter temperature #2: 50
Please enter temperature #3: 60
Please enter temperature #4: 70
Please enter temperature #5: 80
Please enter temperature #6: 90
Please enter temperature #7: 100
Please enter temperature #8: q

All temperatures have been receieved!

40.0F   WARNING ON
50.0F   WARNING ON
60.0F   WARNING ON
70.0F   NORMAL  OFF
80.0F   WARNING ON
90.0F   WARNING ON
100.0F  WARNING ON

Status.txt: 
40.0F   WARNING ON
50.0F   WARNING ON
60.0F   WARNING ON
70.0F   NORMAL  OFF
80.0F   WARNING ON
90.0F   WARNING ON
100.0F  WARNING ON
Average: 70.0

# PASS

-- TEST CASE 3 --
# Question: Is status.txt cleared so it can receive new data?

Input: 10 11 12 q

Result:
--Enter Q to quit when finished--
Please enter temperature #1: 10
Please enter temperature #2: 11
Please enter temperature #3: 12
Please enter temperature #4: q

All temperatures have been receieved!

10.0F   WARNING ON
11.0F   WARNING ON
12.0F   WARNING ON

Status.txt: 
10.0F   WARNING ON
11.0F   WARNING ON
12.0F   WARNING ON
Average: 11.0

# PASS

-- TEST CASE 4 -- 
# Question: Does the program only read floats? 
Input: a 12 b 20 c 40 q

Result:
--Enter Q to quit when finished--
Please enter temperature #1: a
Please enter a temperature
Please enter temperature #1: 12
Please enter temperature #2: b
Please enter a temperature
Please enter temperature #2: 20
Please enter temperature #3: c
Please enter a temperature
Please enter temperature #3: 40
Please enter temperature #4: q

All temperatures have been receieved!

12.0F   WARNING ON
20.0F   WARNING ON
40.0F   WARNING ON

# PASS

-- TEST CASE 5 -- 
# Question: Does the program keep the LED off when all data is in range?
Input: 68 69 70 71 72 73 74 q

Result: 
--Enter Q to quit when finished--
Please enter temperature #1: 68
Please enter temperature #2: 69
Please enter temperature #3: 70
Please enter temperature #4: 71
Please enter temperature #5: 72
Please enter temperature #6: 73
Please enter temperature #7: 74
Please enter temperature #8: 75
Please enter temperature #9: 76
Please enter temperature #10: q

All temperatures have been receieved!

68.0F   NORMAL  OFF
69.0F   NORMAL  OFF
70.0F   NORMAL  OFF
71.0F   NORMAL  OFF
72.0F   NORMAL  OFF
73.0F   NORMAL  OFF
74.0F   NORMAL  OFF
75.0F   NORMAL  OFF
76.0F   NORMAL  OFF

# PASS
