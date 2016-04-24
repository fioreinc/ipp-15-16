import re
import sys
import matplotlib.pyplot as plt

# Make sure a text file is provide
if not len(sys.argv[1:]):
	print("Must supply a filename")
	sys.exit(1)

# Open text file
file_name = sys.argv[1]
f = open(file_name)
test_case = str(raw_input('Enter test case (ex. "empty can"): '))
with open (file_name) as f:
	read_data = f.read()			# read entire text file
	mylist = re.split(',|\n|',read_data)	# parse values, using delimeters
	del mylist[-1]				# remove " " from end of array
	float_list = map(float, mylist)		# convert from string to float

# Debugging
#	print ("List from text file:")
#	for index, item in enumerate(float_list):
#		print index, item

# Assign values to their appropriate array [start:stop:step]
	time_val = float_list[0::6]		# elapsed time
	thumb_val = float_list[1::6]		# thumb readings		
	index_val = float_list[2::6]		# index finger readings
	middle_val = float_list[3::6]		# middle finger readings
	ring_val = float_list[4::6]		# ring finger readings
	pinky_val = float_list[5::6]		# pinky readings

# Print the plot's color 'key' to the command line, for user reference
print ("Python Plot Color Key")
print("Thumb:  RED")
print("Index:  BLUE")
print("Middle: GREEN")
print("Ring:   MAGENTA")
print("Pinky:  BLACK")

plt.title("Sensor Data Plot: %s" % test_case)	# plot title
plt.xlabel('Time (milliseconds)')		# label x axis
plt.ylabel('Sensor Measurements (volts)')	# label y axis 
plt.plot(time_val,thumb_val,'r-')		# plot thumb in red	
plt.plot(time_val,index_val, 'b-')		# plot index in blue
plt.plot(time_val,middle_val,'g-')		# plot middle in green
plt.plot(time_val,ring_val,'m-')		# plot ring in magenta
plt.plot(time_val,pinky_val,'k-')		# plot pinky in black
plt.show()
