#!/usr/bin/env python

from loadcell_calibration.srv import *
import rospy


test_weight = 0;

def handle_requests(req):
    global test_weight
    print "Reading: %s"%(req.lbs_reading)
    return GetFactorResponse(req.lbs_reading/2, False)

def init():
    rospy.init_node('calibration_server.py')
    srv = rospy.Service('get_factor', GetFactor, handle_requests);
    print "Ready to begin calibrating system"
    rospy.spin()

def usage():
    return "%s <test_weight>"%sys.argv[0]


# Runs if the module is executed as a program
if __name__ == "__main__":
    global test_weight
    if len(sys.argv) == 2:
        test_weight = float(sys.argv[1])
    else:
        print usage()
        sys.exit(1)

    init();
