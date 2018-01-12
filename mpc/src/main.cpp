//
// Created by kuang on 17-12-28.
//
#include "../include/mpc/Robot.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "Robot");
    ros::NodeHandle n;

    Robot robot(n);

    robot.init();

    // MPC
//    double delta_t = 0.8;
//    double f = 1/delta_t;
//    ros::Rate loop_rate(f);
//
//    double end_x = 5.0;
//    double end_y = 5.0;
//    double d_stop = 0.1;
//
//    while (ros::ok()){
//        robot.isReach(end_x, end_y, d_stop);
//
//        if (robot.reached) {
//            ROS_INFO("Arrived!\n");
//            break;
//        } else {
//            ROS_INFO("Target position: %f, %f\n", end_x, end_y);
//            robot.MPC_Model(end_x, end_y, delta_t);
//            robot.PrintRobotState();
//
//            ros::spinOnce();
//            loop_rate.sleep();
//        }
//    }



    // PID

    // Go to goal
/*    double theta_d = M_PI / 4;

    double f = 20;
    ros::Rate loop_rate(f);
    double delta_t = 1 / f;

    double x_d = 5.0;
    double y_d = 5.0;
    double d_stop = 0.1;

    while (ros::ok()){
//        robot.GoToAngle(theta_d);
        robot.isReach(x_d, y_d, d_stop);

        if (robot.reached) {
            ROS_INFO("Arrived!\n");
            break;
        } else {
            robot.GoToGoal(x_d, y_d, delta_t);

            ROS_INFO("Target position: %f, %f\n", x_d, y_d);
            robot.PrintRobotState();

            ros::spinOnce();
            loop_rate.sleep();
        }
    }
    */

    // avoid obstacle
    double f = 20;
    ros::Rate loop_rate(f);
    double delta_t = 1 / f;
    while (ros::ok()){
        robot.AvoidObstacles(delta_t);

        robot.PrintRobotState();

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}