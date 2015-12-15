# bluebox_path_planning
Path planning algorithm. Built for ROS with roscpp, rospy and for mavlink/mavros usage.

This ROS node consists of two listeners (subscribers): 
	1) Listens on topic 'waypoint_release_spot'.
	2) Listens on topic 'waypoint_replanner'.

How to use:

1) If a 'waypoint_planning/Coordinates'(float64 longitude, float64 latitude) message is published in that topic,
then the listener produces 4 waypoint path files (wpPlanUAV$I.txt - mavlink dialect) around the initial spot. (I = 1,2,3,4)

2) If a 'waypoint_planning/Replan_Msg'(int8 uav_id, waypoint_planning/Coordinates coordinates) message is published in that topic,
then the listener produces a waypoint path file (wpPlanUAV$uav_id.txt - mavlink dialect), having as a starting point (Coordinates)
the bottom left corner of a rectangle.

For now the coverage is static. Each path covers an area of 2km by 2km and the footprint size is 250m.

How to use (python):

There are also two python scripts in order to integrate with mavros. (incomplete-static also)

1) If there are 4 instances of mavros nodes (mavros1, mavros2 etc)
then by running 'path_planning_service_publisher.py' along with arguments Longitude and Latitude
the script sends to mavros$I/mission/push service each one of the files.

2) If you use 'path_replanning_service_publisher.py' along with arguments uav_id, Longitude and Latitude,
then a new path will be produced and sent to the UAV with number 'uav_id'.
As before, a mavros service (mavros$uav_id/mission/push) must be up for it to work..

-------
Sum up:

1. 'catkin_make' the project.
2. source the project ('source devel/setup.bash').
3. 'rosrun waypoint_planning listener'.
4. Either:
 
  4.1.1 rostopic pub -1 /waypoint_release_spot waypoint_planning/Coordinates $longitude $latitude (4 UAVs)
  4.1.2 rostopic pub -1 /waypoint_replanner waypoint_planning/Replan_Msg $uav_id $longitude $latitude (single UAV)
 
 or

  4.2.1 path_planning_service_publisher.py $longitude $latitude
  4.2.1 path_replanning_service_publisher.py $uav_id $longitude$ $latitude

In 4.2.1 four (4) mavros instances must be up having names mavros$I.
In 4.2.2 one mavros instance must be named mavros$uav_id.
