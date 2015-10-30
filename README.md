# bluebox_path_planning
Path planning algorithm. Built for ROS with roscpp, rospy and for mavlink/mavros usage.

This ROS node consists only of one listener (subscriber), who listens on topic 'waypoint_release_spot'.
If a 'waypoint_planning/Coordinates'(float64 longitude, float64 latitude) message is published in that topic,
then the listener produces 4 waypoint path files (wpPlanUAV$I.txt - mavlink dialect) around the initial spot. 
(I = 1,2,3,4)

For now the coverage is static. Each path covers an area of 2km by 2km and the footprint size is 250m.

In the project there is also a python script in order to integrate with mavros. (incomplete-static also)
If there are 4 instances of mavros nodes (mavros1, mavros2 etc)
then by running 'path_planning_service_publisher.py' along with arguments Longitude and Latitude
the script sends to mavros$I/mission/push service each one of the files.

Sum up:

1. 'catkin_make' the project.
2. source the project ('source devel/setup.bash').
3. 'rosrun waypoint_planning listener'.
4. Either
   4.1 rostopic pub -1 /waypoint_release_spot waypoint_planning/Coordinates [longitude] [latitude]
or
   4.2 path_planning_service_publisher.py [longitude] [latitude]

In 4.2. four (4) mavros instances must be up having names mavros$I.
