#!/usr/bin/env python

import sys
import rospy

from loadcell_calibration.srv import *

def init():
    rospy.wait_for_service('get_factor')
    try:
        get_factor = rospy.ServiceProxy('get_factor', GetFactor);
        lbs = 100
        factor = 2
        for x in range(0, 10):
            response = get_factor(lbs*factor)
            factor = response.factor
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":
    init();
