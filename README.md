# Servo_controller
Controller for a servo node for simulator Gazebo.

To start the world enter the command

    roslaunch servo_gazebo servo_world.launch 

This would start a world with one box(motor driver) and a axle which moves in x-y plane. The motor driver drives the axle to move in any direction. The distance between them has been kept to reduce friction to 0. This will also start the servo controller
    
This would start the controller for the joint. Name of the joint is joint 1. If you give the command

    rostopic list
    
You'll find the publisher and subscriber for the controllers. 

    /servo/joint1_position_controller/command
    
Is the rostopic which commands the axle to move in a particular direction. To manually give commands to the controller try publishing from command line using

    rostopic pub -1 /servo/joint1_position_controller/command std_msgs/Float64 "data: 0.4" 
    
You'll notice that the controller gets into an angle of 0.4 radian. To publish the command from a script i.e a node type

    rosrun joint_controller strt_script
    
This will start a script which subscribes from a subscriber (here: /mavros/imu/data) and adjust servo commands according to it


## To-DO
install ros-control 

	sudo apt-get install ros-kinetic-ros-control ros-kinetic-ros-controllers

Modify the xacro and urdf files in accordance to your code. Change the axis of rotation which suits you.
	
	add transmission interface
	add hardware interface
	add actuator 
	add plugin for gazebo
	add Run and build depends as they are in the code

Now add a control package into your system
	
	catkin_create_pkg servo_control
	make a yaml file with pid values as it is in the code
	make a launch file. Don't forget to include the yaml files
	add build and run depends

Make a world file

	Add spawner in your existing/new world file	

If you want to run the code as a script.
	
	catkin_create_pkg <script_name>
	write the publisher code
	publish in the topic, /servo/joint1_position_controller/command as it is in the code
	add build and ros depends as 

For further queries, mail me at gaurav07@iitkgp.ac.in, or add an issue

