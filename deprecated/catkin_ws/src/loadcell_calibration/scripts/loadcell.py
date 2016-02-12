#!/usr/bin/env python

import sys
import rospy

from loadcell_calibration.srv import *

def loadcell_init_client():
    rospy.wait_for_service('get_factor')
    try:
        get_factor = rospy.ServiceProxy('get_factor', GetFactor);
#        lbs = 100
#        factor = 2
#        for x in range(0, 10):
#            response = get_factor(lbs*factor)
#            factor = response.factor
	response = get_factor(x)
	return response.is_done


    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def usage():
	return "%s [x]"%sys.argv[0]

if __name__ == "__main__":

	if len(sys.argv) == 2:
		x = float(sys.argv[1])
	else:
		print usage()
		sys.exit(1)

	print "Inputted Calibration Weight: %s"%(loadcell_init_client(x))


#! then pass this weight to calibration factor calculation
