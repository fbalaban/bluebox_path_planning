#!/usr/bin/env python

from sys import argv
import os
import subprocess
import time
import rospy
import mavros
import csv
from mavros_msgs.msg import Waypoint, WaypointList, CommandCode
from mavros_msgs.srv import WaypointPush
from std_msgs.msg import String

script, longitude, latitude = argv # here we will later on introduce altitude 

# TODO: looking at published topics. when used rospy.get_published_topics(), the topic wasn't there. 
# TODO: probably for some reason master node didn't returned it. -> published_topics = rospy.get_published_topics()
look_for_topics = subprocess.Popen(["rostopic","list"], stdout=subprocess.PIPE, shell=False)
(out, err) = look_for_topics.communicate()

release_spot_topic = 'waypoint_release_spot'

if release_spot_topic in out:
   print("Found the listening topic! Procceding...")
   bashCommand = "rostopic pub -1 /waypoint_release_spot waypoint_planning/Coordinates " + longitude + " " + latitude
   os.system(bashCommand)
else:
   print("Waypoint planner listener topic not found. Maybe forgot to source or launch the node?")

# TODO: sorry for that :S
time.sleep(3)

# if every instance of mavros node on a ground station of a UAV is mavros$INSTANCE, then for 
# each on of the four (4) UAVs there should be a service named 'mavros$INSTANCE/mission/push.
# waypoint_planning produces four files named wpPlanUAV$INSTANCE.txt and sends them (push)
# to each of the four mavros services 
for x in xrange(1,4):
	service_name = 'mavros'+str(x)+'/mission/push'
	waypoint_file = 'wpPlanUAV'+str(x)+'.txt'
	rospy.wait_for_service(service_name)
	waypoint_push = rospy.ServiceProxy(service_name, WaypointPush)
	try:
		waypointList = []
		with open(waypoint_file) as openedFile:
			lineReader = csv.reader(openedFile, delimiter='\t')
			for row in lineReader:
				   waypointList.append(Waypoint(
	                     is_current = bool(int(row[1])),
	                     frame = int(row[2]),
	                     command = int(row[3]),
	                     param1 = float(row[4]),
	                     param2 = float(row[5]),
	                     param3 = float(row[6]),
	                     param4 = float(row[7]),
	                     x_lat = float(row[8]),
	                     y_long = float(row[9]),
	                     z_alt = float(row[10]),
	                     autocontinue = bool(int(row[11]))
	                 ))
				   print('lon:' + str(float(row[9])) + ' lat:' + str(float(row[8])))
			#for line in openedFile:

		response = waypoint_push(waypointList)
	except rospy.ServiceException as exc:
		print("Service did not process request: " + str(exc))